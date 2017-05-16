FROM etna/moulinette-debian:latest

RUN apt-get -y install valgrind
RUN echo 'alias etnacpp="g++ -std=c++14 -Wall -pedantic -Wextra -Werror -g"' >> ~/.bashrc

WORKDIR /app
VOLUME /app