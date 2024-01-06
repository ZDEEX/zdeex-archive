# Hush Overview

## Mining Algorithm

Equihash (200,9) (ASIC)

## Block time

75 seconds

## Block size

4MB

## P2P

TLS1.3 via WolfSSL is enforced for all network connections as of v3.6.1 .
Many ciphersuites are technically supported by TLS1.3 but many of them
are ancient, proved to be less secure than intended or likely backdoored.
Hush only uses what are widely considered to be the most secure and [best ciphersuites](https://ciphersuite.info/cs/).

New Hush P2P connections randomly choose between these two ciphersuites each
time a new connection to a peer is created:

  * `TLS_AES_256_GCM_SHA384`
  * `TLS_CHACHA20_POLY1305_SHA256`

Encrypted P2P connections are important because it means passive network spies,
such as ISPs, cannot tell what nodes are communicating to each other and also
prevents certain attacks against privacy at the network level, such as looking
for which node was the first to relay a transaction. Bitcoin has no protection
against this which is why it's trivial for network spies to tell which node
(and hence which IP address) created a certain transaction and hence which
IP address owns which addresses.

## RPC

Inherited many RPC's from Bitcoin and Zcash with many new ones

## Consensus

Hush is a mandatory privacy blockchain as of Block 340000 (Nov 2020),
which means you can only send to a shielded address, never to a transparent
address. This is enforced via consensus rules and sometimes called "z2z".
