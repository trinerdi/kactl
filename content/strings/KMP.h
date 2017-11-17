/**
 * Author: Johan Sannemo
 * License: CC0
 * Description: pi[x] computes the length of the longest prefix of s that ends at x, other than s[0..x] itself
 * This is used by find to find all occurances of a string.
 * Time: O(pattern) for pi, O(word + pattern) for find
 * Status: Tested on Kattis, stringmatching
 * Usage:
 *  vi p = pi(pattern); vi occ = find(word, p);
 */
#pragma once

vi pi(const string& s) {
	vi p(s.size());
	rep(i,1,s.size()) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,p.size()-s.size(),p.size())
		if (p[i] == pat.size()) res.push_back(i - 2 * pat.size());
	return res;
}
