#include <iostream>
#include <string>
using namespace std;

// A class to represent a song
class Song {
    public:
    string title; // The title of the song
    string producer; // The producer of the song
    string singer; // The singer of the song
    string genre; // The genre of the song
    Song* prev; // A pointer to the previous song in the doubly linked list
    Song* next; // A pointer to the next song in the doubly linked list

    // A constructor to initialize the song
    Song(string t, string p, string s, string g) {
        title = t;
        producer = p;
        singer = s;
        genre = g;
        prev = NULL;
        next = NULL;
    }
};

// A class to represent a music playlist
class Playlist {
    public:
    Song* head; // A pointer to the head of the doubly linked list
    Song* tail; // A pointer to the tail of the doubly linked list
    Song* curr; // A pointer to the current song in the playlist

    // A constructor to initialize the playlist
    Playlist() {
        head = NULL;
        tail = NULL;
        curr = NULL;
    } 

    // A method to add a new song to the playlist
    void addSong(string t, string p, string s, string g) {
        Song* song = new Song(t, p, s, g); // Create a new song object
        if (head == NULL) { // If the playlist is empty
            head = song; // Set the head to the new song
            tail = song; // Set the tail to the new song
            curr = song; // Set the current song to the new song
        }
        else { // If the playlist is not empty
            tail->next = song; // Add the new song at the end
            song->prev = tail; // Make the new song point to the tail
            tail = song; // Set the tail to the new song
        }
        cout << "Added " << t << " by " << s << " to the playlist." << endl;
    }

    // A method to play the next song in the playlist
    void playNext() {
        if (curr == NULL) { // If the playlist is empty
            cout << "The playlist is empty." << endl;
            return;
        }
        if (curr->next == NULL) { // If the current song is the last song
            cout << "No more songs in the playlist." << endl;
            return;
        }
        curr = curr->next; // Move the current song to the next song
        cout << "Playing " << curr->title << " by " << curr->singer << "." << endl;
    }

    // A method to play the previous song in the playlist
    void playPrev() {
        if (curr == NULL) { // If the playlist is empty
            cout << "The playlist is empty." << endl;
            return;
        }
        if (curr->prev == NULL) { // If the current song is the first song
            cout << "No previous songs in the playlist." << endl;
            return;
        }
        curr = curr->prev; // Move the current song to the previous song
        cout << "Playing " << curr->title << " by " << curr->singer << "." << endl;
    }

    // A method to display the songs in the playlist by producer
    void displayByProducer(string p) {
        if (head == NULL) { // If the playlist is empty
            cout << "The playlist is empty." << endl;
            return;
        }
        cout << "The songs produced by " << p << " are:" << endl;
        Song* song = head; // A pointer to traverse the playlist
        bool found = false; // A flag to indicate if any song is found
        while (song != NULL) { // Loop until the end of the playlist
            if (song->producer == p) { // If the song producer matches
                cout << song->title << " by " << song->singer << endl; // Display the song details
                found = true; // Set the flag to true
            }
            song = song->next; // Move to the next song
        }
        if (!found) { // If the flag is still false
            cout << "No such producer in the playlist." << endl;
        }
    }

    // A method to display the songs in the playlist by singer
    void displayBySinger(string s) {
        if (head == NULL) { // If the playlist is empty
            cout << "The playlist is empty." << endl;
            return;
        }
        cout << "The songs sung by " << s << " are:" << endl;
        Song* song = head; // A pointer to traverse the playlist
        bool found = false; // A flag to indicate if any song is found
        while (song != NULL) { // Loop until the end of the playlist
            if (song->singer == s) { // If the song singer matches
                cout << song->title << " by " << song->producer << endl; // Display the song details
                found = true; // Set the flag to true
            }
            song = song->next; // Move to the next song
        }
        if (!found) { // If the flag is still false
            cout << "No such singer in the playlist." << endl;
        }
    }

    // A method to display the songs in the playlist by genre
    void displayByGenre(string g) {
        if (head == NULL) { // If the playlist is empty
            cout << "The playlist is empty." << endl;
            return;
        }
        cout << "The songs of genre " << g << " are:" << endl;
        Song* song = head; // A pointer to traverse the playlist
        bool found = false; // A flag to indicate if any song is found
        while (song != NULL) { // Loop until the end of the playlist
            if (song->genre == g) { // If the song genre matches
                cout << song->title << " by " << song->singer << endl; // Display the song details
                found = true; // Set the flag to true
            }
            song = song->next; // Move to the next song
        }
        if (!found) { // If the flag is still false
            cout << "No such genre in the playlist." << endl;
        }
    }

    // A method to display the playlist
    void displayPlaylist() {
        if (head == NULL) { // If the playlist is empty
            cout << "The playlist is empty." << endl;
            return;
        }
        cout << "The playlist contains:" << endl;
        Song* song = head; // A pointer to traverse the playlist
        while (song != NULL) { // Loop until the end of the playlist
            cout << song->title << " by " << song->singer << endl; // Display the song details
            song = song->next; // Move to the next song
        }
    }
};

// A main function to test the code
int main() {
    Playlist pl; // Create a playlist object
    pl.addSong("Shape of You", "Ed Sheeran", "Ed Sheeran", "Pop"); // Add a song
    pl.addSong("Despacito", "Luis Fonsi", "Luis Fonsi ft. Daddy Yankee", "Reggaeton"); // Add another song
    pl.addSong("Bohemian Rhapsody", "Queen", "Queen", "Rock"); // Add another song
    pl.displayPlaylist(); // Display the playlist
    pl.playNext(); // Play the next song
    pl.playPrev(); // Play the previous song
    pl.displayByProducer("Ed Sheeran"); // Display the songs by producer
    pl.displayBySinger("Queen"); // Display the songs by singer
    pl.displayByGenre("Rock"); // Display the songs by genre
    return 0;
}
