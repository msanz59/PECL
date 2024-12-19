#include "Arbol.hpp"

Arbol::Arbol() {
	
	raiz = nullptr;
	procesosenarbol = 0;
}
void Arbol::insertar(Proceso val) { 
	
	raiz = insertar(raiz, val); 
	procesosenarbol = procesosenarbol + 1;
	
}
pnodoAbb Arbol::insertar(pnodoAbb nodo, Proceso val)
{
    if(!nodo)
        return new NodoArbol(val);
    if(val.getPrioridad() <= nodo->dato.getPrioridad())
        nodo->izq = insertar(nodo->izq, val);
    else
        nodo->der = insertar(nodo->der, val);
    return nodo;
}
void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}
void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo->dato.getPrioridad() << " ";
    pintar(nodo->der);
}
int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p,
                        char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol =
            nodo->izq->dato.getPrioridad(); // En vez de este valor, tenéis que coger el número de la habitación del paciente.
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol =
        nodo->dato.getPrioridad(); // En vez de este valor, tenéis que coger el número de la habitación del paciente.
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}
void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

Arbol::~Arbol() {
	
	raiz = nullptr;
	procesosenarbol = 0;
	
}

int Arbol::getprocesosenarbol()
{
	return this->procesosenarbol;
}

void Arbol::procesoMenor(pnodoAbb nodo)
{
	if (!nodo->izq){
		cout << "- El proceso normal cuya prioridad es la mas baja: " << endl;
		cout << "El proceso cuyo PID es "<< nodo->dato.getNumerounico() << " es de tipo ";
		if (nodo->dato.getTipo() == 0){
			cout << "normal, ";
		}
		else{
			cout << "tiempo real, ";
		}
		cout << "su estado es ";
		if(nodo->dato.getEstado() == 0){
			cout << "parado ";
		}
		else{
			cout << "en ejecución ";
		}
		cout << "y su prioridad es: "<< nodo->dato.getPrioridad();
		cout << endl;
		
		return;
	}
	procesoMenor(nodo->izq);
}
void Arbol::procesoMayor(pnodoAbb nodo)
{
	if (!nodo->der){
		cout << "- El proceso en tiempo real cuya prioridad es la mas alta: " << endl;
		cout << "El proceso cuyo PID es "<< nodo->dato.getNumerounico() << " es de tipo ";
		if (nodo->dato.getTipo() == 0){
			cout << "normal, ";
		}
		else{
			cout << "tiempo real, ";
		}
		cout << "su estado es ";
		if(nodo->dato.getEstado() == 0){
			cout << "parado ";
		}
		else{
			cout << "en ejecución ";
		}
		cout << "y su prioridad es: "<< nodo->dato.getPrioridad();
		cout << endl;
		
		return;
	}
	procesoMayor(nodo->der);
}

void Arbol::procesoMenor()
{
	procesoMenor(raiz);
}
void Arbol::procesoMayor()
{
	procesoMayor(raiz);
}

void Arbol::inorden()
{
	inorden(raiz);
}
void Arbol::inorden(pnodoAbb nodo)
{
	if(!nodo){
		return;
	}
	inorden(nodo->izq);
	if (nodo->dato.getPrioridad() != 100){
		cout << "El proceso cuyo PID es "<< nodo->dato.getNumerounico() << " es de tipo ";
		if (nodo->dato.getTipo() == 0){
			cout << "normal, ";
		}
		else{
			cout << "tiempo real, ";
		}
		cout << "su estado es ";
		if(nodo->dato.getEstado() == 0){
			cout << "parado ";
		}
		else{
			cout << "en ejecución ";
		}
		cout << "y su prioridad es: "<< nodo->dato.getPrioridad();
		cout << endl;
	}
	inorden(nodo->der);
}

