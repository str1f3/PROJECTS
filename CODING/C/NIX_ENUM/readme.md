## OVERVIEW


nixEnum is a lightweight C utility designed to support **SITUATIONAL AWARENESS** during Linux host assessment by automatically collecting and displaying system information relevant to the operator. The utility is intended to reduce the need for repetitive manual enumeration by programmatically gathering information about the current user, host, network, users, groups, privileges, services, shares, and credentials and data.

This is also a systems-programming project developed to explore Linux APIs, system calls, system resources, process information, filesystem interfaces, and the interaction between user-space applications and the Linux operating system.

## CURRENT CAPABILITIES

In development.

## FUTURE DEVELOPMENT


The following capabilities are planned for future development:

### SITUATIONAL AWARENESS


### CURRENT USER


* Enumerate the context of the current user
* Identify UID and GID information
* Collect associated group information

### HOST


* Enumerate hostname and operating system information
* Identify kernel and system architecture
* Collect system and resource information

### DOMAIN IDENTITY


* Identify available host identity information
* Collect domain or enterprise identity information when exposed by the local system

### NETWORK


* Enumerate network interfaces
* Identify local network addressing information
* Collect relevant network configuration

### USERS


* Enumerate local user accounts
* Collect account information from local system interfaces

### GROUPS


* Enumerate local groups
* Identify group membership information

### PRIVILEGES


* Collect privilege-related information
* Identify information relevant to local privilege assessment

### SERVICES


* Enumerate running processes and services
* Collect information about active system services

### SHARES


* Enumerate locally accessible or mounted shared resources
* Collect filesystem and mount information relevant to host assessment

### CREDENTIALS & DATA


* Identify locations and system information potentially relevant to credential and sensitive-data assessment
* Collect information useful for subsequent host enumeration

### ADDITIONAL DEVELOPMENT

* Linux capability enumeration
* SUID/SGID binary discovery
* Sudo configuration enumeration
* Cron and scheduled-task enumeration
* Expanded service and daemon enumeration
* Expanded network, routing, and DNS information
* Container and virtualization detection
* Expanded credential and sensitive-data discovery
* Improved output formatting and enumeration categorization
* Additional architecture-specific builds

## DISCLAIMER


This is intended for authorized security testing, cybersecurity education, research, and systems-programming development. It is an enumeration utility designed to support host assessment and does not independently exploit vulnerabilities or compromise systems.

Only use on systems for which you have explicit authorization to perform security testing or assessment.

## USE CASES


* OCO host enumeration
* Linux penetration testing and security assessments
* CTF and cybersecurity lab environments
* Linux systems-programming education and research
* Host-based situational awareness and security assessment

## FILE INTEGRITY

TBD

#### SHA-256 CHECKSUM


* `sha256sum nixEnum-linux-amd64`

  * `TBD`

