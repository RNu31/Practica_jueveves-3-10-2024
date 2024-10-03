#include <iostream>
#include <queue>
#include <string>
#include <limits>

struct Doc {
  std::string Nombre;
  std::string Contenido;
};

void MenuPrincipal();
void AgregarArchivo(std::queue<Doc>& NuevoDoc);
void EliminarArchivo(std::queue<Doc>& NuevoDoc);
void MostrarArchivo(std::queue<Doc>& NuevoDoc);

int main(int argc, char* argv[]) {
  std::queue<Doc> NuevoDoc;
  int opcion;
  do {
    MenuPrincipal();
    std::cin >> opcion;
    switch (opcion) {
      case 1:
        AgregarArchivo(NuevoDoc);
        break;

      case 2:
        MostrarArchivo(NuevoDoc);
        break;

      case 3:
        EliminarArchivo(NuevoDoc);
        break;

      case 4:
        std::cout << "Gracias buen dia" << std::endl;
        system("pause");
        break;

      default:
        std::cout << "La opcion seleccionada no existe. Intentelo nuevamente." << std::endl;
        std::cout << "Opciones validas: 1, 2, 3, 4." << std::endl;
        system("pause");
        break;
    }
  } while (opcion != 4);

  return 0;
}

void AgregarArchivo(std::queue<Doc>& NuevoDoc) {
  Doc nuevodoc;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Ingrese el nombre del documento: ";
  std::getline(std::cin, nuevodoc.Nombre);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
  std::cout << "Ingrese el contenido del documento: ";
  std::getline(std::cin, nuevodoc.Contenido);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  NuevoDoc.push(nuevodoc); // Agregar el documento a la cola
  std::cout << "Documento agregado." << std::endl;
}

void EliminarArchivo(std::queue<Doc>& NuevoDoc) {
  if (NuevoDoc.empty()) {
    std::cout << "Este documento no existe." << std::endl;
    return;
  }
  Doc documento = NuevoDoc.front();  // Copia el contenido del documento
  std::cout << "Nombre: " << documento.Nombre << std::endl;
  std::cout << "Contenido: " << documento.Contenido << std::endl;
  int respuesta;
  std::cout << "Si desea eliminar el documento presione 1 y si lo quiere conservar presione 2: ";
  std::cin >> respuesta;  // Pedir respuesta al usuario

  if (respuesta == 1) {
    NuevoDoc.pop();  // Eliminar el documento
    std::cout << "Documento eliminado." << std::endl;
  } else {
    std::cout << "No se elimino el documento." << std::endl;
  }
}

void MostrarArchivo(std::queue<Doc>& NuevoDoc) {
  if (NuevoDoc.empty()) {
    std::cout << "No hay documentos para imprimir." << std::endl;
    return;
  }

  // Mostrar el documento que se está imprimiendo
  Doc documentoActual = NuevoDoc.front();
  std::cout << "Documento actual (en impresion):\n";
  std::cout << "Nombre: " << documentoActual.Nombre << std::endl;
  std::cout << "Contenido: " << documentoActual.Contenido << std::endl;
  std::cout << std::endl;

  // Mostrar los documentos en espera
  std::queue<Doc> temp = NuevoDoc;  // Crea una copia de la cola para mostrar
  temp.pop();  // Elimina el documento que se está imprimiendo de la copia
  std::cout << "Documentos en espera:\n";
  while (!temp.empty()) {
    std::cout << "Nombre: " << temp.front().Nombre << std::endl;
    std::cout << "Contenido: " << temp.front().Contenido << std::endl;
    temp.pop();  // Elimina la lista temporal que se creó
  }
  std::cout << std::endl;
}

void MenuPrincipal() {  // Menu uno
  std::cout << "Menu principal" << std::endl;
  std::cout << "1. Agregar archivos" << std::endl;
  std::cout << "2. Ver archivos" << std::endl;
  std::cout << "3. Eliminar archivos" << std::endl;
  std::cout << "4. Salir" << std::endl;
  std::cout << "Ingrese la opcion que desea realizar" << std::endl;
}
