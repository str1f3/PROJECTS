# identify the OS name
function Get-OSName {
    param (
	    [parameter(Mandatory = $True)]
		[string] $ComputerName
	)
	$osName = Get-CimInstance Win32_OperatingSystem
	return $osName | Select-Object @{
       Name = "Operating System"
       Expression = {"$(($osName).Name.Split('|')[0]): $(($osName).Version)"}
    }
}

# identify the OS version
#function Get-OSVersion {
	#param (
	    #[parameter(Mandatory = $True)]
		#[string] $ComputerName
	#)
	#provide reference
	#$osVersionInfo = (Get-CimInstance Win32_OperatingSystem).Version
	#return $osVersion
#}

# identify the total amount of disk space in use per disk drive
function Get-DriveInfo {
	param (
	    [parameter(Mandatory = $True)]
		[string] $ComputerName
	)
	$driveInfo = Get-CimInstance Win32_LogicalDisk
	return $driveInfo | Select-Object @{
		Name = "Drive Info"
		Expression = {"$($_.DeviceID) | Size: $($_.Size) | Free: $($_.FreeSpace)"}
	}
}

# identify the application name & version of any installed application that has either
# the word "Microsoft" or "Windows" in it anywhere
#  - referrence: instructor's example about pattern searching
#  - referrence: wobc & cctc notes
function Get-AppInfo {
	param (
	    [parameter(Mandatory = $True)]
		[string] $Computername
    )
	$appInfo = Get-CimInstance CIM_Product | Where-Object {$_.Name -like "*microsoft*" -or $_.Name -like "*windows*"} 
	return $appInfo | Select-Object @{
		Name = "Application Information"
		Expression = {"$($_.Name) $($_.Version)"}
	}
}

# identify the ProcessName, OSName, & WindowsVersion for all the processes running
# on the System
# (Get-CimInstance Cim_Process).Name or .ProcessName
# (Get-CimInstance Cim_Process).OSName
# (Get-CimInstance Cim_Process)>WindowsVersion
function Get-ProcessInfo {
    param (
        [Parameter(Mandatory = $True)]
        [string] $ComputerName
    )
    $processes = Get-CimInstance Cim_Process
	Write-Output("Process Information")
    ForEach ($process in ($processes)){
        Write-Output("$(($process).Name) | $(($process).OSName) | $(($process).WindowsVersion)")
    }
}

# identify the username, account type, and Security Identifier (SID) of all valid
# users on the system (have name and SID)
function Get-UserInfo {
    param (
        [Parameter(Mandatory = $True)]
        [string] $ComputerName
    )
    $admins = Get-CimInstance Win32_UserAccount | Where-Object {$_.Caption -like "$ComputerName\Administrator"}
    $nonAdmins = Get-CimInstance Win32_UserAccount | Where-Object {$_.Caption -ne "$ComputerName\Administrator"}
    
	ForEach ($admin in ($admins)){
        Write-Output("Administrator Accounts: $(($admin).Name) `nSID: $(($admin).SID)`nAccount Type: Admin")
    }
    ForEach ($nonAdmin in ($nonAdmins)){
    Write-Output("Non Administrator Accounts: $(($nonAdmin).Name) `nSID: $(($nonAdmin).SID) `nAccount Type: User")
    }
}

# identify the environment variables, if they exist: PSModulePath and the Path
function Get-EnvironmentVariables {
	param (
	    [Parameter(Mandatory = $True)]
		[string] $ComputerName
    )
	$envVar = Get-CimInstance Win32_Environment | Where-Object {$_.Name -like "PSModulePath" -or $_.Name -like "Path"}
	return $envVar | Select-Object @{
		Name = "System Variables"
		Expression = {"$($_.Name) $($_.VariableValue)"}
	}
}

# identify the NIC name, IP address, and MACAddress of every NIC device on the system.
# If there is no information for the IP address or the MAC address, do not display
# anything for those values, but still ddisplay the NIC name.
function Get-NetworkInfo {
	param (
	    [Parameter(Mandatory = $True)]
		[string] $ComputerName
	)
	$nicInfo = Get-CimInstance Win32_NetworkAdapterConfiguration | Select-Object @{
        Name="NIC Infomation"; 
		Expression={
            if ($_.IPAddress -and $_.MACAddress) {
                "$($_.Description) - [IP: $($_.IPAddress)] - [MAC: $($_.MACAddress)]"
            }
		    elseif ($_.IPAddress) {
                "$($_.Description) - [IP: $($_.IPAddress)]"
            }
		    elseif ($_.MACAddress) {
                "$($_.Description) - [MAC: $($_.MACAddress)]"
            }
		    else {
                "$($_.Description)"
            }
	    }
	}
}