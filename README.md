# ft_ping

## usefull links

1. Internet Protocol
   [RFC791](https://datatracker.ietf.org/doc/html/rfc791)
1. Internet Control Message Protocol
   [RFC792](https://datatracker.ietf.org/doc/html/rfc792)

## Valgrind

1. ALL
   ```sh
   valgrind \
   	--leak-check=full \
   	--show-leak-kinds=all \
   	--trace-children=yes \
   	--track-fds=yes \
   	./ft_ping google.com
   ```

## submodules

### update

```
git clone git@github.com:Pixailz/ft_ping && cd ft_ping/rsc && rm -r ./helper
git clone git@github.com:Pixailz/helper && cd ../lib && rm -r ./ft_libft
git clone git@github.com:Pixailz/ft_libft && cd ft_libft/rsc && rm -r ./helper
git clone git@github.com:Pixailz/helper && cd ../../..
```

### update

```
git pull && cd ./rsc/helper
git pull && cd ../../lib/ft_libft
git pull && cd ./rsc/helper
git pull && cd ../../../../
```
