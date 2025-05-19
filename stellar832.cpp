#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// todo: stagioni dimaniche , atti 3-5 e intermedi , punti onore , encounter casuali , tradimenti e relazioni amorose

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

// scelte dell'atto 2.5
int scelta2_5_citta;

// scelte atto 3 (diramazione xenopolis)
int scelta3_visitaxenopolis;

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

void atto2_5(string protagonista) {
    cout << "\nAtto 2.5: NOMADI." << endl;
    cout << "Dopo aver superato numerose sfide, l'equipaggio decide che è giunto il momento di spostarsi in una posizione migliore sul pianeta Xenia, "
         << "nelle zone civilizzate e più sicure." << endl;
    cout << "La squadra si riunisce e, dopo una lunga discussione, ti chiede di scegliere la città in cui stabilirvi. "
         << "Questa scelta influenzerà non solo l'Atto 3, ma determinerà il destino dell'intera vostra avventura su Xenia." << endl;
    
    cout << "\nLe città disponibili su Xenia sono le seguenti:" << endl;
    
    // Presentazione dettagliata della prima città: Xenopolis
    cout << "\n0. Xenopolis" << endl;
    cout << "   Descrizione: Xenopolis è la metropoli ultramoderna di Xenia, famosa per le sue infrastrutture avanzate e la vivace vita culturale." << endl;
    cout << "   Pro:" << endl;
    cout << "        - Infrastrutture all'avanguardia: trasporti efficienti, servizi sanitari eccellenti e tecnologie innovative." << endl;
    cout << "        - Ampia offerta culturale: musei, teatri, eventi internazionali e una scena artistica dinamica." << endl;
    cout << "        - Numerose opportunità di lavoro e di networking, ideale per chi cerca crescita professionale." << endl;
    cout << "   Contro:" << endl;
    cout << "        - Elevato costo della vita: affitti e spese quotidiane molto alti." << endl;
    cout << "        - Problemi di traffico intenso e inquinamento, tipici delle grandi metropoli." << endl;
    
    // Presentazione dettagliata della seconda città: Novaxenia
    cout << "\n1. Novaxenia" << endl;
    cout << "   Descrizione: Novaxenia è una città in rapida espansione che fonde tradizione e innovazione. Offre un ambiente equilibrato e una comunità in crescita." << endl;
    cout << "   Pro:" << endl;
    cout << "        - Costi della vita moderati: un'ottima soluzione per chi cerca stabilità senza spese esorbitanti." << endl;
    cout << "        - Ambiente sicuro e ben organizzato, con infrastrutture in miglioramento e un forte senso di comunità." << endl;
    cout << "        - Buone opportunità per investimenti personali e professionali, con un mercato in continuo sviluppo." << endl;
    cout << "   Contro:" << endl;
    cout << "        - Infrastrutture ancora in fase di sviluppo: alcuni servizi potrebbero non essere al livello delle metropoli maggiori." << endl;
    cout << "        - Offerta culturale e ricreativa in evoluzione, meno ampia rispetto a Xenopolis." << endl;
    
    // Presentazione dettagliata della terza città: Civitas
    cout << "\n2. Civitas" << endl;
    cout << "   Descrizione: Civitas è una città storica, rinomata per la sua stabilità politica e il forte senso di appartenenza della comunità. Ideale per chi cerca tradizione e sicurezza." << endl;
    cout << "   Pro:" << endl;
    cout << "        - Stabilità politica e sociale: una città governata in maniera efficiente, con un basso tasso di criminalità." << endl;
    cout << "        - Grande attenzione all'ambiente e alla qualità della vita, con spazi verdi e infrastrutture a misura d'uomo." << endl;
    cout << "        - Ricca di tradizioni e cultura locale, ideale per chi ama la storia e il senso di comunità." << endl;
    cout << "   Contro:" << endl;
    cout << "        - Opportunità economiche e lavorative limitate rispetto alle città più grandi." << endl;
    cout << "        - Offerta tecnologica e innovativa meno sviluppata, che potrebbe rallentare certi progressi." << endl;
    
    // Dialoghi dei personaggi sulle città
    cout << "\nDopo aver ascoltato la presentazione, i membri dell'equipaggio esprimono le loro opinioni:" << endl;
    cout << "Sora: \"Xenopolis è un sogno per chi ama la modernità, ma il costo della vita potrebbe metterci in difficoltà in fretta.\"" << endl;
    cout << "John: \"Personalmente, Novaxenia mi sembra un compromesso ideale: non troppo costosa e in crescita, con buone opportunità per tutti.\"" << endl;
    cout << "James: \"Civitas ha quel fascino storico e garantisce una sicurezza solida, anche se le opportunità economiche sono limitate.\"" << endl;
    
    cout << "\nDopo aver esaminato attentamente le opzioni, scegli in quale città desideri risiedere:" << endl;

    string citta[] = {"Xenopolis", "Novaxenia", "Civitas"};
    
    for (int i = 0; i < 3; i++) {
        cout << i << ". " << citta[i] << endl;
    }
    cout << "Inserisci il numero corrispondente alla tua scelta: ";
    cin >> scelta2_5_citta;
    
    cout << "\nHai scelto: ";
    switch (scelta2_5_citta) {
        case 0:
            cout << "Xenopolis" << endl;
            break;
        case 1:
            cout << "Novaxenia" << endl;
            break;
        case 2:
            cout << "Civitas" << endl;
            break;
        default:
            cout << "Scelta non valida. Verrà impostata una città di default: Novaxenia." << endl;
            scelta2_5_citta = 1;
            break;
    }

    cout << "\nQuesta decisione influenzerà l'Atto 3 e determinerà il corso della tua avventura su Xenia." << endl;

    cout << "\n--- La storia Finora... ---" << endl;
    cout << "Scelta città: " << citta[scelta2_5_citta] << endl;
    cout << "\nFine dell'Atto 2.5." << endl;
}

// Variabili globali per le scelte dell'Atto 3
int scelta3_xenopolis, scelta3_xenopolis_extra;
int scelta3_novaxenia, scelta3_novaxenia_extra;
int scelta3_civitas, scelta3_civitas_extra;

