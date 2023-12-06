# ft_ping

https://github.com/Pixailz/ft_ping/assets/35565530/4702e5b1-2e30-40eb-a868-3a19350b0745

## TODO

1. A little more falgz

## Usefull links

1. Internet Protocol
   [RFC791](https://datatracker.ietf.org/doc/html/rfc791)
1. Internet Control Message Protocol
   [RFC792](https://datatracker.ietf.org/doc/html/rfc792)

## Usage

```
bash$ make
bash$ ./ft_ping --help
Usage: ft_ping [OPTION...] HOST ...
Send ICMP ECHO_REQUEST packets to network hosts.

 Options valid for all request types:

  -c, --count=NUMBER         stop after sending NUMBER packets
  -i, --interval=FLOAT       wait, FLOAT * 1, second between sending each packet
  -n, --numeric              do not resolve host addresses
      --ttl=N                specify N as time-to-live
  -T, --tos=NUM              set type of service (TOS) to NUM
  -v, --verbose              verbose output
  -w, --timeout=N            stop after N seconds
  -W, --linger=N             number of seconds to wait for response

 Options valid for --echo requests:

  -f, --flood                flood ping (root only)
  -l, --preload=NUMBER       send NUMBER packets as fast as possible before
                             falling into normal mode of behavior (root only)
  -p, --pattern=PATTERN      fill ICMP packet with given pattern (hex)
  -q, --quiet                quiet output
  -s, --size=NUMBER          send NUMBER data octets

  -?, --help                 give this help list
      --usage                give a short usage message
  -V, --version              print program version

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.

Options marked with (root only) are available only to superuser.

Report bugs to <pixailz1@gmail.com>.
bash$ sudo ./ft_ping 42angouleme.com -c1
```

## Usefull command

### STATS

> to make stats about our ping
`sudo ./rsc/ping -f 127.0.0.1 & sleep 5s; sudo kill -s SIGINT $!`

### DEBUG_FD

`sudo bash -c "./ft_ping 127.0.0.1 DEBUG_FD>exec.log"`
   > [!NOTE]
   > This command output DEBUG_FD to a log file with sudo privileges

### VALGRIND
1. ALL
   ```sh
   sudo bash -c "valgrind \
    --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    --trace-children=yes \
    --track-fds=yes \
    ./ft_ping 127.0.0.1 127.0.0.2 127.0.0.3 DEBUG_FD>exec.log"
   ```
