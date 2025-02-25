#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// per memorizzare le scelte del giocatore vengono usati codici interni. Questi codici sono definiti come segue:
// scelta: scelta del giocatore , atto , situazione: situazione in cui si trova il giocatore

// Identità del giocatore. Queste variabili vengono usate in tutto il gioco.
int classe;
int difficolta;

// Scelte del primo atto
int situazione1_1;
int scelta1_1;
int scelta1_1_1;
int scelta1_1_1_2;
int esitoscelta1_1_1_2;
int scelta1_1_2;

void selezionepersonaggio(string protagonista) {
    cout << "Ciao " << protagonista << ", benvenuto in Stellar 832." << endl;
    cout << "In questo gioco dovrai affrontare una serie di avventure e missioni per diventare il piu' grande esploratore della galassia." << endl;
    
    // Scelta della classe
    cout << "\nAdesso, scegli la tua classe:" << endl;
    string classi[] = {"titano", "stregone", "cacciatore", "esploratore"};
    char confermaclasse = 'n';
    while (confermaclasse != 's' && confermaclasse != 'S') {
        for (int i = 0; i < 4; i++) {
            cout << i << ". " << classi[i] << endl;
        }
        cout << "Inserisci il numero corrispondente alla tua scelta: ";
        cin >> classe;
        cout << "La tua classe e': " << classi[classe] << ". E' corretta? (s/n): ";
        cin >> confermaclasse;
    }
    
    // Scelta della difficolta'
    cout << "\nPrima di iniziare la tua avventura, seleziona il livello di sfida del gioco:" << endl;
    string livellidifficolta[] = {"facile", "normale", "sfida di sopravvivenza"};
    string descrizionedifficolta[] = {
        "Indovinelli semplificati, suggerimenti generosi, facilita' di comunicazione, meno probabilita' di perdere equipaggio o venir traditi, 3 vite, checkpoint (alcuni finali sono esclusivi per le difficolta' piu' alte)",
        "La storia per come e' stata intesa: indovinelli normali, suggerimenti normali, comunicazione neutra, probabilita' normale di perdere equipaggio o venir traditi, 2 vite, checkpoint",
        "La sfida definitiva: indovinelli che richiedono REALI CONOSCENZE TECNICHE, nessun suggerimento, comunicazione limitata, alta probabilita' di perdere equipaggio o venir traditi, 1 vita (fallire una sezione comporta la perdita definitiva della partita), nessun checkpoint"
    };
    char confermadifficolta = 'n';
    while (confermadifficolta != 's' && confermadifficolta != 'S') {
        for (int i = 0; i < 3; i++) {
            cout << i << ". " << livellidifficolta[i] << ": " << descrizionedifficolta[i] << endl;
        }
        cout << "Inserisci il numero corrispondente al livello di sfida: ";
        cin >> difficolta;
        if (difficolta == 2) {
            cout << "Sei DAVVERO sicuro di voler giocare a sfida di sopravvivenza? Per superare il gioco sono richieste REALI conoscenze in vari campi. "
                 << "E' concesso usare internet o ChatGPT se non ci arrivi pero'! HAHAHAHAHAHAAHAHAHAHHA, buona fortuna!" << endl;
        }
        cout << "La tua difficolta' e': " << livellidifficolta[difficolta] << ". E' corretta? (s/n): ";
        cin >> confermadifficolta;
    }
    
    cout << "\nBuona fortuna, " << protagonista << "!" << endl;
}

