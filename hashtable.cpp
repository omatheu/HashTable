#include <cstring>
#include <iostream>
#include <list>
using namespace std;

class TabelaHash {
private:
  static const int gruposHash = 10;
  list<pair<int, string>> tabela[gruposHash];

public:
  bool estaVazia() const;
  int funcaoHash(int chave);
  void insereItem(int chave, string valor);
  void removeItem(int chave);
  void buscarTabela(int chave);
  void mostrarTabela();
};

bool TabelaHash::estaVazia() const {
  int soma{};
  for (int i{}; i < gruposHash; i++) {
    soma += tabela[i].size();
  }
  if (!soma) {
    return true;
  }
  return false;
}

int TabelaHash::funcaoHash(int chave) { return chave % gruposHash; }

void TabelaHash::insereItem(int chave, string valor) {
  int valorHash = funcaoHash(chave);
  auto &celula = tabela[valorHash];
  auto itr = begin(celula);
  bool chaveExiste = false;
  for (; itr != end(celula); itr++) {
    if (itr->first == chave) {
      chaveExiste = true;
      itr->second = valor;
      cout << "[AVISO] Chave existe, valor substituído" << endl;
      break;
    }
  }
  if (!chaveExiste) {
    celula.emplace_back(chave, valor);
  }
  return;
}

void TabelaHash::removeItem(int chave) {
  int valorHash = funcaoHash(chave);
  auto &celula = tabela[valorHash];
  auto itr = begin(celula);
  bool chaveExiste = false;
  for (; itr != end(celula); itr++) {
    if (itr->first == chave) {
      chaveExiste = true;
      itr = celula.erase(itr);
      cout << "[INFO] Par removido" << endl;
      break;
    }
  }

  if (!chaveExiste) {
    cout << "[AVISO] Chave não encontrada, par não removido" << endl;
  }

  return;
}

void TabelaHash::mostrarTabela() {
  for (int i{}; i < gruposHash; i++) {
    if (tabela[i].size() == 0)
      continue;
    auto itr = tabela[i].begin();
    for (; itr != tabela[i].end(); itr++) {
      cout << "[INFO] Chave: " << itr->first << " Valor: " << itr->second
           << endl;
    }
  }
  return;
}

void TabelaHash::buscarTabela(int chave) {
  int valorHash = funcaoHash(chave);
  auto &celula = tabela[valorHash];
  auto itr = begin(celula);
  bool chaveExiste = false;
  for (; itr != end(celula); itr++) {
    if (itr->first == chave) {
      chaveExiste = true;
      cout << "[INFO] Chave encontrada: " << itr->second << endl;
      break;
    }
  }
  if (!chaveExiste) {
    cout << "[AVISO] Chave não encontrada" << endl;
  }
}

int main() {
  TabelaHash HT;
  if (HT.estaVazia()) {
    cout << "[INFO] Tabela Hash está vazia" << endl;
  } else {
    cout << "[AVISO] Tabela Hash não está vazia" << endl;
  }

  HT.insereItem(2, "Caneta BIC");
  HT.removeItem(2);
  HT.insereItem(2, "Caneta");
  HT.mostrarTabela();

  // HT.insereItem(2, "Caderneta");
  // HT.insereItem(3, "Lápis");
  // HT.insereItem(4, "Borracha");
  // HT.insereItem(5, "Garafa");
  // HT.insereItem(6, "Folha Sulfite");
  // HT.insereItem(7, "Monitor Dell");
  // HT.insereItem(8, "Mouse");
  // HT.insereItem(9, "Caderno");
  // HT.insereItem(10, "Fone de Ouvido");

  // HT.mostrarTabela();

  // HT.removeItem(1);
  // HT.removeItem(3);

  // HT.mostrarTabela();

  return 0;
}