void atto3_xenopolis(string protagonista) {
    cout << "\nAtto 3: Sightseeing di Xenopolis" << endl;
    cout << "Dopo il trasferimento a Xenopolis, tu e il tuo equipaggio vi trovate nel cuore di una metropoli ultramoderna, dove luci al neon, grattacieli scintillanti e tecnologie all'avanguardia creano un'atmosfera quasi surreale." << endl;
    cout << "Le strade pulsano di energia e, sotto la superficie scintillante, corporazioni dominanti e organizzazioni segrete tramano intrighi per il controllo di tecnologie rivoluzionarie." << endl;
    cout << "\nDurante la vostra prima giornata, ricevete una proposta da un potente imprenditore:" << endl;
    cout << "Imprenditore: \"Offro risorse e contatti preziosi, ma a caro prezzo: dovrete accettare di integrarmi nella vostra squadra.\"" << endl;
    cout << "Questo patto potrebbe aprirvi le porte del mondo high-tech, ma rischia di compromettere la vostra autonomia." << endl;
    cout << "\nNel frattempo, decidete di esplorare la città. Che attività scegli?" << endl;
    
    string listaXenopolis[3] = {"museo di storia naturale", "parco divertimenti", "centro storico"};
    for (int i = 0; i < 3; i++) {
        cout << i << ". " << listaXenopolis[i] << endl;
    }
    cout << "Inserisci il numero corrispondente alla tua scelta: ";
    cin >> scelta3_xenopolis;
    
    // Diramazioni principali per Xenopolis
    switch (scelta3_xenopolis) {
        case 0:
            cout << "\n" << protagonista << ": Andiamo al museo di storia naturale." << endl;
            cout << "Sora: Ottima scelta! Scopriremo antichi reperti e curiosità scientifiche." << endl;
            // Evento chiave: scoperta di un documento segreto
            cout << "Durante la visita, mentre esaminate una collezione dimenticata, Andrew trova un documento segreto che potrebbe cambiare il corso della vostra missione." << endl;
            cout << "Andrew: \"Guardate qui, questo documento parla di una tecnologia proibita!\"" << endl;
            cout << "\nOra hai una scelta: vuoi condividere subito la scoperta con l'imprenditore o tenertela per analizzarla ulteriormente con il team?" << endl;
            cout << "0. Condividere con l'imprenditore (potrebbe portare un'alleanza vantaggiosa)" << endl;
            cout << "1. Tenere la scoperta per il team e studiarla in segreto" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_xenopolis_extra;
            if (scelta3_xenopolis_extra == 0)
                cout << protagonista << ": Condividiamo il documento con l'imprenditore. Forse possiamo ottenere risorse extra!" << endl;
            else
                cout << protagonista << ": Meglio analizzarlo noi prima di fidarci di chiunque." << endl;
            break;
            
        case 1:
            cout << "\n" << protagonista << ": Andiamo al parco divertimenti." << endl;
            cout << "John: Che divertimento! Preparatevi per una giornata piena di adrenalina." << endl;
            // Evento chiave: blackout e tentativo di furto
            cout << "Mentre vi godete le attrazioni, si verifica un improvviso blackout. Nel caos, un gruppo di individui sospetti tenta di rubare tecnologie avanzate." << endl;
            cout << "Sora: \"Non possiamo lasciarli scappare!\"" << endl;
            cout << "\nOra hai una scelta: intervenire personalmente o chiamare la sicurezza della città?" << endl;
            cout << "0. Intervenire personalmente per fermare i malviventi" << endl;
            cout << "1. Chiamare subito la sicurezza e coordinare l'intervento" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_xenopolis_extra;
            if (scelta3_xenopolis_extra == 0)
                cout << protagonista << ": Agisco subito! Dobbiamo proteggere la tecnologia a ogni costo." << endl;
            else
                cout << protagonista << ": Chiamiamo la sicurezza. Meglio essere organizzati in situazioni caotiche." << endl;
            break;
            
        case 2:
            cout << "\n" << protagonista << ": Andiamo al centro storico." << endl;
            cout << "James: Mi piace l'idea. Immergiamoci nelle radici di Xenopolis." << endl;
            // Evento chiave: scoperta di un manifesto
            cout << "Nel centro storico, scoprite un vecchio manifesto che accenna a una cospirazione tra corporazioni. John commenta: \"Questa pista merita di essere seguita...\"" << endl;
            cout << "\nOra hai una scelta: indagare sul manifesto oppure ignorarlo per concentrarti sull'alleanza con l'imprenditore?" << endl;
            cout << "0. Indagare sul manifesto e cercare di svelare la cospirazione" << endl;
            cout << "1. Ignorare il manifesto per concentrarsi sull'offerta dell'imprenditore" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_xenopolis_extra;
            if (scelta3_xenopolis_extra == 0)
                cout << protagonista << ": Seguiamo questa pista, potrebbe svelarci segreti fondamentali." << endl;
            else
                cout << protagonista << ": Meglio concentrarci sull'alleanza, potrebbe garantirci risorse importanti." << endl;
            break;
            
        default:
            cout << "Scelta non valida. Per default, andiamo al centro storico." << endl;
            scelta3_xenopolis = 2;
            break;
    }
    
    // Schematizzazione delle scelte in Xenopolis
    cout << "\n--- Schematizzazione delle scelte in Xenopolis ---" << endl;
    cout << "Attività principale scelta: " << listaXenopolis[scelta3_xenopolis] << endl;
    cout << "Scelta secondaria: ";
    if (scelta3_xenopolis == 0) {
        if (scelta3_xenopolis_extra == 0)
            cout << "Condivisione del documento con l'imprenditore." << endl;
        else
            cout << "Analisi segreta del documento con il team." << endl;
    }
    else if (scelta3_xenopolis == 1) {
        if (scelta3_xenopolis_extra == 0)
            cout << "Intervento diretto per fermare il furto." << endl;
        else
            cout << "Chiamata alla sicurezza per coordinare l'intervento." << endl;
    }
    else if (scelta3_xenopolis == 2) {
        if (scelta3_xenopolis_extra == 0)
            cout << "Indagine sul manifesto cospiratorio." << endl;
        else
            cout << "Concentrazione sull'alleanza con l'imprenditore." << endl;
    }
    cout << "\nFine dell'Atto 3 a Xenopolis." << endl;
}

void atto3_novaxenia(string protagonista) {
    cout << "\nAtto 3: Il Nuovo Inizio a Novaxenia" << endl;
    cout << "Arrivati a Novaxenia, il gruppo scopre una città in rapida espansione, dove il vecchio convive con il nuovo in un equilibrio precario." << endl;
    cout << "Le strade di Novaxenia sono un crocevia di quartieri storici e aree industriali moderne, e l'atmosfera è carica di ambizioni e tensioni sociali." << endl;
    cout << "\nDurante la vostra esplorazione, un gruppo di giovani imprenditori vi propone una riforma civica radicale, mirata ad unire le fazioni in conflitto e a rivoluzionare il sistema cittadino." << endl;
    cout << "Tuttavia, alcuni abitanti tradizionalisti sono preoccupati che questo cambiamento possa cancellare l'identità culturale della città." << endl;
    cout << "\nPer conoscere meglio la città, decidete di scegliere una delle seguenti attività:" << endl;
    string listaNovaxenia[3] = {"mercato locale", "centro culturale", "parco urbano"};
    for (int i = 0; i < 3; i++) {
        cout << i << ". " << listaNovaxenia[i] << endl;
    }
    cout << "Inserisci il numero corrispondente alla tua scelta: ";
    cin >> scelta3_novaxenia;
    
    // Diramazioni principali per Novaxenia
    switch (scelta3_novaxenia) {
        case 0:
            cout << "\n" << protagonista << ": Andiamo al mercato locale." << endl;
            cout << "John: Perfetto, il mercato è il cuore pulsante della città!" << endl;
            // Evento chiave: incontro con un vecchio saggio
            cout << "Al mercato, incontrate un vecchio saggio che vi svela l'esistenza di una rivoluzione imminente, capace di trasformare l'intero sistema cittadino." << endl;
            cout << "Sora: \"Questa informazione potrebbe essere la chiave per la nostra prossima mossa!\"" << endl;
            cout << "\nOra scegli: vuoi informare immediatamente i leader locali per cercare di guidare la riforma oppure mantenere il segreto per usare l'informazione a vostro vantaggio?" << endl;
            cout << "0. Informare i leader locali" << endl;
            cout << "1. Tenere il segreto e pianificare in privato" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_novaxenia_extra;
            if (scelta3_novaxenia_extra == 0)
                cout << protagonista << ": Informiamo subito i leader per guidare il cambiamento!" << endl;
            else
                cout << protagonista << ": Meglio pianificare in privato e sfruttare questa informazione strategicamente." << endl;
            break;
            
        case 1:
            cout << "\n" << protagonista << ": Andiamo al centro culturale." << endl;
            cout << "Sora: Ottima scelta! Il centro culturale è dove arte e innovazione si fondono." << endl;
            // Evento chiave: performance teatrale tesa
            cout << "Durante una performance, notate una forte tensione tra artisti e autorità locali. Un artista vi lancia un messaggio criptico, suggerendo che il cambiamento potrebbe essere imminente." << endl;
            cout << "James: \"Forse è il momento di prendere una posizione...\"" << endl;
            cout << "\nScegli ora: vuoi unirti attivamente alla riforma culturale oppure restare neutrali per osservare gli sviluppi?" << endl;
            cout << "0. Unirsi alla riforma culturale" << endl;
            cout << "1. Restare neutrali" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_novaxenia_extra;
            if (scelta3_novaxenia_extra == 0)
                cout << protagonista << ": Io scelgo di prendere parte attiva, per dare forma al futuro di Novaxenia!" << endl;
            else
                cout << protagonista << ": Preferisco osservare e valutare la situazione prima di schierarmi." << endl;
            break;
            
        case 2:
            cout << "\n" << protagonista << ": Andiamo al parco urbano." << endl;
            cout << "James: Un ambiente rilassante per riflettere e ascoltare il popolo." << endl;
            // Evento chiave: raduno spontaneo di cittadini in protesta
            cout << "Nel parco, assistete a un raduno improvviso di cittadini che protestano contro ingiustizie locali. Andrew interviene: \"Dobbiamo capire le ragioni di questo malcontento!\"" << endl;
            cout << "\nOra scegli: vuoi parlare direttamente con i manifestanti per raccogliere informazioni oppure contattare le autorità per mediare il conflitto?" << endl;
            cout << "0. Parlare con i manifestanti" << endl;
            cout << "1. Contattare le autorità" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_novaxenia_extra;
            if (scelta3_novaxenia_extra == 0)
                cout << protagonista << ": Parliamo con i cittadini, le loro storie ci guideranno!" << endl;
            else
                cout << protagonista << ": Chiamiamo le autorità per cercare di mediare la situazione." << endl;
            break;
            
        default:
            cout << "Scelta non valida. Per default, andiamo al centro culturale." << endl;
            scelta3_novaxenia = 1;
            break;
    }
    
    // Schematizzazione delle scelte in Novaxenia
    cout << "\n--- Schematizzazione delle scelte in Novaxenia ---" << endl;
    cout << "Attività principale scelta: " << listaNovaxenia[scelta3_novaxenia] << endl;
    cout << "Scelta secondaria: ";
    if (scelta3_novaxenia == 0) {
        if (scelta3_novaxenia_extra == 0)
            cout << "Informare i leader locali." << endl;
        else
            cout << "Mantenere il segreto e pianificare in privato." << endl;
    }
    else if (scelta3_novaxenia == 1) {
        if (scelta3_novaxenia_extra == 0)
            cout << "Unirsi attivamente alla riforma culturale." << endl;
        else
            cout << "Restare neutrali." << endl;
    }
    else if (scelta3_novaxenia == 2) {
        if (scelta3_novaxenia_extra == 0)
            cout << "Parlare con i manifestanti." << endl;
        else
            cout << "Contattare le autorità." << endl;
    }
    cout << "\nFine dell'Atto 3 a Novaxenia." << endl;
}

