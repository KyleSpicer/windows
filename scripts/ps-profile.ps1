# Reload the PowerShell profile
function sourceProfile {
    . $PROFILE
}

function GoTo-Desktop {
    Set-Location $HOME\Desktop
}

function GoTo-Project {
    Set-Location $HOME\Desktop\codelevelup\kspicer-cmake-demo
}

function GoTo-GitLab {
    Set-Location $HOME\Desktop\gitlab
}

function GoTo-GitHub {
    Set-Location $HOME\Desktop\github
}

# Aliases
Set-Alias source sourceProfile
Set-Alias d GoTo-Desktop
Set-Alias p GoTo-Project
Set-Alias lab GoTo-GitLab
Set-Alias hub GoTo-GitHub

# display current time/date
Write-Host (Get-Date) -ForegroundColor Blue

Import-Module posh-git
