#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// nel gioco vengono usate variabili per memorizzare scelte nominate secondo un codice sotto qui descritto: 
// scelta_(numero atto)_(numero sezione)_(se è influita da classe, onore, rapporti o altro verrà siglata qui.)
// situazione = monologo, dialogo = quando parla con qualcuno , scelta = scelta del giocatore.

void selezionepersonaggio(string protagonista, int classe, int difficolta) {
    cout << "come ti chiami? ";
    cin >> protagonista;
    cout << "ciao " << protagonista << " benvenuto in stellar 832." << endl;
    cout << "in questo gioco dovrai affrontare una serie di avventure e missioni per diventare il piu' grande esploratore della galassia." << endl;

    cout << "adesso, scegli la tua classe: \n ";
    string classi[] = {"titano", "stregone", "cacciatore", "esploratore"};

    char confermaclasse; // scegli la classe.
    while (confermaclasse != 's') {
      for (int i = 0; i < 4; i++) {
        cout << i << ". " << classi[i] << "\n ";
    }
      cin >> classe;
      cout << "la tua classe e': " << classi[classe] << ", e' corretto? (s/n)" << endl;
      cin >> confermaclasse;
    }

    cout << "prima di iniziare la tua avventura, seleziona il livello di sfida del gioco: \n "; // le vite vengono riportate al loro stato originale ad ogni atto. Cio significa che se si conclude il primo con una vita , nel secondo si avranno tre vite. Cio non si applica alla difficoltà piu alta
    string livellidifficolta[] = {"facile", "normale", "sfida di sopravvivenza"};
    string descrizionedifficolta[] = {"Indovinelli semplificati, suggerimenti generosi, facilità di comunicazione, meno probabilità di perdere equipaggio o venir traditi, 3 vite, checkpoint (alcuni finali sono esclusivi per le difficoltà piu' alte)",
                                      "La storia per com'è stata intesa: indovinelli normali, suggerimenti normali, comunicazione neutra, proabilità normale di perdere equipaggio o venir traditi, 2 vite, checkpoint",
                                      "La sfida definitiva: indovinelli che richiedono REALI CONOSCENZE TECNICHE, nessun suggerimento, comunicazione limitata, alta probabilità di perdere equipaggio o venir traditi, 1 vita (fallire una sezione comporta la perdita definitiva della partita.), nessun checkpoint"};
    
    char confermadifficolta; // scegli la difficoltà.
    while (confermadifficolta != 's') {
      for (int i = 0; i < 3; i++) {
        cout << i << ". " << livellidifficolta[i] << ": " << descrizionedifficolta[i] << "\n ";
    }
      cin >> difficolta;
      if (difficolta == 2) {
        cout << "Sei DAVVERO sicuro di voler giocare a sfida di sopravvivenza? per superare il gioco sono richieste REALI conoscenze in vari campi. E' concesso usare internet o ChatGPT se non ci arrivi pero'! HAHAHAHAHAHAAHAHAHAHHA, buona fortuna!" << endl;
    }
      cout << "la tua difficolta' e': " << livellidifficolta[difficolta] << ", e' corretta? (s/n)" << endl;
      cin >> confermadifficolta;
    }

    cout << "buona fortuna, " << protagonista << "!" << endl;
}

void atto1(string protagonista, int classe, int difficolta, int situazione1_1) {
    cout << "atto 1: GENESI." << endl;
    cout << "la tua avventura inizia su un pianeta sconosciuto, dove la tua astronave si e' schiantata." << endl;

    switch (classe) {
        case 0: // titano
            cout << "il tuo corpo massiccio e' stato danneggiato, ma la tua forza e' ancora intatta." << endl;
            break;
        case 1: // stregone
            cout << "la tua magia e' stata indebolita, ma la tua intelligenza e' ancora intatta." << endl;
            break;
        case 2: // cacciatore
            cout << "il tuo equipaggiamento e' stato distrutto, ma la tua abilita' e' ancora intatta." << endl;
            break;
        case 3: // esploratore
            cout << "la tua nave e' distrutta, ma la tua abilita' di sopravvivenza e' ancora intatta." << endl;
            break;
    }

    cout << "dopo esserti ripreso, ti rendi conto che sei da solo." << endl;
    cout << protagonista << ": " << "dove stracavolo sono gli altri? che è successo?" << endl;

    situazione1_1 = rand() % 3; // situazione 1.1
    switch (situazione1_1) {
        case 0: {
            cout << protagonista << " : sono da solo aiuto non so come fare! la mia radio non funziona! le batterie sono scariche!" << endl;
            string listascelte1_1[] = {"usa una patata con degli elettrodi che hai per qualche motivo in tasca", "dai un colpo alla radio", "usa un limone."};
            for (int i = 0; i < 3; i++) {
                cout << i << ". " << listascelte1_1[i] << endl;
            }
            int scelta1_1;
            cin >> scelta1_1;

            switch (scelta1_1) {
                case 0: {
                    cout << protagonista << " usa la patata con gli elettrodi e, collegandoli alle cavità della radio , riesce a stabilire un contatto." << endl;
                    break;
                }
                case 1: {
                    cout << protagonista << " ha dato un colpo alla radio e stranamente, contro ogni logica, funziona." << endl;
                    break;
                }
                case 2: {
                    cout << protagonista << "il limone manda in cortocircuito la radio , bisogna prendere obbligatoriamente un altra strada." << endl;
                    break;
                }
            }
            break;
        }
        case 1: {
            cout << protagonista << "devo trovare un modo per contattarli." << endl;
            break;
        }
        case 2: {
            cout << protagonista << "non lo so, ma devo trovare un modo per riparare la nave." << endl;
            break;
        }
    }

}

int main() {
    srand(time(0));

    string protagonista;
    int classe;
    int difficolta;

    int situazione1_1;

    selezionepersonaggio(protagonista, classe, difficolta);
    atto1(protagonista, classe, difficolta, situazione1_1);
    return 0;
}
