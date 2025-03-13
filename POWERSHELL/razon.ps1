<#
.SYNOPSIS
    A PS script that gathers data on remote or local system

.DESCRIPTION
    This PS script gathers data on both remote or local systems

.PARAMETER parameterName
    This is a user-defined entry 

.PARAMETER ComputerName
    This is a user-defined entry

.USAGE
    PS C:\> .\razon.ps1 --mode [remote | local] -ComputerName {computerName}

.EXAMPLE Remote Mode
    PS C:\> .\razon.ps1 -mode remote  -ComputerName {computerName}

.EXAMPLE Local Mode (default)
    PS C:\> .\razon.ps1 -mode local -ComputerName {computerName}
#>

# Dot-Sourcing
. ".\razonExtModule.ps1"

# Import-Module
# Import-Module ".\razonExtModule.ps1"

$computers = @([System.Net.Dns]::GetHostName())
#$destinationMachines = @("Machine1", "Machine2", "Machine3")
$masterHashtable = @{}

#foreach ($computer in $destinationMachines
foreach ($computer in $computers) {

    Enter-PSSession -ComputerName $computer
    $jobs = @()
    $functions = @("Get-OSName", "Get-DriveInfo", "Get-AppInfo", "Get-ProcessInfo", "Get-UserInfo", "Get-EnvironmentVariables", "Get-NetworkInfo")

    foreach ($function in $functions) {
        $job = Start-Job -ScriptBlock (Get-Command $function).ScriptBlock -ArgumentList $computer
        $jobs += $job
    }

    # Wait for all jobs to complete
    $jobs | ForEach-Object { $_ | Wait-Job }

    # Retrieve and format the output from all jobs
    $results = $jobs | ForEach-Object { Receive-Job -Job $_ }
    $jobs | ForEach-Object { Remove-Job -Job $_ }
    
    $computerResults = @{}

    foreach ($result in $results) {
        foreach ($prop in $result.PSObject.Properties) {
            if ($prop.Name -notin @("RunspaceId", "PSComputerName", "PSShowComputerName")) {
                if (-not $computerResults[$prop.Name]) {
                    $computerResults[$prop.Name] = @()
                }
                $computerResults[$prop.Name] += $prop.Value
            }
        }
    }

    $masterHashtable[$computer] = $computerResults
}

# Ensure the output directory exists
$outputDir = "C:\Temp"
if (-not (Test-Path -Path $outputDir)) {
    New-Item -Path $outputDir -ItemType Directory
}

# Convert the master hashtable to JSON format
$json = $masterHashtable | ConvertTo-Json -Depth 5
$jsonFilePath = "C:\Temp\system_info.json"
$json | Out-File -FilePath $jsonFilePath

# Make a directory on the local system
$localDir = "C:\Tmp"
if (-not (Test-Path -Path $localDir)) {
    New-Item -Path $localDir -ItemType Directory
}

# Copy the local JSON file to the new directory on the local system
Copy-Item -Path $jsonFilePath -Destination "$localDir\system_info.json"

# Copy the local JSON file to the script's directory
$scriptDir = $PSScriptRoot
Copy-Item -Path $jsonFilePath -Destination "$scriptDir\system_info.json"

# Remove the local JSON file
Remove-Item -Path $jsonFilePath

# Ensure the event source exists
if (-not [System.Diagnostics.EventLog]::SourceExists("WinDiagTool")) {
    New-EventLog -LogName Application -Source "WinDiagTool"
}

# Write a message to the system log
Write-EventLog -LogName Application -Source "WinDiagTool" -EventId 1001 -EntryType Information -Message "Diagnostics complete."

# Display the last 30 minutes of the system log to ensure that your message is in the log
Get-EventLog -LogName Application -After (Get-Date).AddMinutes(-30) | Where-Object { $_.Source -eq "WinDiagTool" }

