<#
.SYNOPSIS
    Generates a memory usage report of all running processes and saves it to a text file.

.DESCRIPTION
    This script retrieves detailed memory information for all active processes on the system.
    It captures the Process Name, ID, Handles, Working Set (physical memory in use),
    Private Bytes (memory allocated by the process not shared with other processes),
    Paged Pool, and Non-Paged Pool memory.
    The output is formatted as a list and saved to C:\MemoryReport.txt.

.NOTES
    - Requires Administrator privileges to access information for all processes.
    - The output file will be created/overwritten at C:\MemoryReport.txt.
    - WorkingSet: The current size, in bytes, of the Working Set of the process.
                  The Working Set is the set of memory pages currently visible to the process in physical RAM.
    - PrivateMemorySize64: The current size, in bytes, of the private memory allocated for the process.
                           This memory cannot be shared with other processes.
    - PagedPool: The amount of paged pool memory, in bytes, allocated by the process.
                 Paged pool memory is virtual memory that can be moved to the paging file (disk) if not used.
    - NonPagedPool: The amount of nonpaged pool memory, in bytes, allocated by the process.
                    Nonpaged pool memory is virtual memory that cannot be moved to the paging file.
.EXAMPLE
    To run this script:
    1. Open PowerShell as Administrator.
    2. Navigate to the directory where you saved the script (e.g., cd C:\Scripts).
    3. Execute the script: .\Get-MemoryReport.ps1

.LINK
    Get-Process: https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.management/get-process
    Format-List: https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/format-list
#>

# Define the output file path
$OutputPath = "C:\MemoryReport.txt"

# Get the current date and time for the report header
$DateTime = Get-Date -Format "yyyy-MM-dd HH:mm:ss"

Write-Host "Starting memory report generation..."
Write-Host "Output will be saved to: $OutputPath"

# Use a try-catch block for robust error handling
try {
    # Clear the content of the output file if it exists, or create it
    # Add a header with the timestamp
    "Memory Usage Report - Generated on: $DateTime" | Out-File -FilePath $OutputPath -Encoding UTF8
    "`n" | Out-File -FilePath $OutputPath -Encoding UTF8 -Append

    # Get all running processes and select relevant memory properties.
    # We'll also convert byte values to MB for readability.
    Get-Process | Select-Object -Property `
        Name, `
        Id, `
        Handles, `
        @{Name='WorkingSet (MB)'; Expression={$_.WS / 1MB -as [int]}}, `
        @{Name='PrivateBytes (MB)'; Expression={$_.PrivateMemorySize64 / 1MB -as [int]}}, `
        @{Name='PagedPool (MB)'; Expression={$_.PagedPool / 1MB -as [int]}}, `
        @{Name='NonPagedPool (MB)'; Expression={$_.NonPagedPool / 1MB -as [int]}} `
    | Format-List | Out-File -FilePath $OutputPath -Encoding UTF8 -Append

    Write-Host "Memory report successfully saved to $OutputPath"
}
catch {
    # Display any errors that occur during script execution
    Write-Error "An error occurred during report generation: $($_.Exception.Message)"
    Write-Host "Please ensure PowerShell is run as Administrator."
}

