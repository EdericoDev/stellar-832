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

// scelte del secondo atto
int scelta2_salvaJohn;
int scelta2_1;
int atto2_scelta_composto;
int atto2_risposta_utente;
int atto2_vite;
int atto2_num_composti;
bool atto2_bomba_disinnescata;
int scelta2_porta;
int scelta2_oggetto;
int sceltaSimboli;

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

    cout << "\n--- La storia finora... ---" << endl;
    
    // 1. Scelta della situazione iniziale
    cout << "1. Situazione iniziale: ";
    if (situazione1_1 == 0)
        cout << "Emergenza: radio non funziona e batterie scariche." << endl;
    else if (situazione1_1 == 1)
        cout << "Ricerca di un modo per contattare gli altri." << endl;
    
    // 2. Scelta sull'uso della radio (solo se situazione1_1 è 0)
    if (situazione1_1 == 0) {
        cout << "2. Scelta sull'uso della radio: ";
        if (scelta1_1 == 0)
            cout << "Usata una patata con elettrodi." << endl;
        else if (scelta1_1 == 1)
            cout << "Dato un colpo alla radio." << endl;
        else if (scelta1_1 == 2)
            cout << "Usato un limone (radio mandata in cortocircuito)." << endl;
    }
    
    // 3. Scelta sulla posizione o l'esplorazione (solo se si era in emergenza e si aveva scelta sulla radio)
    if (situazione1_1 == 0 && (scelta1_1 == 0 || scelta1_1 == 1)) {
        cout << "3. Scelta sulla posizione: ";
        if (scelta1_1_1 == 0)
            cout << "Esplorazione della foresta." << endl;
        else if (scelta1_1_1 == 1)
            cout << "Attesa sul luogo, in attesa dell'arrivo dell'equipaggio." << endl;
    }
    
    // 4. Scelta sulle larve (solo se si era scelto di esplorare la foresta)
    if (situazione1_1 == 0 && scelta1_1 == 0 && scelta1_1_1 == 0) {
        cout << "4. Scelta sulle larve: ";
        if (scelta1_1_1_2 == 0)
            cout << "Prendute le larve." << endl;
        else if (scelta1_1_1_2 == 1)
            cout << "Lasciate le larve." << endl;
    }
    
    // 5. Scelta per contattare l'equipaggio (se situazione1_1 è 1)
    if (situazione1_1 == 1) {
        cout << "3. Scelta per contattare gli altri: ";
        if (scelta1_1_2 == 0)
            cout << "Usato un bengala." << endl;
        else if (scelta1_1_2 == 1)
            cout << "Urlato." << endl;
        else if (scelta1_1_2 == 2)
            cout << "Scritto SOS con le pietre." << endl;
    }
    
    cout << "\nFine dell'Atto 1." << endl;
}

