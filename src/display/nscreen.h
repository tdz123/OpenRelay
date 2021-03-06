/*
# Copyright (C) 2008-2015 Renato Machado Monaro
# This file is part of OpenRelay.
#
# OpenRelay is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# OpenRelay is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
*/
#ifndef NSCREEN_H
#define NSCREEN_H

#ifdef NCURSES
#include <curses.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <boost/thread/thread.hpp>
#include "channel.h" 
#include "types.h"
#include "parameters.h"

using namespace std;
namespace orelay{
//! Classe Display.
class Display{
	public:
                /*! Método virtual pura, necessária para execução das funções do display.*/
		virtual void Run()=0;
                /*! Definição do ponteiro de tempo para o display.*/
		void SetClock(Channel<timer> *);
	protected:
                /*! Atributo que armazena o ponteiro de tempo usado no relé.*/
		Channel<timer> *MasterClock;
	};
//! Classe NScreen.
/** Esta é uma classe derivada da classe Display. Esta classe é responsável pela exibição na tela.*/
class NScreen: public Display{
public:
                /*! Construtor em vazio da clsse NScreen.*/
		NScreen();
                /*! Destrutor da classe NScreen.*/
		~NScreen();
                /*! Método que adiciona um canal digital a ser exibido na tela.*/
		void Join_Channel(Channel<digital>*);
		void Join_Channel(Channel<Complex>*);
                /*! Método que adiciona um canal analógico a ser exibido na tela.*/
		void Join_Channel(Channel<analogic>*);
                /*! Método que adiciona um canal de tempo a ser exibido na tela.*/
		void Join_Channel(Channel<string>*);
                /*! Método que adiciona um canal de tempo a ser exibido na tela.*/
		void Join_Channel(Channel<timer>*);
                /*! Método para que ocorra a exibição na tela.*/
		virtual void Run();
	private:
		/*!Armazena o endereço do antigo Cout.*/
                streambuf* OldCout;
                /*!Armazena todas as informações contidas no Cout.*/
		ostringstream OutBuffer;
                // /*! Atributo que irá receber o ponteiro do trigger.*/
		//Channel<digital> *Trigger;
                /*! Vetor que armazena os ponteiros dos canais analógicos.*/
		vector <Channel<analogic>* > Analogic;
                /*! Vetor que armazena os ponteiros dos canais digitais.*/
		vector <Channel<digital>* > Digital;
		vector <Channel<Complex>* > Phasor;
		vector <Channel<string>* > String;
                /*! Vetor que armazena os ponteiros dos canal de tempo.*/
		vector <Channel<timer>* > Timer;
		/*! Variáveis que indicam o número máximo de colunas (MaxCol) e o de linhas (MaxRow) da tela. */
		int MaxCol,MaxRow;
	};
}
#endif
#endif /* !NSCREEN_H */
