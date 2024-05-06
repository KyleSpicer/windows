$numWindows = 4

# loop to open multiple terminal windows
for ($i = 1; $i -le $numWindows; $i++) {
    # start a new process
    Start-Process powershell -ArgumentList "-NoExit", "-Command `"Write-Host 'Terminal Window $i'; Read-Host 'Press Enter to exit...'; exit`""
}