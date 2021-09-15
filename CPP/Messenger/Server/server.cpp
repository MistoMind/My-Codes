#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;

string make_daytime_string(){
    time_t now = time(0);
    return ctime(&now);
}

int main(){
    cout << "Running main" << endl;
    try{
    boost::asio::io_context io;
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 1111));
    
    for(;;){
        tcp::socket socket(io);
        acceptor.accept(socket);
        boost::system::error_code ignored_error;
        string message = make_daytime_string();

        boost::asio::write(socket, boost::asio::buffer("Hello client\n"), ignored_error);
        boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
    }
    }
    catch(exception& e){
        cerr << e.what() << endl;
    }
}