#pragma once

#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "Trie.h"

const int SUCCESS = 0;
const int FAILURE = 1;

#define MAX_ITEM 1000100

struct sortItem
{
	std::vector<int> * data;
	int size;

	sortItem(std::vector<int> * data)
	{
		this->data = data;
		size = data->size();
	}

	sortItem(){}
	~sortItem(){}
};

class SimSearcher
{
public:
	SimSearcher();
	~SimSearcher();

	//std::unordered_map<std::string, std::vector<int> *> m_map;
	Trie* m_tree_ED;
	std::unordered_map<int, int> m_freq;
	std::unordered_set<int> m_flag;
	std::unordered_map<std::string, int> m_gram_id;
	std::unordered_map<int, std::vector<int>*> m_jaccard[257];
	std::vector<std::vector<std::string> > m_string_grams;
	std::vector<int> m_gram_length[257];
	char** m_string_list;
	int* m_string_size, *searchQueue, *searchList;
	int m_q;
	int m_idx;
	int m_min_gram;
	int m_max_gram;
	int d[257][257];
	sortItem* lists;

	int createIndex(const char *filename, unsigned q);
	int searchJaccard(const char *query, double threshold, std::vector<std::pair<unsigned, double> > &result);
	int searchED(const char *query, unsigned threshold, std::vector<std::pair<unsigned, unsigned> > &result);
	int DP(const char *query, int item, int length_query, int thres);
};

