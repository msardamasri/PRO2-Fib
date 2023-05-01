OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -std=c++11

program.exe: program.o Cjt_problemas.o Cjt_cursos.o Cjt_sesiones.o Cjt_usuarios.o Usuario.o Curso.o usuario_problemas.o Sesion.o
	g++ -o program.exe program.o Cjt_problemas.o Cjt_cursos.o Cjt_sesiones.o Cjt_usuarios.o Usuario.o Curso.o usuario_problemas.o Sesion.o
	
program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cjt_cursos.o: Cjt_cursos.cc Cjt_cursos.hh
	g++ -c Cjt_cursos.cc $(OPCIONS)
	
Cjt_sesiones.o: Cjt_sesiones.cc Cjt_sesiones.hh
	g++ -c Cjt_sesiones.cc $(OPCIONS)
	
Cjt_problemas.o: Cjt_problemas.cc Cjt_problemas.hh
	g++ -c Cjt_problemas.cc $(OPCIONS)

Cjt_usuarios.o: Cjt_usuarios.cc Cjt_usuarios.hh
	g++ -c Cjt_usuarios.cc $(OPCIONS)

Usuario.o: Usuario.cc Usuario.hh
	g++ -c Usuario.cc $(OPCIONS)
	
Curso.o: Curso.cc Curso.hh
	g++ -c Curso.cc $(OPCIONS)
	
usuario_problemas.o: usuario_problemas.cc usuario_problemas.hh
	g++ -c usuario_problemas.cc $(OPCIONS)
	
Sesion.o: Sesion.cc Sesion.hh
	g++ -c Sesion.cc $(OPCIONS)

tar: program.cc Cjt_problemas.cc Cjt_cursos.cc Cjt_sesiones.cc Cjt_usuarios.cc Usuario.cc Curso.cc usuario_problemas.cc Sesion.cc  Cjt_problemas.hh Cjt_cursos.hh Cjt_sesiones.hh Cjt_usuarios.hh Usuario.hh Curso.hh usuario_problemas.hh Sesion.hh
	tar -cvf practica.tar program.cc Cjt_problemas.cc Cjt_cursos.cc Cjt_sesiones.cc Cjt_usuarios.cc Usuario.cc Curso.cc usuario_problemas.cc Sesion.cc  Cjt_problemas.hh Cjt_cursos.hh Cjt_sesiones.hh Cjt_usuarios.hh Usuario.hh Curso.hh usuario_problemas.hh Sesion.hh Makefile
clean:
	rm -f *.o
	rm -f *.exe