void atto3_civitas(string protagonista) {
    cout << "\nAtto 3: Le Radici di Civitas" << endl;
    cout << "In Civitas, la città ricca di storia e tradizione, ogni angolo racconta leggende secolari. Le antiche mura, le piazze acciottolate e i templi nascosti custodiscono segreti che potrebbero cambiare il destino di Xenia." << endl;
    cout << "\nIl gruppo si immerge nell'atmosfera senza tempo di Civitas. Mentre esplorate la città, emergono documenti antichi e leggende che parlano di un potere nascosto." << endl;
    cout << "Sora: \"Ci sono storie che dicono che una reliquia possa sbloccare un segreto millenario.\" " << endl;
    cout << "John: \"Questa potrebbe essere la chiave per affrontare le minacce future.\" " << endl;
    cout << "James: \"Ma attenzione, la tradizione ha anche il suo peso e la sua rigidità.\" " << endl;
    cout << "\nPer approfondire la conoscenza della città, scegli una delle seguenti attività:" << endl;
    string listaCivitas[3] = {"antico teatro", "museo della città", "piazze e caffè tradizionali"};
    for (int i = 0; i < 3; i++) {
        cout << i << ". " << listaCivitas[i] << endl;
    }
    cout << "Inserisci il numero corrispondente alla tua scelta: ";
    cin >> scelta3_civitas;
    
    // Diramazioni principali per Civitas
    switch (scelta3_civitas) {
        case 0:
            cout << "\n" << protagonista << ": Andiamo all'antico teatro." << endl;
            cout << "Sora: Sarà affascinante rivivere le opere del passato." << endl;
            // Evento chiave: messaggio criptico durante la rappresentazione
            cout << "Durante uno spettacolo, un attore misterioso recita versi enigmatici che alludono a una fazione segreta e a un imminente cambiamento politico." << endl;
            cout << "\nAdesso scegli: vuoi seguire l'attore per scoprire di più oppure tornare subito dal gruppo?" << endl;
            cout << "0. Seguire l'attore in segreto" << endl;
            cout << "1. Tornare dal gruppo per discutere l'accaduto" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_civitas_extra;
            if (scelta3_civitas_extra == 0)
                cout << protagonista << ": Lo seguirò discretamente per capire il significato del messaggio." << endl;
            else
                cout << protagonista << ": Meglio unirci al gruppo e discutere questo mistero insieme." << endl;
            break;
            
        case 1:
            cout << "\n" << protagonista << ": Andiamo al museo della città." << endl;
            cout << "John: Ottima idea! Le reliquie e i documenti antichi sono la chiave per svelare i misteri di Civitas." << endl;
            // Evento chiave: scoperta di una reliquia misteriosa
            cout << "Nel museo, trovate una reliquia che, secondo la leggenda, custodisce il segreto per il futuro di Xenia. Sora esclama: \"Questa reliquia potrebbe essere la nostra salvezza!\"" << endl;
            cout << "\nOra decidi: vuoi portare la reliquia immediatamente al consiglio cittadino oppure conservarla per studiarla in segreto?" << endl;
            cout << "0. Portare la reliquia al consiglio cittadino" << endl;
            cout << "1. Conservare la reliquia per ulteriori analisi in privato" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_civitas_extra;
            if (scelta3_civitas_extra == 0)
                cout << protagonista << ": Dobbiamo informare le autorità e usare questo potere per il bene comune." << endl;
            else
                cout << protagonista << ": Meglio studiarla prima di svelare il suo potere al mondo." << endl;
            break;
            
        case 2:
            cout << "\n" << protagonista << ": Andiamo a esplorare le piazze e sediamoci in un caffè tradizionale." << endl;
            cout << "James: Adoro l'atmosfera di queste piazze; ascoltare le storie degli abitanti è impagabile." << endl;
            // Evento chiave: racconto della vecchia signora
            cout << "In una piazza, una vecchia signora racconta leggende di intrighi antichi e avverte di una minaccia imminente, lanciando un monito al gruppo." << endl;
            cout << "\nOra scegli: vuoi prendere sul serio il suo avvertimento e allertare il gruppo, oppure considerarlo solo una storia antica?" << endl;
            cout << "0. Allertare immediatamente il gruppo" << endl;
            cout << "1. Considerarlo solo una leggenda e continuare a esplorare" << endl;
            cout << "Inserisci la tua scelta: ";
            cin >> scelta3_civitas_extra;
            if (scelta3_civitas_extra == 0)
                cout << protagonista << ": Dobbiamo prendere sul serio questo avvertimento e preparaci a ogni evenienza." << endl;
            else
                cout << protagonista << ": Sono solo storie... per ora, continuiamo la nostra esplorazione." << endl;
            break;
            
        default:
            cout << "Scelta non valida. Per default, andiamo al museo della città." << endl;
            scelta3_civitas = 1;
            break;
    }
    
    // Schematizzazione delle scelte in Civitas
    cout << "\n--- Schematizzazione delle scelte in Civitas ---" << endl;
    cout << "Attività principale scelta: " << listaCivitas[scelta3_civitas] << endl;
    cout << "Scelta secondaria: ";
    if (scelta3_civitas == 0) {
        if (scelta3_civitas_extra == 0)
            cout << "Seguire l'attore in segreto." << endl;
        else
            cout << "Tornare dal gruppo per discutere l'accaduto." << endl;
    }
    else if (scelta3_civitas == 1) {
        if (scelta3_civitas_extra == 0)
            cout << "Portare la reliquia al consiglio cittadino." << endl;
        else
            cout << "Conservare la reliquia per ulteriori analisi." << endl;
    }
    else if (scelta3_civitas == 2) {
        if (scelta3_civitas_extra == 0)
            cout << "Allertare immediatamente il gruppo." << endl;
        else
            cout << "Continuare a esplorare senza dare peso all'avvertimento." << endl;
    }
    cout << "\nFine dell'Atto 3 a Civitas." << endl;
}

