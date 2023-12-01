# ft_ping

## usefull links

1. Internet Protocol
   [RFC791](https://datatracker.ietf.org/doc/html/rfc791)
1. Internet Control Message Protocol
   [RFC792](https://datatracker.ietf.org/doc/html/rfc792)

## USEFULL COMMAND

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

## TODO

1. Do more falgz
1. fix return value according to `/rsc/ping`
   1. help
   1. incompatible flag (`-f` and `-i`)
