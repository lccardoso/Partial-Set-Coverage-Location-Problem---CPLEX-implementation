CFLAGS= -Wall -m64 -g -w
#CFLAGS= -Wall -m64 -o2 
CXX=g++

#ILOG= /mnt/dadoslinux/ibm/ILOG/CPLEX_Studio1210/
#ILOG= /opt/ibm/ILOG/CPLEX_Studio1271
ILOG= /opt/ibm/ILOG/CPLEX_Studio1210
CPPFLAGS= -DIL_STD -I$(ILOG)/cplex/include -I$(ILOG)/concert/include
CPLEXLIB=-L$(ILOG)/cplex/lib/x86-64_linux/static_pic -lilocplex -lcplex -L$(ILOG)/concert/lib/x86-64_linux/static_pic -lconcert -lm -lpthread

comp-loc:  
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o loc  problema-localizacao.cpp  $(CPLEXLIB) -ldl

clean:
	rm -f  *.out *.aux *.log *.nav *.snm *.out *.toc 
