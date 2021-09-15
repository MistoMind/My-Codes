echo "House keeping"
rm ./object_files/* Game
echo "Compiling the program"
cd src
g++ -I .. -c *.cpp 
mv *.o .. 
cd ..
g++ -c main.cpp 
mv *.o object_files
cd object_files
g++ * -o Game 
mv Game ..
cd ..
echo "Running the game!!"
./Game
echo "Game ran successfully (^_^)/"