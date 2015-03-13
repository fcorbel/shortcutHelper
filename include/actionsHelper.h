#ifndef ACTIONSHELPER_H
#define ACTIONSHELPER_H

#include <string>
#include <vector>
#include <utility>
#include <json/json.h>
#include <simstring/simstring.h>

typedef struct {
  std::string action;
  std::string description;
} Entry;

// typedef simstring::cosine cosineSS;

class ActionsHelper
{
  private:
    const std::string AppListPath;

    std::string loadedAppName;
    std::vector<Entry> loadedEntries;

  public:
    ActionsHelper(std::string appName="help");
    bool loadEntries(const std::string appName);
    bool findEntriesFile(std::string& result, const std::string appName);
    bool loadAppList();
    bool processCmd(std::string cmd);
    bool addEntry(Entry newEntry);
    bool hasDb();
    bool createDb();
    std::vector<std::string> makeSearch(std::string search,std::string measure="cosine", double threshold=0.1);

    std::string getLoadedAppName();
    std::vector<Entry> getLoadedEntries();
    


};


#endif