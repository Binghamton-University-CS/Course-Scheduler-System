COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 1
LASTNAME = Fehrer
GITUSERID = mtfehrer
EXE = scheduler_cp1

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/scheduler.o $(OBJ)/Student.o $(OBJ)/Course.o $(OBJ)/ExtraFucntions.o
	$(CC) $(FLAGS) $(OBJ)/scheduler.o -o $@

$(OBJ)/scheduler.o: scheduler.cpp Student.cpp Course.cpp ExtraFunctions.cpp StudentList.cpp CourseList.cpp
	$(CC) $(FLAGS) -c scheduler.cpp -o $@

$(OBJ)/Course.o: Course.cpp Student.cpp StudentList.cpp
	$(CC) $(FLAGS) -c Course.cpp -o $@
	
$(OBJ)/Student.o: Student.cpp Course.cpp CourseList.cpp
	$(CC) $(FLAGS) -c Student.cpp -o $@

$(OBJ)/ExtraFunctions.o: ExtraFunctions.cpp
	$(CC) $(FLAGS) -c ExtraFunctions.cpp -o $@

$(OBJ)/StudentList.o: StudentList.cpp Student.cpp Course.cpp
	$(CC) $(FLAGS) -c StudentList.cpp -o $@

$(OBJ)/CourseList.o: CourseList.cpp Course.cpp Student.cpp
	$(CC) $(FLAGS) -c CourseList.cpp -o $@

#$(OBJ)/MichaelList.o: MichaelList.cpp
#	$(CC) $(FLAGS) -c MichaelList.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
