# This is a build script for Windows 10 machines using PowerShell

# Install the Posh-Git module using PowerShellGet
# Write-Output "Installing Posh-Git module..."
# Install-Module posh-git -Scope CurrentUser -Force
# Write-Output "Posh-Git installation completed."

# Add Import statement to $PROFILE
# Write-Output "Adding Import-Module posh-git to $PROFILE..."
# Add-Content -Path $PROFILE -Value "Import-Module posh-git"
# Write-Output "Import-Module posh-git added to $PROFILE."

# Verify the addition
# Write-Output "Verifying the $PROFILE contents..."
# Get-Content $PROFILE
# Write-Output "Verification completed."

# create github/gitlab directories
# $dir_names = @("gitlab", "github")
# foreach ($dir in $dir_names) {
#     $dirPath = Join-Path $HOME\desktop $dir
#     New-Item -ItemType Directory -Path $dirPath -Force
#     Write-Host "Directory created: $dirPath"
# }

# install git: https://git-scm.com/download/win
winget install --id Git.Git -e --source winget

# Done
Write-Output "All steps completed. Please restart PowerShell."
