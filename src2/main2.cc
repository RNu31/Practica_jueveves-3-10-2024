#include <iostream>
#include <queue>
#include <string>
struct Doc {
  std::string Nombre;
  std::string Contenido;
};

void MenuPrinsipal();
void AñadirArchivo(std::queue<Doc>& NuevoDoc);
void EliminarDoc(std::queue<Doc>& NuevoDoc);
void MostrarDoc(std::queue<Doc>& NuevoDoc);

int main(int argc, char* argv[]) {
  std::queue<Doc> NuevoDoc;
  int respuesta_menu;
  do {
    MenuPrinsipal();
    std::cin >> respuesta_menu;
    switch (respuesta_menu) {
      case 1:
        system("cls");
        AñadirArchivo(NuevoDoc);
        break;

      case 2:
        system("cls");
        MostrarDoc(NuevoDoc);
        break;

      case 3:
        system("cls");
        EliminarDoc(NuevoDoc);
        break;

      case 0:
        system("cls");
        std::cout << "Gracias buen dia" << std::endl;
        system("pause");
        break;

      default:
        system("cls");
        std::cout << "la opcion seleccionada no exite vuelve a intentarlo"
                  << std::endl;
        system("pause");
        break;
    }
  } while (respuesta_menu != 0);

}

void AñadirArchivo(std::queue<Doc>& NuevoDoc) {//crea solo crear
  Doc nuevodoc;
  std::cout << "ingrese el nombre del cocumento\n";
  std::cin >> nuevodoc.Nombre;
  std::cout << "\n";
  std::cout << "ingrese el contenido del cocumento\n";
  std::cin >> nuevodoc.Contenido;
  std::cout << "\n";
}

void EliminarDoc(std::queue<Doc>& NuevoDoc) {
  if (NuevoDoc.empty()) {
    std::cout << "este Documento no existe";
  }
  Doc documento = NuevoDoc.front();//esto copia contenido del doc para que el usuraio vea el usuraio par que este segruo de borrarlo
  std::cout << "Nombre:\n" << documento.Nombre << std::endl;
  std::cout << "Contenido\n" << documento.Contenido << std::endl;
  int respuesta;
  std::cout<<"desea eliminar este documento\n";// Confirmacion clasica para ver si elimina el archivo
  std::cout<<"1. Si\n";
  std::cout<<"2. NO\n";
  if (respuesta=1){
    NuevoDoc.pop();
  }
  std::cout<<"Regrasando";
}

void MostrarDoc(std::queue<Doc>& NuevoDoc){
if (NuevoDoc.empty()) {
    std::cout << "La cola esta vacia." << std::endl;
    return;
  }
  std::queue<Doc> temp = NuevoDoc;  // Crea una copia de la pila temporal solo para mostrar 
  std::cout << "Elementos en la cola: ";
  while (!temp.empty()) {
    std::cout << temp.front().Nombre << " ";
    std::cout << temp.front().Contenido << " ";
    temp.pop();  // Elimina la lista temporal que se creo
  }
  std::cout << std::endl;
}

void MenuPrinsipal(){// Menu uno
  std::cout << "Menu prinsipal" << std::endl;
  std::cout << "que deseas hacer?" << std::endl;
  std::cout << "\n 1 Añadir archivos" << std::endl;
  std::cout << "2 Ver archivos" << std::endl;
  std::cout << "3 Eliminar archivos" << std::endl;
  std::cout << "0 Salir" << std::endl;
}