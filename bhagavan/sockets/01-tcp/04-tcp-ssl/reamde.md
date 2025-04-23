### Notes

#### Environment install
```sh
	sudo apt install libssl-dev
	openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365 -nodes
```

#### Server compilation
```sh
	gcc -o ssl_tcp_server ssl_tcp_server.c -lssl -lcrypto
	./ssl_tcp_server
```

#### Client compilation
```sh
	gcc -o ssl_tcp_client ssl_tcp_client.c -lssl -lcrypto
	./ssl_tcp_client
```

### 🔐 SSL/TLS Handshake – Sequence Diagram

```plaintext
Client                             Server
  |                                   |
  | --------- ClientHello ----------> |   (Includes supported ciphers, TLS version, client random)
  |                                   |
  | <-------- ServerHello ----------- |   (Selected cipher, TLS version, server random)
  | <-------- Certificate ----------- |   (Server sends its certificate to prove identity)
  | <------ ServerHelloDone --------- |
  |                                   |
  | ------ [Optional: Certificate] -->|   (Client certificate for mutual auth, rarely used)
  | -------- ClientKeyExchange -----> |   (Contains key material encrypted with server's public key)
  | --------- ChangeCipherSpec -----> |   (Client is ready to switch to encrypted communication)
  | -------- Finished (Encrypted) --> |   (Client verifies entire handshake so far)
  |                                   |
  | <------- ChangeCipherSpec ------- |   (Server switches to encrypted mode)
  | <-------- Finished (Encrypted) -- |   (Server verifies the handshake)
  |                                   |
  |------ Encrypted Application Data ------>|
  |<----- Encrypted Application Data -------|
```

---

### 🧠 Key Concepts

- **ClientHello**: Proposes TLS version, cipher suites, compression methods, and a random number.
- **ServerHello**: Server selects parameters and sends its certificate.
- **ClientKeyExchange**: Contains the **pre-master secret** used to generate session keys.
- **ChangeCipherSpec**: Notifies the other party to start encrypted communication.
- **Finished**: First encrypted message verifying the handshake integrity.

---