int scelta4_xenopolis,
    scelta4_xenopolis_extra,
    scelta4_xenopolis_ageggio,
    scelta4_xenopolis_piani;
int scelta4_novaxenia,
    scelta4_novaxenia_extra,
    scelta4_novaxenia_rimedio;
int scelta4_civitas,
    scelta4_civitas_extra,
    scelta4_civitas_alleanza;

void atto4_xenopolis(string protagonista) {
    cout << "\nAtto 4: Minaccia a Xenopolis" << endl;
    cout << "Dopo aver esplorato Xenopolis, il gruppo scopre che la città è minacciata da una corporazione segreta." << endl;
    cout << "Sora: \"Dobbiamo fermarli prima che sia troppo tardi!\"" << endl;
    cout << "John: \"Abbiamo bisogno di alleati e informazioni per affrontare questa minaccia.\"" << endl;
    cout << "James: \"La nostra avventura non è finita, anzi, sta per diventare ancora più intensa!\"" << endl;
    cout << "\nScegli come intervenire:" << endl;
    string opzioni1[2] = { "Unirsi ai ribelli", "Infiltrarsi nella corporazione" };
    for(int i=0; i<2; i++) cout << i << ". " << opzioni1[i] << endl;
    cout << "Scelta: "; cin >> scelta4_xenopolis;

    if (scelta4_xenopolis == 0) {
        cout << "\nHai deciso di unirti ai ribelli." << endl;
        cout << "Ti presentano la loro leader, Kaela, che ti chiede di sabotare un convoglio di armi." << endl;
        cout << "Vuoi:" << endl;
        string opzioni1b[2] = { "Tuffarti nell'azione subito", "Pianificare un'imboscata" };
        for(int i=0; i<2; i++) cout << i << ". " << opzioni1b[i] << endl;
        cout << "Scelta: "; cin >> scelta4_xenopolis_extra;
        if (scelta4_xenopolis_extra == 0) {
            cout << "\nAssalti il convoglio con forza bruta: ottieni rispetto ma perdi risorse." << endl;
        }
        else {
            cout << "\nOrganizzi un'imboscata perfetta: risparmi risorse, guadagni nuovi alleati nel sottobosco." << endl;
        }
    }
    else {
        cout << "\nHai scelto di infiltrarti nella corporazione." << endl;
        if (scelta2_salvajohn == 0) {
            cout << "Grazie al tuo legame con John, hai accesso a informazioni riservate." << endl;
            scelta4_xenopolis_ageggio = 1;
        }
        else {
            cout << "Entri sotto copertura, ma parti senza supporto esterno." << endl;
        }
        cout << "\nOra decidi il tuo piano interno:" << endl;
        string opzioni2[2] = { "Sabotare le operazioni", "Raccogliere informazioni" };
        for(int i=0; i<2; i++) cout << i << ". " << opzioni2[i] << endl;
        cout << "Scelta: "; cin >> scelta4_xenopolis_piani;

        if (scelta4_xenopolis_piani == 0) {
            cout << "\nMetti fuori uso i macchinari: rallenti la produzione ma ti espongono." << endl;
            if (scelta4_xenopolis_ageggio == 1)
                cout << "Il tuo vantaggio informativo riduce il sospetto su di te." << endl;
        }
        else {
            cout << "\nRaccogli dossier segreti: scopri il piano di conquista completo." << endl;
            cout << "Vuoi inviare subito le info ai ribelli o conservarle per un colpo finale?" << endl;
            string opzioni2b[2] = { "Inviare subito", "Conservarle" };
            for(int i=0; i<2; i++) cout << i << ". " << opzioni2b[i] << endl;
            cout << "Scelta: "; cin >> scelta4_xenopolis_extra;
            if (scelta4_xenopolis_extra == 0)
                cout << "I ribelli si preparano all'assalto: hai guadagnato il loro rispetto." << endl;
            else
                cout << "Conservi le informazioni per usarle in un momento critico: aumenta il fattore sorpresa." << endl;
        }
    }

    cout << "Fine dell'Atto 4 a Xenopolis." << endl;
}

void atto4_novaxenia(string protagonista) {
    cout << "\nAtto 4: Terrore a Nova Xenia" << endl;
    cout << "La città di Nova Xenia è avvolta da un'ombra tossica, i cittadini cadono malati." << endl;
    cout << "Sora: \"Dobbiamo trovare la fonte di questa contaminazione!\"" << endl;
    cout << "James: \"Ho sentito voci su un laboratorio clandestino.\"" << endl;
    cout << "\nScegli come agire:" << endl;
    string opzioni1[2] = { "Soccorri i malati", "Indaga sul laboratorio" };
    for(int i=0; i<2; i++) cout << i << ". " << opzioni1[i] << endl;
    cout << "Scelta: "; cin >> scelta4_novaxenia;

    if (scelta4_novaxenia == 0) {
        cout << "\nTi dedichi ai soccorsi: raccogli erbe curative e tassi l'inquinamento." << endl;
        cout << "Vuoi:" << endl;
        string opzioni1b[2] = { "Costruire un campo medico", "Distribuire cure porta a porta" };
        for(int i=0; i<2; i++) cout << i << ". " << opzioni1b[i] << endl;
        cout << "Scelta: "; cin >> scelta4_novaxenia_extra;
        if (scelta4_novaxenia_extra == 0)
            cout << "Il campo medico salva centinaia di vite, ma attira l'attenzione dei nemici." << endl;
        else
            cout << "Porti cura direttamente alle famiglie, guadagni fiducia ma procedi più lentamente." << endl;
    }
    else {
        cout << "\nIndaghi sul laboratorio clandestino." << endl;
        cout << "Andrew: \"I documenti parlano di un'arma biologica sperimentale.\""<< endl;
        cout << "\nOra decidi:" << endl;
        string opzioni2[2] = { "Distruggere il laboratorio", "Rubare il prototipo" };
        for(int i=0; i<2; i++) cout << i << ". " << opzioni2[i] << endl;
        cout << "Scelta: "; cin >> scelta4_novaxenia_rimedio;
        if (scelta4_novaxenia_rimedio == 0) {
            cout << "\nFai esplodere il complesso: impedisci la diffusione ma perdi dati preziosi." << endl;
        }
        else {
            cout << "\nRubate il prototipo: potete studiarlo e creare un antidoto." << endl;
            scelta4_novaxenia_extra = 1;
        }
    }

    cout << "Fine dell'Atto 4 a Nova Xenia." << endl;
}

