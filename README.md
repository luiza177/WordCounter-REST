# To make it work

Needs [Pistache](http://pistache.io/) library:

```bash
git clone https://github.com/oktal/pistache.git 
git submodule update --init 
```
Then build it:
```bash
cd pistache
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
```