void atto1(string protagonista) {
    cout << "\nAtto 1: GENESI." << endl;
    cout << "La tua avventura inizia su un pianeta sconosciuto, dove la tua astronave si e' schiantata." << endl;
    
    switch (classe) {
        case 0: // titano
            cout << "Il tuo corpo massiccio e' stato danneggiato, ma la tua forza e' ancora intatta." << endl;
            break;
        case 1: // stregone
            cout << "La tua magia e' stata indebolita, ma la tua intelligenza e' ancora intatta." << endl;
            break;
        case 2: // cacciatore
            cout << "Il tuo equipaggiamento e' stato distrutto, ma la tua abilita' e' ancora intatta." << endl;
            break;
        case 3: // esploratore
            cout << "La tua nave e' distrutta, ma la tua abilita' di sopravvivenza e' ancora intatta." << endl;
            break;
    }
    
    cout << "\nDopo esserti ripreso, ti rendi conto che sei da solo." << endl;
    cout << protagonista << ": dove stracavolo sono gli altri? Che e' successo?" << endl;
    
    situazione1_1 = rand() % 2; // modificare a 3 quando il percorso numerato 2 verrà implementato.
    
    switch (situazione1_1) {
        case 0: {
            cout << protagonista << ": Sono da solo! Aiuto, non so come fare! La mia radio non funziona! Le batterie sono scariche!" << endl;
            string listascelte1_1[] = {"usa una patata con degli elettrodi che hai per qualche motivo in tasca",
                                        "dai un colpo alla radio",
                                        "usa un limone"};
            for (int i = 0; i < 3; i++) {
                cout << i << ". " << listascelte1_1[i] << endl;
            }
            cout << "Inserisci il numero corrispondente alla tua scelta: ";
            cin >> scelta1_1;
            
            switch (scelta1_1) {
                case 0:
                    cout << protagonista << " usa la patata con gli elettrodi e, collegandoli alle cavita' della radio, riesce a stabilire un contatto." << endl;
                    break;
                case 1:
                    cout << protagonista << " ha dato un colpo alla radio e, stranamente, contro ogni logica, essa funziona." << endl;
                    break;
                case 2:
                    cout << protagonista << " usa il limone, ma manda in cortocircuito la radio. Dovrai prendere un'altra strada." << endl;
                    break;
            }
            if (scelta1_1 == 0 || scelta1_1 == 1) {
                cout << "Andrew: Ciao " << protagonista << ", ti ricevo forte e chiaro. Dove sei?" << endl;
                cout << protagonista << ": sono in una foresta, non riesco a mandarti la posizione." << endl;
                cout << "Andrew: Va bene, stai li'. Devo calcolare la traiettoria di schianto dell'astronave e forse riesco a risalire al luogo dell'impatto." << endl;

                cout << protagonista << ": che faccio ora? \n";
                string listascelte1_1_1[] = {"esplora la foresta","rimani dove sei"};
                for (int i = 0; i < 2; i++) {
                cout << i << ". " << listascelte1_1_1[i] << endl;
                }
                cout << "Inserisci il numero corrispondente alla tua scelta: ";
                cin >> scelta1_1_1;
            }
            

            switch (scelta1_1_1) { // vuoi esplorare o rimanere li? 
                case 0: {
                    cout << protagonista << ": esploro la foresta adesso, dovresti avere la mia posizione in tempo reale." << endl;
                    break;
                }
                case 1: {
                    cout << protagonista << ": rimango dove sono, in attesa dell'equipaggio." << endl;
                    break;
                }
            }

            if (scelta1_1_1 == 1) { // rimani dove sei
                cout << "Andrew: " << protagonista << ", ho trovato la tua posizione. Vengo subito da te." << endl;
                cout << "Andrew: eccoti! dobbiamo prendere il resto dell'equipaggio." << endl;
            }
            else if (scelta1_1_1 == 0) { // esplora la foresta
                cout << "il nostro protagonista " << protagonista << " va a esplorare la foresta." << endl;

                cout << "Dopo aver camminato per un po', " << protagonista << " trova un mucchio di larve." << endl;
                cout << protagonista << ": Che schifo! Ma forse potrebbero servirmi." << endl;
                cout << protagonista << ": Cosa faccio? " << "?" << endl;

                string listascelte1_1_1_2[] = {"prendi le larve", "lascia le larve"};
                for (int i = 0; i < 2; i++) {
                    cout << i << ". " << listascelte1_1_1_2[i] << endl;
                }
                cout << "Inserisci il numero corrispondente alla tua scelta: ";
                cin >> scelta1_1_1_2;

                if (scelta1_1_1_2 == 0) {
                    cout << protagonista << " prende le larve." << endl;
                    esitoscelta1_1_1_2 = rand() % 2;

                    if (esitoscelta1_1_1_2 == 0)  { // 50% di probabilita' di successo
                        cout << protagonista << ": schifose, ma molto buone!" << endl;
                    }
                    else {
                        if (difficolta == 2) {
                        cout << "Le larve erano velenose. " << protagonista << " muore." << endl;
                        cout << "Andrew: dove sei? dove sei? pronto???? rispondi!!!!! cavolo l'abbiamo perso...." << endl;
                        }
                        else {
                            cout << protagonista << " si sente indebolito." << endl;
                        }
                    }
                }
                else {
                    cout << protagonista << " lascia le larve." << endl;
                    cout << protagonista << ": non mi fido." << endl;
                }

            }
            
            break;
        }
        case 1: {
            cout << protagonista << ": Devo trovare un modo per contattarli." << endl;

            cout << protagonista << ": che faccio ora? \n";
            string listascelte1_1_2[] = {"usa un bengala", "urla","scrivi SOS con le pietre."};

            for (int i = 0; i < 3; i++) {
                cout << i << ". " << listascelte1_1_2[i] << endl;
            }
            cout << "Inserisci il numero corrispondente alla tua scelta: ";
            cin >> scelta1_1_2;

            switch (scelta1_1_2) {
                case 0: {
                    cout << protagonista << " usa un bengala." << endl;
                    cout << "Andrew: " << protagonista << ", ti vedo! Vengo subito da te." << endl;
                    break;
                }
                case 1: {
                    cout << protagonista << " urla." << endl;
                    cout << protagonista << ": AIUTO! AIUTO!" << endl;
                    cout << "Andrew: " << protagonista << ", ti sento! Vengo subito da te." << endl;
                    break;
                }
                case 2: {
                    cout << protagonista << " scrive SOS con le pietre." << endl;
                    cout << "Andrew: " << protagonista << ", ti vedo! Vengo subito da te." << endl;
                    break;
                }
            }

            break;
        }
        case 2: {
            cout << "PERCORSO NON PROGRAMMATO. Rieseguire il programma.";

            break;
        }
    }
}

int main() {
    srand(time(0));
    
    cout << "SOLO L'ATTO 1 E' GIOCABILE IN QUESTO STATO. GLI ALTRI SONO IN WORK IN PROGRESS. NON SONO STATI NEANCHE PROGRAMMATI TUTTI I PERCORSI. IL GIOCO FUNZIONA IN MODALITA INVINCIBILE PER ORA." << endl;
    cout << "FUNZIONALITA' PREVISTE NEL PROSSIMO UPDATE: ATTO 2 , TEMPO LIBERO , STAGIONI DINAMICHE.\n" << endl;
    
    string protagonista;
    cout << "Come ti chiami? ";
    cin >> protagonista;
    
    selezionepersonaggio(protagonista);
    
    atto1(protagonista);
    
    
    return 0;
}