void atto2(string protagonista) {
    cout << "\nAtto 2: LA RICERCA." << endl;
    cout << protagonista << " si mette alla ricerca degli altri membri dell'equipaggio..." << endl;
    cout << "Dopo qualche istante, incontri Sora, John e James nelle vicinanze." << endl;
    cout << "Sora: Eccoti qui, " << protagonista << "!" << endl;
    cout << "John: Finalmente ci siamo riuniti." << endl;
    cout << "James: Forza, andiamo avanti!" << endl;
    
    // Scelta chiave: salvare John o lasciarlo
    cout << "\nNoti che John ha riportato ferite gravi durante l'incidente." << endl;
    cout << "Vuoi aiutarlo a stabilizzarsi?" << endl;
    cout << "0. Sì, aiutalo" << endl;
    cout << "1. No, lascialo" << endl;
    cout << "Inserisci il numero corrispondente alla tua scelta: ";
    cin >> scelta2_salvaJohn;
    
    if (scelta2_salvaJohn == 0) {
        cout << "\nHai deciso di aiutare John. Lui ti ringrazia e promette di darti supporto nelle prossime sfide." << endl;
    }
    else {
        cout << "\nHai deciso di non aiutare John. Lui resta in uno stato critico e potrebbe non essere in grado di assisterti in futuro." << endl;
    }
    
    cout << "\nDecidete di usare un metal detector. In breve, questo rivela una preziosa risorsa nascosta nel sottosuolo." << endl;
    
    // Controllo della mappa: se il giocatore ha scelto la classe 'esploratore' (codice 3) usa la sua mappa, altrimenti quella di Sora.
    if (classe == 3) {
        cout << "\nUsando la tua mappa, individui un ingresso segreto a una catacomba." << endl;
    }
    else {
        cout << "\nUsando la mappa di Sora, individuate un ingresso segreto a una catacomba." << endl;
    }
    
    cout << "\nEntrate nella catacomba. Il corridoio si biforca e vi trovate di fronte a diverse direzioni da prendere." << endl;
    string listaScelte2_1[3] = {"vai a sinistra", "vai a destra", "vai dritto"};
    for (int i = 0; i < 3; i++) {
        cout << i << ". " << listaScelte2_1[i] << endl;
    }
    cout << "Inserisci il numero corrispondente alla tua scelta: ";
    cin >> scelta2_1;
    
    cout << "\nScegliendo \"" << listaScelte2_1[scelta2_1] << "\", procedete lungo un lungo corridoio." << endl;
    
    // Nuovo segmento: analisi dei simboli
    cout << "\nDopo aver percorso il corridoio, vi trovate in una sala ampia ma buia, con strani simboli incisi sulle pareti." << endl;
    cout << "Il gruppo si ferma per decidere il da farsi." << endl;
    cout << "\nScelte extra:" << endl;
    cout << "0. Esaminare attentamente i simboli per cercare indizi utili." << endl;
    cout << "1. Ignorare i simboli e procedere subito." << endl;
    cout << "Inserisci il numero corrispondente alla tua scelta: ";
    cin >> sceltaSimboli;
    if (sceltaSimboli == 0) {
        cout << "\nDecidi di esaminare i simboli. Scopri un messaggio criptico che suggerisce come evitare certe trappole." << endl;
    }
    else {
        cout << "\nDecidi di non perdere tempo e procedi subito, affidandoti al tuo istinto." << endl;
    }
    
    // Inizio del puzzle della bomba
    cout << "\nMentre attraversate una porta pesante, il pavimento cede e vi ritrovate in un vicolo cieco." << endl;
    cout << "Improvvisamente, una bomba si attiva!" << endl;
    
    // Imposta il numero di vite in base alla difficoltà
    switch (difficolta) {
        case 0: {
            atto2_vite = 3;
            break;
        }
        case 1: {
            atto2_vite = 2;
            break;
        }
        case 2: {
            atto2_vite = 1;
            break;
        }
    }

    // Se hai aiutato John, guadagni una vita extra
    if (scelta2_salvaJohn == 0) {
        atto2_vite++;
        cout << "\nJohn ti assiste e, grazie al suo intervento, guadagni una vita extra per affrontare la sfida." << endl;
    }
    
    cout << "\nPer disinnescare la bomba, devi rispondere correttamente ad un indovinello sui composti ionici." << endl;
    
    atto2_bomba_disinnescata = false;
    
    // Puzzle: difficoltà facile e normale
    if (difficolta == 0 || difficolta == 1) {
        atto2_num_composti = 3;
        string compostiFacile[3] = {"cloruro di sodio", "floruro di magnesio", "bromuro ferrico"};
        int risposteFacile[3] = {1, 2, 3};  // Le risposte corrispondono ai trasferimenti di elettroni
        
        while (atto2_vite > 0 && !atto2_bomba_disinnescata) {
            cout << "\nScegli il composto per l'indovinello:" << endl;
            for (int i = 0; i < atto2_num_composti; i++) {
                cout << i << ". " << compostiFacile[i] << endl;
            }
            cout << "Inserisci il numero corrispondente al composto: ";
            cin >> atto2_scelta_composto;
            
            cout << "\nIndovinello: Quanti elettroni vengono spostati per creare " 
                 << compostiFacile[atto2_scelta_composto] << "?" << endl;
            if (difficolta == 0) {
                cout << "Suggerimento: la risposta e' " << risposteFacile[atto2_scelta_composto] << "." << endl;
            }
            else if (difficolta == 1) {
                cout << "Suggerimento: ricorda che il trasferimento corrisponde alla carica del metallo." << endl;
            }
            
            cout << "Inserisci la tua risposta (numero): ";
            cin >> atto2_risposta_utente;
            
            if (atto2_risposta_utente == risposteFacile[atto2_scelta_composto]) {
                cout << "\nHai disinnescato la bomba!" << endl;
                atto2_bomba_disinnescata = true;
            }
            else {
                atto2_vite--;
                if (atto2_vite > 0)
                    cout << "\nRisposta sbagliata! Hai ancora " << atto2_vite << " vite." << endl;
                else {
                    cout << "\nRisposta sbagliata! Non hai vite rimaste." << endl;
                    cout << protagonista << " muore a causa della bomba." << endl;
                    return;
                }
            }
        }
    }
    // Puzzle: difficoltà sfida di sopravvivenza
    else if (difficolta == 2) {
        atto2_num_composti = 6;
        string compostiSopravvivenza[6] = {"cloruro di alluminio", "bromuro di argento", "ioduro di piombo", 
                                           "bromuro di stronzio", "acido cloridricο", "adico fluoridico"};
        int risposteSopravvivenza[6] = {3, 1, 2, 2, 1, 1};
        
        while (atto2_vite > 0 && !atto2_bomba_disinnescata) {
            cout << "\nScegli il composto per l'indovinello:" << endl;
            for (int i = 0; i < atto2_num_composti; i++) {
                cout << i << ". " << compostiSopravvivenza[i] << endl;
            }
            cout << "Inserisci il numero corrispondente al composto: ";
            cin >> atto2_scelta_composto;
            
            cout << "\nIndovinello: Quanti elettroni vengono spostati per creare " 
                 << compostiSopravvivenza[atto2_scelta_composto] << "?" << endl;
            cout << "Inserisci la tua risposta (numero): ";
            cin >> atto2_risposta_utente;
            
            if (atto2_risposta_utente == risposteSopravvivenza[atto2_scelta_composto]) {
                cout << "\nHai disinnescato la bomba!" << endl;
                atto2_bomba_disinnescata = true;
            }
            else {
                atto2_vite--;
                if (atto2_vite > 0)
                    cout << "\nRisposta sbagliata! Hai ancora " << atto2_vite << " vite." << endl;
                else {
                    cout << "\nRisposta sbagliata! Non hai vite rimaste." << endl;
                    cout << protagonista << " muore a causa della bomba." << endl;
                    return;
                }
            }
        }
    }
    
    // Proseguimento dell'atto dopo il disinnesco della bomba
    if (atto2_bomba_disinnescata) {
        cout << "\nNella camera successiva trovate la preziosa risorsa che cercavate." << endl;
        cout << "Il gruppo si inoltra in un corridoio che conduce a una porta misteriosa che protegge una stanza segreta." << endl;
        
        cout << "\nCome intendi aprire la porta?" << endl;
        cout << "0. Forzare la porta con la forza bruta" << endl;
        cout << "1. Cercare un meccanismo segreto" << endl;
        cout << "2. Usare la tecnologia di Sora per sbloccarla" << endl;
        cout << "Inserisci il numero corrispondente alla tua scelta: ";
        cin >> scelta2_porta;
        
        if (scelta2_porta == 0) {
            cout << "\nDecidi di forzare la porta con la forza bruta." << endl;
            if (classe == 0 || classe == 2) { // titano o cacciatore
                cout << "La tua forza ti permette di aprirla, anche se con qualche danno alla struttura." << endl;
            }
            else {
                cout << "Forzi la porta, ma rischi di compromettere ulteriormente la struttura." << endl;
            }
        }
        else if (scelta2_porta == 1) {
            cout << "\nCerchi un meccanismo segreto sulla porta." << endl;
            if (classe == 3) { // esploratore
                cout << "Con la tua esperienza, individui rapidamente il meccanismo e apri la porta in sicurezza." << endl;
            }
            else {
                cout << "Trovi un meccanismo, ma faticando a decifrarlo, ci metti più tempo a sbloccarla." << endl;
            }
        }
        else if (scelta2_porta == 2) {
            cout << "\nUsi la tecnologia avanzata di Sora per tentare di sbloccare la porta." << endl;
            cout << "Il dispositivo funziona, aprendo la porta con un clic." << endl;
        }
        
        cout << "\nAll'interno della stanza segreta, trovate un oggetto misterioso che potrebbe essere utile in futuro." << endl;
        cout << "Decidi di prenderlo o lasciarlo?" << endl;
        cout << "0. Prendi l'oggetto" << endl;
        cout << "1. Lascia l'oggetto" << endl;
        cout << "Inserisci il numero corrispondente alla tua scelta: ";
        cin >> scelta2_oggetto;
        
        if (scelta2_oggetto == 0) {
            cout << "\nDecidi di prendere l'oggetto misterioso. Potrà rivelarsi utile in seguito." << endl;
        }
        else {
            cout << "\nDecidi di non prendere l'oggetto. Forse è meglio non interferire con l'ignoto." << endl;
        }
    }
    
    // Schematizzazione delle scelte effettuate in questo atto
    cout << "\n--- La storia finora: ---" << endl;
    cout << "1. Salvataggio di John: ";
    if (scelta2_salvaJohn == 0)
        cout << "Hai aiutato John." << endl;
    else
        cout << "Non hai aiutato John." << endl;
    cout << "2. Scelta del percorso nella catacomba: " << listaScelte2_1[scelta2_1] << endl;
    cout << "3. Esame dei simboli: ";
    if (sceltaSimboli == 0)
        cout << "Hai esaminato i simboli." << endl;
    else
        cout << "Non hai esaminato i simboli." << endl;
    cout << "4. Risoluzione dell'indovinello sulla bomba: ";
    if (atto2_bomba_disinnescata)
        cout << "Bomba disinnescata." << endl;
    else
        cout << "Bomba non disinnescata (sei morto)." << endl;
    cout << "5. Metodo di apertura della porta: ";
    if (scelta2_porta == 0)
        cout << "Forzata la porta." << endl;
    else if (scelta2_porta == 1)
        cout << "Cercato il meccanismo segreto." << endl;
    else if (scelta2_porta == 2)
        cout << "Usata la tecnologia di Sora." << endl;
    cout << "6. Scelta sull'oggetto misterioso: ";
    if (scelta2_oggetto == 0)
        cout << "Hai preso l'oggetto." << endl;
    else
        cout << "Non hai preso l'oggetto." << endl;
    
    cout << "\nFine dell'Atto 2." << endl;
}

int main() {
    srand(time(0));
    
    cout << "SOLO L'ATTO 1 E L'ATTO 2 SONO GIOCABILI IN QUESTO STATO. GLI ALTRI SONO IN WORK IN PROGRESS. NON SONO STATI NEANCHE PROGRAMMATI TUTTI I PERCORSI. IL GIOCO FUNZIONA IN MODALITA INVINCIBILE PER ORA." << endl;
    
    string protagonista;
    cout << "Come ti chiami? ";
    cin >> protagonista;
    
    selezionepersonaggio(protagonista);
    
    atto1(protagonista);
    atto2(protagonista);
    
    return 0;
}
