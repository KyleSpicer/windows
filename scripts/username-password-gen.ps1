param(
    [string]$fileName,
    [int]$number
)

# generate username:password
$output = @() # initialize empty array to store generated user/pass before writing to file.
for ($i = 1; $i -le $number; $i++) {
    $username = "user$i"
    $password = "pass$i"
    $output += "${username}:${password}"
}

# write to file
$output | Out-File -FilePath $fileName -Encoding utf8

Write-Host "Usernames and passwords have been generated and saved to $fileName."