void atto4_civitas(string protagonista) {
    cout << "\nAtto 4: Semper Civitas" << endl;
    cout << "Nella città-stato di Civitas infuria una crisi politica tra senato e popolari." << endl;
    cout << "John: \"Dobbiamo decidere se appoggiare il Senato o i Ribelli di Popolo.\""<< endl;
    cout << "\nScegli da che parte stare:" << endl;
    string opzioni1[2] = { "Supportare il Senato", "Supportare i Ribelli" };
    for(int i=0; i<2; i++) cout << i << ". " << opzioni1[i] << endl;
    cout << "Scelta: "; cin >> scelta4_civitas;

    if (scelta4_civitas == 0) {
        cout << "\nTi allei con il Senato: ottieni risorse ufficiali." << endl;
        cout << "Vuoi:" << endl;
        string opzioni1b[2] = { "Conferire con il Console", "Rafforzare le guarnigioni" };
        for(int i=0; i<2; i++) cout << i << ". " << opzioni1b[i] << endl;
        cout << "Scelta: "; cin >> scelta4_civitas_extra;
        if (scelta4_civitas_extra == 0)
            cout << "Ottieni il favore del Console, ma il popolo diffida del tuo intervento." << endl;
        else
            cout << "Le guarnigioni tengono la città sicura, ma i ribelli si rafforzano nell'ombra." << endl;
    }
    else {
        cout << "\nAccetti di appoggiare i Ribelli di Popolo." << endl;
        cout << "Sora: \"Dobbiamo guadagnare il cuore dei cittadini.\""<< endl;
        cout << "\nOra scegli:" << endl;
        string opzioni2[2] = { "Organizzare un comizio pubblico", "Sabotare le scorte del Senato" };
        for(int i=0; i<2; i++) cout << i << ". " << opzioni2[i] << endl;
        cout << "Scelta: "; cin >> scelta4_civitas_alleanza;
        if (scelta4_civitas_alleanza == 0)
            cout << "\nIl comizio infiamma le folle: ottieni un esercito di cittadini." << endl;
        else
            cout << "\nAffondi le scorte: il Senato vacilla, ma attiri troppa attenzione militare." << endl;
    }

    cout << "Fine dell'Atto 4 a Civitas." << endl;
}

// variabili di stato atto 5
int scelta5_xenopolis_primo;
int scelta5_xenopolis_secondo;
int scelta5_xenopolis_terzo;
int scelta5_xenopolis_finale;

int scelta5_novaxenia_primo;
int scelta5_novaxenia_secondo;
int scelta5_novaxenia_terzo;
int scelta5_novaxenia_finale;

int scelta5_civitas_primo;
int scelta5_civitas_secondo;
int scelta5_civitas_terzo;
int scelta5_civitas_finale;

