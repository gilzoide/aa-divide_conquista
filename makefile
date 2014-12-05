#  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
#
# SCC0218 • Algoritmos Avançados e Aplicações
#
# Projeto 03 • Divisão e Conquista
# makefile
#
# Gil Barbosa Reis                     NUSPº 8532248
# Leonardo Sampaio Ferraz Ribeiro      NUSPº 8532300
#
#  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #

objs = main.o grafico.o
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -O2 -march=native
exe = proj3

all : $(objs)
	$(CXX) $(CXXFLAGS) $(objs) -o $(exe)

run :
	@./$(exe)

clean :
	$(RM) $(objs) $(exe) *~
