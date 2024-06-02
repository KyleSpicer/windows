# Echo Server


## Table of Contents
1. [System Requirements](#system-requirements)
1. [Start Server](#start-server)
1. [Start Client](#start-client)
1. [Current Status](#current-status)
1. [Known Issues](#known-issues)

## System Requirements
## Start Server
## Start Client

## Current Status

### Shared Libraries
- **As of: 2 June 2024**
- SharedControlHandler.lib: Control Handler Library to catch CTRL+C and handle gracefully.

### Server
- **As of: 2 June 2024**
- Server uses Windows Socket (TCP/IPV4 only) to listen for one client connection
- Once client connects, server echos back, closes client socket and gracefully shutsdown

### Client

### Known Issues
- SharedControlHandler.lib needs to be refactored so server and client can use the functions appropriately.