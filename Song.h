#include <iostream>
#include <map>

#ifndef EX2_SONG_H
#define EX2_SONG_H

using namespace std;


class Song {
 public:

  /**
   * @brief todo
   */
  int virtual calculateScore();

 private:

  /**
   *
   */
  int _score;

  /**
   *
   */
  string _title;

  /**
   *
   */
  map<string ,int> _tags;
};


#endif //EX2_SONG_H
