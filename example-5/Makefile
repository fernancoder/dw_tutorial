CC=g++
LIBS=-ldaework -lpthread

chemical: chemical.o ChemicalServer.o ChemicalThread.o ChemicalDispatcher.o FormulaToText.o TextToFormula.o ChemicalTraslator.o ChemicalAction.o ChemicalTraslatorPool.o ChemicalTraslatorHelper.o
	$(CC) -o chemical chemical.o ChemicalServer.o ChemicalThread.o ChemicalDispatcher.o FormulaToText.o TextToFormula.o ChemicalTraslator.o ChemicalAction.o ChemicalTraslatorPool.o ChemicalTraslatorHelper.o $(LIBS)

chemical.o: chemical.cpp
	$(CC) -c chemical.cpp

ChemicalServer.o: ChemicalServer.cpp ChemicalServer.h
	$(CC) -c ChemicalServer.cpp

ChemicalThread.o: ChemicalThread.cpp ChemicalThread.h
	$(CC) -c ChemicalThread.cpp

ChemicalDispatcher.o: ChemicalDispatcher.cpp ChemicalDispatcher.h
	$(CC) -c ChemicalDispatcher.cpp

FormulaToText.o: FormulaToText.cpp FormulaToText.h
	$(CC) -c FormulaToText.cpp

TextToFormula.o: TextToFormula.cpp TextToFormula.h
	$(CC) -c TextToFormula.cpp

ChemicalTraslator.o: ChemicalTraslator.cpp ChemicalTraslator.h
	$(CC) -c ChemicalTraslator.cpp

ChemicalAction.o: ChemicalAction.cpp ChemicalAction.h
	$(CC) -c ChemicalAction.cpp

ChemicalTraslatorPool.o: ChemicalTraslatorPool.cpp ChemicalTraslatorPool.h
	$(CC) -c ChemicalTraslatorPool.cpp 

ChemicalTraslatorHelper.o: ChemicalTraslatorHelper.cpp ChemicalTraslatorHelper.h
	$(CC) -c ChemicalTraslatorHelper.cpp
