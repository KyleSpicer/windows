# Retrieve current git branch 
function Get-GitBranch {
    if (Test-Path .git) {
        $branch = git rev-parse --abbrev-ref HEAD
        " [$branch]"
    }
}

# Customize the PowerShell prompt
function prompt {
    $p = Get-Location
    Write-Host "$p" -NoNewline
    $gitBranch = Get-GitBranch
    if ($gitBranch) {
        Write-Host $gitBranch -NoNewline -ForegroundColor Yellow
    }
    Write-Host " > " -NoNewline
    return " "
}

# Function to reload the PowerShell profile
function sourceProfile {
    . $PROFILE
}

# Alias to reload the PowerShell profile
Set-Alias source sourceProfile