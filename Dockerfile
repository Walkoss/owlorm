FROM etna/moulinette-debian:latest

RUN apt-get update
RUN apt-get -y install valgrind libmysqlcppconn-dev 
RUN echo 'alias etnacpp="g++ -std=c++14 -Wall -pedantic -Wextra -Werror -g"' >> ~/.bashrc

WORKDIR /app
VOLUME /app