void atto5_xenopolis(string protagonista) {
    cout << "\nAtto 5: L'Assedio di Xenopolis" << endl;
    cout << "Le macchine della corporazione avanzano sui bastioni. Il tuo gruppo è pronto." << endl;

    // fase 1: formazione della difesa
    cout << "\n1) Come organizzi la difesa delle mura?" << endl;
    string op1[3] = {
        "Rafforzare i baluardi con cariche EMP",
        "Schierare truppe di ribelli alle torri",
        "Infiltrare droni di sorveglianza nei droni di supporto nemici"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op1[i] << endl;
    cout << "Scelta: "; cin >> scelta5_xenopolis_primo;

    if (scelta5_xenopolis_primo == 0) {
        cout << "\nLe cariche EMP disabilitano mezza guarnigione nemica." << endl;
        if (scelta4_xenopolis_piani == 0)
            cout << "Il sabotaggio interno amplifica l'effetto: caos totale." << endl;
    }
    else if (scelta5_xenopolis_primo == 1) {
        cout << "\nI ribelli salgono in massa sulle torri, ma subiscono perdite." << endl;
        if (scelta4_xenopolis_extra == 1)
            cout << "Grazie all'imboscata, i rinforzi ribelli arrivano in tempo." << endl;
    }
    else {
        cout << "\nI droni confondono il nemico, guadagni preziosi secondi." << endl;
    }

    // fase 2: controffensiva
    cout << "\n2) Vuoi pilotare personalmente un veicolo d'assalto?" << endl;
    string op2[2] = { "Sì, guida il carro EMP", "No, resta a coordinare" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op2[i] << endl;
    cout << "Scelta: "; cin >> scelta5_xenopolis_secondo;

    if (scelta5_xenopolis_secondo == 0) {
        cout << "\nSalti sul carro: la tua manovra frontale demoralizza il nemico." << endl;
    } else {
        cout << "\nDa lontano dai ordini: la difesa è più compatta, ma perdi visione diretta." << endl;
    }

    // fase 3: gesto finale
    cout << "\n3) I leader corporativi ti sfidano a un duello: accetti?" << endl;
    string op3[2] = { "Accetto", "Rifiuto e attacco in gruppo" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op3[i] << endl;
    cout << "Scelta: "; cin >> scelta5_xenopolis_terzo;

    if (scelta5_xenopolis_terzo == 0) {
        cout << "\nDuelli uno a uno: dimostri la tua forza, instauri rispetto." << endl;
        if (scelta4_xenopolis_ageggio == 1)
            cout << "John ti copre le spalle consentendoti di vincere." << endl;
    }
    else {
        cout << "\nAttacco concentrato: travolgete i nemici, ma rischiate ingenti perdite." << endl;
    }

    // fase finale: scelta del destino della corporazione
    cout << "\n4) Cosa fai una volta caduto il comando avversario?" << endl;
    string op4[2] = { "Distruggere le strutture rimaste", "Riadattarle al servizio dei ribelli" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op4[i] << endl;
    cout << "Scelta: "; cin >> scelta5_xenopolis_finale;

    if (scelta5_xenopolis_finale == 0) {
        cout << "\nRase al suolo le officine: la minaccia è estinta ma perdi tecnologie." << endl;
    }
    else {
        cout << "\nConverti le officine: i ribelli ottengono nuove armi e supporto tecnico." << endl;
    }

    cout << "\nFine Atto 5 a Xenopolis." << endl;
}

void atto5_novaxenia(string protagonista) {
    cout << "\nAtto 5: La Cura di Nova Xenia" << endl;
    cout << "L'arma biologica è pronta a scatenarsi. È l'ultima occasione per fermarla." << endl;

    // fase 1: recupero del campione
    cout << "\n1) Come entri nel cuore del laboratorio?" << endl;
    string op1[3] = {
        "Travestimento da scienziato",
        "Appostamento notturno",
        "Forzatura dei sistemi di sicurezza"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op1[i] << endl;
    cout << "Scelta: "; cin >> scelta5_novaxenia_primo;

    if (scelta5_novaxenia_primo == 0) {
        cout << "\nAccesso con false credenziali, eviti controlli ma perdi tempo prezioso." << endl;
    }
    else if (scelta5_novaxenia_primo == 1) {
        cout << "\nSorpresi i guardiani dormienti, ma un allarme silenzioso si attiva." << endl;
    }
    else {
        cout << "\nDisabiliti gran parte dei laser di sicurezza: avanzata rapida." << endl;
        if (scelta4_novaxenia_rimedio == 1)
            cout << "Con il prototipo già in mano, recuperi i dati senza intoppi." << endl;
    }

    // fase 2: sviluppo dell'antidoto
    cout << "\n2) Dove concentri le risorse per l'antidoto?" << endl;
    string op2[2] = { "Laboratorio mobile in città", "Installazione fissa nei sotterranei" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op2[i] << endl;
    cout << "Scelta: "; cin >> scelta5_novaxenia_secondo;

    if (scelta5_novaxenia_secondo == 0) {
        cout << "\nIl laboratorio mobile segue i malati, ma è vulnerabile agli attacchi." << endl;
    } else {
        cout << "\nLa base fissa è sicura, ma richiede tempo per installarsi." << endl;
    }

    // fase 3: somministrazione
    cout << "\n3) Chi dovresti curare per primo?" << endl;
    string op3[3] = { "I leader della città", "I più giovani", "Gli anziani" };
    for (int i = 0; i < 3; i++) cout << i << ". " << op3[i] << endl;
    cout << "Scelta: "; cin >> scelta5_novaxenia_terzo;

    if (scelta5_novaxenia_terzo == 0) {
        cout << "\nSalvi i governanti, ottieni aiuti politici ma desti invidia." << endl;
    }
    else if (scelta5_novaxenia_terzo == 1) {
        cout << "\nI giovani si riprendono in fretta: aumenta la speranza nella popolazione." << endl;
    }
    else {
        cout << "\nGli anziani riconoscenti tramandano il tuo nome alle nuove generazioni." << endl;
        if (scelta4_novaxenia_extra == 1)
            cout << "Il prototipo rubato accelera la cura: tempi record." << endl;
    }

    // fase finale: il sacrificio
    cout << "\n4) Sei disposto a usare te stesso come cavie?" << endl;
    string op4[2] = { "Sì, somministrami il vaccino", "No, trova una squadra volontaria" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op4[i] << endl;
    cout << "Scelta: "; cin >> scelta5_novaxenia_finale;

    if (scelta5_novaxenia_finale == 0) {
        cout << "\nTi inietti il vaccino: rischi la vita ma dimostri coraggio supremo." << endl;
    }
    else {
        cout << "\nFormi una squadra: qualcuno perderà la vita al tuo posto." << endl;
    }

    cout << "\nFine Atto 5 a Nova Xenia." << endl;
}

void atto5_civitas(string protagonista) {
    cout << "\nAtto 5: Il Concilio di Civitas" << endl;
    cout << "Il Senato convoca un'assemblea straordinaria per decidere il destino della città." << endl;

    // fase 1: discorso pubblico
    cout << "\n1) Il tuo discorso si concentra su:" << endl;
    string op1[3] = {
        "Ordine e stabilità",
        "Libertà e diritti",
        "Unione di tutte le fazioni"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op1[i] << endl;
    cout << "Scelta: "; cin >> scelta5_civitas_primo;

    if (scelta5_civitas_primo == 0) {
        cout << "\nOttieni il favore del Senato, ma i cittadini gridano tradimento." << endl;
        if (scelta4_civitas == 0 && scelta4_civitas_extra == 1)
            cout << "Le guarnigioni rafforzate mantengono l'ordine." << endl;
    }
    else if (scelta5_civitas_primo == 1) {
        cout << "\nIl popolo acclama la tua causa, ma il Console ti considera una minaccia." << endl;
    }
    else {
        cout << "\nRiesci a ottenere silenzio e speranza: Senato e Ribelli ascoltano." << endl;
    }

    // fase 2: trattativa segreta
    cout << "\n2) Incontri il Console in privato: come lo convinci?" << endl;
    string op2[2] = { "Minacciare con prove scottanti", "Promettere una spartizione del potere" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op2[i] << endl;
    cout << "Scelta: "; cin >> scelta5_civitas_secondo;

    if (scelta5_civitas_secondo == 0) {
        cout << "\nIl Console cede per paura, ma giura vendetta." << endl;
    } else {
        cout << "\nIl Console accetta, ma i Ribelli si sentono traditi." << endl;
    }

    // fase 3: decisione sul futuro
    cout << "\n3) Voti per:" << endl;
    string op3[2] = { "Monarchia riformata", "Repubblica parlamentare" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op3[i] << endl;
    cout << "Scelta: "; cin >> scelta5_civitas_terzo;

    if (scelta5_civitas_terzo == 0) {
        cout << "\nLa monarchia riformata promette stabilità, ma limita le libertà." << endl;
    }
    else {
        cout << "\nLa repubblica parlamentare esalta il voto popolare, ma rischia l'instabilità." << endl;
        if (scelta4_civitas_alleanza == 0)
            cout << "I cittadini che hai convinto al comizio formano il primo parlamento." << endl;
    }

    // fase finale: il Giuramento
    cout << "\n4) Giuri fedeltà al nuovo ordine?" << endl;
    string op4[2] = { "Sì, davanti al Concilio", "No, ti ritiri nelle brughiere" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op4[i] << endl;
    cout << "Scelta: "; cin >> scelta5_civitas_finale;

    if (scelta5_civitas_finale == 0) {
        cout << "\nPronunci il giuramento: diventi simbolo di rinascita per Civitas." << endl;
    }
    else {
        cout << "\nTi allontani dalla politica: lasci il potere ma mantieni la tua coscienza pura." << endl;
    }

    cout << "\nFine Atto 5 a Civitas." << endl;
}

// variabili di stato atto6
int scelta6_xenopolis_fase1;
int scelta6_xenopolis_fase2;
int scelta6_xenopolis_fase3;
int scelta6_xenopolis_epilogo;

int scelta6_novaxenia_fase1;
int scelta6_novaxenia_fase2;
int scelta6_novaxenia_fase3;
int scelta6_novaxenia_epilogo;

int scelta6_civitas_fase1;
int scelta6_civitas_fase2;
int scelta6_civitas_fase3;
int scelta6_civitas_epilogo;

void atto6_xenopolis(string protagonista) {
    cout << "\nAtto6: Rinascita di Xenopolis" << endl;
    cout << "La città in rovina cerca di rialzarsi. Tu e il tuo gruppo avete la possibilità di guidare il futuro." << endl;

    // fase1: rifondazione politica
    cout << "\n1) Quale forma di governo proporrai?" << endl;
    string op1[3] = {
        "Consiglio misto ribelli cittadini",
        "Dominio magistrale degli ingegneri",
        "Democrazia diretta tramite votazioni pubbliche"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op1[i] << endl;
    cout << "Scelta: "; cin >> scelta6_xenopolis_fase1;

    if (scelta6_xenopolis_fase1 == 0) {
        cout << "\nI ribelli siedono insieme ai cittadini nell'Assemblea. Xenopolis ritrova coesione." << endl;
        if (scelta4_xenopolis == 0)
            cout << "La tua alleanza con i ribelli (Atto 4) rafforza il Consiglio." << endl;
    }
    else if (scelta6_xenopolis_fase1 == 1) {
        cout << "\nGli ingegneri ottengono plenario potere tecnico. Efficienza ma freddezza politica." << endl;
        if (scelta5_xenopolis_primo == 0)
            cout << "Le cariche EMP (Atto 5) convincono gli ingegneri dell'importanza della sicurezza." << endl;
    }
    else {
        cout << "\nLa democrazia diretta entusiasma la popolazione, ma rallenta le decisioni." << endl;
    }

    // fase2: ricostruzione delle infrastrutture
    cout << "\n2) Dove concentri le risorse per ricostruire?" << endl;
    string op2[2] = {
        "Rimettere in funzione le officine convertite",
        "Costruire un nuovo quartiere high tech"
    };
    for (int i = 0; i < 2; i++) cout << i << ". " << op2[i] << endl;
    cout << "Scelta: "; cin >> scelta6_xenopolis_fase2;

    if (scelta6_xenopolis_fase2 == 0) {
        cout << "\nLe officine ereditate dai ribelli producono strumenti utili." << endl;
        if (scelta6_xenopolis_finale == 1)
            cout << "Grazie alla conversione organizzata in Atto 5, la produzione è rapida." << endl;
    } else {
        cout << "\nIl quartiere high tech attira talenti ma costa risorse preziose." << endl;
    }

    // fase3: sicurezza interna
    cout << "\n3) Come garantisci la pace dentro le mura?" << endl;
    string op3[3] = {
        "Guardie civiche addestrate dai ribelli",
        "Rete di sorveglianza droni-city",
        "Milizia volontaria dei cittadini"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op3[i] << endl;
    cout << "Scelta: "; cin >> scelta6_xenopolis_fase3;

    if (scelta6_xenopolis_fase3 == 0) {
        cout << "\nLe guardie civiche pattugliano con disciplina." << endl;
        if (scelta4_xenopolis_extra == 1)
            cout << "L'imboscata pianificata in Atto 4 insegna tecniche di guerriglia urbana." << endl;
    }
    else if (scelta6_xenopolis_fase3 == 1) {
        cout << "\nI droni monitorano ogni angolo: privacy ridotta, ma ordine stabile." << endl;
    }
    else {
        cout << "\nLa milizia volontaria rende la popolazione protagonista della difesa." << endl;
    }

    // epilogo: il simbolo di rinascita
    cout << "\n4) Quale monumento innalzerai a ricordo della lotta?" << endl;
    string op4[2] = {
        "Statua dell'eroe che ha guidato i ribelli",
        "Fontana delle tecnologie riconvertite"
    };
    for (int i = 0; i < 2; i++) cout << i << ". " << op4[i] << endl;
    cout << "Scelta: "; cin >> scelta6_xenopolis_epilogo;

    if (scelta6_xenopolis_epilogo == 0) {
        cout << "\nLa statua rafforza l'orgoglio popolare e ricorda il coraggio." << endl;
    }
    else {
        cout << "\nLa fontana unisce arte e scienza, simbolo di rinascita tecnologica." << endl;
    }

    cout << "\nFine Atto6 a Xenopolis." << endl;
}

void atto6_novaxenia(string protagonista) {
    cout << "\nAtto 6: Rinnovamento di Nova Xenia" << endl;
    cout << "La cura ha funzionato, ma il pianeta rimane ferito. Ora tocca a te ricostruirlo." << endl;

    // fase1: gestione delle risorse ambientali
    cout << "\n1) Come ripristini l'ecosistema?" << endl;
    string op1[3] = {
        "Pianta di nuovo le foreste aliene",
        "Riprogramma l'atmosfera con generatori bio",
        "Crea riserve protette per le specie sopravvissute"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op1[i] << endl;
    cout << "Scelta: "; cin >> scelta6_novaxenia_fase1;

    if (scelta6_novaxenia_fase1 == 0) {
        cout << "\nI germogli crescono in fretta grazie al prototipo sottratto." << endl;
        if (scelta4_novaxenia_rimedio == 1)
            cout << "Il prototipo rubato in Atto 4 accelera la fotosintesi aliena." << endl;
    }
    else if (scelta6_novaxenia_fase1 == 1) {
        cout << "\nL'atmosfera torna respirabile, ma i macchinari richiedono manutenzione." << endl;
    }
    else {
        cout << "\nLe riserve diventano rifugi sicuri per le nuove generazioni." << endl;
    }

    // fase2: ricostruzione sociale
    cout << "\n2) Quale sistema sanitario istituisci?" << endl;
    string op2[2] = {
        "Cliniche mobili in ogni insediamento",
        "Ospedale centrale con reparti di ricerca"
    };
    for (int i = 0; i < 2; i++) cout << i << ". " << op2[i] << endl;
    cout << "Scelta: "; cin >> scelta6_novaxenia_fase2;

    if (scelta6_novaxenia_fase2 == 0) {
        cout << "\nLe cliniche mobili raggiungono tutti, ma con risorse limitate." << endl;
    } else {
        cout << "\nL'ospedale diventa faro di speranza, ma il costo è elevato." << endl;
        if (scelta5_novaxenia_secondo == 1)
            cout << "La base fissa di Atto 5 ha gettato le fondamenta per questo ospedale." << endl;
    }

    // fase3: leadership culturale
    cout << "\n3) Quale valore esalti nel discorso inaugurale?" << endl;
    string op3[3] = {
        "Solidarietà tra sopravvissuti",
        "Scienza e innovazione",
        "Rispetto per il pianeta"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op3[i] << endl;
    cout << "Scelta: "; cin >> scelta6_novaxenia_fase3;

    if (scelta6_novaxenia_fase3 == 0) {
        cout << "\nLa comunità si stringe insieme, il senso di appartenenza cresce." << endl;
    }
    else if (scelta6_novaxenia_fase3 == 1) {
        cout << "\nI giovani scienziati si ispirano al tuo discorso." << endl;
        if (scelta5_novaxenia_primo == 2)
            cout << "Il colpo di sicurezza di Atto 5 garantisce protezione ai laboratori." << endl;
    }
    else {
        cout << "\nLa protezione ambientale diventa legge fondamentale." << endl;
    }

    // epilogo: il patto con il futuro
    cout << "\n4) Quale promessa fai al pianeta?" << endl;
    string op4[2] = {
        "Mai più armi biologiche",
        "Condivisione aperta della cura con le altre colonie"
    };
    for (int i = 0; i < 2; i++) cout << i << ". " << op4[i] << endl;
    cout << "Scelta: "; cin >> scelta6_novaxenia_epilogo;

    if (scelta6_novaxenia_epilogo == 0) {
        cout << "\nIl patto antibio diventa trattato interplanetario." << endl;
    }
    else {
        cout << "\nLe conoscenze mediche di Nova Xenia salvano altre civiltà." << endl;
    }

    cout << "\nFine Atto 6 a Nova Xenia." << endl;
}

void atto6_civitas(string protagonista) {
    cout << "\nAtto 6: La Legge di Civitas" << endl;
    cout << "Il nuovo ordine politico deve ora tradursi in norme e istituzioni durevoli." << endl;

    // fase1: codifica delle leggi
    cout << "\n1) Qual è il primo articolo della Costituzione?" << endl;
    string op1[3] = {
        "Diritti di tutti i cittadini",
        "Potere temperato tra fazioni",
        "Obbligo di servizio pubblico"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op1[i] << endl;
    cout << "Scelta: "; cin >> scelta6_civitas_fase1;

    if (scelta6_civitas_fase1 == 0) {
        cout << "\nLa popolazione festeggia l'articolo egalitario." << endl;
        if (scelta4_civitas_alleanza == 0)
            cout << "Il comizio di Atto 4 aveva già instillato fiducia nel popolo." << endl;
    }
    else if (scelta6_civitas_fase1 == 1) {
        cout << "\nIl bilanciamento di poteri evita derive autoritarie." << endl;
    }
    else {
        cout << "\nIl servizio pubblico unisce cittadini e governi." << endl;
    }

    // fase2: implementazione giudiziaria
    cout << "\n2) Come crei il sistema giudiziario?" << endl;
    string op2[2] = {
        "Tribunali popolari itineranti",
        "Corte suprema stabile in Senato"
    };
    for (int i = 0; i < 2; i++) cout << i << ". " << op2[i] << endl;
    cout << "Scelta: "; cin >> scelta6_civitas_fase2;

    if (scelta6_civitas_fase2 == 0) {
        cout << "\nLa giustizia arriva ovunque, ma con ritardi organizzativi." << endl;
    } else {
        cout << "\nLa Corte suprema assicura uniformità, ma sembra distante al popolo." << endl;
        if (scelta5_civitas_secondo == 1)
            cout << "Il patto segreto con il Console di Atto 5 influisce sui giudici." << endl;
    }

    // fase3: difesa della legge
    cout << "\n3) Chi sorveglia il rispetto delle norme?" << endl;
    string op3[3] = {
        "Guardia cittadina eletta",
        "Forze armate di Civitas",
        "Magistrati itineranti"
    };
    for (int i = 0; i < 3; i++) cout << i << ". " << op3[i] << endl;
    cout << "Scelta: "; cin >> scelta6_civitas_fase3;

    if (scelta6_civitas_fase3 == 0) {
        cout << "\nLa guardia elegge rappresentanti locali responsabili." << endl;
    }
    else if (scelta6_civitas_fase3 == 1) {
        cout << "\nLe forze armate impongono l'ordine, ma temute dal popolo." << endl;
    }
    else {
        cout << "\nI magistrati viaggiano per assicurare applicazione uniforme." << endl;
    }

    // epilogo: la firma del protagonista
    cout << "\n4) Firma il testo finale della Costituzione?" << endl;
    string op4[2] = { "Sì, come garante della legge", "No, come custode esterno" };
    for (int i = 0; i < 2; i++) cout << i << ". " << op4[i] << endl;
    cout << "Scelta: "; cin >> scelta6_civitas_epilogo;

    if (scelta6_civitas_epilogo == 0) {
        cout << "\nLa tua firma sancisce il nuovo patto sociale." << endl;
    }
    else {
        cout << "\nRimani al di fuori: vegli sul rispetto in futuro." << endl;
    }

    cout << "\nFine Atto 6 a Civitas." << endl;
}

int soluzioneEnigma;
int sceltaEnigma;
int scelta7;

void enigmaFinale() {
    cout << "\n--- Enigma Finale: Il Cuore del Cosmo ---" << endl;
    cout << "Davanti a te, un altare di luce pulsante: tre runici cerchi concentrici,\n";
    cout << "ognuno segnato da simboli di scienza, arte e fede. Un iscrizione recita:\n\n";
    cout << "«Solo chi coniuga calcolo, melodia e speranza potrà varcare la soglia eterna.»\n\n";
    cout << "1) 5-Do-Re-Mi-13: EQUILIBRIO UNIVERSALE\n";
    cout << "2) 7-Mi-Fa-Sol-17: ARMONIA CELESTE\n";
    cout << "3) 11-La-Si-23: FIDUCIA SENZA TEMPO\n";
    cout << "Risposta: "; cin >> sceltaEnigma;

    // definizione della risposta corretta e suggerimenti in base alla difficoltà
    soluzioneEnigma = 2;  // Armonia Celeste
    if (difficolta == 0) {
        cout << "\nSuggerimento (facile): un numero primo doppio e una scala portante di melodia ascendente.\n";
    }
    else if (difficolta == 1) {
        cout << "\nSuggerimento (normale): considera i numeri primi e la nota mediana della scala.\n";
    }
    else {
        // nessun suggerimento
        cout << "\nModalità Sopravvivenza: nessun aiuto, nessuna pietà.\n";
    }

    if (sceltaEnigma == soluzioneEnigma) {
        cout << "\nCon un rintocco di luce pura, i cerchi si spengono uno a uno.\nIl Sigillo del Cosmo è spezzato." << endl;
    } else {
        cout << "\nUn boato echeggia: i cerchi rimangono intatti." << endl;
        if (difficolta == 2) {
            cout << "Hai fallito l'enigma supremo: la tua leggenda finisce qui.\nGAME OVER.\n";
            exit(0);
        } else {
            cout << "Prova ancora: il tempo scorre ma il tuo spirito non vacilla.\n";
            enigmaFinale();
        }
    }
}

void atto7(string protagonista) {
    cout << "\nAtto 7: L'Alba delle Infinite Scelte" << endl;
    cout << "Le stelle di Xenia, Novaxenia e Civitas convergono nel tuo destino, " << protagonista << ".\n";
    cout << "Ogni tua scelta — dalla città in cui hai posato i piedi (Atto 2.5) ai tuoi atti di ribellione,\n";
    cout << "cura e legislazione (Atti 4 - 6) — ha forgiato un sentiero unico.\n\n";

    // Ricordo delle azioni passate
    if (scelta2_5_citta == 0) {
        cout << "Xenopolis, la metropoli di luci e acciaio, ha respirato grazie al tuo sabotaggio\n";
        if (scelta4_xenopolis == 0)
            cout << "- hai stretto patto coi ribelli, instillando nelle vie un nuovo coraggio.\n";
        else
            cout << "- hai intrufolato segreti nella corporazione e riacceso la fiamma della rivolta.\n";
        if (scelta5_xenopolis_secondo == 0)
            cout << "- a bordo del carro EMP hai sfidato il fulmine, infondendo speranza al popolo.\n";
        if (scelta6_xenopolis_fase1 == 2)
            cout << "- inaugurata la democrazia diretta, hai consegnato il potere nelle mani di tutti.\n";
    }
    else if (scelta2_5_citta == 1) {
        cout << "Novaxenia, oasi di rinascita, ha respirato grazie ai tuoi veleni e rimedi:\n";
        if (scelta4_novaxenia == 1)
            cout << "- hai sottratto il prototipo dal laboratorio, aprendo la via alla cura.\n";
        if (scelta5_novaxenia_terzo == 2)
            cout << "- curando gli anziani, hai seminato saggezza nelle nuove generazioni.\n";
        if (scelta6_novaxenia_fase1 == 0)
            cout << "- hai piantato le foreste aliene, radicando vita dove c'era morte.\n";
    }
    else {
        cout << "Civitas, antica roccaforte di legge e consuetudine, si è trasformata per la tua voce:\n";
        if (scelta4_civitas == 1)
            cout << "- affiancando i ribelli, hai risvegliato il cuore popolare.\n";
        else
            cout << "- schierando le guarnigioni, hai preservato l'ordine fino all ultimo istante.\n";
        if (scelta5_civitas_primo == 2)
            cout << "- il tuo discorso d unità ha fatto tacere spade e risvegliato speranza.\n";
        if (scelta6_civitas_fase1 == 0)
            cout << "- con l'articolo dei diritti hai inciso il futuro nella pietra.\n";
    }

    cout << "\nOra, ai confini dell Archivio Interplanetario, ti attende il Sigillo del Cosmo.\n";
    cout << "Con cuore colmo di ricordi e speranze, preparati a distruggerlo o plasmarlo.\n";

    // Enigma finale
    enigmaFinale();

    // Scelta epilogo
    cout << "\nMentre la polvere di stelle si posa, tre vie si spalancano davanti a te:\n";
    cout << "1) Diffondere la Conoscenza a tutte le colonie: un alba di progresso condiviso.\n";
    cout << "2) Custodire il sapere come Guardiano: un faro invisibile nell ombra.\n";
    cout << "3) Sigillare e distruggere tutto: un sacrificio per evitare abusi futuri.\n";
    cout << "Scelta definitiva: "; cin >> scelta7;

    cout << "\n--- Epilogo ---\n";
    if (scelta7 == 1) {
        cout << "Al canto degli astri, versi di rinascita si diffondono in ogni angolo del cosmo.\n";
        cout << "Le tue gesta diventano leggenda, un ponte di luce tra mondi in cerca di speranza.\n";
    }
    else if (scelta7 == 2) {
        cout << "Silenzioso custode, vegli sulle memorie di chi verrà.\n";
        cout << "Il tuo nome rimarrà scolpito in cuori e codici, guida eterna per i viandanti stellari.\n";
    }
    else {
        cout << "Con mano ferma, annulli il potere stesso che ti ha plasmato.\n";
        cout << "Una scelta di pietas supera ogni ambizione: anche nel vuoto, la vita trova un senso.\n";
    }

    cout << "\n--- FINE DELL'EPICA SAGA DEL COSMO ---" << endl;
}


int main() {
    srand(time(0));
    
    string protagonista;
    cout << "Come ti chiami? ";
    cin >> protagonista;
    
    selezionepersonaggio(protagonista);
    
    atto1(protagonista);
    atto2(protagonista);
    atto2_5(protagonista);

    switch (scelta2_5_citta) {
        case 0:
            atto3_xenopolis(protagonista);
            break;
        case 1:
            atto3_novaxenia(protagonista);
            break;
        case 2:
            atto3_civitas(protagonista);
            break;
    }

    switch (scelta2_5_citta) {
        case 0: atto4_xenopolis(protagonista); break;
        case 1: atto4_novaxenia(protagonista);  break;
        case 2: atto4_civitas(protagonista);    break;
    }

    switch (scelta2_5_citta) {
        case 0: atto5_xenopolis(protagonista); break;
        case 1: atto5_novaxenia(protagonista);  break;
        case 2: atto5_civitas(protagonista);    break;
    }

    switch (scelta2_5_citta) {
        case 0: atto6_xenopolis(protagonista); break;
        case 1: atto6_novaxenia(protagonista);  break;
        case 2: atto6_civitas(protagonista);    break;
    }

    atto7(protagonista);
    
    return 0;
}