void Arbol::mostrarTiemporeal()
{
	mostrarTiemporeal(raiz);
}
void Arbol::mostrarNormal()
{
	mostrarNormal(raiz);
}
void Arbol::mostrarTiemporeal(pnodoAbb nodo)
{
	if(!nodo){
		return;
	}
	mostrarTiemporeal(nodo->der);
	if (nodo->dato.getPrioridad() != 100 && nodo->dato.getTipo() == 1){
		cout << "El proceso cuyo PID es "<< nodo->dato.getNumerounico() << " es de tipo ";
		if (nodo->dato.getTipo() == 0){
			cout << "normal, ";
		}
		else{
			cout << "tiempo real, ";
		}
		cout << "su estado es ";
		if(nodo->dato.getEstado() == 0){
			cout << "parado ";
		}
		else{
			cout << "en ejecución ";
		}
		cout << "y su prioridad es: "<< nodo->dato.getPrioridad();
		cout << endl;
	}
	mostrarTiemporeal(nodo->izq);
	
}
void Arbol::mostrarNormal(pnodoAbb nodo)
{
	if(!nodo){
		return;
	}
	mostrarTiemporeal(nodo->der);
	if (nodo->dato.getPrioridad() != 100 && nodo->dato.getTipo() == 0){
		cout << "El proceso cuyo PID es "<< nodo->dato.getNumerounico() << " es de tipo ";
		if (nodo->dato.getTipo() == 0){
			cout << "normal, ";
		}
		else{
			cout << "tiempo real, ";
		}
		cout << "su estado es ";
		if(nodo->dato.getEstado() == 0){
			cout << "parado ";
		}
		else{
			cout << "en ejecución ";
		}
		cout << "y su prioridad es: "<< nodo->dato.getPrioridad();
		cout << endl;
	}
	mostrarTiemporeal(nodo->izq);
}

void Arbol::eliminarPorPrioridad(int PID)
{
	return eliminarPorPrioridad(PID, raiz);
	
	

}

void Arbol::eliminarPorPrioridad(int PID, pnodoAbb& nodo)
{
	if(nodo == nullptr){
		return;
	}
	if (nodo->dato.getPrioridad() == PID){
		
		Proceso devolver = nodo->dato;
		if (nodo->der == nullptr && nodo->izq == nullptr){
			delete nodo;
			nodo = nullptr;
		}
		else if (nodo->izq && nodo->der == nullptr){
			pnodoAbb naux = nodo;
			nodo = nodo->izq;
			delete naux;
		}
		else if (nodo->izq == nullptr && nodo->der){
			pnodoAbb naux = nodo;
			nodo = nodo->der;
			delete naux;
		}
		else if (nodo->izq && nodo->der){
			pnodoAbb recorrido = nodo->izq;
			pnodoAbb padre = nodo;
			while(recorrido->der){
				padre = recorrido;
				recorrido = recorrido->der;
			}
			
			nodo->dato = recorrido->dato;
			
			if(padre->der == recorrido){
				padre->der = recorrido->izq;
			}
			else{
				padre->izq = recorrido->izq;
			}
			delete recorrido;
			
		}
		this->elimin = devolver;
		procesosenarbol--;
		return;
	}
	else{
		if (nodo->dato.getPrioridad() > PID){
			eliminarPorPrioridad(PID, nodo->izq);
		}
		else{
			eliminarPorPrioridad(PID, nodo->der);
		}
		
	}
	
}

void Arbol::mostrarHoja()
{
	mostrarHoja(raiz);
}
void Arbol::mostrarHoja(pnodoAbb nodo)
{
	if(nodo == nullptr){
		return;
	}
	mostrarHoja(nodo->izq);
	if (nodo->izq == nullptr && nodo->der == nullptr){
		
		cout << "El proceso cuyo PID es "<< nodo->dato.getNumerounico() << " es de tipo ";
		if (nodo->dato.getTipo() == 0){
			cout << "normal, ";
		}
		else{
			cout << "tiempo real, ";
		}
		cout << "su estado es ";
		if(nodo->dato.getEstado() == 0){
			cout << "parado ";
		}
		else{
			cout << "en ejecución ";
		}
		cout << "y su prioridad es: "<< nodo->dato.getPrioridad();
		cout << endl;
	}
	mostrarHoja(nodo->der);
}

Proceso Arbol::getElimin()
{
	Proceso aux = this->elimin;
	return aux;
	
}