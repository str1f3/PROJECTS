# PowerShell System Information Gathering Script

## Overview
This PowerShell script collects detailed system information from both local and remote machines. Designed as part of the **Warrant Officer Advanced Course (WOAC24-002) Advanced PowerShell Project**, it automates data retrieval across multiple systems, making it useful for cybersecurity, network operations, and system administration.

## Features
- **Supports Local & Remote Execution**: Gathers data from the local machine or specified remote computers.
- **Comprehensive System Details**: Collects OS information, disk usage, installed applications, running processes, network configuration, and more.
- **Asynchronous Processing**: Utilizes PowerShell jobs to parallelize tasks for efficiency.
- **Structured Output**: Exports data in JSON format for further analysis or integration with security tools.
- **Event Logging**: Logs execution details to Windows Event Log for auditing.

## Use Cases
- **Cybersecurity & Threat Hunting**: Helps security teams analyze system configurations and detect anomalies.
- **Network Operations & System Administration**: Assists in managing and troubleshooting multiple systems.
- **Digital Forensics**: Provides a structured way to extract key system details for forensic analysis.

## Prerequisites
- Windows OS with **PowerShell v5.x** or later
- Administrator privileges (Run PowerShell as Admin)
- PowerShell Remoting enabled for remote execution

## Installation
1. Clone this repository:
   ```powershell
   git clone https://github.com/YourGitHubUsername/YourRepoName.git
   cd YourRepoName
   ```
2. Ensure the required PowerShell execution policy is set:
   ```powershell
   Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope CurrentUser
   ```
3. Place `razon.ps1` and `razonExtModule.ps1` in the same directory.

## Usage
### Local Execution
```powershell
.\razon.ps1 -mode local -ComputerName "LocalPC"
```
### Remote Execution
```powershell
.\razon.ps1 -mode remote -ComputerName "RemotePC1", "RemotePC2"
```
> **Note:** Remote execution requires `Enable-PSRemoting -Force` on target machines.

## Output
The script generates a JSON report with system details:
```powershell
C:\Temp\system_info.json
```

## Security Considerations
- Ensure the script is run in a **secure environment** with controlled privileges.
- Validate the integrity of the script before execution.
- Modify logging settings to fit operational security (OPSEC) requirements.

## Future Enhancements
- Add integrity verification to detect unauthorized script modifications.
- Implement anomaly detection to flag suspicious system configurations.
- Expand logging to include security-specific events.

## Author
**Stephen Razon**  
Warrant Officer Advanced Course (WOAC24-002)  

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
