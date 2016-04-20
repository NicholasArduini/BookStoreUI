OBJ = main.o BMScontrol.o UImanager.o BookArray.o Course.o Book.o Product.o WaterBottle.o Sweater.o Computer.o Shopper.o AdminAccount.o

bsms:	$(OBJ)
	g++ -o bsms $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BMScontrol.o:   BMScontrol.cc BMScontrol.h UImanager.h DList.h Shopper.h AdminAccount.h defs.h
	g++ -c BMScontrol.cc

UImanager.o:    UImanager.cc UImanager.h Computer.h WaterBottle.h Sweater.h Shopper.h defs.h
	g++ -c UImanager.cc

BookArray.o:    BookArray.cc BookArray.h Book.h defs.h
	g++ -c BookArray.cc

Course.o:   Course.cc Course.h defs.h
	g++ -c Course.cc

Product.o:      Product.cc Product.h defs.h
	g++ -c Product.cc

Book.o:     Book.cc Product.h Book.h defs.h
	g++ -c Book.cc

Computer.o:     Computer.cc Product.h Computer.h defs.h
	g++ -c Computer.cc

Sweater.o:      Sweater.cc Product.h Sweater.h defs.h
	g++ -c Sweater.cc

WaterBottle.o:      WaterBottle.cc Product.h WaterBottle.h defs.h
	g++ -c WaterBottle.cc

AdminAccount.o:     AdminAccount.cc AdminAccount.h Product.h DList.h defs.h
	g++ -c AdminAccount.cc

Shopper.o:      Shopper.cc Shopper.h Product.h DList.h AdminAccount.h defs.h
	g++ -c Shopper.cc

clean:
	rm -f *.o bsms

