rm -r build/
rm -r results/ || true 
mkdir results
mkdir build && cd build
cmake ..
make 
cd .. 