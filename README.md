## SFMLeton 💀
A skeleton for developing SFML programs

`🗝️ FAST`: Easily and quickly get started with SFML <br/>
`☠️ LEAN`: Only has features you need 90% of the time <br/>
`🦴 BONE`: Pick a bone with your problem, not yak-shave for 20 days <br/>
`🏴‍☠️ SHIP`: Supports WIN+LIN (and probably Mac) <br/>

### Getting started:
```
# clone:
git clone https://github.com/Xunie/sfmleton.git
cd sfmleton
git submodule init && git submodule update
cd .. # exit dir

# build:
mkdir sfmleton-build
cd sfmleton-build
cmake ../sfmleton
make -j
```

If you're on MSYS2 MinGW64 like the real pros are, generate build with:
```
cmake -G "MSYS Makefiles" ../sfmleton
````
