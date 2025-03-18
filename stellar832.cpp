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


int main() {
    srand(time(0));
    
    cout << "SOLO L'ATTO 1 E L'ATTO 2 SONO GIOCABILI IN QUESTO STATO. GLI ALTRI SONO IN WORK IN PROGRESS. NON SONO STATI NEANCHE PROGRAMMATI TUTTI I PERCORSI. IL GIOCO FUNZIONA IN MODALITA INVINCIBILE PER ORA." << endl;
    
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
    
    return 0;
}
