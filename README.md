# Simple C Client-Server Application

Learing how to create a socket-based client-sever system in C.

## Client Structure

1. Socket for client is created by ```socket()```

2. Client socket is created, and settings for socket are defined

   - Domain: IPv4 (AF_INET)
   - Type Of Socket: TCP/UDP (SOCK_STREAM)
   - Protocol: IP (0)

3. Attempt to connect to remote address/port number with ```connect()```

4. Request Data Receival From Server via ```recv()```

5. Connection To Remote Server Is Establised

6. Data Is received from server via ```recv()``` -> a string

## Server Structure

1. Socket for client is created by ```socket()```

2. Client socket is created, and settings for socket are defined

   - Domain: IPv4 (AF_INET)
   - Type Of Socket: TCP/UDP (SOCK_STREAM)
   - Protocol: IP (0)

3. Create Data - In This Case A Message - To Send To Client Node

4. Bind To A Empty Port In Network via ```bind()```

5. Set Server To Listen For Connection Attempts via ```listen()```

6. Send Data From Server To Client via ```send()```

## Useage

1. Open 2 Terminals

2. Run ```server``` on one

3. Run ```client``` on other

4. Data Should Be Send To Other Terminal & Displayed

### Acknowledgements

- [geeksforgeeks][https://www.geeksforgeeks.org/simple-client-server-application-in-c/]
