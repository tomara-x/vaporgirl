/* ------------------------------------------------------------
author: "amy universe"
license: "WTFPL"
name: "moodygirl"
version: "0.14"
Code generated with Faust 2.50.6 (https://faust.grame.fr)
Compilation options: -a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -double -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2016 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************
 ************************************************************************/

#include <algorithm>
#include <assert.h>

#if JUCE_WINDOWS
#define JUCE_CORE_INCLUDE_NATIVE_HEADERS 1
#endif

#include "JuceLibraryCode/JuceHeader.h"

/************************** BEGIN MapUI.h ******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***********************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>
#include <stdio.h>

/************************** BEGIN UI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __UI_H__
#define __UI_H__

/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#ifndef __export__
#define __export__

#define FAUSTVERSION "2.50.6"

// Use FAUST_API for code that is part of the external API but is also compiled in faust and libfaust
// Use LIBFAUST_API for code that is compiled in faust and libfaust

#ifdef _WIN32
    #pragma warning (disable: 4251)
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #elif FAUST_LIB
        #define FAUST_API __declspec(dllexport)
        #define LIBFAUST_API __declspec(dllexport)
    #else
        #define FAUST_API
        #define LIBFAUST_API 
    #endif
#else
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #else
        #define FAUST_API __attribute__((visibility("default")))
        #define LIBFAUST_API __attribute__((visibility("default")))
    #endif
#endif

#endif

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

template <typename REAL>
struct FAUST_API UIReal {
    
    UIReal() {}
    virtual ~UIReal() {}
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // -- active widgets
    
    virtual void addButton(const char* label, REAL* zone) = 0;
    virtual void addCheckButton(const char* label, REAL* zone) = 0;
    virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
    
    // -- metadata declarations
    
    virtual void declare(REAL* zone, const char* key, const char* val) {}
    
    // To be used by LLVM client
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
};

struct FAUST_API UI : public UIReal<FAUSTFLOAT> {
    UI() {}
    virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN PathBuilder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __PathBuilder__
#define __PathBuilder__

#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <regex>


/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class FAUST_API PathBuilder {

    protected:
    
        std::vector<std::string> fControlsLevel;
        std::vector<std::string> fFullPaths;
        std::map<std::string, std::string> fFull2Short;  // filled by computeShortNames()
    
        /**
         * @brief check if a character is acceptable for an ID
         *
         * @param c
         * @return true is the character is acceptable for an ID
         */
        bool isIDChar(char c) const
        {
            return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
        }
    
        /**
         * @brief remove all "/0x00" parts
         *
         * @param src
         * @return modified string
         */
        std::string remove0x00(const std::string& src) const
        {
            return std::regex_replace(src, std::regex("/0x00"), "");
        }
    
        /**
         * @brief replace all non ID char with '_' (one '_' may replace several non ID char)
         *
         * @param src
         * @return modified string
         */
        std::string str2ID(const std::string& src) const
        {
            std::string dst;
            bool need_underscore = false;
            for (char c : src) {
                if (isIDChar(c) || (c == '/')) {
                    if (need_underscore) {
                        dst.push_back('_');
                        need_underscore = false;
                    }
                    dst.push_back(c);
                } else {
                    need_underscore = true;
                }
            }
            return dst;
        }
    
        /**
         * @brief Keep only the last n slash-parts
         *
         * @param src
         * @param n : 1 indicates the last slash-part
         * @return modified string
         */
        std::string cut(const std::string& src, int n) const
        {
            std::string rdst;
            for (int i = int(src.length())-1; i >= 0; i--) {
                char c = src[i];
                if (c != '/') {
                    rdst.push_back(c);
                } else if (n == 1) {
                    std::string dst;
                    for (int j = int(rdst.length())-1; j >= 0; j--) {
                        dst.push_back(rdst[j]);
                    }
                    return dst;
                } else {
                    n--;
                    rdst.push_back(c);
                }
            }
            return src;
        }
    
        void addFullPath(const std::string& label) { fFullPaths.push_back(buildPath(label)); }
    
        /**
         * @brief Compute the mapping between full path and short names
         */
        void computeShortNames()
        {
            std::vector<std::string>           uniquePaths;  // all full paths transformed but made unique with a prefix
            std::map<std::string, std::string> unique2full;  // all full paths transformed but made unique with a prefix
            char num_buffer[16];
            int pnum = 0;
        
            for (const auto& s : fFullPaths) {
                sprintf(num_buffer, "%d", pnum++);
                std::string u = "/P" + std::string(num_buffer) + str2ID(remove0x00(s));
                uniquePaths.push_back(u);
                unique2full[u] = s;  // remember the full path associated to a unique path
            }
        
            std::map<std::string, int> uniquePath2level;                // map path to level
            for (const auto& s : uniquePaths) uniquePath2level[s] = 1;   // we init all levels to 1
            bool have_collisions = true;
        
            while (have_collisions) {
                // compute collision list
                std::set<std::string>              collisionSet;
                std::map<std::string, std::string> short2full;
                have_collisions = false;
                for (const auto& it : uniquePath2level) {
                    std::string u = it.first;
                    int n = it.second;
                    std::string shortName = cut(u, n);
                    auto p = short2full.find(shortName);
                    if (p == short2full.end()) {
                        // no collision
                        short2full[shortName] = u;
                    } else {
                        // we have a collision, add the two paths to the collision set
                        have_collisions = true;
                        collisionSet.insert(u);
                        collisionSet.insert(p->second);
                    }
                }
                for (const auto& s : collisionSet) uniquePath2level[s]++;  // increase level of colliding path
            }
        
            for (const auto& it : uniquePath2level) {
                std::string u = it.first;
                int n = it.second;
                std::string shortName = replaceCharList(cut(u, n), {'/'}, '_');
                fFull2Short[unique2full[u]] = shortName;
            }
        }
    
        std::string replaceCharList(const std::string& str, const std::vector<char>& ch1, char ch2)
        {
            auto beg = ch1.begin();
            auto end = ch1.end();
            std::string res = str;
            for (size_t i = 0; i < str.length(); ++i) {
                if (std::find(beg, end, str[i]) != end) res[i] = ch2;
            }
            return res;
        }
     
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        // Return true for the first level of groups
        bool pushLabel(const std::string& label) { fControlsLevel.push_back(label); return fControlsLevel.size() == 1;}
    
        // Return true for the last level of groups
        bool popLabel() { fControlsLevel.pop_back(); return fControlsLevel.size() == 0; }
    
        std::string buildPath(const std::string& label)
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res = res + fControlsLevel[i] + "/";
            }
            res += label;
            return replaceCharList(res, {' ', '#', '*', ',', '?', '[', ']', '{', '}', '(', ')'}, '_');
        }
    
};

#endif  // __PathBuilder__
/**************************  END  PathBuilder.h **************************/

/*******************************************************************************
 * MapUI : Faust User Interface.
 *
 * This class creates:
 * - a map of 'labels' and zones for each UI item.
 * - a map of unique 'shortname' (built so that they never collide) and zones for each UI item
 * - a map of complete hierarchical 'paths' and zones for each UI item
 *
 * Simple 'labels', 'shortname' and complete 'paths' (to fully discriminate between possible same
 * 'labels' at different location in the UI hierachy) can be used to access a given parameter.
 ******************************************************************************/

class FAUST_API MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
        // Shortname zone map
        std::map<std::string, FAUSTFLOAT*> fShortnameZoneMap;
    
        // Full path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        void addZoneLabel(const std::string& label, FAUSTFLOAT* zone)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            fPathZoneMap[path] = zone;
            fLabelZoneMap[label] = zone;
        }
    
    public:
        
        MapUI() {}
        virtual ~MapUI() {}
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' map
                for (const auto& it : fFullPaths) {
                    fShortnameZoneMap[fFull2Short[it]] = fPathZoneMap[it];
                }
            }
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
    
        //-------------------------------------------------------------------------------
        // Public API
        //-------------------------------------------------------------------------------
    
        /**
         * Set the param value.
         *
         * @param str - the UI parameter label/shortname/path
         * @param value - the UI parameter value
         *
         */
        void setParamValue(const std::string& str, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                *fPathZoneMap[str] = value;
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                *fShortnameZoneMap[str] = value;
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                *fLabelZoneMap[str] = value;
            } else {
                fprintf(stderr, "ERROR : setParamValue '%s' not found\n", str.c_str());
            }
        }
        
        /**
         * Return the param value.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return *fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return *fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[str];
            } else {
                fprintf(stderr, "ERROR : getParamValue '%s' not found\n", str.c_str());
                return 0;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getFullpathMap() { return fPathZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getShortnameMap() { return fShortnameZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getLabelMap() { return fLabelZoneMap; }
            
        /**
         * Return the number of parameters in the UI.
         *
         * @return the number of parameters
         */
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        /**
         * Return the param path.
         *
         * @param index - the UI parameter index
         *
         * @return the param path
         */
        std::string getParamAddress(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return "";
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamAddress1(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param shortname.
         *
         * @param index - the UI parameter index
         *
         * @return the param shortname
         */
        std::string getParamShortname(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return "";
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamShortname1(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param label.
         *
         * @param index - the UI parameter index
         *
         * @return the param label
         */
        std::string getParamLabel(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return "";
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamLabel1(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param path.
         *
         * @param zone - the UI parameter memory zone
         *
         * @return the param path
         */
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            for (const auto& it : fPathZoneMap) {
                if (it.second == zone) return it.first;
            }
            return "";
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter label/shortname/path
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return fLabelZoneMap[str];
            }
            return nullptr;
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter index
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->second;
            }
        }
    
        static bool endsWith(const std::string& str, const std::string& end)
        {
            size_t l1 = str.length();
            size_t l2 = end.length();
            return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
        }
    
};

#endif // FAUST_MAPUI_H
/**************************  END  MapUI.h **************************/
/************************** BEGIN base_dsp-adapter.h *************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_adapter__
#define __dsp_adapter__

#ifndef _WIN32
#include <alloca.h>
#endif
#include <string.h>
#include <cmath>
#include <assert.h>
#include <stdio.h>

/************************** BEGIN base_dsp.h ********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API UI;
struct FAUST_API Meta;

/**
 * DSP memory manager.
 */

struct FAUST_API dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    /**
     * Inform the Memory Manager with the number of expected memory zones.
     * @param count - the number of expected memory zones
     */
    virtual void begin(size_t count) {}
    
    /**
     * Give the Memory Manager information on a given memory zone.
     * @param size - the size in bytes of the memory zone
     * @param reads - the number of Read access to the zone used to compute one frame
     * @param writes - the number of Write access to the zone used to compute one frame
     */
    virtual void info(size_t size, size_t reads, size_t writes) {}
    
    /**
     * Inform the Memory Manager that all memory zones have been described,
     * to possibly start a 'compute the best allocation strategy' step.
     */
    virtual void end() {}
    
    /**
     * Allocate a memory zone.
     * @param size - the memory zone size in bytes
     */
    virtual void* allocate(size_t size) = 0;
    
    /**
     * Destroy a memory zone.
     * @param ptr - the memory zone pointer to be deallocated
     */
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class FAUST_API base_dsp {

    public:

        base_dsp() {}
        virtual ~base_dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'openTabBox', 'addButton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Return the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceInit(int sample_rate) = 0;
    
        /**
         * Init instance constant state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (like delay lines...) but keep the control parameter values */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual base_dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class FAUST_API decorator_dsp : public base_dsp {

    protected:

        base_dsp* fDSP;

    public:

        decorator_dsp(base_dsp* base_dsp = nullptr):fDSP(base_dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int sample_rate) { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { fDSP->instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class, used with LLVM and Interpreter backends
 * to create DSP instances from a compiled DSP program.
 */

class FAUST_API dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual base_dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

// Denormal handling

#if defined (__SSE__)
#include <xmmintrin.h>
#endif

class FAUST_API ScopedNoDenormals {
    
    private:
    
        intptr_t fpsr = 0;
        
        void setFpStatusRegister(intptr_t fpsr_aux) noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("msr fpcr, %0" : : "ri" (fpsr_aux));
        #elif defined (__SSE__)
            // The volatile keyword here is needed to workaround a bug in AppleClang 13.0
            // which aggressively optimises away the variable otherwise
            volatile uint32_t fpsr_w = static_cast<uint32_t>(fpsr_aux);
            _mm_setcsr(fpsr_w);
        #endif
        }
        
        void getFpStatusRegister() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("mrs %0, fpcr" : "=r" (fpsr));
        #elif defined (__SSE__)
            fpsr = static_cast<intptr_t>(_mm_getcsr());
        #endif
        }
    
    public:
    
        ScopedNoDenormals() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            intptr_t mask = (1 << 24 /* FZ */);
        #elif defined (__SSE__)
        #if defined (__SSE2__)
            intptr_t mask = 0x8040;
        #else
            intptr_t mask = 0x8000;
        #endif
        #else
            intptr_t mask = 0x0000;
        #endif
            getFpStatusRegister();
            setFpStatusRegister(fpsr | mask);
        }
        
        ~ScopedNoDenormals() noexcept
        {
            setFpStatusRegister(fpsr);
        }

};

#define AVOIDDENORMALS ScopedNoDenormals ftz_scope;

#endif

/************************** END base_dsp.h **************************/

// Adapts a DSP for a different number of inputs/outputs
class dsp_adapter : public decorator_dsp {
    
    private:
    
        FAUSTFLOAT** fAdaptedInputs;
        FAUSTFLOAT** fAdaptedOutputs;
        int fHWInputs;
        int fHWOutputs;
        int fBufferSize;
    
        void adaptBuffers(FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int i = 0; i < fHWInputs; i++) {
                fAdaptedInputs[i] = inputs[i];
            }
            for (int i = 0; i < fHWOutputs; i++) {
                fAdaptedOutputs[i] = outputs[i];
            }
        }
    
    public:
    
        dsp_adapter(base_dsp* base_dsp, int hw_inputs, int hw_outputs, int buffer_size):decorator_dsp(base_dsp)
        {
            fHWInputs = hw_inputs;
            fHWOutputs = hw_outputs;
            fBufferSize = buffer_size;
            
            fAdaptedInputs = new FAUSTFLOAT*[base_dsp->getNumInputs()];
            for (int i = 0; i < base_dsp->getNumInputs() - fHWInputs; i++) {
                fAdaptedInputs[i + fHWInputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedInputs[i + fHWInputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
            
            fAdaptedOutputs = new FAUSTFLOAT*[base_dsp->getNumOutputs()];
            for (int i = 0; i < base_dsp->getNumOutputs() - fHWOutputs; i++) {
                fAdaptedOutputs[i + fHWOutputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedOutputs[i + fHWOutputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
        }
    
        virtual ~dsp_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs() - fHWInputs; i++) {
                delete [] fAdaptedInputs[i + fHWInputs];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs() - fHWOutputs; i++) {
                delete [] fAdaptedOutputs[i + fHWOutputs];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual int getNumInputs() { return fHWInputs; }
        virtual int getNumOutputs() { return fHWOutputs; }
    
        virtual dsp_adapter* clone() { return new dsp_adapter(fDSP->clone(), fHWInputs, fHWOutputs, fBufferSize); }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(date_usec, count, fAdaptedInputs, fAdaptedOutputs);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(count, fAdaptedInputs, fAdaptedOutputs);
        }
};

// Adapts a DSP for a different sample size
template <typename REAL_INT, typename REAL_EXT>
class dsp_sample_adapter : public decorator_dsp {
    
    private:
    
        REAL_INT** fAdaptedInputs;
        REAL_INT** fAdaptedOutputs;
    
        void adaptInputBuffers(int count, FAUSTFLOAT** inputs)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    fAdaptedInputs[chan][frame] = REAL_INT(reinterpret_cast<REAL_EXT**>(inputs)[chan][frame]);
                }
            }
        }
    
        void adaptOutputsBuffers(int count, FAUSTFLOAT** outputs)
        {
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    reinterpret_cast<REAL_EXT**>(outputs)[chan][frame] = REAL_EXT(fAdaptedOutputs[chan][frame]);
                }
            }
        }
    
    public:
    
        dsp_sample_adapter(base_dsp* base_dsp):decorator_dsp(base_dsp)
        {
            fAdaptedInputs = new REAL_INT*[base_dsp->getNumInputs()];
            for (int i = 0; i < base_dsp->getNumInputs(); i++) {
                fAdaptedInputs[i] = new REAL_INT[4096];
            }
            
            fAdaptedOutputs = new REAL_INT*[base_dsp->getNumOutputs()];
            for (int i = 0; i < base_dsp->getNumOutputs(); i++) {
                fAdaptedOutputs[i] = new REAL_INT[4096];
            }
        }
    
        virtual ~dsp_sample_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                delete [] fAdaptedInputs[i];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                delete [] fAdaptedOutputs[i];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual dsp_sample_adapter* clone() { return new dsp_sample_adapter(fDSP->clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= 4096);
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses REAL_INT
            fDSP->compute(count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= 4096);
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses REAL_INT
            fDSP->compute(date_usec, count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
};

// Template used to specialize double parameters expressed as NUM/DENOM
template <int NUM, int DENOM>
struct Double {
    static constexpr double value() { return double(NUM)/double(DENOM); }
};

// Base class for filters
template <class fVslider0, int fVslider1>
struct Filter {
    inline int getFactor() { return fVslider1; }
};

// Identity filter: copy input to output
template <class fVslider0, int fVslider1>
struct Identity : public Filter<fVslider0, fVslider1> {
    inline int getFactor() { return fVslider1; }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        memcpy(output0, input0, count * sizeof(FAUSTFLOAT));
    }
};

// Generated with process = fi.lowpass(3, ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass3 : public Filter<fVslider0, fVslider1> {
    
    REAL fVec0[2];
    REAL fRec1[2];
    REAL fRec0[3];
    
    inline REAL LowPass3_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass3()
    {
        for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
            fVec0[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fRec1[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 1.0000000000000002) / fSlow0) + 1.0));
        REAL fSlow3 = (1.0 / (fSlow1 + 1.0));
        REAL fSlow4 = (1.0 - fSlow1);
        REAL fSlow5 = (((fSlow1 + -1.0000000000000002) / fSlow0) + 1.0);
        REAL fSlow6 = (2.0 * (1.0 - (1.0 / LowPass3_faustpower2_f(fSlow0))));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            REAL fTemp0 = REAL(input0[i]);
            fVec0[0] = fTemp0;
            fRec1[0] = (0.0 - (fSlow3 * ((fSlow4 * fRec1[1]) - (fTemp0 + fVec0[1]))));
            fRec0[0] = (fRec1[0] - (fSlow2 * ((fSlow5 * fRec0[2]) + (fSlow6 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (fRec0[2] + (fRec0[0] + (2.0 * fRec0[1])))));
            fVec0[1] = fVec0[0];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass(4, ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass4 : public Filter<fVslider0, fVslider1> {
    
    REAL fRec1[3];
    REAL fRec0[3];
    
    inline REAL LowPass4_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass4()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec1[l0] = 0.0f;
        }
        for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
            fRec0[l1] = 0.0f;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 0.76536686473017945) / fSlow0) + 1.0));
        REAL fSlow3 = (1.0 / (((fSlow1 + 1.8477590650225735) / fSlow0) + 1.0));
        REAL fSlow4 = (((fSlow1 + -1.8477590650225735) / fSlow0) + 1.0);
        REAL fSlow5 = (2.0 * (1.0 - (1.0 / LowPass4_faustpower2_f(fSlow0))));
        REAL fSlow6 = (((fSlow1 + -0.76536686473017945) / fSlow0) + 1.0);
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec1[0] = (REAL(input0[i]) - (fSlow3 * ((fSlow4 * fRec1[2]) + (fSlow5 * fRec1[1]))));
            fRec0[0] = ((fSlow3 * (fRec1[2] + (fRec1[0] + (2.0 * fRec1[1])))) - (fSlow2 * ((fSlow6 * fRec0[2]) + (fSlow5 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (fRec0[2] + (fRec0[0] + (2.0 * fRec0[1])))));
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass3e(ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass3e : public Filter<fVslider0, fVslider1> {
    
    REAL fRec1[3];
    REAL fVec0[2];
    REAL fRec0[2];
    
    inline REAL LowPass3e_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass3e()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec1[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fVec0[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (fSlow1 + 0.82244590899881598));
        REAL fSlow3 = (0.82244590899881598 - fSlow1);
        REAL fSlow4 = (1.0 / (((fSlow1 + 0.80263676416103003) / fSlow0) + 1.4122708937742039));
        REAL fSlow5 = LowPass3e_faustpower2_f(fSlow0);
        REAL fSlow6 = (0.019809144837788999 / fSlow5);
        REAL fSlow7 = (fSlow6 + 1.1615164189826961);
        REAL fSlow8 = (((fSlow1 + -0.80263676416103003) / fSlow0) + 1.4122708937742039);
        REAL fSlow9 = (2.0 * (1.4122708937742039 - (1.0 / fSlow5)));
        REAL fSlow10 = (2.0 * (1.1615164189826961 - fSlow6));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec1[0] = (REAL(input0[i]) - (fSlow4 * ((fSlow8 * fRec1[2]) + (fSlow9 * fRec1[1]))));
            REAL fTemp0 = (fSlow4 * (((fSlow7 * fRec1[0]) + (fSlow10 * fRec1[1])) + (fSlow7 * fRec1[2])));
            fVec0[0] = fTemp0;
            fRec0[0] = (0.0 - (fSlow2 * ((fSlow3 * fRec0[1]) - (fTemp0 + fVec0[1]))));
            output0[i] = FAUSTFLOAT(fRec0[0]);
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fVec0[1] = fVec0[0];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass6e(ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass6e : public Filter<fVslider0, fVslider1> {
    
    REAL fRec2[3];
    REAL fRec1[3];
    REAL fRec0[3];
    
    inline REAL LowPass6e_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass6e()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec2[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
            fRec1[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 0.16840487111358901) / fSlow0) + 1.0693584077073119));
        REAL fSlow3 = LowPass6e_faustpower2_f(fSlow0);
        REAL fSlow4 = (1.0 / fSlow3);
        REAL fSlow5 = (fSlow4 + 53.536152954556727);
        REAL fSlow6 = (1.0 / (((fSlow1 + 0.51247864188914105) / fSlow0) + 0.68962136448467504));
        REAL fSlow7 = (fSlow4 + 7.6217312988706034);
        REAL fSlow8 = (1.0 / (((fSlow1 + 0.78241304682164503) / fSlow0) + 0.24529150870616001));
        REAL fSlow9 = (9.9999997054999994e-05 / fSlow3);
        REAL fSlow10 = (fSlow9 + 0.00043322720055500002);
        REAL fSlow11 = (((fSlow1 + -0.78241304682164503) / fSlow0) + 0.24529150870616001);
        REAL fSlow12 = (2.0 * (0.24529150870616001 - fSlow4));
        REAL fSlow13 = (2.0 * (0.00043322720055500002 - fSlow9));
        REAL fSlow14 = (((fSlow1 + -0.51247864188914105) / fSlow0) + 0.68962136448467504);
        REAL fSlow15 = (2.0 * (0.68962136448467504 - fSlow4));
        REAL fSlow16 = (2.0 * (7.6217312988706034 - fSlow4));
        REAL fSlow17 = (((fSlow1 + -0.16840487111358901) / fSlow0) + 1.0693584077073119);
        REAL fSlow18 = (2.0 * (1.0693584077073119 - fSlow4));
        REAL fSlow19 = (2.0 * (53.536152954556727 - fSlow4));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec2[0] = (REAL(input0[i]) - (fSlow8 * ((fSlow11 * fRec2[2]) + (fSlow12 * fRec2[1]))));
            fRec1[0] = ((fSlow8 * (((fSlow10 * fRec2[0]) + (fSlow13 * fRec2[1])) + (fSlow10 * fRec2[2]))) - (fSlow6 * ((fSlow14 * fRec1[2]) + (fSlow15 * fRec1[1]))));
            fRec0[0] = ((fSlow6 * (((fSlow7 * fRec1[0]) + (fSlow16 * fRec1[1])) + (fSlow7 * fRec1[2]))) - (fSlow2 * ((fSlow17 * fRec0[2]) + (fSlow18 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (((fSlow5 * fRec0[0]) + (fSlow19 * fRec0[1])) + (fSlow5 * fRec0[2]))));
            fRec2[2] = fRec2[1];
            fRec2[1] = fRec2[0];
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// A "si.bus(N)" like hard-coded class
struct dsp_bus : public base_dsp {
    
    int fChannels;
    int fSampleRate;
    
    dsp_bus(int channels):fChannels(channels), fSampleRate(-1)
    {}
    
    virtual int getNumInputs() { return fChannels; }
    virtual int getNumOutputs() { return fChannels; }
    
    virtual int getSampleRate() { return fSampleRate; }
    
    virtual void buildUserInterface(UI* ui_interface) {}
    virtual void init(int sample_rate)
    {
        //classInit(sample_rate);
        instanceInit(sample_rate);
    }
    
    virtual void instanceInit(int sample_rate)
    {
        fSampleRate = sample_rate;
        instanceConstants(sample_rate);
        instanceResetUserInterface();
        instanceClear();
    }
    
    virtual void instanceConstants(int sample_rate) {}
    virtual void instanceResetUserInterface() {}
    virtual void instanceClear() {}
    
    virtual base_dsp* clone() { return new dsp_bus(fChannels); }
    
    virtual void metadata(Meta* m) {}
    
    virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        for (int chan = 0; chan < fChannels; chan++) {
            memcpy(outputs[chan], inputs[chan], sizeof(FAUSTFLOAT) * count);
        }
    }
    
    virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        compute(count, inputs, outputs);
    }
    
};

// Base class for sample-rate adapter
template <typename FILTER>
class sr_sampler : public decorator_dsp {
    
    protected:
    
        std::vector<FILTER> fInputLowPass;
        std::vector<FILTER> fOutputLowPass;
    
        inline int getFactor() { return this->fOutputLowPass[0].getFactor(); }
    
    public:
    
        sr_sampler(base_dsp* base_dsp):decorator_dsp(base_dsp)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                fInputLowPass.push_back(FILTER());
            }
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                fOutputLowPass.push_back(FILTER());
            }
        }
};

// Down sample-rate adapter
template <typename FILTER>
class dsp_down_sampler : public sr_sampler<FILTER> {
    
    public:
    
        dsp_down_sampler(base_dsp* base_dsp):sr_sampler<FILTER>(base_dsp)
        {}
    
        virtual void init(int sample_rate)
        {
            this->fDSP->init(sample_rate / this->getFactor());
        }
    
        virtual void instanceInit(int sample_rate)
        {
            this->fDSP->instanceInit(sample_rate / this->getFactor());
        }
    
        virtual void instanceConstants(int sample_rate)
        {
            this->fDSP->instanceConstants(sample_rate / this->getFactor());
        }
    
        virtual dsp_down_sampler* clone() { return new dsp_down_sampler(decorator_dsp::clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            int real_count = count / this->getFactor();
            
            // Adapt inputs
            FAUSTFLOAT** fInputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < this->fDSP->getNumInputs(); chan++) {
                // Lowpass filtering in place on 'inputs'
                this->fInputLowPass[chan].compute(count, inputs[chan], inputs[chan]);
                // Allocate fInputs with 'real_count' frames
                fInputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
                // Decimate
                for (int frame = 0; frame < real_count; frame++) {
                    fInputs[chan][frame] = inputs[chan][frame * this->getFactor()];
                }
            }
            
            // Allocate fOutputs with 'real_count' frames
            FAUSTFLOAT** fOutputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                fOutputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
            }
            
            // Compute at lower rate
            this->fDSP->compute(real_count, fInputs, fOutputs);
            
            // Adapt outputs
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                // Puts zeros
                memset(outputs[chan], 0, sizeof(FAUSTFLOAT) * count);
                for (int frame = 0; frame < real_count; frame++) {
                    // Copy one sample every 'DownFactor'
                    // Apply volume
                    //outputs[chan][frame * this->getFactor()] = fOutputs[chan][frame] * this->getFactor();
                    outputs[chan][frame * this->getFactor()] = fOutputs[chan][frame];
                }
                // Lowpass filtering in place on 'outputs'
                this->fOutputLowPass[chan].compute(count, outputs[chan], outputs[chan]);
            }
        }
    
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Up sample-rate adapter
template <typename FILTER>
class dsp_up_sampler : public sr_sampler<FILTER> {
    
    public:
    
        dsp_up_sampler(base_dsp* base_dsp):sr_sampler<FILTER>(base_dsp)
        {}
    
        virtual void init(int sample_rate)
        {
            this->fDSP->init(sample_rate * this->getFactor());
        }
    
        virtual void instanceInit(int sample_rate)
        {
            this->fDSP->instanceInit(sample_rate * this->getFactor());
        }
    
        virtual void instanceConstants(int sample_rate)
        {
            this->fDSP->instanceConstants(sample_rate * this->getFactor());
        }
    
        virtual dsp_up_sampler* clone() { return new dsp_up_sampler(decorator_dsp::clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            int real_count = count * this->getFactor();
            
            // Adapt inputs
            FAUSTFLOAT** fInputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumInputs() * sizeof(FAUSTFLOAT*));
            
            for (int chan = 0; chan < this->fDSP->getNumInputs(); chan++) {
                // Allocate fInputs with 'real_count' frames
                fInputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
                // Puts zeros
                memset(fInputs[chan], 0, sizeof(FAUSTFLOAT) * real_count);
                for (int frame = 0; frame < count; frame++) {
                    // Copy one sample every 'UpFactor'
                    fInputs[chan][frame * this->getFactor()] = inputs[chan][frame];
                }
                // Lowpass filtering in place on 'fInputs'
                this->fInputLowPass[chan].compute(real_count, fInputs[chan], fInputs[chan]);
            }
            
            // Allocate fOutputs with 'real_count' frames
            FAUSTFLOAT** fOutputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumOutputs() * sizeof(FAUSTFLOAT*));
            
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                fOutputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
            }
            
            // Compute at upper rate
            this->fDSP->compute(real_count, fInputs, fOutputs);
            
            // Adapt outputs
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                // Lowpass filtering in place on 'fOutputs'
                this->fOutputLowPass[chan].compute(real_count, fOutputs[chan], fOutputs[chan]);
                // Decimate
                for (int frame = 0; frame < count; frame++) {
                    // Apply volume
                    //outputs[chan][frame] = fOutputs[chan][frame * this->getFactor()] * this->getFactor();
                    outputs[chan][frame] = fOutputs[chan][frame * this->getFactor()];
                }
            }
        }
    
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Create a UP/DS + Filter adapted DSP
template <typename REAL>
base_dsp* createSRAdapter(base_dsp* DSP, int ds = 0, int us = 0, int filter = 0)
{
    if (ds > 0) {
        switch (filter) {
            case 0:
                if (ds == 2) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 2>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 3>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 4>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 8>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 16>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 32>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 1:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 2:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 3:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 4:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            default:
                fprintf(stderr, "ERROR : filter type must be in [0..4] range\n");
                assert(false);
                return nullptr;
        }
    } else if (us > 0) {
        
        switch (filter) {
            case 0:
                if (us == 2) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 2>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 3>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 4>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 8>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 16>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 32>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 1:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 2:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 3:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 4:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            default:
                fprintf(stderr, "ERROR : filter type must be in [0..4] range\n");
                assert(false);
                return nullptr;
        }
    } else {
        return DSP;
    }
}
    
#endif
/************************** END base_dsp-adapter.h **************************/
/************************** BEGIN MidiUI.h ****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>

/************************** BEGIN meta.h *******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__


/**
 The base class of Meta handler to be used in base_dsp::metadata(Meta* m) method to retrieve (key, value) metadata.
 */
struct FAUST_API Meta {
    virtual ~Meta() {}
    virtual void declare(const char* key, const char* value) = 0;
};

#endif
/**************************  END  meta.h **************************/
/************************** BEGIN GUI.h **********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <assert.h>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/************************** BEGIN ValueConverter.h ********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
 ValueConverter.h
 (GRAME, Copyright 2015-2019)
 
 Set of conversion objects used to map user interface values (for example a gui slider
 delivering values between 0 and 1) to faust values (for example a vslider between
 20 and 20000) using a log scale.
 
 -- Utilities
 
 Range(lo,hi) : clip a value x between lo and hi
 Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
 Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2
 
 -- Value Converters
 
 ValueConverter::ui2faust(x)
 ValueConverter::faust2ui(x)
 
 -- ValueConverters used for sliders depending of the scale
 
 LinearValueConverter(umin, umax, fmin, fmax)
 LinearValueConverter2(lo, mi, hi, v1, vm, v2) using 2 segments
 LogValueConverter(umin, umax, fmin, fmax)
 ExpValueConverter(umin, umax, fmin, fmax)
 
 -- ValueConverters used for accelerometers based on 3 points
 
 AccUpConverter(amin, amid, amax, fmin, fmid, fmax)        -- curve 0
 AccDownConverter(amin, amid, amax, fmin, fmid, fmax)      -- curve 1
 AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)    -- curve 2
 AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)    -- curve 3
 
 -- lists of ZoneControl are used to implement accelerometers metadata for each axes
 
 ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter
 
 -- ZoneReader are used to implement screencolor metadata
 
 ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>


//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef           with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef              with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class FAUST_API Interpolator {
    
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class FAUST_API Interpolator3pt {

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class FAUST_API ValueConverter {

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) { return x; };
        virtual double faust2ui(double x) { return x; };
};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class FAUST_API UpdatableValueConverter : public ValueConverter {
    
    protected:
        
        bool fActive;
        
    public:
        
        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}
        
        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;
        
        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }
    
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LinearValueConverter : public ValueConverter {
    
    private:
        
        Interpolator fUI2F;
        Interpolator fF2UI;
        
    public:
        
        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}
        
        LinearValueConverter() : fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) { return fUI2F(x); }
        virtual double faust2ui(double x) { return fF2UI(x); }
    
};

//--------------------------------------------------------------------------------------
// Two segments linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LinearValueConverter2 : public UpdatableValueConverter {
    
    private:
    
        Interpolator3pt fUI2F;
        Interpolator3pt fF2UI;
        
    public:
    
        LinearValueConverter2(double amin, double amid, double amax, double min, double init, double max) :
            fUI2F(amin, amid, amax, min, init, max), fF2UI(min, init, max, amin, amid, amax)
        {}
        
        LinearValueConverter2() : fUI2F(0.,0.,0.,0.,0.,0.), fF2UI(0.,0.,0.,0.,0.,0.)
        {}
    
        virtual double ui2faust(double x) { return fUI2F(x); }
        virtual double faust2ui(double x) { return fF2UI(x); }
    
        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max)
        {
            fUI2F = Interpolator3pt(amin, amid, amax, min, init, max);
            fF2UI = Interpolator3pt(min, init, max, amin, amid, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fUI2F.getMappingValues(amin, amid, amax);
        }
    
};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LogValueConverter : public LinearValueConverter {

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, std::log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) { return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API ExpValueConverter : public LinearValueConverter {

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, std::min<double>(DBL_MAX, std::exp(fmin)), std::min<double>(DBL_MAX, std::exp(fmax)))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::min<double>(DBL_MAX, std::exp(x))); }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class FAUST_API AccUpConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmin, fmid, fmax);
            fF2A = Interpolator3pt(fmin, fmid, fmax, amin, amid, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class FAUST_API AccDownConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmax, fmid, fmin);
            fF2A = Interpolator3pt(fmin, fmid, fmax, amax, amid, amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class FAUST_API AccUpDownConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotonic function
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmin, fmax, fmin);
            fF2A = Interpolator(fmin, fmax, amin, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class FAUST_API AccDownUpConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotonic function
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmax, fmin, fmax);
            fF2A = Interpolator(fmin, fmax, amin, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class FAUST_API ZoneControl {

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) const {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class FAUST_API ConverterZoneControl : public ZoneControl {

    protected:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* converter) : ZoneControl(zone), fValueConverter(converter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        virtual void update(double v) const { *fZone = FAUSTFLOAT(fValueConverter->ui2faust(v)); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class FAUST_API CurveZoneControl : public ZoneControl {

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            for (const auto& it : fValueConverters) { delete it; }
        }
        void update(double v) const { if (fValueConverters[fCurve]->getActive()) *fZone = FAUSTFLOAT(fValueConverters[fCurve]->ui2faust(v)); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            for (const auto& it : fValueConverters) { it->setActive(on_off); }
        }

        int getCurve() { return fCurve; }
};

class FAUST_API ZoneReader {

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            return (fZone != nullptr) ? int(fInterpolator(*fZone)) : 127;
        }

};

#endif
/**************************  END  ValueConverter.h **************************/
/************************** BEGIN MetaDataUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef MetaData_UI_H
#define MetaData_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <map>
#include <set>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h> // We use the lighter fprintf code

/************************** BEGIN SimpleParser.h *********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdio.h> // We use the lighter fprintf code
#include <ctype.h>
#include <assert.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

struct itemInfo {
    std::string type;
    std::string label;
    std::string shortname;
    std::string address;
    std::string url;
    int index;
    double init;
    double fmin;
    double fmax;
    double step;
    std::vector<std::pair<std::string, std::string> > meta;
    
    itemInfo():index(0), init(0.), fmin(0.), fmax(0.), step(0.)
    {}
};

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    fprintf(stderr, "Parse error : %s here : %s\n", errmsg, p);
    return true;
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
static void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
static bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
static bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] or [s]d[.dddd][E|e][s][dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
static bool parseDouble(const char*& p, double& x)
{
    double sign = 1.0;     // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part
    double expsign = 1.0;  // sign of the E|e part
    double expcoef = 0.0;  // multiplication factor of E|e part
    
    bool valid = false;    // true if the number contains at least one digit
    
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    
    // Sign
    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    
    // Integral part
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    
    // Possible decimal part
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    
    // Possible E|e part
    if (parseChar(p, 'E') || parseChar(p, 'e')) {
        if (parseChar(p, '+')) {
            expsign = 1.0;
        } else if (parseChar(p, '-')) {
            expsign = -1.0;
        }
        while (isdigit(*p)) {
            expcoef = expcoef*10 + (*p - '0');
            p++;
        }
    }
    
    if (valid)  {
        x = (sign*(ipart + dpart/dcoef)) * std::pow(10.0, expcoef*expsign);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseString(const char*& p, char quote, std::string& s)
{
    std::string str;
    skipBlank(p);
    
    const char* saved = p;  // to restore position if we fail
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseSQString(const char*& p, std::string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseDQString(const char*& p, std::string& s)
{
    return parseString(p, '"', s);
}

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
static bool parseMenuItem(const char*& p, std::string& name, double& value)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

static bool parseMenuItem2(const char*& p, std::string& name)
{
    const char* saved = p;  // to restore position if we fail
    // single quoted
    if (parseSQString(p, name)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values)
{
    std::vector<std::string> tmpnames;
    std::vector<double> tmpvalues;
    const char* saved = p; // to restore position if we fail

    if (parseChar(p, '{')) {
        do {
            std::string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug)
{
    std::vector<std::string> tmpnames;
    const char* saved = p;  // to restore position if we fail
    
    if (parseChar(p, '{')) {
        do {
            std::string n;
            if (parseMenuItem2(p, n)) {
                tmpnames.push_back(n);
            } else {
                goto error;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            return true;
        }
    }
    
error:
    if (debug) { fprintf(stderr, "parseMenuList2 : (%s) is not a valid list !\n", p); }
    p = saved;
    return false;
}

/// ---------------------------------------------------------------------
// Parse list of strings
/// ---------------------------------------------------------------------
static bool parseList(const char*& p, std::vector<std::string>& items)
{
    const char* saved = p;  // to restore position if we fail
    if (parseChar(p, '[')) {
        do {
            std::string item;
            if (!parseDQString(p, item)) {
                p = saved;
                return false;
            }
            items.push_back(item);
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    const char* saved = p; // to restore position if we fail
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    const char* saved = p; // to restore position if we fail
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
/// ---------------------------------------------------------------------
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, double& dbl, std::map<std::string, std::string>& metadatas, std::vector<std::string>& items)
{
    const char* saved = p; // to restore position if we fail
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && (parseDQString(p, value) || parseList(p, items) || parseDouble(p, dbl));
        }
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
/// ---------------------------------------------------------------------
static bool parseUI(const char*& p, std::vector<itemInfo>& uiItems, int& numItems)
{
    const char* saved = p; // to restore position if we fail
    if (parseChar(p, '{')) {
   
        std::string label;
        std::string value;
        double dbl = 0;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo item;
                        item.type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].label = value;
                    }
                }
                
                else if (label == "shortname") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].shortname = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].address = value;
                    }
                }
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].url = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].index = int(dbl);
                    }
                }
                
                else if (label == "meta") {
                    if (!parseItemMetaData(p, uiItems[numItems].meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].init = dbl;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].fmin = dbl;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].fmax = dbl;
                    }
                }
                
                else if (label == "step") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].step = dbl;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do {
                            if (!parseUI(p, uiItems, numItems)) {
                                p = saved;
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo item;
                            item.type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
            
                } else {
                    fprintf(stderr, "Parse error unknown : %s \n", label.c_str());
                    assert(false);
                }
            } else {
                p = saved;
                return false;
            }
            
        } while (tryChar(p, ','));
    
        return parseChar(p, '}');
    } else {
        return true; // "items": [] is valid
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
/// ---------------------------------------------------------------------
static bool parseJson(const char*& p,
                      std::map<std::string, std::pair<std::string, double> >& metaDatas0,
                      std::map<std::string, std::string>& metaDatas1,
                      std::map<std::string, std::vector<std::string> >& metaDatas2,
                      std::vector<itemInfo>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        double dbl = 0;
        std::vector<std::string> items;
        if (parseGlobalMetaData(p, key, value, dbl, metaDatas1, items)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                if (items.size() > 0) {
                    metaDatas2[key] = items;
                    items.clear();
                } else if (value != "") {
                    metaDatas0[key].first = value;
                } else {
                    metaDatas0[key].second = dbl;
                }
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H
/**************************  END  SimpleParser.h **************************/

static bool startWith(const std::string& str, const std::string& prefix)
{
    return (str.substr(0, prefix.size()) == prefix);
}

/**
 * Convert a dB value into a scale between 0 and 1 (following IEC standard ?)
 */
static FAUSTFLOAT dB2Scale(FAUSTFLOAT dB)
{
    FAUSTFLOAT scale = FAUSTFLOAT(1.0);
    
    /*if (dB < -70.0f)
     scale = 0.0f;
     else*/
    if (dB < FAUSTFLOAT(-60.0))
        scale = (dB + FAUSTFLOAT(70.0)) * FAUSTFLOAT(0.0025);
    else if (dB < FAUSTFLOAT(-50.0))
        scale = (dB + FAUSTFLOAT(60.0)) * FAUSTFLOAT(0.005) + FAUSTFLOAT(0.025);
    else if (dB < FAUSTFLOAT(-40.0))
        scale = (dB + FAUSTFLOAT(50.0)) * FAUSTFLOAT(0.0075) + FAUSTFLOAT(0.075);
    else if (dB < FAUSTFLOAT(-30.0))
        scale = (dB + FAUSTFLOAT(40.0)) * FAUSTFLOAT(0.015) + FAUSTFLOAT(0.15);
    else if (dB < FAUSTFLOAT(-20.0))
        scale = (dB + FAUSTFLOAT(30.0)) * FAUSTFLOAT(0.02) + FAUSTFLOAT(0.3);
    else if (dB < FAUSTFLOAT(-0.001) || dB > FAUSTFLOAT(0.001))  /* if (dB < 0.0) */
        scale = (dB + FAUSTFLOAT(20.0)) * FAUSTFLOAT(0.025) + FAUSTFLOAT(0.5);
    
    return scale;
}

/*******************************************************************************
 * MetaDataUI : Common class for MetaData handling
 ******************************************************************************/

//============================= BEGIN GROUP LABEL METADATA===========================
// Unlike widget's label, metadata inside group's label are not extracted directly by
// the Faust compiler. Therefore they must be extracted within the architecture file
//-----------------------------------------------------------------------------------

class MetaDataUI {
    
    protected:
        
        std::string                         fGroupTooltip;
        std::map<FAUSTFLOAT*, FAUSTFLOAT>   fGuiSize;            // map widget zone with widget size coef
        std::map<FAUSTFLOAT*, std::string>  fTooltip;            // map widget zone with tooltip strings
        std::map<FAUSTFLOAT*, std::string>  fUnit;               // map widget zone to unit string (i.e. "dB")
        std::map<FAUSTFLOAT*, std::string>  fRadioDescription;   // map zone to {'low':440; ...; 'hi':1000.0}
        std::map<FAUSTFLOAT*, std::string>  fMenuDescription;    // map zone to {'low':440; ...; 'hi':1000.0}
        std::set<FAUSTFLOAT*>               fKnobSet;            // set of widget zone to be knobs
        std::set<FAUSTFLOAT*>               fLedSet;             // set of widget zone to be LEDs
        std::set<FAUSTFLOAT*>               fNumSet;             // set of widget zone to be numerical bargraphs
        std::set<FAUSTFLOAT*>               fLogSet;             // set of widget zone having a log UI scale
        std::set<FAUSTFLOAT*>               fExpSet;             // set of widget zone having an exp UI scale
        std::set<FAUSTFLOAT*>               fHiddenSet;          // set of hidden widget zone
        
        void clearMetadata()
        {
            fGuiSize.clear();
            fTooltip.clear();
            fUnit.clear();
            fRadioDescription.clear();
            fMenuDescription.clear();
            fKnobSet.clear();
            fLedSet.clear();
            fNumSet.clear();
            fLogSet.clear();
            fExpSet.clear();
            fHiddenSet.clear();
            fGroupTooltip = "";
        }
        
        /**
         * rmWhiteSpaces(): Remove the leading and trailing white spaces of a string
         * (but not those in the middle of the string)
         */
        static std::string rmWhiteSpaces(const std::string& s)
        {
            size_t i = s.find_first_not_of(" \t");
            size_t j = s.find_last_not_of(" \t");
            if ((i != std::string::npos) && (j != std::string::npos)) {
                return s.substr(i, 1+j-i);
            } else {
                return "";
            }
        }
        
        /**
         * Format tooltip string by replacing some white spaces by
         * return characters so that line width doesn't exceed n.
         * Limitation : long words exceeding n are not cut.
         */
        std::string formatTooltip(int n, const std::string& tt)
        {
            std::string ss = tt;  // ss string we are going to format
            int lws = 0;          // last white space encountered
            int lri = 0;          // last return inserted
            for (int i = 0; i < (int)tt.size(); i++) {
                if (tt[i] == ' ') lws = i;
                if (((i-lri) >= n) && (lws > lri)) {
                    // insert return here
                    ss[lws] = '\n';
                    lri = lws;
                }
            }
            return ss;
        }
        
    public:
        
        virtual ~MetaDataUI()
        {}
        
        enum Scale {
            kLin,
            kLog,
            kExp
        };
        
        Scale getScale(FAUSTFLOAT* zone)
        {
            if (fLogSet.count(zone) > 0) return kLog;
            if (fExpSet.count(zone) > 0) return kExp;
            return kLin;
        }
        
        bool isKnob(FAUSTFLOAT* zone)
        {
            return fKnobSet.count(zone) > 0;
        }
        
        bool isRadio(FAUSTFLOAT* zone)
        {
            return fRadioDescription.count(zone) > 0;
        }
        
        bool isMenu(FAUSTFLOAT* zone)
        {
            return fMenuDescription.count(zone) > 0;
        }
        
        bool isLed(FAUSTFLOAT* zone)
        {
            return fLedSet.count(zone) > 0;
        }
        
        bool isNumerical(FAUSTFLOAT* zone)
        {
            return fNumSet.count(zone) > 0;
        }
        
        bool isHidden(FAUSTFLOAT* zone)
        {
            return fHiddenSet.count(zone) > 0;
        }
        
        /**
         * Extracts metadata from a label : 'vol [unit: dB]' -> 'vol' + metadata(unit=dB)
         */
        static void extractMetadata(const std::string& fulllabel, std::string& label, std::map<std::string, std::string>& metadata)
        {
            enum {kLabel, kEscape1, kEscape2, kEscape3, kKey, kValue};
            int state = kLabel; int deep = 0;
            std::string key, value;
            
            for (unsigned int i = 0; i < fulllabel.size(); i++) {
                char c = fulllabel[i];
                switch (state) {
                    case kLabel :
                        assert(deep == 0);
                        switch (c) {
                            case '\\' : state = kEscape1; break;
                            case '[' : state = kKey; deep++; break;
                            default : label += c;
                        }
                        break;
                        
                    case kEscape1:
                        label += c;
                        state = kLabel;
                        break;
                        
                    case kEscape2:
                        key += c;
                        state = kKey;
                        break;
                        
                    case kEscape3:
                        value += c;
                        state = kValue;
                        break;
                        
                    case kKey:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape2;
                                break;
                                
                            case '[':
                                deep++;
                                key += c;
                                break;
                                
                            case ':':
                                if (deep == 1) {
                                    state = kValue;
                                } else {
                                    key += c;
                                }
                                break;
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = "";
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    key += c;
                                }
                                break;
                            default : key += c;
                        }
                        break;
                        
                    case kValue:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape3;
                                break;
                                
                            case '[':
                                deep++;
                                value += c;
                                break;
                                
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = rmWhiteSpaces(value);
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    value += c;
                                }
                                break;
                            default : value += c;
                        }
                        break;
                        
                    default:
                        fprintf(stderr, "ERROR unrecognized state %d\n", state);
                }
            }
            label = rmWhiteSpaces(label);
        }
        
        /**
         * Analyses the widget zone metadata declarations and takes appropriate actions.
         */
        void declare(FAUSTFLOAT* zone, const char* key, const char* value)
        {
            if (zone == 0) {
                // special zone 0 means group metadata
                if (strcmp(key, "tooltip") == 0) {
                    // only group tooltip are currently implemented
                    fGroupTooltip = formatTooltip(30, value);
                } else if (strcmp(key, "hidden") == 0) {
                    fHiddenSet.insert(zone);
                }
            } else {
                if (strcmp(key, "size") == 0) {
                    fGuiSize[zone] = atof(value);
                }
                else if (strcmp(key, "tooltip") == 0) {
                    fTooltip[zone] = formatTooltip(30, value);
                }
                else if (strcmp(key, "unit") == 0) {
                    fUnit[zone] = value;
                }
                else if (strcmp(key, "hidden") == 0) {
                    fHiddenSet.insert(zone);
                }
                else if (strcmp(key, "scale") == 0) {
                    if (strcmp(value, "log") == 0) {
                        fLogSet.insert(zone);
                    } else if (strcmp(value, "exp") == 0) {
                        fExpSet.insert(zone);
                    }
                }
                else if (strcmp(key, "style") == 0) {
                    if (strcmp(value, "knob") == 0) {
                        fKnobSet.insert(zone);
                    } else if (strcmp(value, "led") == 0) {
                        fLedSet.insert(zone);
                    } else if (strcmp(value, "numerical") == 0) {
                        fNumSet.insert(zone);
                    } else {
                        const char* p = value;
                        if (parseWord(p, "radio")) {
                            fRadioDescription[zone] = std::string(p);
                        } else if (parseWord(p, "menu")) {
                            fMenuDescription[zone] = std::string(p);
                        }
                    }
                }
            }
        }
    
};

#endif
/**************************  END  MetaDataUI.h **************************/
/************************** BEGIN ring-buffer.h **************************/
/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
# pragma warning (disable: 4334)
#else
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

static ringbuffer_t *ringbuffer_create(size_t sz);
static void ringbuffer_free(ringbuffer_t *rb);
static void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
static void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
static size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
static size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
static void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_read_space(const ringbuffer_t *rb);
static int ringbuffer_mlock(ringbuffer_t *rb);
static void ringbuffer_reset(ringbuffer_t *rb);
static void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
static size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
static void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

static ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

static void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

static int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

static size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

static size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

static size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

static void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

static void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__
/**************************  END  ring-buffer.h **************************/

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
class GUI;
struct clist;

typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

/**
 * Base class for uiTypedItem: memory zones that can be grouped and synchronized, using an internal cache.
 */
struct uiItemBase
{
    
    uiItemBase(GUI* ui, FAUSTFLOAT* zone)
    {
        assert(ui);
        assert(zone);
    }
    
    virtual ~uiItemBase()
    {}
    
    /**
     * This method will be called when the value changes externally,
     * and will signal the new value to all linked uItem
     * when the value is different from the cached one.
     *
     * @param v - the new value
     */
    virtual void modifyZone(FAUSTFLOAT v) = 0;
    
    /**
     * This method will be called when the value changes externally,
     * and will signal the new value to all linked uItem
     * when the value is different from the cached one.
     *
     * @param date - the timestamp of the received value in usec
     * @param v - the new value
     */
    virtual void modifyZone(double date, FAUSTFLOAT v) {}
    
    /**
     * This method is called by the synchronisation mecanism and is expected
     * to 'reflect' the new value, by changing the Widget layout for instance,
     * or sending a message (OSC, MIDI...)
     */
    virtual void reflectZone() = 0;
    
    /**
     * Return the cached value.
     *
     * @return - the cached value
     */
    virtual double cache() = 0;
    
};

// Declared as 'static' to avoid code duplication at link time
static void deleteClist(clist* cl);

/**
 * A list containing all groupe uiItemBase objects.
 */
struct clist : public std::list<uiItemBase*>
{
    
    virtual ~clist()
    {
        deleteClist(this);
    }
        
};

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data);

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
    
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            for (const auto& it : fZoneMap) {
                delete it.second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItemBase* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }
    
        void updateZone(FAUSTFLOAT* z)
        {
            FAUSTFLOAT v = *z;
            clist* cl = fZoneMap[z];
            for (const auto& c : *cl) {
                if (c->cache() != v) c->reflectZone();
            }
        }
    
        void updateAllZones()
        {
            for (const auto& m : fZoneMap) {
                updateZone(m.first);
            }
        }
    
        static void updateAllGuis()
        {
            for (const auto& g : fGuiList) {
                g->updateAllZones();
            }
        }
    
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data)
        {
            createUiCallbackItem(this, zone, foo, data);
        }

        // Start event or message processing
        virtual bool run() { return false; };
        // Stop event or message processing
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition.
 */
template <typename REAL>
class uiTypedItemReal : public uiItemBase
{
    protected:
        
        GUI* fGUI;
        REAL* fZone;
        REAL fCache;
        
        uiTypedItemReal(GUI* ui, REAL* zone):uiItemBase(ui, static_cast<FAUSTFLOAT*>(zone)),
        fGUI(ui), fZone(zone), fCache(REAL(-123456.654321))
        {
            ui->registerZone(zone, this);
        }
        
    public:
        
        virtual ~uiTypedItemReal()
        {}
    
        void modifyZone(REAL v)
        {
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
    
        double cache() { return fCache; }
    
};

class uiItem : public uiTypedItemReal<FAUSTFLOAT> {
    
    protected:
    
        uiItem(GUI* ui, FAUSTFLOAT* zone):uiTypedItemReal<FAUSTFLOAT>(ui, zone)
        {}

    public:

        virtual ~uiItem() 
        {}

		void modifyZone(FAUSTFLOAT v)
		{
			fCache = v;
			if (*fZone != v) {
				*fZone = v;
				fGUI->updateZone(fZone);
			}
		}

};

/**
 * Base class for items with a value converter.
 */
struct uiConverter {
    
    ValueConverter* fConverter;
    
    uiConverter(MetaDataUI::Scale scale, FAUSTFLOAT umin, FAUSTFLOAT umax, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        // Select appropriate converter according to scale mode
        if (scale == MetaDataUI::kLog) {
            fConverter = new LogValueConverter(umin, umax, fmin, fmax);
        } else if (scale == MetaDataUI::kExp) {
            fConverter = new ExpValueConverter(umin, umax, fmin, fmax);
        } else {
            fConverter = new LinearValueConverter(umin, umax, fmin, fmax);
        }
    }
    
    virtual ~uiConverter()
    {
        delete fConverter;
    }
};

/**
 * User Interface item owned (and so deleted) by external code.
 */
class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item.
 */
class uiCallbackItem : public uiItem {
    
    protected:
    
        uiCallback fCallback;
        void* fData;
    
    public:
    
        uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
        : uiItem(ui, zone), fCallback(foo), fData(data) {}
        
        virtual void reflectZone() 
        {		
            FAUSTFLOAT v = *fZone;
            fCache = v; 
            fCallback(v, fData);	
        }
};

/**
 *  For timestamped control.
 */
struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

/**
 * Base class for timed items.
 */
class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
    
        using uiItem::modifyZone;
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                fprintf(stderr, "ringbuffer_write error DatedControl\n");
            }
        }
    
};

/**
 * Allows to group a set of zones.
 */
class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            for (const auto& it : fZoneMap) {
                *it = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

// Cannot be defined as method in the classes.

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
{
    new uiCallbackItem(ui, zone, foo, data);
}

static void deleteClist(clist* cl)
{
    for (const auto& it : *cl) {
        // This specific code is only used in JUCE context. TODO: use proper 'shared_ptr' based memory management.
    #if defined(JUCE_32BIT) || defined(JUCE_64BIT)
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(it);
        // owned items are deleted by external code
        if (!owned) {
            delete it;
        }
    #else
        delete it;
    #endif
    }
}

#endif
/**************************  END  GUI.h **************************/
/************************** BEGIN JSONUI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>


/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 *
 * Since 'shortname' can only be computed when all paths have been created,
 * the fAllUI vector is progressively filled with partially built UI items,
 * which are finally created in the JSON(...) method.
 ******************************************************************************/

typedef std::vector<std::tuple<std::string, int, int, int, int, int>> MemoryLayoutType;
typedef std::map<std::string, int> PathTableType;

template <typename REAL>
class FAUST_API JSONUIReal : public PathBuilder, public Meta, public UIReal<REAL> {

    protected:
    
        std::stringstream fUI;
        std::vector<std::string> fAllUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;           // Compiler version
        std::string fCompileOptions;    // Compilation options
        std::vector<std::string> fLibraryList;
        std::vector<std::string> fIncludePathnames;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fJSON;
        int fDSPSize;                   // In bytes
        PathTableType fPathTable;
        MemoryLayoutType fMemoryLayout;
        bool fExtended;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs, fSRIndex;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        std::string flatten(const std::string& src)
        {
            std::string dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    default:
                        dst += src[i];
                        break;
                }
            }
            return dst;
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        int getAddressIndex(const std::string& path)
        {
            return (fPathTable.find(path) != fPathTable.end()) ? fPathTable[path] : -1;
        }
      
     public:
     
        JSONUIReal(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const PathTableType& path_table,
                  MemoryLayoutType memory_layout)
        {
            init(name, filename, inputs, outputs, sr_index, sha_key, dsp_code, version, compile_options, library_list, include_pathnames, size, path_table, memory_layout);
        }

        JSONUIReal(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }

        JSONUIReal(int inputs, int outputs)
        {
            init("", "", inputs, outputs, -1, "", "","", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }
        
        JSONUIReal()
        {
            init("", "", -1, -1, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }
 
        virtual ~JSONUIReal() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        void setSRIndex(int sr_index) { fSRIndex = sr_index; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const PathTableType& path_table,
                  MemoryLayoutType memory_layout,
                  bool extended = false)
        {
            fTab = 1;
            fExtended = extended;
            if (fExtended) {
                fUI << std::setprecision(std::numeric_limits<REAL>::max_digits10);
                fMeta << std::setprecision(std::numeric_limits<REAL>::max_digits10);
            }
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fSRIndex = sr_index;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fCompileOptions = compile_options;
            fLibraryList = library_list;
            fIncludePathnames = include_pathnames;
            fMemoryLayout = memory_layout;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            pushLabel(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
            }
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
        
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
        
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab, false);
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
         
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
        
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"init\": " << init << ",";
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max << ",";
            tab(fTab, fUI); fUI << "\"step\": " << step;
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
         
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
            
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max;
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fPathTable.size() > 0) ? "," : "");
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path);
            }
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            if (fJSON.empty()) {
                fTab = 0;
                std::stringstream JSON;
                if (fExtended) {
                    JSON << std::setprecision(std::numeric_limits<REAL>::max_digits10);
                }
                JSON << "{";
                fTab += 1;
                tab(fTab, JSON); JSON << "\"name\": \"" << fName << "\",";
                tab(fTab, JSON); JSON << "\"filename\": \"" << fFileName << "\",";
                if (fVersion != "") { tab(fTab, JSON); JSON << "\"version\": \"" << fVersion << "\","; }
                if (fCompileOptions != "") { tab(fTab, JSON); JSON << "\"compile_options\": \"" <<  fCompileOptions << "\","; }
                if (fLibraryList.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"library_list\": [";
                    for (size_t i = 0; i < fLibraryList.size(); i++) {
                        JSON << "\"" << fLibraryList[i] << "\"";
                        if (i < (fLibraryList.size() - 1)) JSON << ",";
                    }
                    JSON << "],";
                }
                if (fIncludePathnames.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"include_pathnames\": [";
                    for (size_t i = 0; i < fIncludePathnames.size(); i++) {
                        JSON << "\"" << fIncludePathnames[i] << "\"";
                        if (i < (fIncludePathnames.size() - 1)) JSON << ",";
                    }
                    JSON << "],";
                }
                if (fMemoryLayout.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"memory_layout\": [";
                    for (size_t i = 0; i < fMemoryLayout.size(); i++) {
                        // DSP or field name, type, size, sizeBytes, reads, writes
                        std::tuple<std::string, int, int, int, int, int> item = fMemoryLayout[i];
                        tab(fTab + 1, JSON);
                        JSON << "{\"size\": " << std::get<3>(item) << ", ";
                        JSON << "\"reads\": " << std::get<4>(item) << ", ";
                        JSON << "\"writes\": " << std::get<5>(item) << "}";
                        if (i < (fMemoryLayout.size() - 1)) JSON << ",";
                    }
                    tab(fTab, JSON);
                    JSON << "],";
                }
                if (fDSPSize != -1) { tab(fTab, JSON); JSON << "\"size\": " << fDSPSize << ","; }
                if (fSHAKey != "") { tab(fTab, JSON); JSON << "\"sha_key\": \"" << fSHAKey << "\","; }
                if (fExpandedCode != "") { tab(fTab, JSON); JSON << "\"code\": \"" << fExpandedCode << "\","; }
                tab(fTab, JSON); JSON << "\"inputs\": " << fInputs << ",";
                tab(fTab, JSON); JSON << "\"outputs\": " << fOutputs << ",";
                if (fSRIndex != -1) { tab(fTab, JSON); JSON << "\"sr_index\": " << fSRIndex << ","; }
                tab(fTab, fMeta); fMeta << "],";
              
                // Add last UI section
                fAllUI.push_back(fUI.str());
                // Finalize UI generation
                fUI.str("");
                // Add N-1 sections
                for (size_t i = 0; i < fAllUI.size()-1; i++) {
                    fUI << fAllUI[i] << fFull2Short[fFullPaths[i]] << "\",";
                }
                // And the last one
                fUI << fAllUI[fAllUI.size()-1];
                // Terminates the UI section
                tab(fTab, fUI); fUI << "]";
            
                fTab -= 1;
                if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                    JSON << fMeta.str() << fUI.str();
                } else {
                    JSON << fUI.str();
                }
                
                tab(fTab, JSON); JSON << "}";
                
                // Keep result in fJSON
                fJSON = JSON.str();
            }
            return (flat) ? flatten(fJSON) : fJSON;
        }
    
};

// Externally available class using FAUSTFLOAT

struct FAUST_API JSONUI : public JSONUIReal<FAUSTFLOAT>, public UI {
    
    JSONUI(const std::string& name,
           const std::string& filename,
           int inputs,
           int outputs,
           int sr_index,
           const std::string& sha_key,
           const std::string& dsp_code,
           const std::string& version,
           const std::string& compile_options,
           const std::vector<std::string>& library_list,
           const std::vector<std::string>& include_pathnames,
           int size,
           const PathTableType& path_table,
           MemoryLayoutType memory_layout):
    JSONUIReal<FAUSTFLOAT>(name, filename,
                          inputs, outputs,
                          sr_index,
                          sha_key, dsp_code,
                          version, compile_options,
                          library_list, include_pathnames,
                          size, path_table, memory_layout)
    {}
    
    JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
    JSONUIReal<FAUSTFLOAT>(name, filename, inputs, outputs)
    {}
    
    JSONUI(int inputs, int outputs):JSONUIReal<FAUSTFLOAT>(inputs, outputs)
    {}
    
    JSONUI():JSONUIReal<FAUSTFLOAT>()
    {}

    virtual void openTabBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openTabBox(label);
    }
    virtual void openHorizontalBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openHorizontalBox(label);
    }
    virtual void openVerticalBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openVerticalBox(label);
    }
    virtual void closeBox()
    {
        JSONUIReal<FAUSTFLOAT>::closeBox();
    }
    
    // -- active widgets
    
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    {
        JSONUIReal<FAUSTFLOAT>::addButton(label, zone);
    }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        JSONUIReal<FAUSTFLOAT>::addCheckButton(label, zone);
    }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addVerticalSlider(label, zone, init, min, max, step);
    }
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addHorizontalSlider(label, zone, init, min, max, step);
    }
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addNumEntry(label, zone, init, min, max, step);
    }
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        JSONUIReal<FAUSTFLOAT>::addHorizontalBargraph(label, zone, min, max);
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        JSONUIReal<FAUSTFLOAT>::addVerticalBargraph(label, zone, min, max);
    }
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone)
    {
        JSONUIReal<FAUSTFLOAT>::addSoundfile(label, filename, sf_zone);
    }
    
    // -- metadata declarations
    
    virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
    {
        JSONUIReal<FAUSTFLOAT>::declare(zone, key, val);
    }

    virtual void declare(const char* key, const char* val)
    {
        JSONUIReal<FAUSTFLOAT>::declare(key, val);
    }

    virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/**************************  END  JSONUI.h **************************/
/************************** BEGIN midi.h *******************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <assert.h>


class FAUST_API MapUI;

/**
 * A timestamped short MIDI message used with SOUL.
 */

// Force contiguous memory layout
#pragma pack (push, 1)
struct MIDIMessage
{
    uint32_t frameIndex;
    uint8_t byte0, byte1, byte2;
};
#pragma pack (pop)

/**
 * For timestamped MIDI messages (in usec).
 */
struct DatedMessage {
    
    double fDate;
    unsigned char fBuffer[3];
    size_t fSize;
    
    DatedMessage(double date, unsigned char* buffer, size_t size)
    :fDate(date), fSize(size)
    {
        assert(size <= 3);
        memcpy(fBuffer, buffer, size);
    }
    
    DatedMessage():fDate(0.0), fSize(0)
    {}
    
};

/**
 * MIDI processor definition.
 *
 * MIDI input or output handling classes will implement this interface,
 * so the same method names (keyOn, keyOff, ctrlChange...) will be used either
 * when decoding MIDI input or encoding MIDI output events.
 * MIDI channel is numbered in [0..15] in this layer.
 */
class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 0)
        {
            keyOff(channel, pitch, velocity);
        }
    
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
    
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
    
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }
    
        virtual void rpn(double, int channel, int ctrl, int value)
        {
            rpn(channel, ctrl, value);
        }

        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
    
        virtual void sysEx(double, std::vector<unsigned char>& message)
        {
            sysEx(message);
        }

        // MIDI sync
        virtual void startSync(double date)  {}
        virtual void stopSync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return nullptr; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void rpn(int channel, int ctrl, int value)              {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}
        virtual void sysEx(std::vector<unsigned char>& message)         {}

        enum MidiStatus {
            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_CONT = 0xFB,
            MIDI_STOP = 0xFC,
            MIDI_SYSEX_START = 0xF0,
            MIDI_SYSEX_STOP = 0xF7
        };

        enum MidiCtrl {
            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120
        };
    
        enum MidiNPN {
            PITCH_BEND_RANGE = 0
        };

};

/**
 * A class to decode NRPN and RPN messages, adapted from JUCE forum message:
 * https://forum.juce.com/t/14bit-midi-controller-support/11517
 */
class MidiNRPN {
    
    private:
    
        bool ctrlnew;
        int ctrlnum;
        int ctrlval;
        
        int nrpn_lsb, nrpn_msb;
        int data_lsb, data_msb;
        
        enum
        {
            midi_nrpn_lsb = 98,
            midi_nrpn_msb = 99,
            midi_rpn_lsb  = 100,
            midi_rpn_msb  = 101,
            midi_data_lsb = 38,
            midi_data_msb = 6
        };
    
    public:
        
        MidiNRPN(): ctrlnew(false), nrpn_lsb(-1), nrpn_msb(-1), data_lsb(-1), data_msb(-1)
        {}
        
        // return true if the message has been filtered
        bool process(int data1, int data2)
        {
            switch (data1)
            {
                case midi_nrpn_lsb: nrpn_lsb = data2; return true;
                case midi_nrpn_msb: nrpn_msb = data2; return true;
                case midi_rpn_lsb: {
                    if (data2 == 127) {
                        nrpn_lsb = data_lsb = -1;
                    } else {
                        nrpn_lsb = 0;
                        data_lsb = -1;
                    }
                    return true;
                }
                case midi_rpn_msb: {
                    if (data2 == 127) {
                        nrpn_msb = data_msb = -1;
                    } else {
                        nrpn_msb = 0;
                        data_msb = -1;
                    }
                    return true;
                }
                case midi_data_lsb:
                case midi_data_msb:
                {
                    if (data1 == midi_data_msb) {
                        if (nrpn_msb < 0) {
                            return false;
                        }
                        data_msb = data2;
                    } else { // midi_data_lsb
                        if (nrpn_lsb < 0) {
                            return false;
                        }
                        data_lsb = data2;
                    }
                    if (data_lsb >= 0 && data_msb >= 0) {
                        ctrlnum = (nrpn_msb << 7) | nrpn_lsb;
                        ctrlval = (data_msb << 7) | data_lsb;
                        data_lsb = data_msb = -1;
                        nrpn_msb = nrpn_lsb = -1;
                        ctrlnew = true;
                    }
                    return true;
                }
                default: return false;
            };
        }
        
        bool hasNewNRPN() { bool res = ctrlnew; ctrlnew = false; return res; }
        
        // results in [0, 16383]
        int getCtrl() const { return ctrlnum; }
        int getVal() const { return ctrlval; }
    
};

/**
 * A pure interface for MIDI handlers that can send/receive MIDI messages to/from 'midi' objects.
 */
struct midi_interface {
    virtual void addMidiIn(midi* midi_dsp)      = 0;
    virtual void removeMidiIn(midi* midi_dsp)   = 0;
    virtual ~midi_interface() {}
};

/****************************************************
 * Base class for MIDI input handling.
 *
 * Shared common code used for input handling:
 * - decoding Real-Time messages: handleSync
 * - decoding one data byte messages: handleData1
 * - decoding two data byte messages: handleData2
 * - getting ready messages in polling mode
 ****************************************************/
class midi_handler : public midi, public midi_interface {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;
        MidiNRPN fNRPN;
    
        int range(int min, int max, int val) { return (val < min) ? min : ((val >= max) ? max : val); }
  
    public:

        midi_handler(const std::string& name = "MIDIHandler"):midi_interface(), fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        // Those 2 methods have to be implemented by subclasses
        virtual bool startMidi() { return true; }
        virtual void stopMidi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
    
        // To be used in polling mode
        virtual int recvMessages(std::vector<MIDIMessage>* message) { return 0; }
        virtual void sendMessages(std::vector<MIDIMessage>* message, int count) {}
    
        // MIDI Real-Time
        void handleClock(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->clock(time);
            }
        }
        
        void handleStart(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->startSync(time);
            }
        }
        
        void handleStop(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->stopSync(time);
            }
        }
    
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                handleClock(time);
            // We can consider start and continue as identical messages
            } else if ((type == MIDI_START) || (type == MIDI_CONT)) {
                handleStart(time);
            } else if (type == MIDI_STOP) {
                handleStop(time);
            }
        }
    
        // MIDI 1 data
        void handleProgChange(double time, int channel, int data1)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->progChange(time, channel, data1);
            }
        }
    
        void handleAfterTouch(double time, int channel, int data1)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->chanPress(time, channel, data1);
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                handleProgChange(time, channel, data1);
            } else if (type == MIDI_AFTERTOUCH) {
                handleAfterTouch(time, channel, data1);
            }
        }
    
        // MIDI 2 datas
        void handleKeyOff(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->keyOff(time, channel, data1, data2);
            }
        }
        
        void handleKeyOn(double time, int channel, int data1, int data2)
        {
            if (data2 == 0) {
                handleKeyOff(time, channel, data1, data2);
            } else {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            }
        }
    
        void handleCtrlChange(double time, int channel, int data1, int data2)
        {
            // Special processing for NRPN and RPN
            if (fNRPN.process(data1, data2)) {
                if (fNRPN.hasNewNRPN()) {
                    for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                        fMidiInputs[i]->rpn(time, channel, fNRPN.getCtrl(), fNRPN.getVal());
                    }
                }
            } else {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            }
        }
        
        void handlePitchWheel(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->pitchWheel(time, channel, (data2 << 7) + data1);
            }
        }
    
        void handlePitchWheel(double time, int channel, int bend)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->pitchWheel(time, channel, bend);
            }
        }
        
        void handlePolyAfterTouch(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->keyPress(time, channel, data1, data2);
            }
        }
  
        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF) {
                handleKeyOff(time, channel,  data1, data2);
            } else if (type == MIDI_NOTE_ON) {
                handleKeyOn(time, channel, data1, data2);
            } else if (type == MIDI_CONTROL_CHANGE) {
                handleCtrlChange(time, channel, data1, data2);
            } else if (type == MIDI_PITCH_BEND) {
                handlePitchWheel(time, channel, data1, data2);
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                handlePolyAfterTouch(time, channel, data1, data2);
            }
        }
    
        // SysEx
        void handleSysex(double time, std::vector<unsigned char>& message)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->sysEx(time, message);
            }
        }
    
        void handleMessage(double time, int type, std::vector<unsigned char>& message)
        {
            if (type == MIDI_SYSEX_START) {
                handleSysex(time, message);
            }
        }
  
};

#endif // __midi__
/**************************  END  midi.h **************************/

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/**
 * Helper code for MIDI meta and polyphonic 'nvoices' parsing.
 */
struct MidiMeta : public Meta, public std::map<std::string, std::string> {
    
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        return (this->find(key) != this->end()) ? (*this)[key] : def;
    }
    
    static void analyse(base_dsp* mono_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        mono_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos) ||
                      (json.find("timestamp") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        mono_dsp->metadata(&meta);
        bool found_voices = false;
        // If "options" metadata is used
        std::string options = meta.get("options", "");
        if (options != "") {
            std::map<std::string, std::string> metadata;
            std::string res;
            MetaDataUI::extractMetadata(options, res, metadata);
            if (metadata.find("nvoices") != metadata.end()) {
                nvoices = std::atoi(metadata["nvoices"].c_str());
                found_voices = true;
            }
        }
        // Otherwise test for "nvoices" metadata
        if (!found_voices) {
            std::string numVoices = meta.get("nvoices", "0");
            nvoices = std::atoi(numVoices.c_str());
        }
        nvoices = std::max<int>(0, nvoices);
    #endif
    }
    
    static bool checkPolyphony(base_dsp* mono_dsp)
    {
        MapUI map_ui;
        mono_dsp->buildUserInterface(&map_ui);
        bool has_freq = false;
        bool has_gate = false;
        bool has_gain = false;
        for (int i = 0; i < map_ui.getParamsCount(); i++) {
            std::string path = map_ui.getParamAddress(i);
            has_freq |= MapUI::endsWith(path, "/freq");
            has_freq |= MapUI::endsWith(path, "/key");
            has_gate |= MapUI::endsWith(path, "/gate");
            has_gain |= MapUI::endsWith(path, "/gain");
            has_gain |= MapUI::endsWith(path, "/vel");
            has_gain |= MapUI::endsWith(path, "/velocity");
        }
        return (has_freq && has_gate && has_gain);
    }
    
};

/**
 * uiMidi : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrlChange, keyOn/keyOff, keyPress, progChange, chanPress, pitchWheel/pitchBend
 * start/stop/clock meta data is handled.
 * MIDI channel is numbered in [1..16] in this layer.
 * Channel 0 means "all channels" when receiving or sending.
 */
class uiMidi {
    
    friend class MidiUI;
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        int fChan;
    
        bool inRange(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT v) { return (min <= v && v <= max); }
    
    public:
        
        uiMidi(midi* midi_out, bool input, int chan = 0):fMidiOut(midi_out), fInputCtrl(input), fChan(chan)
        {}
        virtual ~uiMidi()
        {}

};

/**
 * Base class for MIDI aware UI items.
 */
class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true, int chan = 0)
            :uiMidi(midi_out, input, chan), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

/**
 * Base class for MIDI aware UI items with timestamp support.
 */
class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true, int chan = 0)
            :uiMidi(midi_out, input, chan), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

/**
 * MIDI sync.
 */
class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->startSync(0);
            }
        }
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem {
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stopSync(0);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
};

class uiMidiClock : public uiMidiTimedItem {

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }

};

/**
 * Standard MIDI events.
 */

/**
 * uiMidiProgChange uses the [min...max] range.
 */
class uiMidiProgChange : public uiMidiTimedItem {
    
    public:
    
        FAUSTFLOAT fMin, fMax;
    
        uiMidiProgChange(midi* midi_out, GUI* ui, FAUSTFLOAT* zone,
                         FAUSTFLOAT min, FAUSTFLOAT max,
                         bool input = true, int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), fMin(min), fMax(max)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (inRange(fMin, fMax, v)) {
                if (fChan == 0) {
                    // Send on [0..15] channels on the MIDI layer
                    for (int chan = 0; chan < 16; chan++) {
                        fMidiOut->progChange(chan, v);
                    }
                } else {
                    fMidiOut->progChange(fChan - 1, v);
                }
            }
        }
    
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl && inRange(fMin, fMax, v)) {
                uiItem::modifyZone(v);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl && inRange(fMin, fMax, v)) {
                uiMidiTimedItem::modifyZone(date, v);
            }
        }
        
};

/**
 * uiMidiChanPress.
 */
class uiMidiChanPress : public uiMidiTimedItem, public uiConverter {
    
    public:
    
        uiMidiChanPress(midi* midi_out, GUI* ui,
                        FAUSTFLOAT* zone,
                        FAUSTFLOAT min, FAUSTFLOAT max,
                        bool input = true,
                        MetaDataUI::Scale scale = MetaDataUI::kLin,
                        int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->chanPress(chan, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->chanPress(fChan - 1, fConverter->faust2ui(v));
            }
        }
    
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
        
};

/**
 * uiMidiCtrlChange does scale (kLin/kLog/kExp) mapping.
 */
class uiMidiCtrlChange : public uiMidiTimedItem, public uiConverter {
    
    private:
    
        int fCtrl;
 
    public:

        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui,
                     FAUSTFLOAT* zone,
                     FAUSTFLOAT min, FAUSTFLOAT max,
                     bool input = true,
                     MetaDataUI::Scale scale = MetaDataUI::kLin,
                     int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fCtrl(ctrl)
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->ctrlChange(chan, fCtrl, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->ctrlChange(fChan - 1, fCtrl, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
};

class uiMidiPitchWheel : public uiMidiTimedItem {

    private:
    
        LinearValueConverter2 fConverter;
    
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone,
                         FAUSTFLOAT min, FAUSTFLOAT max,
                         bool input = true, int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan)
        {
            if (min <= 0 && max >= 0) {
                fConverter = LinearValueConverter2(0., 8191., 16383., double(min), 0., double(max));
            } else {
                // Degenerated case...
                fConverter = LinearValueConverter2(0., 8191., 16383., double(min),double(min + (max - min)/FAUSTFLOAT(2)), double(max));
            }
        }
    
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->pitchWheel(chan, fConverter.faust2ui(v));
                }
            } else {
                fMidiOut->pitchWheel(fChan - 1, fConverter.faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void setRange(int val)
        {
            double semi = (val / 128) + ((val % 128) / 100.);
            fConverter.setMappingValues(0., 8191., 16383., -semi, 0., semi);
        }
 
};

/**
 * uiMidiKeyOn does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyOn : public uiMidiTimedItem, public uiConverter {

    private:
        
        int fKeyOn;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui,
                    FAUSTFLOAT* zone,
                    FAUSTFLOAT min, FAUSTFLOAT max,
                    bool input = true,
                    MetaDataUI::Scale scale = MetaDataUI::kLin,
                    int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKeyOn(key)
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKeyOn, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKeyOn, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/**
 * uiMidiKeyOff does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyOff : public uiMidiTimedItem, public uiConverter {

    private:
        
        int fKeyOff;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui,
                     FAUSTFLOAT* zone,
                     FAUSTFLOAT min, FAUSTFLOAT max,
                     bool input = true,
                     MetaDataUI::Scale scale = MetaDataUI::kLin,
                     int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKeyOff(key)
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKeyOff, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKeyOff, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/**
 * uiMidiKeyPress does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyPress : public uiMidiTimedItem, public uiConverter {

    private:
    
        int fKey;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui,
                       FAUSTFLOAT* zone,
                       FAUSTFLOAT min, FAUSTFLOAT max,
                       bool input = true,
                       MetaDataUI::Scale scale = MetaDataUI::kLin,
                       int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKey(key)
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKey, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKey, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/******************************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI metadata and maps incoming MIDI messages to them.
 * Currently ctrlChange, keyOn/keyOff, keyPress, progChange, chanPress, pitchWheel/pitchBend
 * start/stop/clock meta data are handled.
 *
 * Maps associating MIDI event ID (like each ctrl number) with all MIDI aware UI items
 * are defined and progressively filled when decoding MIDI related metadata.
 * MIDI aware UI items are used in both directions:
 *  - modifying their internal state when receving MIDI input events
 *  - sending their internal state as MIDI output events
 *******************************************************************************************/

class MidiUI : public GUI, public midi, public midi_interface, public MetaDataUI {

    // Add uiItem subclasses objects are deallocated by the inherited GUI class
    typedef std::map <int, std::vector<uiMidiCtrlChange*> > TCtrlChangeTable;
    typedef std::vector<uiMidiProgChange*>                  TProgChangeTable;
    typedef std::vector<uiMidiChanPress*>                   TChanPressTable;
    typedef std::map <int, std::vector<uiMidiKeyOn*> >      TKeyOnTable;
    typedef std::map <int, std::vector<uiMidiKeyOff*> >     TKeyOffTable;
    typedef std::map <int, std::vector<uiMidiKeyPress*> >   TKeyPressTable;
    typedef std::vector<uiMidiPitchWheel*>                  TPitchWheelTable;
    
    protected:
    
        TCtrlChangeTable fCtrlChangeTable;
        TProgChangeTable fProgChangeTable;
        TChanPressTable  fChanPressTable;
        TKeyOnTable      fKeyOnTable;
        TKeyOffTable     fKeyOffTable;
        TKeyOnTable      fKeyTable;
        TKeyPressTable   fKeyPressTable;
        TPitchWheelTable fPitchWheelTable;
        
        std::vector<uiMidiStart*> fStartTable;
        std::vector<uiMidiStop*>  fStopTable;
        std::vector<uiMidiClock*> fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
        bool fTimeStamp;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    unsigned chan;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u %u", &num, &chan) == 2) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u %u", &num, &chan) == 2) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u %u", &num, &chan) == 2) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u %u", &num, &chan) == 2) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u %u", &num, &chan) == 2) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &chan) == 1) {
                            fProgChangeTable.push_back(new uiMidiProgChange(fMidiHandler, this, zone, min, max, input, chan));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pgm") == 0) {
                            fProgChangeTable.push_back(new uiMidiProgChange(fMidiHandler, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &chan) == 1) {
                            fChanPressTable.push_back(new uiMidiChanPress(fMidiHandler, this, zone, min, max, input, getScale(zone), chan));
                        } else if ((fMetaAux[i].second == "chanpress")) {
                            fChanPressTable.push_back(new uiMidiChanPress(fMidiHandler, this, zone, min, max, input, getScale(zone)));
                        } else if ((gsscanf(fMetaAux[i].second.c_str(), "pitchwheel %u", &chan) == 1) || (gsscanf(fMetaAux[i].second.c_str(), "pitchbend %u", &chan) == 1)) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, min, max, input, chan));
                        } else if ((fMetaAux[i].second == "pitchwheel") || (fMetaAux[i].second == "pitchbend")) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, min, max, input));
                        // MIDI sync
                        } else if (fMetaAux[i].second == "start") {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "stop") {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "clock") {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        // Explicit metadata to activate 'timestamp' mode
                        } else if (fMetaAux[i].second == "timestamp") {
                            fTimeStamp = true;
                        }
                    }
                }
            }
            fMetaAux.clear();
        }
    
        template <typename TABLE>
        void updateTable1(TABLE& table, double date, int channel, int val1)
        {
            for (size_t i = 0; i < table.size(); i++) {
                int channel_aux = table[i]->fChan;
                // channel_aux == 0 means "all channels"
                if (channel_aux == 0 || channel == channel_aux - 1) {
                    if (fTimeStamp) {
                        table[i]->modifyZone(date, FAUSTFLOAT(val1));
                    } else {
                        table[i]->modifyZone(FAUSTFLOAT(val1));
                    }
                }
            }
        }
        
        template <typename TABLE>
        void updateTable2(TABLE& table, double date, int channel, int val1, int val2)
        {
            if (table.find(val1) != table.end()) {
                for (size_t i = 0; i < table[val1].size(); i++) {
                    int channel_aux = table[val1][i]->fChan;
                    // channel_aux == 0 means "all channels"
                    if (channel_aux == 0 || channel == channel_aux - 1) {
                        if (fTimeStamp) {
                            table[val1][i]->modifyZone(date, FAUSTFLOAT(val2));
                        } else {
                            table[val1][i]->modifyZone(FAUSTFLOAT(val2));
                        }
                    }
                }
            }
        }
    
    public:
    
        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            // TODO: use shared_ptr based implementation
            fDelete = delete_handler;
            fTimeStamp = false;
        }
 
        virtual ~MidiUI() 
        {
            // Remove from fMidiHandler
            fMidiHandler->removeMidiIn(this);
            // TODO: use shared_ptr based implementation
            if (fDelete) delete fMidiHandler;
        }
    
        bool run() { return fMidiHandler->startMidi(); }
        void stop() { fMidiHandler->stopMidi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            MetaDataUI::declare(zone, key, val);
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API
    
        void key(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOnTable>(fKeyTable, date, channel, note, velocity);
        }
    
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOnTable>(fKeyOnTable, date, channel, note, velocity);
            // If note is in fKeyTable, handle it as a keyOn
            key(date, channel, note, velocity);
            return nullptr;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOffTable>(fKeyOffTable, date, channel, note, velocity);
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            key(date, channel, note, 0);
        }
        
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            updateTable2<TCtrlChangeTable>(fCtrlChangeTable, date, channel, ctrl, value);
        }
    
        void rpn(double date, int channel, int ctrl, int value)
        {
            if (ctrl == midi::PITCH_BEND_RANGE) {
                for (size_t i = 0; i < fPitchWheelTable.size(); i++) {
                    // channel_aux == 0 means "all channels"
                    int channel_aux = fPitchWheelTable[i]->fChan;
                    if (channel_aux == 0 || channel == channel_aux - 1) {
                        fPitchWheelTable[i]->setRange(value);
                    }
                }
            }
        }
    
        void progChange(double date, int channel, int pgm)
        {
            updateTable1<TProgChangeTable>(fProgChangeTable, date, channel, pgm);
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            updateTable1<TPitchWheelTable>(fPitchWheelTable, date, channel, wheel);
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            updateTable2<TKeyPressTable>(fKeyPressTable, date, channel, pitch, press);
        }
        
        void chanPress(double date, int channel, int press)
        {
            updateTable1<TChanPressTable>(fChanPressTable, date, channel, press);
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void startSync(double date)
        {
            for (size_t i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stopSync(double date)
        {
            for (size_t i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (size_t i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/**************************  END  MidiUI.h **************************/
/************************** BEGIN poly-base_dsp.h *************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*********************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>
#include <assert.h>

/************************** BEGIN base_dsp-combiner.h **************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <string>
#include <assert.h>
#include <sstream>


// Base class and common code for binary combiners

enum Layout { kVerticalGroup, kHorizontalGroup, kTabGroup };

class dsp_binary_combiner : public base_dsp {

    protected:

        base_dsp* fDSP1;
        base_dsp* fDSP2;
        int fBufferSize;
        Layout fLayout;
        std::string fLabel;

        void buildUserInterfaceAux(UI* ui_interface)
        {
            switch (fLayout) {
                case kHorizontalGroup:
                    ui_interface->openHorizontalBox(fLabel.c_str());
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kVerticalGroup:
                    ui_interface->openVerticalBox(fLabel.c_str());
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kTabGroup:
                    ui_interface->openTabBox(fLabel.c_str());
                    ui_interface->openVerticalBox("DSP1");
                    fDSP1->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP2");
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->closeBox();
                    break;
            }
        }

        FAUSTFLOAT** allocateChannels(int num)
        {
            FAUSTFLOAT** channels = new FAUSTFLOAT*[num];
            for (int chan = 0; chan < num; chan++) {
                channels[chan] = new FAUSTFLOAT[fBufferSize];
                memset(channels[chan], 0, sizeof(FAUSTFLOAT) * fBufferSize);
            }
            return channels;
        }

        void deleteChannels(FAUSTFLOAT** channels, int num)
        {
            for (int chan = 0; chan < num; chan++) {
                delete [] channels[chan];
            }
            delete [] channels;
        }

     public:

        dsp_binary_combiner(base_dsp* dsp1, base_dsp* dsp2, int buffer_size, Layout layout, const std::string& label)
        :fDSP1(dsp1), fDSP2(dsp2), fBufferSize(buffer_size), fLayout(layout), fLabel(label)
        {}

        virtual ~dsp_binary_combiner()
        {
            delete fDSP1;
            delete fDSP2;
        }

        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
        virtual void init(int sample_rate)
        {
            fDSP1->init(sample_rate);
            fDSP2->init(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            fDSP1->instanceInit(sample_rate);
            fDSP2->instanceInit(sample_rate);
        }
        virtual void instanceConstants(int sample_rate)
        {
            fDSP1->instanceConstants(sample_rate);
            fDSP2->instanceConstants(sample_rate);
        }

        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }

        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }

};

// Combine two 'compatible' DSP in sequence

class dsp_sequencer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;

    public:

        dsp_sequencer(base_dsp* dsp1, base_dsp* dsp2,
                      int buffer_size = 4096,
                      Layout layout = Layout::kTabGroup,
                      const std::string& label = "Sequencer")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
        }

        virtual ~dsp_sequencer()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);
            fDSP2->compute(count, fDSP1Outputs, outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_parallelizer(base_dsp* dsp1, base_dsp* dsp2,
                     int buffer_size = 4096,
                     Layout layout = Layout::kTabGroup,
                     const std::string& label = "Parallelizer")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fDSP2Outputs = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }

        virtual ~dsp_parallelizer()
        {
            delete [] fDSP2Inputs;
            delete [] fDSP2Outputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);

            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fDSP2Inputs[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fDSP2Outputs[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }

            fDSP2->compute(count, fDSP2Inputs, fDSP2Outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two 'compatible' DSP in splitter

class dsp_splitter : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

    public:

        dsp_splitter(base_dsp* dsp1, base_dsp* dsp2,
                     int buffer_size = 4096,
                     Layout layout = Layout::kTabGroup,
                     const std::string& label = "Splitter")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_splitter()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_splitter(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);

            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                 fDSP2Inputs[chan] = fDSP1Outputs[chan % fDSP1->getNumOutputs()];
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in merger

class dsp_merger : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

        void mix(int count, FAUSTFLOAT* dst, FAUSTFLOAT* src)
        {
            for (int frame = 0; frame < count; frame++) {
                dst[frame] += src[frame];
            }
        }

    public:

        dsp_merger(base_dsp* dsp1, base_dsp* dsp2,
                   int buffer_size = 4096,
                   Layout layout = Layout::kTabGroup,
                   const std::string& label = "Merger")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs());
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_merger()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_merger(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, fDSP1Inputs, fDSP1Outputs);

            memset(fDSP2Inputs, 0, sizeof(FAUSTFLOAT*) * fDSP2->getNumInputs());

            for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                int mchan = chan % fDSP2->getNumInputs();
                if (fDSP2Inputs[mchan]) {
                    mix(count, fDSP2Inputs[mchan], fDSP1Outputs[chan]);
                } else {
                    fDSP2Inputs[mchan] = fDSP1Outputs[chan];
                }
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in a recursive way

class dsp_recursiver : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_recursiver(base_dsp* dsp1, base_dsp* dsp2,
                       Layout layout = Layout::kTabGroup,
                       const std::string& label = "Recursiver")
        :dsp_binary_combiner(dsp1, dsp2, 1, layout, label)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs());
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = allocateChannels(fDSP2->getNumInputs());
            fDSP2Outputs = allocateChannels(fDSP2->getNumOutputs());
        }

        virtual ~dsp_recursiver()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            deleteChannels(fDSP2Inputs, fDSP2->getNumInputs());
            deleteChannels(fDSP2Outputs, fDSP2->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() - fDSP2->getNumOutputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual base_dsp* clone()
        {
            return new dsp_recursiver(fDSP1->clone(), fDSP2->clone(), fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int frame = 0; (frame < count); frame++) {

                for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan][0] = fDSP2Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP1->getNumInputs() - fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan + fDSP2->getNumOutputs()][0] = inputs[chan][frame];
                }

                fDSP1->compute(1, fDSP1Inputs, fDSP1Outputs);

                for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                    outputs[chan][frame] = fDSP1Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                    fDSP2Inputs[chan][0] = fDSP1Outputs[chan][0];
                }

                fDSP2->compute(1, fDSP2Inputs, fDSP2Outputs);
            }
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

/*
 Crossfade between two DSP.
 When fCrossfade = 1, the first DSP only is computed, when fCrossfade = 0,
 the second DSP only is computed, otherwise both DSPs are computed and mixed.
*/

class dsp_crossfader: public dsp_binary_combiner {

    private:
    
        FAUSTFLOAT fCrossfade;
        FAUSTFLOAT** fDSPOutputs1;
        FAUSTFLOAT** fDSPOutputs2;
    
    public:
    
        dsp_crossfader(base_dsp* dsp1, base_dsp* dsp2,
                       Layout layout = Layout::kTabGroup,
                       const std::string& label = "Crossfade")
        :dsp_binary_combiner(dsp1, dsp2, 4096, layout, label),fCrossfade(FAUSTFLOAT(0.5))
        {
            fDSPOutputs1 = allocateChannels(fDSP1->getNumOutputs());
            fDSPOutputs2 = allocateChannels(fDSP1->getNumOutputs());
        }
    
        virtual ~dsp_crossfader()
        {
            deleteChannels(fDSPOutputs1, fDSP1->getNumInputs());
            deleteChannels(fDSPOutputs2, fDSP1->getNumOutputs());
        }
    
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs(); }

        void buildUserInterface(UI* ui_interface)
        {
            switch (fLayout) {
                case kHorizontalGroup:
                    ui_interface->openHorizontalBox(fLabel.c_str());
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kVerticalGroup:
                    ui_interface->openVerticalBox(fLabel.c_str());
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kTabGroup:
                    ui_interface->openTabBox(fLabel.c_str());
                    ui_interface->openVerticalBox("Crossfade");
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP1");
                    fDSP1->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP2");
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->closeBox();
                    break;
            }
        }
    
        virtual base_dsp* clone()
        {
            return new dsp_crossfader(fDSP1->clone(), fDSP2->clone(), fLayout, fLabel);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            if (fCrossfade == FAUSTFLOAT(1)) {
                fDSP1->compute(count, inputs, outputs);
            } else if (fCrossfade == FAUSTFLOAT(0)) {
                fDSP2->compute(count, inputs, outputs);
            } else {
                // Compute each effect
                fDSP1->compute(count, inputs, fDSPOutputs1);
                fDSP2->compute(count, inputs, fDSPOutputs2);
                // Mix between the two effects
                FAUSTFLOAT gain1 = fCrossfade;
                FAUSTFLOAT gain2 = FAUSTFLOAT(1) - gain1;
                for (int frame = 0; (frame < count); frame++) {
                    for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                        outputs[chan][frame] = fDSPOutputs1[chan][frame] * gain1 + fDSPOutputs2[chan][frame] * gain2;
                    }
                }
            }
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#ifndef __dsp_algebra_api__
#define __dsp_algebra_api__

// DSP algebra API
/*
 Each operation takes two DSP and a optional Layout and Label parameters, returns the combined DSPs, or null if failure with an error message.
 */

static base_dsp* createDSPSequencer(base_dsp* dsp1, base_dsp* dsp2,
                               std::string& error,
                               Layout layout = Layout::kTabGroup,
                               const std::string& label = "Sequencer")
{
    if (dsp1->getNumOutputs() != dsp2->getNumInputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_sequencer : the number of outputs ("
                  << dsp1->getNumOutputs() << ") of A "
                  << "must be equal to the number of inputs (" << dsp2->getNumInputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    }
}

static base_dsp* createDSPParallelizer(base_dsp* dsp1, base_dsp* dsp2,
                                  std::string& error,
                                  Layout layout = Layout::kTabGroup,
                                  const std::string& label = "Parallelizer")
{
    return new dsp_parallelizer(dsp1, dsp2, 4096, layout, label);
}

static base_dsp* createDSPSplitter(base_dsp* dsp1, base_dsp* dsp2, std::string& error, Layout layout = Layout::kTabGroup, const std::string& label = "Splitter")
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_splitter : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_splitter : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() % dsp1->getNumOutputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_splitter : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a divisor of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    } else {
        return new dsp_splitter(dsp1, dsp2, 4096, layout, label);
    }
}

static base_dsp* createDSPMerger(base_dsp* dsp1, base_dsp* dsp2,
                            std::string& error,
                            Layout layout = Layout::kTabGroup,
                            const std::string& label = "Merger")
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_merger : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_merger : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp1->getNumOutputs() % dsp2->getNumInputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_merger : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a multiple of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    } else {
        return new dsp_merger(dsp1, dsp2, 4096, layout, label);
    }
}

static base_dsp* createDSPRecursiver(base_dsp* dsp1, base_dsp* dsp2,
                                std::string& error,
                                Layout layout = Layout::kTabGroup,
                                const std::string& label = "Recursiver")
{
    if ((dsp2->getNumInputs() > dsp1->getNumOutputs()) || (dsp2->getNumOutputs() > dsp1->getNumInputs())) {
        std::stringstream error_aux;
        error_aux << "Connection error in : dsp_recursiver" << std::endl;
        if (dsp2->getNumInputs() > dsp1->getNumOutputs()) {
            error_aux << "The number of outputs " << dsp1->getNumOutputs()
                      << " of the first expression should be greater or equal to the number of inputs ("
                      << dsp2->getNumInputs()
                      << ") of the second expression" << std::endl;
        }
        if (dsp2->getNumOutputs() > dsp1->getNumInputs()) {
            error_aux << "The number of inputs " << dsp1->getNumInputs()
                      << " of the first expression should be greater or equal to the number of outputs ("
                      << dsp2->getNumOutputs()
                      << ") of the second expression" << std::endl;
        }
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_recursiver(dsp1, dsp2, layout, label);
    }
}

static base_dsp* createDSPCrossfader(base_dsp* dsp1, base_dsp* dsp2,
                                 std::string& error,
                                 Layout layout = Layout::kTabGroup,
                                 const std::string& label = "Crossfade")
{
    if (dsp1->getNumInputs() != dsp2->getNumInputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_crossfader : the number of inputs ("
        << dsp1->getNumInputs() << ") of A "
        << "must be equal to the number of inputs (" << dsp2->getNumInputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp1->getNumOutputs() != dsp2->getNumOutputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_crossfader : the number of outputs ("
        << dsp1->getNumOutputs() << ") of A "
        << "must be equal to the number of outputs (" << dsp2->getNumOutputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_crossfader(dsp1, dsp2, layout, label);
    }
}

#endif

#endif
/************************** END base_dsp-combiner.h **************************/
/************************** BEGIN proxy-base_dsp.h ***************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
***************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************** BEGIN JSONUIDecoder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <functional>

/************************** BEGIN CGlue.h *****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*************************************************************************/

#ifndef CGLUE_H
#define CGLUE_H

/************************** BEGIN CInterface.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef CINTERFACE_H
#define CINTERFACE_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
struct Soundfile;

/*******************************************************************************
 * UI, Meta and MemoryManager structures for C code.
 ******************************************************************************/

// -- widget's layouts

typedef void (* openTabBoxFun) (void* ui_interface, const char* label);
typedef void (* openHorizontalBoxFun) (void* ui_interface, const char* label);
typedef void (* openVerticalBoxFun) (void* ui_interface, const char* label);
typedef void (* closeBoxFun) (void* ui_interface);

// -- active widgets

typedef void (* addButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addCheckButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addVerticalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addHorizontalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addNumEntryFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);

// -- passive widgets

typedef void (* addHorizontalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);
typedef void (* addVerticalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);

// -- soundfiles
    
typedef void (* addSoundfileFun) (void* ui_interface, const char* label, const char* url, struct Soundfile** sf_zone);

typedef void (* declareFun) (void* ui_interface, FAUSTFLOAT* zone, const char* key, const char* value);

typedef struct {

    void* uiInterface;

    openTabBoxFun openTabBox;
    openHorizontalBoxFun openHorizontalBox;
    openVerticalBoxFun openVerticalBox;
    closeBoxFun closeBox;
    addButtonFun addButton;
    addCheckButtonFun addCheckButton;
    addVerticalSliderFun addVerticalSlider;
    addHorizontalSliderFun addHorizontalSlider;
    addNumEntryFun addNumEntry;
    addHorizontalBargraphFun addHorizontalBargraph;
    addVerticalBargraphFun addVerticalBargraph;
    addSoundfileFun addSoundfile;
    declareFun declare;

} UIGlue;

typedef void (* metaDeclareFun) (void* ui_interface, const char* key, const char* value);

typedef struct {

    void* metaInterface;
    
    metaDeclareFun declare;

} MetaGlue;

/***************************************
 *  Interface for the DSP object
 ***************************************/

typedef char dsp_imp;
    
typedef dsp_imp* (* newDspFun) ();
typedef void (* destroyDspFun) (dsp_imp* base_dsp);
typedef int (* getNumInputsFun) (dsp_imp* base_dsp);
typedef int (* getNumOutputsFun) (dsp_imp* base_dsp);
typedef void (* buildUserInterfaceFun) (dsp_imp* base_dsp, UIGlue* ui);
typedef int (* getSampleRateFun) (dsp_imp* base_dsp);
typedef void (* initFun) (dsp_imp* base_dsp, int sample_rate);
typedef void (* classInitFun) (int sample_rate);
typedef void (* instanceInitFun) (dsp_imp* base_dsp, int sample_rate);
typedef void (* instanceConstantsFun) (dsp_imp* base_dsp, int sample_rate);
typedef void (* instanceResetUserInterfaceFun) (dsp_imp* base_dsp);
typedef void (* instanceClearFun) (dsp_imp* base_dsp);
typedef void (* computeFun) (dsp_imp* base_dsp, int len, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs);
typedef void (* metadataFun) (MetaGlue* meta);
    
/***************************************
 * DSP memory manager functions
 ***************************************/

typedef void* (* allocateFun) (void* manager_interface, size_t size);
typedef void (* destroyFun) (void* manager_interface, void* ptr);

typedef struct {
    
    void* managerInterface;
    
    allocateFun allocate;
    destroyFun destroy;
    
} MemoryManagerGlue;

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CInterface.h **************************/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * UI glue code
 ******************************************************************************/
 
class UIFloat
{

    public:

        UIFloat() {}

        virtual ~UIFloat() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, float* zone) = 0;
        virtual void addCheckButton(const char* label, float* zone) = 0;
        virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
        virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(float* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueFloat(void* cpp_interface)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueFloat(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueFloat(void* cpp_interface, float* zone, const char* key, const char* value)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

class UIDouble
{

    public:

        UIDouble() {}

        virtual ~UIDouble() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, double* zone) = 0;
        virtual void addCheckButton(const char* label, double* zone) = 0;
        virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max) = 0;
        virtual void addVerticalBargraph(const char* label, double* zone, double min, double max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(double* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueDouble(void* cpp_interface)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueDouble(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueDouble(void* cpp_interface, double* zone, const char* key, const char* value)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

static void buildUIGlue(UIGlue* glue, UI* ui_interface, bool is_double)
{
    glue->uiInterface = ui_interface;
    
    if (is_double) {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueDouble);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueDouble);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueDouble);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueDouble);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueDouble);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueDouble);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueDouble);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueDouble);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueDouble);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueDouble);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueDouble);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueDouble);
        glue->declare = reinterpret_cast<declareFun>(declareGlueDouble);
    } else {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueFloat);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueFloat);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueFloat);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueFloat);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueFloat);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueFloat);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueFloat);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueFloat);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueFloat);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueFloat);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueFloat);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueFloat);
        glue->declare = reinterpret_cast<declareFun>(declareGlueFloat);
    }
}
    
// Base class
    
struct UIInterface
{
    virtual ~UIInterface() {}
    
    virtual int sizeOfFAUSTFLOAT() = 0;
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // float version
    
    // -- active widgets
    
    virtual void addButton(const char* label, float* zone) = 0;
    virtual void addCheckButton(const char* label, float* zone) = 0;
    
    virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
    virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    
    // -- metadata declarations
    
    virtual void declare(float* zone, const char* key, const char* val) = 0;
    
    // double version
    
    virtual void addButton(const char* label, double* zone) = 0;
    virtual void addCheckButton(const char* label, double* zone) = 0;
  
    virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
    virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
    
    virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max) = 0;
    virtual void addVerticalBargraph(const char* label, double* zone, double min, double max) = 0;
     
    // -- metadata declarations
    
    virtual void declare(double* zone, const char* key, const char* val) = 0;
    
};
    
struct UITemplate : public UIInterface
{
 
    void* fCPPInterface;

    UITemplate(void* cpp_interface):fCPPInterface(cpp_interface)
    {}
    virtual ~UITemplate() {}
    
    int sizeOfFAUSTFLOAT()
    {
        return reinterpret_cast<UI*>(fCPPInterface)->sizeOfFAUSTFLOAT();
    }
    
    // -- widget's layouts
    
    void openTabBox(const char* label)
    {
        openTabBoxGlueFloat(fCPPInterface, label);
    }
    void openHorizontalBox(const char* label)
    {
        openHorizontalBoxGlueFloat(fCPPInterface, label);
    }
    void openVerticalBox(const char* label)
    {
        openVerticalBoxGlueFloat(fCPPInterface, label);
    }
    void closeBox()
    {
        closeBoxGlueFloat(fCPPInterface);
    }
    
    // float version
    
    // -- active widgets
    
    void addButton(const char* label, float* zone)
    {
        addButtonGlueFloat(fCPPInterface, label, zone);
    }
    void addCheckButton(const char* label, float* zone)
    {
        addCheckButtonGlueFloat(fCPPInterface, label, zone);
    }
    
    void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        addVerticalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        addHorizontalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addNumEntry(const char* label, float* zone, float init, float min, float max, float step)
    {
        addNumEntryGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, float* zone, float min, float max)
    {
        addHorizontalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
    }
    
    void addVerticalBargraph(const char* label, float* zone, float min, float max)
    {
        addVerticalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
    }

    // -- metadata declarations
    
    void declare(float* zone, const char* key, const char* val)
    {
        declareGlueFloat(fCPPInterface, zone, key, val);
    }
    
    // double version
    
    void addButton(const char* label, double* zone)
    {
        addButtonGlueDouble(fCPPInterface, label, zone);
    }
    void addCheckButton(const char* label, double* zone)
    {
        addCheckButtonGlueDouble(fCPPInterface, label, zone);
    }
    
    void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        addVerticalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        addHorizontalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addNumEntry(const char* label, double* zone, double init, double min, double max, double step)
    {
        addNumEntryGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }

    // -- soundfiles
    
    void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
    {
        addSoundfileGlueFloat(fCPPInterface, label, url, sf_zone);
    }

    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, double* zone, double min, double max)
    {
        addHorizontalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
    }
    
    void addVerticalBargraph(const char* label, double* zone, double min, double max)
    {
        addVerticalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
    }

    // -- metadata declarations
    
    void declare(double* zone, const char* key, const char* val)
    {
        declareGlueDouble(fCPPInterface, zone, key, val);
    }

};
    
struct UIGlueTemplate : public UIInterface
{
    
    UIGlue* fGlue;
    
    UIGlueTemplate(UIGlue* glue):fGlue(glue)
    {}
    virtual ~UIGlueTemplate() {}
    
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
    
    // -- widget's layouts
    
    void openTabBox(const char* label)
    {
        fGlue->openTabBox(fGlue->uiInterface, label);
    }
    void openHorizontalBox(const char* label)
    {
        fGlue->openHorizontalBox(fGlue->uiInterface, label);
    }
    void openVerticalBox(const char* label)
    {
        fGlue->openVerticalBox(fGlue->uiInterface, label);
    }
    void closeBox()
    {
        fGlue->closeBox(fGlue->uiInterface);
    }

    // float version
    
    // -- active widgets
    
    void addButton(const char* label, float* zone)
    {
        fGlue->addButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    void addCheckButton(const char* label, float* zone)
    {
        fGlue->addCheckButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    
    void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addVerticalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addHorizontalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addNumEntry(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addNumEntry(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, float* zone, float min, float max)
    {
        fGlue->addHorizontalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    void addVerticalBargraph(const char* label, float* zone, float min, float max)
    {
        fGlue->addVerticalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    
    // -- metadata declarations
    
    void declare(float* zone, const char* key, const char* val)
    {
        fGlue->declare(fGlue->uiInterface, reinterpret_cast<FAUSTFLOAT*>(zone), key, val);
    }
    
    // double version
    
    void addButton(const char* label, double* zone)
    {
        fGlue->addButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    void addCheckButton(const char* label, double* zone)
    {
        fGlue->addCheckButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    
    void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addVerticalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addHorizontalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addNumEntry(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addNumEntry(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    // -- soundfiles
    
    void addSoundfile(const char* label, const char* url, Soundfile** sf_zone) {}
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, double* zone, double min, double max)
    {
        fGlue->addHorizontalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    void addVerticalBargraph(const char* label, double* zone, double min, double max)
    {
        fGlue->addVerticalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    
    // -- metadata declarations
    
    void declare(double* zone, const char* key, const char* val)
    {
        fGlue->declare(fGlue->uiInterface, reinterpret_cast<FAUSTFLOAT*>(zone), key, val);
    }
    
};

/*******************************************************************************
 * Meta glue code
 ******************************************************************************/

static void declareMetaGlue(void* cpp_interface, const char* key, const char* value)
{
    Meta* meta_interface = static_cast<Meta*>(cpp_interface);
    meta_interface->declare(key, value);
}

static void buildMetaGlue(MetaGlue* glue, Meta* meta)
{
    glue->metaInterface = meta;
    glue->declare = declareMetaGlue;
}
    
/*******************************************************************************
 * Memory manager glue code
 ******************************************************************************/

static void* allocateMemoryManagerGlue(void* cpp_interface, size_t size)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    return manager_interface->allocate(size);
}
    
static void destroyMemoryManagerGlue(void* cpp_interface, void* ptr)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    manager_interface->destroy(ptr);
}

static void buildManagerGlue(MemoryManagerGlue* glue, dsp_memory_manager* manager)
{
    glue->managerInterface = manager;
    glue->allocate = allocateMemoryManagerGlue;
    glue->destroy = destroyMemoryManagerGlue;
}

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CGlue.h **************************/

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

//------------------------------------------------------------------------------------------
//  Decode a base_dsp JSON description and implement 'buildUserInterface' and 'metadata' methods
//------------------------------------------------------------------------------------------

#define REAL_UI(ui_interface) reinterpret_cast<UIReal<REAL>*>(ui_interface)
#define REAL_ADR(index)      reinterpret_cast<REAL*>(&memory_block[index])
#define REAL_EXT_ADR(index)  reinterpret_cast<FAUSTFLOAT*>(&memory_block[index])
#define SOUNDFILE_ADR(index) reinterpret_cast<Soundfile**>(&memory_block[index])

typedef std::function<void(FAUSTFLOAT)> ReflectFunction;
typedef std::function<FAUSTFLOAT()> ModifyFunction;

struct FAUST_API ExtZoneParam {

    virtual void reflectZone() = 0;
    virtual void modifyZone() = 0;
    
    virtual void setReflectZoneFun(ReflectFunction reflect) = 0;
    virtual void setModifyZoneFun(ModifyFunction modify) = 0;
    
    virtual ~ExtZoneParam()
    {}
    
};

// Templated decoder

struct FAUST_API JSONUIDecoderBase
{
    virtual ~JSONUIDecoderBase()
    {}
    
    virtual void metadata(Meta* m) = 0;
    virtual void metadata(MetaGlue* glue) = 0;
    virtual int getDSPSize() = 0;
    virtual std::string getName() = 0;
    virtual std::string getLibVersion() = 0;
    virtual std::string getCompileOptions() = 0;
    virtual std::vector<std::string> getLibraryList() = 0;
    virtual std::vector<std::string> getIncludePathnames() = 0;
    virtual int getNumInputs() = 0;
    virtual int getNumOutputs() = 0;
    virtual int getSampleRate(char* memory_block) = 0;
    virtual void setReflectZoneFun(int index, ReflectFunction fun) = 0;
    virtual void setModifyZoneFun(int index, ModifyFunction fun) = 0;
    virtual void setupDSPProxy(UI* ui_interface, char* memory_block) = 0;
    virtual bool hasDSPProxy() = 0;
    virtual std::vector<ExtZoneParam*>& getInputControls() = 0;
    virtual std::vector<ExtZoneParam*>& getOutputControls() = 0;
    virtual void resetUserInterface() = 0;
    virtual void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr) = 0;
    virtual void buildUserInterface(UI* ui_interface) = 0;
    virtual void buildUserInterface(UI* ui_interface, char* memory_block) = 0;
    virtual void buildUserInterface(UIGlue* ui_interface, char* memory_block) = 0;
    virtual bool hasCompileOption(const std::string& option) = 0;
};

template <typename REAL>
struct FAUST_API JSONUIDecoderReal : public JSONUIDecoderBase {
    
    struct ZoneParam : public ExtZoneParam {
        
        FAUSTFLOAT fZone;
        ReflectFunction fReflect;
        ModifyFunction fModify;
        
    #if defined(TARGET_OS_IPHONE) || defined(WIN32)
        ZoneParam(ReflectFunction reflect = nullptr, ModifyFunction modify = nullptr)
        :fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { if (fReflect) fReflect(fZone); }
        void modifyZone() { if (fModify) fZone = fModify(); }
    #else
        ZoneParam(ReflectFunction reflect = [](FAUSTFLOAT value) {}, ModifyFunction modify = []() { return FAUSTFLOAT(-1); })
        :fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { fReflect(fZone); }
        void modifyZone() { fZone = fModify(); }
    #endif
        
        void setReflectZoneFun(ReflectFunction reflect) { fReflect = reflect; }
        void setModifyZoneFun(ModifyFunction modify) { fModify = modify; }
        
    };
    
    typedef std::vector<ExtZoneParam*> controlMap;
  
    std::string fName;
    std::string fFileName;
    std::string fJSON;
    std::string fVersion;
    std::string fCompileOptions;
    
    std::map<std::string, std::string> fMetadata;
    std::vector<itemInfo> fUiItems;
    
    std::vector<std::string> fLibraryList;
    std::vector<std::string> fIncludePathnames;
    
    int fNumInputs, fNumOutputs, fSRIndex;
    int fDSPSize;
    bool fDSPProxy;
    
    controlMap fPathInputTable;     // [path, ZoneParam]
    controlMap fPathOutputTable;    // [path, ZoneParam]
    
    bool startWith(const std::string& str, const std::string& prefix)
    {
        return (str.substr(0, prefix.size()) == prefix);
    }

    bool isInput(const std::string& type)
    {
        return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox");
    }
    bool isOutput(const std::string& type) { return (type == "hbargraph" || type == "vbargraph"); }
    bool isSoundfile(const std::string& type) { return (type == "soundfile"); }
    
    std::string getString(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? map[key].first : "";
    }
    
    int getInt(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? int(map[key].second) : -1;
    }
    
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        fPathInputTable[index]->setReflectZoneFun(fun);
    }
    
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        fPathOutputTable[index]->setModifyZoneFun(fun);
    }

    JSONUIDecoderReal(const std::string& json)
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        std::map<std::string, std::pair<std::string, double> > meta_data1;
        std::map<std::string, std::vector<std::string> > meta_data2;
        parseJson(p, meta_data1, fMetadata, meta_data2, fUiItems);
        
        // meta_data1 contains <name : val>, <inputs : val>, <ouputs : val> pairs etc...
        fName = getString(meta_data1, "name");
        fFileName = getString(meta_data1, "filename");
        fVersion = getString(meta_data1, "version");
        fCompileOptions = getString(meta_data1, "compile_options");
        
        if (meta_data2.find("library_list") != meta_data2.end()) {
            fLibraryList = meta_data2["library_list"];
        } else {
            // 'library_list' is coded as successive 'library_pathN' metadata
            for (const auto& it : fMetadata) {
                if (startWith(it.first, "library_path")) {
                    fLibraryList.push_back(it.second);
                }
            }
        }
        if (meta_data2.find("include_pathnames") != meta_data2.end()) {
            fIncludePathnames = meta_data2["include_pathnames"];
        }
        
        fDSPSize = getInt(meta_data1, "size");
        fNumInputs = getInt(meta_data1, "inputs");
        fNumOutputs = getInt(meta_data1, "outputs");
        fSRIndex = getInt(meta_data1, "sr_index");
        fDSPProxy = false;
        
        // Prepare the fPathTable and init zone
        for (const auto& it : fUiItems) {
            std::string type = it.type;
            // Meta data declaration for input items
            if (isInput(type)) {
                ZoneParam* param = new ZoneParam();
                fPathInputTable.push_back(param);
                param->fZone = it.init;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                ZoneParam* param = new ZoneParam();
                fPathOutputTable.push_back(param);
                param->fZone = REAL(0);
            }
        }
    }
    
    virtual ~JSONUIDecoderReal()
    {
        for (const auto& it : fPathInputTable) {
            delete it;
        }
        for (const auto& it : fPathOutputTable) {
            delete it;
        }
    }
    
    void metadata(Meta* m)
    {
        for (const auto& it : fMetadata) {
            m->declare(it.first.c_str(), it.second.c_str());
        }
    }
    
    void metadata(MetaGlue* m)
    {
        for (const auto& it : fMetadata) {
            m->declare(m->metaInterface, it.first.c_str(), it.second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        int item = 0;
        for (const auto& it : fUiItems) {
            if (isInput(it.type)) {
                static_cast<ZoneParam*>(fPathInputTable[item++])->fZone = it.init;
            }
        }
    }
    
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        for (const auto& it : fUiItems) {
            int index = it.index;
            if (isInput(it.type)) {
                *REAL_ADR(index) = it.init;
            } else if (isSoundfile(it.type)) {
                if (*SOUNDFILE_ADR(index) == nullptr) {
                    *SOUNDFILE_ADR(index) = defaultsound;
                }
            }
        }
    }
    
    int getSampleRate(char* memory_block)
    {
        return *reinterpret_cast<int*>(&memory_block[fSRIndex]);
    }
    
    void setupDSPProxy(UI* ui_interface, char* memory_block)
    {
        if (!fDSPProxy) {
            fDSPProxy = true;
            int countIn = 0;
            int countOut = 0;
            for (const auto& it : fUiItems) {
                std::string type = it.type;
                int index = it.index;
                if (isInput(type)) {
                    fPathInputTable[countIn++]->setReflectZoneFun([=](FAUSTFLOAT value) { *REAL_ADR(index) = REAL(value); });
                } else if (isOutput(type)) {
                    fPathOutputTable[countOut++]->setModifyZoneFun([=]() { return FAUSTFLOAT(*REAL_ADR(index)); });
                }
            }
        }
        
        // Setup soundfile in any case
        for (const auto& it : fUiItems) {
            if (isSoundfile(it.type)) {
                ui_interface->addSoundfile(it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(it.index));
            }
        }
    }
    
    bool hasDSPProxy() { return fDSPProxy; }
  
    void buildUserInterface(UI* ui_interface)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        int countIn = 0;
        int countOut = 0;
        int countSound = 0;
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(&static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(&static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui_interface->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") {
                ui_interface->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                ui_interface->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                ui_interface->addVerticalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "hslider") {
                ui_interface->addHorizontalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "checkbox") {
                ui_interface->addCheckButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "soundfile") {
                // Nothing
            } else if (type == "hbargraph") {
                ui_interface->addHorizontalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "vbargraph") {
                ui_interface->addVerticalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "nentry") {
                ui_interface->addNumEntry(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "button") {
                ui_interface->addButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "close") {
                ui_interface->closeBox();
            }
            
            if (isInput(type)) {
                countIn++;
            } else if (isOutput(type)) {
                countOut++;
            } else if (isSoundfile(type)) {
                countSound++;
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            int index = it.index;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                REAL_UI(ui_interface)->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") {
                REAL_UI(ui_interface)->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                REAL_UI(ui_interface)->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                REAL_UI(ui_interface)->addVerticalSlider(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "hslider") {
                REAL_UI(ui_interface)->addHorizontalSlider(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "checkbox") {
                REAL_UI(ui_interface)->addCheckButton(it.label.c_str(), REAL_ADR(index));
            } else if (type == "soundfile") {
                REAL_UI(ui_interface)->addSoundfile(it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(index));
            } else if (type == "hbargraph") {
                REAL_UI(ui_interface)->addHorizontalBargraph(it.label.c_str(), REAL_ADR(index), min, max);
            } else if (type == "vbargraph") {
                REAL_UI(ui_interface)->addVerticalBargraph(it.label.c_str(), REAL_ADR(index), min, max);
            } else if (type == "nentry") {
                REAL_UI(ui_interface)->addNumEntry(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "button") {
                REAL_UI(ui_interface)->addButton(it.label.c_str(), REAL_ADR(index));
            } else if (type == "close") {
                REAL_UI(ui_interface)->closeBox();
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            int index = it.index;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, REAL_EXT_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, REAL_EXT_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, 0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui_interface->openHorizontalBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "vgroup") {
                ui_interface->openVerticalBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "tgroup") {
                ui_interface->openTabBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "vslider") {
                ui_interface->addVerticalSlider(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "hslider") {
                ui_interface->addHorizontalSlider(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "checkbox") {
                ui_interface->addCheckButton(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index));
            } else if (type == "soundfile") {
                ui_interface->addSoundfile(ui_interface->uiInterface, it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(index));
            } else if (type == "hbargraph") {
                ui_interface->addHorizontalBargraph(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), min, max);
            } else if (type == "vbargraph") {
                ui_interface->addVerticalBargraph(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), min, max);
            } else if (type == "nentry") {
                ui_interface->addNumEntry(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "button") {
                ui_interface->addButton(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index));
            } else if (type == "close") {
                ui_interface->closeBox(ui_interface->uiInterface);
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    bool hasCompileOption(const std::string& option)
    {
        std::istringstream iss(fCompileOptions);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            if (token == option) return true;
        }
        return false;
    }
    
    int getDSPSize() { return fDSPSize; }
    std::string getName() { return fName; }
    std::string getLibVersion() { return fVersion; }
    std::string getCompileOptions() { return fCompileOptions; }
    std::vector<std::string> getLibraryList() { return fLibraryList; }
    std::vector<std::string> getIncludePathnames() { return fIncludePathnames; }
    int getNumInputs() { return fNumInputs; }
    int getNumOutputs() { return fNumOutputs; }
    
    std::vector<ExtZoneParam*>& getInputControls()
    {
        return fPathInputTable;
    }
    std::vector<ExtZoneParam*>& getOutputControls()
    {
        return fPathOutputTable;
    }
    
};

// FAUSTFLOAT templated decoder

struct FAUST_API JSONUIDecoder : public JSONUIDecoderReal<FAUSTFLOAT>
{
    JSONUIDecoder(const std::string& json):JSONUIDecoderReal<FAUSTFLOAT>(json)
    {}
};

// Generic factory

static JSONUIDecoderBase* createJSONUIDecoder(const std::string& json)
{
    JSONUIDecoder decoder(json);
    if (decoder.hasCompileOption("-double")) {
        return new JSONUIDecoderReal<double>(json);
    } else {
        return new JSONUIDecoderReal<float>(json);
    }
}

#endif
/**************************  END  JSONUIDecoder.h **************************/

/**
 * Proxy base_dsp definition created from the DSP JSON description.
 * This class allows a 'proxy' base_dsp to control a real base_dsp
 * possibly running somewhere else.
 */
class proxy_dsp : public base_dsp {

    protected:
    
        JSONUIDecoder* fDecoder;
        int fSampleRate;
    
        void init(const std::string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSampleRate = -1;
        }
        
    public:
    
        proxy_dsp():fDecoder(nullptr), fSampleRate(-1)
        {}
    
        proxy_dsp(const std::string& json)
        {
            init(json);
        }
          
        proxy_dsp(base_dsp* base_dsp)
        {
            JSONUI builder(base_dsp->getNumInputs(), base_dsp->getNumOutputs());
            base_dsp->metadata(&builder);
            base_dsp->buildUserInterface(&builder);
            fSampleRate = base_dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
    
        virtual int getNumInputs() { return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy base_dsp 
        virtual void init(int sample_rate)
        {
            instanceInit(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            instanceConstants(sample_rate);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int sample_rate) { fSampleRate = sample_rate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSampleRate; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif
/************************** END proxy-base_dsp.h **************************/

/************************** BEGIN DecoratorUI.h **************************
 FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class FAUST_API GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class FAUST_API DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

// Defined here to simplify header #include inclusion 
class FAUST_API SoundUIInterface : public GenericUI {};

#endif
/**************************  END  DecoratorUI.h **************************/
/************************** BEGIN JSONControl.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __JSON_CONTROL__
#define __JSON_CONTROL__

#include <string>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API JSONControl {
    
    virtual std::string getJSON() { return ""; }

    virtual void setParamValue(const std::string& path, FAUSTFLOAT value) {}

    virtual FAUSTFLOAT getParamValue(const std::string& path) { return 0; }
    
    virtual ~JSONControl()
    {}
    
};

#endif
/**************************  END  JSONControl.h **************************/

#define kActiveVoice    0
#define kFreeVoice     -1
#define kReleaseVoice  -2
#define kLegatoVoice   -3
#define kNoVoice       -4

#define VOICE_STOP_LEVEL  0.0005    // -70 db
#define MIX_BUFFER_SIZE   4096

/**
 * Allows to control zones in a grouped manner.
 */
class GroupUI : public GUI, public PathBuilder {

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!MapUI::endsWith(label, "/gate")
                && !MapUI::endsWith(label, "/freq")
                && !MapUI::endsWith(label, "/key")
                && !MapUI::endsWith(label, "/gain")
                && !MapUI::endsWith(label, "/vel")
                && !MapUI::endsWith(label, "/velocity")) {

                // Groups all controllers except 'freq/key', 'gate', and 'gain/vel|velocity'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            popLabel();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */
struct dsp_voice : public MapUI, public decorator_dsp {
    
    typedef std::function<double(int)> TransformFunction;
  
    static double midiToFreq(double note)
    {
        return 440.0 * std::pow(2.0, (note-69.0)/12.0);
    }
    
    int fCurNote;                       // Playing note pitch
    int fNextNote;                      // In kLegatoVoice state, next note to play
    int fNextVel;                       // In kLegatoVoice state, next velocity to play
    int fDate;                          // KeyOn date
    int fRelease;                       // Current number of samples used in release mode to detect end of note
    FAUSTFLOAT fLevel;                  // Last audio block level
    double fReleaseLengthSec;           // Maximum release length in seconds (estimated time to silence after note release)
    std::vector<std::string> fGatePath; // Paths of 'gate' control
    std::vector<std::string> fGainPath; // Paths of 'gain/vel|velocity' control
    std::vector<std::string> fFreqPath; // Paths of 'freq/key' control
    TransformFunction        fKeyFun;   // MIDI key to freq conversion function
    TransformFunction        fVelFun;   // MIDI velocity to gain conversion function
    
    FAUSTFLOAT** fInputsSlice;
    FAUSTFLOAT** fOutputsSlice;
 
    dsp_voice(base_dsp* base_dsp):decorator_dsp(base_dsp)
    {
        // Default versions
        fVelFun = [](int velocity) { return double(velocity)/127.0; };
        fKeyFun = [](int pitch) { return midiToFreq(pitch); };
        base_dsp->buildUserInterface(this);
        fCurNote = kFreeVoice;
        fNextNote = fNextVel = -1;
        fLevel = FAUSTFLOAT(0);
        fDate = fRelease = 0;
        fReleaseLengthSec = 0.5;  // A half second is a reasonable default maximum release length.
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }
    virtual ~dsp_voice()
    {}
    
    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        FAUSTFLOAT** inputsSlice = static_cast<FAUSTFLOAT**>(alloca(sizeof(FAUSTFLOAT*) * getNumInputs()));
        for (int chan = 0; chan < getNumInputs(); chan++) {
            inputsSlice[chan] = &(inputs[chan][offset]);
        }
        FAUSTFLOAT** outputsSlice = static_cast<FAUSTFLOAT**>(alloca(sizeof(FAUSTFLOAT*) * getNumOutputs()));
        for (int chan = 0; chan < getNumOutputs(); chan++) {
            outputsSlice[chan] = &(outputs[chan][offset]);
        }
        compute(slice, inputsSlice, outputsSlice);
    }
    
    void computeLegato(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        int slice = count/2;
        
        // Reset envelops
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        // Compute current voice on half buffer
        computeSlice(0, slice, inputs, outputs);
         
        // Start next keyOn
        keyOn(fNextNote, fNextVel);
        
        // Compute on second half buffer
        computeSlice(slice, slice, inputs, outputs);
    }

    void extractPaths(std::vector<std::string>& gate, std::vector<std::string>& freq, std::vector<std::string>& gain)
    {
        // Keep gain/vel|velocity, freq/key and gate labels
        for (const auto& it : getFullpathMap()) {
            std::string path = it.first;
            if (endsWith(path, "/gate")) {
                gate.push_back(path);
            } else if (endsWith(path, "/freq")) {
                fKeyFun = [](int pitch) { return midiToFreq(pitch); };
                freq.push_back(path);
            } else if (endsWith(path, "/key")) {
                fKeyFun = [](int pitch) { return pitch; };
                freq.push_back(path);
            } else if (endsWith(path, "/gain")) {
                fVelFun = [](int velocity) { return double(velocity)/127.0; };
                gain.push_back(path);
            } else if (endsWith(path, "/vel") || endsWith(path, "/velocity")) {
                fVelFun = [](int velocity) { return double(velocity); };
                gain.push_back(path);
            }
        }
    }
    
    void reset()
    {
        init(getSampleRate());
    }
 
    void instanceClear()
    {
        decorator_dsp::instanceClear();
        fCurNote = kFreeVoice;
        fNextNote = fNextVel = -1;
        fLevel = FAUSTFLOAT(0);
        fDate = fRelease = 0;
    }
    
    // Keep 'pitch' and 'velocity' to fadeOut the current voice and start next one in the next buffer
    void keyOn(int pitch, int velocity, bool legato = false)
    {
        if (legato) {
            fNextNote = pitch;
            fNextVel = velocity;
        } else {
            keyOn(pitch, fVelFun(velocity));
        }
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, double velocity)
    {
        for (size_t i = 0; i < fFreqPath.size(); i++) {
            setParamValue(fFreqPath[i], fKeyFun(pitch));
        }
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(1));
        }
        for (size_t i = 0; i < fGainPath.size(); i++) {
            setParamValue(fGainPath[i], velocity);
        }
        
        fCurNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        if (hard) {
            // Immediately stop voice
            fCurNote = kFreeVoice;
        } else {
            // Release voice
            fRelease = fReleaseLengthSec * fDSP->getSampleRate();
            fCurNote = kReleaseVoice;
        }
    }
 
    // Change the voice release
    void setReleaseLength(double sec)
    {
        fReleaseLengthSec = sec;
    }

};

/**
 * A group of voices.
 */
struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    base_dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }
    
    void instanceResetUserInterface()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->instanceResetUserInterface();
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl || dynamic_cast<SoundUIInterface*>(ui_interface)) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), long(i+1));
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for MIDI controllable polyphonic DSP.
 */
#ifdef EMCC
#endif

class dsp_poly : public decorator_dsp, public midi, public JSONControl {

    protected:
    
    #ifdef EMCC
        MapUI fMapUI;
        std::string fJSON;
        midi_handler fMidiHandler;
        MidiUI fMIDIUI;
    #endif
    
    public:
    
    #ifdef EMCC
        dsp_poly(base_dsp* base_dsp):decorator_dsp(base_dsp), fMIDIUI(&fMidiHandler)
        {
            JSONUI jsonui(getNumInputs(), getNumOutputs());
            buildUserInterface(&jsonui);
            fJSON = jsonui.JSON(true);
            buildUserInterface(&fMapUI);
            buildUserInterface(&fMIDIUI);
        }
    #else
        dsp_poly(base_dsp* base_dsp):decorator_dsp(base_dsp)
        {}
    #endif
    
        virtual ~dsp_poly() {}
    
        // Reimplemented for EMCC
    #ifdef EMCC
        virtual int getNumInputs() { return decorator_dsp::getNumInputs(); }
        virtual int getNumOutputs() { return decorator_dsp::getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { decorator_dsp::buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return decorator_dsp::getSampleRate(); }
        virtual void init(int sample_rate) { decorator_dsp::init(sample_rate); }
        virtual void instanceInit(int sample_rate) { decorator_dsp::instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { decorator_dsp::instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { decorator_dsp::instanceResetUserInterface(); }
        virtual void instanceClear() { decorator_dsp::instanceClear(); }
        virtual dsp_poly* clone() { return new dsp_poly(fDSP->clone()); }
        virtual void metadata(Meta* m) { decorator_dsp::metadata(m); }
    
        // Additional API
        std::string getJSON()
        {
            return fJSON;
        }
    
        virtual void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            fMapUI.setParamValue(path, value);
            GUI::updateAllGuis();
        }
        
        virtual FAUSTFLOAT getParamValue(const std::string& path) { return fMapUI.getParamValue(path); }

        virtual void computeJS(int count, uintptr_t inputs, uintptr_t outputs)
        {
            decorator_dsp::compute(count, reinterpret_cast<FAUSTFLOAT**>(inputs),reinterpret_cast<FAUSTFLOAT**>(outputs));
        }
    #endif
    
        virtual MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return midi::keyOn(channel, pitch, velocity);
        }
        virtual void keyOff(int channel, int pitch, int velocity)
        {
            midi::keyOff(channel, pitch, velocity);
        }
        virtual void keyPress(int channel, int pitch, int press)
        {
            midi::keyPress(channel, pitch, press);
        }
        virtual void chanPress(int channel, int press)
        {
            midi::chanPress(channel, press);
        }
        virtual void ctrlChange(int channel, int ctrl, int value)
        {
            midi::ctrlChange(channel, ctrl, value);
        }
        virtual void ctrlChange14bits(int channel, int ctrl, int value)
        {
            midi::ctrlChange14bits(channel, ctrl, value);
        }
        virtual void pitchWheel(int channel, int wheel)
        {
        #ifdef EMCC
            fMIDIUI.pitchWheel(0., channel, wheel);
            GUI::updateAllGuis();
        #else
            midi::pitchWheel(channel, wheel);
        #endif
        }
        virtual void progChange(int channel, int pgm)
        {
            midi::progChange(channel, pgm);
        }
    
        // Change the voice release
        virtual void setReleaseLength(double seconds)
        {}
    
};

/**
 * Polyphonic DSP: groups a set of DSP to be played together or triggered by MIDI.
 *
 * All voices are preallocated by cloning the single DSP voice given at creation time.
 * Dynamic voice allocation is done in 'getFreeVoice'
 */
class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        FAUSTFLOAT** fOutBuffer;
        midi_interface* fMidiHandler; // The midi_interface the DSP is connected to
        int fDate;
    
        void fadeOut(int count, FAUSTFLOAT** outBuffer)
        {
            // FadeOut on half buffer
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                double factor = 1., step = 1./double(count);
                for (int frame = 0; frame < count; frame++) {
                    outBuffer[chan][frame] *= factor;
                    factor -= step;
                }
            }
        }
    
        FAUSTFLOAT mixCheckVoice(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                FAUSTFLOAT* mixChannel = mixBuffer[chan];
                FAUSTFLOAT* outChannel = outBuffer[chan];
                for (int frame = 0; frame < count; frame++) {
                    level = std::max<FAUSTFLOAT>(level, (FAUSTFLOAT)fabs(mixChannel[frame]));
                    outChannel[frame] += mixChannel[frame];
                }
            }
            return level;
        }
    
        void mixVoice(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                FAUSTFLOAT* mixChannel = mixBuffer[chan];
                FAUSTFLOAT* outChannel = outBuffer[chan];
                for (int frame = 0; frame < count; frame++) {
                    outChannel[frame] += mixChannel[frame];
                }
            }
        }
    
        void copy(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                memcpy(outBuffer[chan], mixBuffer[chan], count * sizeof(FAUSTFLOAT));
            }
        }

        void clear(int count, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                memset(outBuffer[chan], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
            
            return voice_playing;
        }
    
        int allocVoice(int voice, int type)
        {
            fVoiceTable[voice]->fDate++;
            fVoiceTable[voice]->fCurNote = type;
            return voice;
        }
    
        // Always returns a voice
        int getFreeVoice()
        {
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == kFreeVoice) {
                    return allocVoice(i, kActiveVoice);
                }
            }

            // Otherwise steal one
            int voice_release = kNoVoice;
            int voice_playing = kNoVoice;
            int oldest_date_release = INT_MAX;
            int oldest_date_playing = INT_MAX;

            // Scan all voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == kReleaseVoice) {
                    // Keeps oldest release voice
                    if (fVoiceTable[i]->fDate < oldest_date_release) {
                        oldest_date_release = fVoiceTable[i]->fDate;
                        voice_release = int(i);
                    }
                } else {
                    // Otherwise keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
        
            // Then decide which one to steal
            if (oldest_date_release != INT_MAX) {
                fprintf(stderr, "Steal release voice : voice_date = %d cur_date = %d voice = %d \n",
                        fVoiceTable[voice_release]->fDate,
                        fDate,
                        voice_release);
                return allocVoice(voice_release, kLegatoVoice);
            } else if (oldest_date_playing != INT_MAX) {
                fprintf(stderr, "Steal playing voice : voice_date = %d cur_date = %d voice = %d \n",
                        fVoiceTable[voice_playing]->fDate,
                        fDate,
                        voice_release);
                return allocVoice(voice_playing, kLegatoVoice);
            } else {
                assert(false);
                return kNoVoice;
            }
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                fprintf(stderr, "DSP is not polyphonic...\n");
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param base_dsp - the base_dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices, should be at least 1
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(base_dsp* base_dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(base_dsp) // base_dsp parameter is deallocated by ~dsp_poly
        {
            fDate = 0;
            fMidiHandler = nullptr;

            // Create voices
            assert(nvoices > 0);
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(base_dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            fOutBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                fMixBuffer[chan] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
                fOutBuffer[chan] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            // Remove from fMidiHandler
            if (fMidiHandler) fMidiHandler->removeMidiIn(this);
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                delete[] fMixBuffer[chan];
                delete[] fOutBuffer[chan];
            }
            delete[] fMixBuffer;
            delete[] fOutBuffer;
            
        }

        // DSP API
        void buildUserInterface(UI* ui_interface)
        {
            // MidiUI ui_interface contains the midi_handler connected to the MIDI driver
            if (dynamic_cast<midi_interface*>(ui_interface)) {
                fMidiHandler = dynamic_cast<midi_interface*>(ui_interface);
                fMidiHandler->addMidiIn(this);
            }
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int sample_rate)
        {
            decorator_dsp::init(sample_rate);
            fVoiceGroup->init(sample_rate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(sample_rate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int sample_rate)
        {
            decorator_dsp::instanceConstants(sample_rate);
            fVoiceGroup->instanceConstants(sample_rate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(sample_rate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= MIX_BUFFER_SIZE);

            // First clear the intermediate fOutBuffer
            clear(count, fOutBuffer);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fCurNote == kLegatoVoice) {
                        // Play from current note and next note
                        voice->computeLegato(count, inputs, fMixBuffer);
                        // FadeOut on first half buffer
                        fadeOut(count/2, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixCheckVoice(count, fMixBuffer, fOutBuffer);
                    } else if (voice->fCurNote != kFreeVoice) {
                        // Compute current note
                        voice->compute(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixCheckVoice(count, fMixBuffer, fOutBuffer);
                        // Check the level to possibly set the voice in kFreeVoice again
                        voice->fRelease -= count;
                        if ((voice->fCurNote == kReleaseVoice)
                            && (voice->fRelease < 0)
                            && (voice->fLevel < VOICE_STOP_LEVEL)) {
                            voice->fCurNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, fOutBuffer);
                }
            }
            
            // Finally copy intermediate buffer to outputs
            copy(count, fOutBuffer, outputs);
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }
    
        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }
 
        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            auto it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                dsp_voice* voice = *it;
                voice->keyOff();
                voice->reset();
            } else {
                fprintf(stderr, "Voice not found\n");
            }
        }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity, fVoiceTable[voice]->fCurNote == kLegatoVoice);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    fprintf(stderr, "Playing pitch = %d not found\n", pitch);
                }
            }
        }

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        // Change the voice release
        void setReleaseLength(double seconds)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->setReleaseLength(seconds);
            }
        }

};

/**
 * Polyphonic DSP with an integrated effect.
 */
class dsp_poly_effect : public dsp_poly {
    
    private:
    
        // fPolyDSP will respond to MIDI messages.
        dsp_poly* fPolyDSP;
        
    public:
        
        dsp_poly_effect(dsp_poly* voice, base_dsp* combined)
        :dsp_poly(combined), fPolyDSP(voice)
        {}
        
        virtual ~dsp_poly_effect()
        {
            // dsp_poly_effect is also a decorator_dsp, which will free fPolyDSP
        }
    
        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return fPolyDSP->keyOn(channel, pitch, velocity);
        }
        void keyOff(int channel, int pitch, int velocity)
        {
            fPolyDSP->keyOff(channel, pitch, velocity);
        }
        void keyPress(int channel, int pitch, int press)
        {
            fPolyDSP->keyPress(channel, pitch, press);
        }
        void chanPress(int channel, int press)
        {
            fPolyDSP->chanPress(channel, press);
        }
        void ctrlChange(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange(channel, ctrl, value);
        }
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange14bits(channel, ctrl, value);
        }
        void pitchWheel(int channel, int wheel)
        {
            fPolyDSP->pitchWheel(channel, wheel);
        }
        void progChange(int channel, int pgm)
        {
            fPolyDSP->progChange(channel, pgm);
        }
    
        // Change the voice release
        void setReleaseLength(double sec)
        {
            fPolyDSP->setReleaseLength(sec);
        }
    
};

/**
 * Polyphonic DSP factory class. Helper code to support polyphonic DSP source with an integrated effect.
 */
struct dsp_poly_factory : public dsp_factory {
    
    dsp_factory* fProcessFactory;
    dsp_factory* fEffectFactory;
    
    base_dsp* adaptDSP(base_dsp* base_dsp, bool is_double)
    {
        return (is_double) ? new dsp_sample_adapter<double, float>(base_dsp) : base_dsp;
    }

    dsp_poly_factory(dsp_factory* process_factory = nullptr,
                     dsp_factory* effect_factory = nullptr):
    fProcessFactory(process_factory)
    ,fEffectFactory(effect_factory)
    {}

    virtual ~dsp_poly_factory()
    {}

    virtual std::string getName() { return fProcessFactory->getName(); }
    virtual std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    virtual std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    virtual std::string getCompileOptions() { return fProcessFactory->getCompileOptions(); }
    virtual std::vector<std::string> getLibraryList() { return fProcessFactory->getLibraryList(); }
    virtual std::vector<std::string> getIncludePathnames() { return fProcessFactory->getIncludePathnames(); }

    std::string getEffectCode(const std::string& dsp_content)
    {
        std::stringstream effect_code;
        effect_code << "adapt(1,1) = _; adapt(2,2) = _,_; adapt(1,2) = _ <: _,_; adapt(2,1) = _,_ :> _;";
        effect_code << "adaptor(F,G) = adapt(outputs(F),inputs(G)); dsp_code = environment{ " << dsp_content << " };";
        effect_code << "process = adaptor(dsp_code.process, dsp_code.effect) : dsp_code.effect;";
        return effect_code.str();
    }

    virtual void setMemoryManager(dsp_memory_manager* manager)
    {
        fProcessFactory->setMemoryManager(manager);
        if (fEffectFactory) {
            fEffectFactory->setMemoryManager(manager);
        }
    }
    virtual dsp_memory_manager* getMemoryManager() { return fProcessFactory->getMemoryManager(); }

    /* Create a new polyphonic DSP instance with global effect, to be deleted with C++ 'delete'
     *
     * @param nvoices - number of polyphony voices, should be at least 1
     * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
     *                If false all voices are always running.
     * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
     *                a given control on all voices, assuming GUI::updateAllGuis() is called.
     *                If false, all voices can be individually controlled.
     * @param is_double - if true, internally allocated DSPs will be adapted to receive 'double' samples.
     */
    dsp_poly* createPolyDSPInstance(int nvoices, bool control, bool group, bool is_double = false)
    {
        dsp_poly* dsp_poly = new mydsp_poly(adaptDSP(fProcessFactory->createDSPInstance(), is_double), nvoices, control, group);
        if (fEffectFactory) {
            // the 'dsp_poly' object has to be controlled with MIDI, so kept separated from new dsp_sequencer(...) object
            return new dsp_poly_effect(dsp_poly, new dsp_sequencer(dsp_poly, adaptDSP(fEffectFactory->createDSPInstance(), is_double)));
        } else {
            return new dsp_poly_effect(dsp_poly, dsp_poly);
        }
    }

    /* Create a new DSP instance, to be deleted with C++ 'delete' */
    base_dsp* createDSPInstance()
    {
        return fProcessFactory->createDSPInstance();
    }

};

#endif // __poly_dsp__
/************************** END poly-base_dsp.h **************************/
#ifndef PLUGIN_MAGIC
/************************** BEGIN JuceGUI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef JUCE_GUI_H
#define JUCE_GUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <stack>

#include "../JuceLibraryCode/JuceHeader.h"


// Definition of the standard size of the different elements

#define kKnobWidth 100
#define kKnobHeight 100

#define kVSliderWidth 80
#define kVSliderHeight 250

#define kHSliderWidth 350
#define kHSliderHeight 50

#define kButtonWidth 100
#define kButtonHeight 50

#define kCheckButtonWidth 60
#define kCheckButtonHeight 40

#define kMenuWidth 100
#define kMenuHeight 50

#define kRadioButtonWidth 100
#define kRadioButtonHeight 55

#define kNumEntryWidth 100
#define kNumEntryHeight 50

#define kNumDisplayWidth 75
#define kNumDisplayHeight 50

#define kVBargraphWidth 60
#define kVBargraphHeight 250

#define kHBargraphWidth 350
#define kHBargraphHeight 50

#define kLedWidth 25
#define kLedHeight 25

#define kNameHeight 14

#define kMargin 4

/**
 * \brief       Custom LookAndFeel class.
 * \details     Define the appearance of all the JUCE widgets.
 */

struct CustomLookAndFeel : public juce::LookAndFeel_V3
{
    void drawRoundThumb (juce::Graphics& g, const float x, const float y,
                         const float diameter, const juce::Colour& colour, float outlineThickness)
    {
        const juce::Rectangle<float> a (x, y, diameter, diameter);
        const float halfThickness = outlineThickness * 0.5f;

        juce::Path p;
        p.addEllipse (x + halfThickness, y + halfThickness, diameter - outlineThickness, diameter - outlineThickness);

        const juce::DropShadow ds (juce::Colours::black, 1, juce::Point<int> (0, 0));
        ds.drawForPath (g, p);

        g.setColour (colour);
        g.fillPath (p);

        g.setColour (colour.brighter());
        g.strokePath (p, juce::PathStrokeType (outlineThickness));
    }

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) override
    {
        juce::Colour baseColour (backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (button.isEnabled() ? 0.9f : 0.5f));

        if (isButtonDown || isMouseOverButton)
            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);

        const bool flatOnLeft   = button.isConnectedOnLeft();
        const bool flatOnRight  = button.isConnectedOnRight();
        const bool flatOnTop    = button.isConnectedOnTop();
        const bool flatOnBottom = button.isConnectedOnBottom();

        const float width  = button.getWidth() - 1.0f;
        const float height = button.getHeight() - 1.0f;

        if (width > 0 && height > 0)
        {
            const float cornerSize = juce::jmin(15.0f, juce::jmin(width, height) * 0.45f);
            const float lineThickness = cornerSize * 0.1f;
            const float halfThickness = lineThickness * 0.5f;

            juce::Path outline;
            outline.addRoundedRectangle (0.5f + halfThickness, 0.5f + halfThickness, width - lineThickness, height - lineThickness,
                                         cornerSize, cornerSize,
                                         ! (flatOnLeft  || flatOnTop),
                                         ! (flatOnRight || flatOnTop),
                                         ! (flatOnLeft  || flatOnBottom),
                                         ! (flatOnRight || flatOnBottom));

            const juce::Colour outlineColour (button.findColour (button.getToggleState() ? juce::TextButton::textColourOnId
                                        : juce::TextButton::textColourOffId));

            g.setColour (baseColour);
            g.fillPath (outline);

            if (! button.getToggleState()) {
                g.setColour (outlineColour);
                g.strokePath (outline, juce::PathStrokeType (lineThickness));
            }
        }
    }

    void drawTickBox (juce::Graphics& g, juce::Component& component,
                      float x, float y, float w, float h,
                      bool ticked,
                      bool isEnabled,
                      bool isMouseOverButton,
                      bool isButtonDown) override
    {
        const float boxSize = w * 0.7f;

        bool isDownOrDragging = component.isEnabled() && (component.isMouseOverOrDragging() || component.isMouseButtonDown());
        const juce::Colour colour (component.findColour (juce::TextButton::buttonColourId).withMultipliedSaturation ((component.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
                             .withMultipliedAlpha (component.isEnabled() ? 1.0f : 0.7f));

        drawRoundThumb (g, x, y + (h - boxSize) * 0.5f, boxSize, colour,
                        isEnabled ? ((isButtonDown || isMouseOverButton) ? 1.1f : 0.5f) : 0.3f);

        if (ticked) {
            const juce::Path tick (juce::LookAndFeel_V2::getTickShape (6.0f));
            g.setColour (isEnabled ? findColour (juce::TextButton::buttonOnColourId) : juce::Colours::grey);

            const float scale = 9.0f;
            const juce::AffineTransform trans (juce::AffineTransform::scale (w / scale, h / scale)
                                         .translated (x - 2.5f, y + 1.0f));
            g.fillPath (tick, trans);
        }
    }

    void drawLinearSliderThumb (juce::Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const juce::Slider::SliderStyle style, juce::Slider& slider) override
    {
        const float sliderRadius = (float)(getSliderThumbRadius (slider) - 2);

        bool isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
        juce::Colour knobColour (slider.findColour (juce::Slider::thumbColourId).withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f));

        if (style == juce::Slider::LinearHorizontal || style == juce::Slider::LinearVertical) {
            float kx, ky;

            if (style == juce::Slider::LinearVertical) {
                kx = x + width * 0.5f;
                ky = sliderPos;
            } else {
                kx = sliderPos;
                ky = y + height * 0.5f;
            }

            const float outlineThickness = slider.isEnabled() ? 0.8f : 0.3f;

            drawRoundThumb (g,
                            kx - sliderRadius,
                            ky - sliderRadius,
                            sliderRadius * 2.0f,
                            knobColour, outlineThickness);
        } else {
            // Just call the base class for the demo
            juce::LookAndFeel_V2::drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }

    void drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const juce::Slider::SliderStyle style, juce::Slider& slider) override
    {
        g.fillAll (slider.findColour (juce::Slider::backgroundColourId));

        if (style == juce::Slider::LinearBar || style == juce::Slider::LinearBarVertical) {
            const float fx = (float)x, fy = (float)y, fw = (float)width, fh = (float)height;

            juce::Path p;

            if (style == juce::Slider::LinearBarVertical)
                p.addRectangle (fx, sliderPos, fw, 1.0f + fh - sliderPos);
            else
                p.addRectangle (fx, fy, sliderPos - fx, fh);

            juce::Colour baseColour (slider.findColour (juce::Slider::rotarySliderFillColourId)
                               .withMultipliedSaturation (slider.isEnabled() ? 1.0f : 0.5f)
                               .withMultipliedAlpha (0.8f));

            g.setColour (baseColour);
            g.fillPath (p);

            const float lineThickness = juce::jmin(15.0f, juce::jmin(width, height) * 0.45f) * 0.1f;
            g.drawRect (slider.getLocalBounds().toFloat(), lineThickness);
        } else {
            drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
            drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }

    void drawLinearSliderBackground (juce::Graphics& g, int x, int y, int width, int height,
                                     float /*sliderPos*/,
                                     float /*minSliderPos*/,
                                     float /*maxSliderPos*/,
                                     const juce::Slider::SliderStyle /*style*/, juce::Slider& slider) override
    {
        const float sliderRadius = getSliderThumbRadius (slider) - 5.0f;
        juce::Path on, off;

        if (slider.isHorizontal()) {
            const float iy = y + height * 0.5f - sliderRadius * 0.5f;
            juce::Rectangle<float> r (x - sliderRadius * 0.5f, iy, width + sliderRadius, sliderRadius);
            const float onW = r.getWidth() * ((float)slider.valueToProportionOfLength (slider.getValue()));

            on.addRectangle (r.removeFromLeft (onW));
            off.addRectangle (r);
        } else {
            const float ix = x + width * 0.5f - sliderRadius * 0.5f;
            juce::Rectangle<float> r (ix, y - sliderRadius * 0.5f, sliderRadius, height + sliderRadius);
            const float onH = r.getHeight() * ((float)slider.valueToProportionOfLength (slider.getValue()));

            on.addRectangle (r.removeFromBottom (onH));
            off.addRectangle (r);
        }

        g.setColour (slider.findColour (juce::Slider::rotarySliderFillColourId));
        g.fillPath (on);

        g.setColour (slider.findColour (juce::Slider::trackColourId));
        g.fillPath (off);
    }

    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                           float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        const float radius = juce::jmin(width / 2, height / 2) - 4.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();

        //Background
        {
            g.setColour(juce::Colours::lightgrey.withAlpha (isMouseOver ? 1.0f : 0.7f));
            juce::Path intFilledArc;
            intFilledArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, 0.8);
            g.fillPath(intFilledArc);
        }

        if (slider.isEnabled()) {
            g.setColour(slider.findColour (juce::Slider::rotarySliderFillColourId).withAlpha (isMouseOver ? 1.0f : 0.7f));
        } else {
            g.setColour(juce::Colour (0x80808080));
        }

        //Render knob value
        {
            juce::Path pathArc;
            pathArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, angle, 0.8);
            g.fillPath(pathArc);

            juce::Path cursor, cursorShadow;
            float rectWidth = radius*0.4;
            float rectHeight = rectWidth/2;
            float rectX = centreX + radius*0.9 - rectHeight/2;
            float rectY = centreY - rectWidth/2;

            cursor.addRectangle(rectX, rectY, rectWidth, rectHeight);
            cursorShadow.addRectangle(rectX-1, rectY-1, rectWidth+2, rectHeight+2);

            juce::AffineTransform t = juce::AffineTransform::translation(-rectWidth + 2, rectHeight/2);
            t = t.rotated((angle - MathConstants<float>::pi/2), centreX, centreY);

            cursor.applyTransform(t);
            cursorShadow.applyTransform(t);

            g.setColour(juce::Colours::black);
            g.fillPath(cursor);

            g.setColour(juce::Colours::black .withAlpha(0.15f));
            g.fillPath(cursorShadow);
        }
    }
};

/**
 * \brief   Different kind of slider available
 * \see     uiSlider
 */
enum SliderType {
    HSlider,    /*!< Horizontal Slider      */
    VSlider,    /*!< Vertical Slider        */
    NumEntry,   /*!< Numerical Entry Box    */
    Knob        /*!< Circular Slider        */
};

/**
 * \brief   Different kind of VU-meter available.
 */
enum VUMeterType {
    HVUMeter,   /*!< Horizontal VU-meter    */
    VVUMeter,   /*!< Vertical VU-meter      */
    Led,        /*!< LED VU-meter           */
    NumDisplay  /*!< TextBox VU-meter       */
};

/**
 * \brief   Intern class for all FAUST widgets.
 * \details Every active, passive or box widgets derive from this class.
 */
class uiBase
{
    
    protected:
        
        int fTotalWidth, fTotalHeight;              // Size with margins included (for a uiBox)
        int fDisplayRectWidth, fDisplayRectHeight;  // Size without margin, just the child dimensions, sum on one dimension, max on the other
        float fHRatio, fVRatio;
        
    public:
        
        /**
         * \brief   Constructor.
         * \details Initialize a uiBase with all its sizes.
         *
         * \param   totWidth    Minimal total width.
         * \param   totHeight   Minimal total Height.
         */
        uiBase(int totWidth = 0, int totHeight = 0):
            fTotalWidth(totWidth), fTotalHeight(totHeight),
            fDisplayRectWidth(0), fDisplayRectHeight(0),
            fHRatio(1), fVRatio(1)
        {}
        
        virtual ~uiBase()
        {}
        
        /** Return the size. */
        juce::Rectangle<int> getSize()
        {
            return juce::Rectangle<int>(0, 0, fTotalWidth, fTotalHeight);
        }
        
        /** Return the total height in pixels. */
        int getTotalHeight()
        {
            return fTotalHeight;
        }
        
        /** Return the total width in pixels. */
        int getTotalWidth()
        {
            return fTotalWidth;
        }
        
        /** Return the horizontal ratio, between 0 and 1. */
        float getHRatio()
        {
            return fHRatio;
        }
        
        /** Return the vertical ratio, between 0 and 1. */
        float getVRatio()
        {
            return fVRatio;
        }
        
        /**
         * \brief   Set the uiBase bounds.
         * \details Convert absolute bounds to relative bounds,
         *          used in JUCE Component mechanics.
         *
         * \param r The absolute bounds.
         *
         */
        void setRelativeSize(juce::Component* comp, const juce::Rectangle<int>& r)
        {
            comp->setBounds(r.getX() - comp->getParentComponent()->getX(),
                            r.getY() - comp->getParentComponent()->getY(),
                            r.getWidth(),
                            r.getHeight());
        }
    
        virtual void init(juce::Component* comp = nullptr)
        {
            /** Initialize both vertical and horizontal ratios. */
            assert(comp);
            uiBase* parentBox = comp->findParentComponentOfClass<uiBase>();
            if (parentBox != nullptr) {
                fHRatio = (float)fTotalWidth / (float)parentBox->fDisplayRectWidth;
                fVRatio = (float)fTotalHeight / (float)parentBox->fDisplayRectHeight;
            }
        }
    
        virtual void setRecommendedSize()
        {}
        
        virtual void add(juce::Component* comp)
        {}
    
};

/**
 * \brief   Intern class for all FAUST active or passive widgets.
 * \details Every activ or passive widgets derive from this class.
 */
class uiComponent : public uiBase, public juce::Component, public uiItem
{

    public:
        /**
         * \brief   Constructor.
         * \details Initialize all uiItem, uiBase and the tooltip variables.
         *
         * \param   gui     Current FAUST GUI.
         * \param   zone    Zone of the widget.
         * \param   w       Width of the widget.
         * \param   h       Height of the widget.
         * \param   name    Name of the widget.
         */
        uiComponent(GUI* gui, FAUSTFLOAT* zone, int w, int h, juce::String name):uiBase(w, h), Component(name), uiItem(gui, zone)
        {}

};

/** 
 * \brief   Intern class for all kind of sliders.
 * \see     SliderType
 */
class uiSlider : public uiComponent, public uiConverter, private juce::Slider::Listener
{
    
    private:
        
        juce::Slider::SliderStyle fStyle;
        juce::Label fLabel;
        SliderType fType;
        juce::Slider fSlider;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize all uiComponent variables, and Slider specific ones.
         *          Initialize juce::Slider parameters.
         *
         * \param   gui, zone, w, h, tooltip, name  uiComponent variables.
         * \param   min                             Minimum value of the slider.
         * \param   max                             Maximum value of the slider.
         * \param   cur                             Initial value of the slider.
         * \param   step                            Step of the slider.
         * \param   unit                            Unit of the slider value.
         * \param   scale                           Scale of the slider, exponential, logarithmic, or linear.
         * \param   type                            Type of slider (see SliderType).
         */
        uiSlider(GUI* gui, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, FAUSTFLOAT cur, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, juce::String name, juce::String unit, juce::String tooltip, MetaDataUI::Scale scale, SliderType type)
            : uiComponent(gui, zone, w, h, name), uiConverter(scale, min, max, min, max), fType(type)
        {
            // Set the JUCE widget initalization variables.
            switch(fType) {
                case HSlider:
                    fStyle = juce::Slider::SliderStyle::LinearHorizontal;
                    break;
                case VSlider:
                    fStyle = juce::Slider::SliderStyle::LinearVertical;
                    fSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
                    break;
                case NumEntry:
                    fSlider.setIncDecButtonsMode(juce::Slider::incDecButtonsDraggable_AutoDirection);
                    fStyle = juce::Slider::SliderStyle::IncDecButtons;
                    break;
                case Knob:
                    fStyle = juce::Slider::SliderStyle::Rotary;
                    fSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
                    break;
                default:
                    break;
            }
            addAndMakeVisible(fSlider);

            // Slider settings
            fSlider.setRange(min, max, step);
            fSlider.setValue(fConverter->faust2ui(cur));
            fSlider.addListener(this);
            fSlider.setSliderStyle(fStyle);
            fSlider.setTextValueSuffix(" " + unit);
            fSlider.setTooltip(tooltip);
            switch (scale) {
                case MetaDataUI::kLog:
                    fSlider.setSkewFactor(0.25);
                    break;
                case MetaDataUI::kExp:
                    fSlider.setSkewFactor(0.75);
                    break;
                default:
                    break;
            }
      
            // Label settings, only happens for a horizontal of numerical entry slider
            // because the method attachToComponent only give the choice to place the
            // slider name on centered top, which is what we want. It's done manually
            // in the paint method.
            if (fType == HSlider || fType == NumEntry) {
                fLabel.setText(getName(), juce::dontSendNotification);
                fLabel.attachToComponent(&fSlider, true);
                fLabel.setTooltip(tooltip);
                addAndMakeVisible(fLabel);
            }
        }

        /** Draw the name of a vertical or circular slider. */
        virtual void paint(juce::Graphics& g) override
        {
            if (fType == VSlider || fType == Knob) {
                g.setColour(juce::Colours::black);
                g.drawText(getName(), getLocalBounds(), juce::Justification::centredTop);
            }
        }

        /** Allow to control the slider when its value is changed, but not by the user. */
        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fSlider.setValue(fConverter->faust2ui(v));
        }

        /** JUCE callback for a slider value change, give the value to the FAUST module. */
        void sliderValueChanged(juce::Slider* slider) override
        {
            float v = slider->getValue();
            modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
        }

        /** 
         * Set the good coordinates and size for the juce::Slider object depending 
         * on its SliderType, whenever the layout size changes.
         */
        void resized() override
        {
            int x, y, width, height;
            
            switch (fType) {
                    
                case HSlider: {
                    int nameWidth = juce::Font().getStringWidth(getName()) + kMargin * 2;
                    x = nameWidth;
                    y = 0;
                    width = getWidth() - nameWidth;
                    height = getHeight();
                    break;
                }
                    
                case VSlider:
                    x = 0;
                    y = kNameHeight; // kNameHeight pixels for the name
                    height = getHeight() - kNameHeight;
                    width = getWidth();
                    break;

                case NumEntry:
                    width = kNumEntryWidth;
                    height = kNumEntryHeight;
                    // x position is the top left corner horizontal position of the box
                    // and not the top left of the NumEntry label, so we have to do that
                    x = (getWidth() - width)/2 + (juce::Font().getStringWidth(getName()) + kMargin)/2;
                    y = (getHeight() - height)/2;
                    break;
                    
                case Knob:
                    // The knob name needs to be displayed, kNameHeight pixels
                    height = width = juce::jmin(getHeight() - kNameHeight, kKnobHeight);
                    x = (getWidth() - width)/2;
                    // kNameHeight pixels for the knob name still
                    y = juce::jmax((getHeight() - height)/2, kNameHeight);
                    break;
                    
                default:
                    assert(false);
                    break;
            }
            
            fSlider.setBounds(x, y, width, height);
        }
    
};

/** Intern class for button */
class uiButton : public uiComponent, private juce::Button::Listener
{
    
    private:
        
        juce::TextButton fButton;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize all uiComponent variables and juce::TextButton parameters.
         *
         * \param   gui, zone, w, h, tooltip, label uiComponent variable.
         */
        uiButton(GUI* gui, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, juce::String label, juce::String tooltip) :  uiComponent(gui, zone, w, h, label)
        {
            int x = 0;
            int y = (getHeight() - kButtonHeight)/2;

            fButton.setButtonText(label);
            fButton.setBounds(x, y, kButtonWidth, kButtonHeight);
            fButton.addListener(this);
            fButton.setTooltip(tooltip);
            addAndMakeVisible(fButton);
        }

        /** 
         * Has to be defined because its a pure virtual function of juce::Button::Listener, 
         * which uiButton derives from. Control of user actions is done in buttonStateChanged.
         * \see buttonStateChanged
         */
        void buttonClicked (juce::Button* button) override
        {}

        /** Indicate to the FAUST module when the button is pressed and released. */
        void buttonStateChanged (juce::Button* button) override
        {
            if (button->isDown()) {
                modifyZone(FAUSTFLOAT(1));
            } else {
                modifyZone(FAUSTFLOAT(0));
            }
        }
        
        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v == FAUSTFLOAT(1)) {
                fButton.triggerClick();
            }
        }

        /** Set the good coordinates and size to the juce::TextButton widget whenever the layout size changes. */
        virtual void resized() override
        {
            int x = kMargin;
            int width = getWidth() - 2 * kMargin;
            int height = juce::jmin(getHeight(), kButtonHeight);
            int y = (getHeight()-height)/2;
            fButton.setBounds(x, y, width, height);
        }
    
};

/** Intern class for checkButton */
class uiCheckButton : public uiComponent, private juce::Button::Listener
{
    
    private:
        
        juce::ToggleButton fCheckButton;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize all uiComponent variables and juce::ToggleButton parameters.
         *
         * \param   gui, zone, w, h, label, tooltip  uiComponent variables.
         */
        uiCheckButton(GUI* gui, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, juce::String label, juce::String tooltip) : uiComponent(gui, zone, w, h, label)
        {
            int x = 0;
            int y = (getHeight()-h)/2;
            
            fCheckButton.setButtonText(label);
            fCheckButton.setBounds(x, y, w, h);
            fCheckButton.addListener(this);
            fCheckButton.setTooltip(tooltip);
            addAndMakeVisible(fCheckButton);
        }

        /** Indicate to the FAUST module when the button is toggled or not. */
        void buttonClicked(juce::Button* button) override
        {
            //std::cout << getName() << " : " << button->getToggleState() << std::endl;
            modifyZone(button->getToggleState());
        }

        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fCheckButton.triggerClick();
        }

        /** Set the good coordinates and size to the juce::ToggleButton widget, whenever the layout size changes. */
        virtual void resized() override
        {
            fCheckButton.setBounds(getLocalBounds());
        }
    
};

/** Intern class for Menu */
class uiMenu : public uiComponent, private juce::ComboBox::Listener
{
    
    private:
        
        juce::ComboBox fComboBox;
        std::vector<double> fValues;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize the uiComponent and Menu specific variables, and the juce::ComboBox parameters.
         *          Menu is considered as a slider in the FAUST logic, with a step of one. The first item
         *          would be 0 on a slider, the second 1, etc. Each "slider value" is associated with a 
         *          string.
         *
         * \param   gui, zone, w, h, tooltip, label     uiComponent variables.
         * \param   cur                                 Current "slider value" associated with the current item selected.
         * \param   low                                 Lowest value possible.
         * \param   hi                                  Highest value possible.
         * \param   mdescr                              Menu description. Contains the names of the items associated with their "value".
         */
        uiMenu(GUI* gui, FAUSTFLOAT* zone, juce::String label, FAUSTFLOAT w, FAUSTFLOAT h, FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, juce::String tooltip, const char* mdescr) : uiComponent(gui, zone, w, h, label)
        {
            //Init ComboBox parameters
            fComboBox.setEditableText(false);
            fComboBox.setJustificationType(juce::Justification::centred);
            fComboBox.addListener(this);
            addAndMakeVisible(fComboBox);

            std::vector<std::string> names;
            std::vector<double> values;

            if (parseMenuList(mdescr, names, values)) {

                int defaultitem = -1;
                double mindelta = FLT_MAX;
                int item = 1;

                // Go through all the Menu's items.
                for (int i = 0; i < names.size(); i++) {
                    double v = values[i];
                    if ((v >= lo) && (v <= hi)) {
                        // It is a valid value : add corresponding menu item
                        // item astrating at 1 because index 0 is reserved for a non-defined item.
                        fComboBox.addItem(juce::String(names[i].c_str()), item++);
                        fValues.push_back(v);

                        // Check if this item is a good candidate to represent the current value
                        double delta = fabs(cur-v);
                        if (delta < mindelta) {
                            mindelta = delta;
                            defaultitem = fComboBox.getNumItems();
                        }
                    }
                }
                // check the best candidate to represent the current value
                if (defaultitem > -1) {
                    fComboBox.setSelectedItemIndex(defaultitem);
                }
            }

            *fZone = cur;
        }

        /** Indicate to the FAUST module when the selected items is changed. */
        void comboBoxChanged (juce::ComboBox* cb) override
        {
            //std::cout << getName( )<< " : " << cb->getSelectedId() - 1 << std::endl;
            // -1 because of the starting item  at 1 at the initialization
            modifyZone(fValues[cb->getSelectedId() - 1]);
        }

        virtual void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;

            // search closest value
            int defaultitem = -1;
            double mindelta = FLT_MAX;

            for (unsigned int i = 0; i < fValues.size(); i++) {
                double delta = fabs(fValues[i]-v);
                if (delta < mindelta) {
                    mindelta = delta;
                    defaultitem = i;
                }
            }
            if (defaultitem > -1) {
                fComboBox.setSelectedItemIndex(defaultitem);
            }
        }

        /** Set the good coordinates and size to the juce::ComboBox widget whenever the layout get reiszed */
        virtual void resized() override
        {
            fComboBox.setBounds(0, 0 + kMenuHeight/2, getWidth(), kMenuHeight/2);
        }

        /** Display the name of the Menu */
        virtual void paint(juce::Graphics& g) override
        {
            g.setColour(juce::Colours::black);
            g.drawText(getName(), getLocalBounds().withHeight(getHeight()/2), juce::Justification::centredTop);
        }
    
};

/** Intern class for RadioButton */
class uiRadioButton : public uiComponent, private juce::Button::Listener
{
    
    private:
        
        bool fIsVertical;
        juce::OwnedArray<juce::ToggleButton> fButtons;
        std::vector<double> fValues;

    public:
        /**
         * \brief   Constructor.
         * \details Initialize the uiComponent variables, and the RadioButton specific variables
         *          and parameters. Works in a similar way to the Menu, because it is a special
         *          kind of sliders in the faust logic. 
         * \see     uiMenu
         * 
         * \param   gui, zone, tooltip, label   uiComponent variables.
         * \param   w                           uiComponent variable and width of the RadioButton widget.
         * \param   h                           uiComponent variable and height of the RadioButton widget.
         * \param   cur                         Current "value" associated with the item selected.
         * \param   low                         Lowest "value" possible.
         * \param   hi                          Highest "value" possible.
         * \param   vert                        True if vertical, false if horizontal.
         * \param   names                       Contain the names of the different items.
         * \param   values                      Contain the "values" of the different items.
         * \param   fRadioGroupID               RadioButton being multiple CheckButton in JUCE,
         *                                      we need an ID to know which are linked together.
         */
        uiRadioButton(GUI* gui, FAUSTFLOAT* zone, juce::String label, FAUSTFLOAT w, FAUSTFLOAT h, FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, bool vert, std::vector<std::string>& names, std::vector<double>& values, juce::String tooltip, int radioGroupID) : uiComponent(gui, zone, w, h, label), fIsVertical(vert)
        {
            juce::ToggleButton* defaultbutton = 0;
            double mindelta = FLT_MAX;

            for (int i = 0; i < names.size(); i++) {
                double v = values[i];
                if ((v >= lo) && (v <= hi)) {

                    // It is a valid value included in slider's range
                    juce::ToggleButton* tb = new juce::ToggleButton(names[i]);
                    addAndMakeVisible(tb);
                    tb->setRadioGroupId (radioGroupID);
                    tb->addListener(this);
                    tb->setTooltip(tooltip);
                    fValues.push_back(v);
                    fButtons.add(tb);
      
                    // Check if this item is a good candidate to represent the current value
                    double delta = fabs(cur-v);
                    if (delta < mindelta) {
                        mindelta = delta;
                        defaultbutton = tb;
                    }
                }
            }
            // check the best candidate to represent the current value
            if (defaultbutton) {
                defaultbutton->setToggleState (true, juce::dontSendNotification);
            }
        }
     
        virtual void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;

            // select closest value
            int defaultitem = -1;
            double mindelta = FLT_MAX;

            for (unsigned int i = 0; i < fValues.size(); i++) {
                double delta = fabs(fValues[i]-v);
                if (delta < mindelta) {
                    mindelta = delta;
                    defaultitem = i;
                }
            }
            if (defaultitem > -1) {
                fButtons.operator[](defaultitem)->setToggleState (true, juce::dontSendNotification);
            }
        }

        /** Handle the placement of each juce::ToggleButton everytime the layout size is changed. */
        virtual void resized() override
        {
            int width, height;
            fIsVertical ? (height = (getHeight() - kNameHeight) / fButtons.size()) : (width = getWidth() / fButtons.size());

            for (int i = 0; i < fButtons.size(); i++) {
                if (fIsVertical) {
                    fButtons.operator[](i)->setBounds(0, i * height + kNameHeight, getWidth(), height);
                } else {
                    // kNameHeight pixels offset for the title
                    fButtons.operator[](i)->setBounds(i * width, kNameHeight, width, getHeight() - kNameHeight);
                }
            }
        }
        
        /** Display the RadioButton name */
        virtual void paint(juce::Graphics& g) override
        {
            g.setColour(juce::Colours::black);
            g.drawText(getName(), getLocalBounds().withHeight(kNameHeight), juce::Justification::centredTop);
        }

        /** Check which button is checked, and give its "value" to the FAUST module */
    void buttonClicked(juce::Button* button) override
        {
            juce::ToggleButton* checkButton = dynamic_cast<juce::ToggleButton*>(button);
            //std::cout << getName() << " : " << fButtons.indexOf(checkButton) << std::endl;
            modifyZone(fButtons.indexOf(checkButton));
        }
    
};

/**
 * \brief   Intern class for VU-meter
 * \details There is no JUCE widgets for VU-meter, so its fully designed in this class.
 */
class uiVUMeter : public uiComponent, public juce::SettableTooltipClient, public juce::Timer
{
    
    private:
    
        FAUSTFLOAT fLevel;               // Current level of the VU-meter.
        FAUSTFLOAT fMin, fMax;           // Linear range of the VU-meter.
        FAUSTFLOAT fScaleMin, fScaleMax; // Range in dB if needed.
        bool fDB;                        // True if it's a dB VU-meter, false otherwise.
        VUMeterType fStyle;
        juce::String fUnit;
        juce::Label fLabel;               // Name of the VU-meter.
    
        bool isNameDisplayed()
        {
            return (!(getName().startsWith("0x")) && getName().isNotEmpty());
        }
        
        /** Give the right coordinates and size to the text of Label depending on the VU-meter style */
        void setLabelPos()
        {
            if (fStyle == VVUMeter) {
                // -22 on the height because of the text box.
                fLabel.setBounds((getWidth()-50)/2, getHeight()-22, 50, 20);
            } else if (fStyle == HVUMeter) {
                isNameDisplayed() ? fLabel.setBounds(63, (getHeight()-20)/2, 50, 20)
                : fLabel.setBounds(3, (getHeight()-20)/2, 50, 20);
            } else if (fStyle == NumDisplay) {
                fLabel.setBounds((getWidth()-kNumDisplayWidth)/2,
                                 (getHeight()-kNumDisplayHeight/2)/2,
                                 kNumDisplayWidth,
                                 kNumDisplayHeight/2);
            }
        }
        
        /** Contain all the initialization need for our Label */
        void setupLabel(juce::String tooltip)
        {
            setLabelPos();
            fLabel.setEditable(false, false, false);
            fLabel.setJustificationType(juce::Justification::centred);
            fLabel.setText(juce::String((int)*fZone) + " " + fUnit, juce::dontSendNotification);
            fLabel.setTooltip(tooltip);
            addAndMakeVisible(fLabel);
        }
        
        /**
         * \brief   Generic method to draw an horizontal VU-meter.
         * \details Draw the background of the bargraph, and the TextBox box, without taking
         *          care of the actual level of the VU-meter
         * \see     drawHBargraphDB
         * \see     drawHBargraphLin
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   width   Width of the VU-meter widget.
         * \param   height  Height of the VU-meter widget.
         * \param   level   Current level that needs to be displayed.
         * \param   dB      True if it's a db level, false otherwise.
         */
        void drawHBargraph(juce::Graphics& g, int width, int height)
        {
            float x;
            float y = (float)(getHeight()-height)/2;
            if (isNameDisplayed()) {
                x = 120;
                width -= x;
                // VUMeter Name
                g.setColour(juce::Colours::black);
                g.drawText(getName(), 0, y, 60, height, juce::Justification::centredRight);
            } else {
                x = 60;
                width -= x;
            }
            
            // VUMeter Background
            g.setColour(juce::Colours::lightgrey);
            g.fillRect(x, y, (float)width, (float)height);
            g.setColour(juce::Colours::black);
            g.fillRect(x+1.0f, y+1.0f, (float)width-2, (float)height-2);
            
            // Label Window
            g.setColour(juce::Colours::darkgrey);
            g.fillRect((int)x-58, (getHeight()-22)/2, 52, 22);
            g.setColour(juce::Colours::white.withAlpha(0.8f));
            g.fillRect((int)x-57, (getHeight()-20)/2, 50, 20);
            
            // Call the appropriate drawing method for the level.
            fDB ? drawHBargraphDB (g, y, height) : drawHBargraphLin(g, x, y, width, height);
        }
        
        /**
         * Method in charge of drawing the level of a horizontal dB VU-meter.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   y       y coordinate of the VU-meter.
         * \param   height  Height of the VU-meter.
         * \param   level   Current level of the VU-meter, in dB.
         */
        void drawHBargraphDB(juce::Graphics& g, int y, int height)
        {
            // Drawing Scale
            g.setFont(9.0f);
            g.setColour(juce::Colours::white);
            for (int i = -10; i > fMin; i -= 10) {
                paintScale(g, i);
            }
            for (int i = -6; i < fMax; i += 3)  {
                paintScale(g, i);
            }
            
            int alpha = 200;
            FAUSTFLOAT dblevel = dB2Scale(fLevel);
            
            // We need to test here every color changing levels, to avoid to mix colors because of the alpha,
            // and so to start the new color rectangle at the end of the previous one.
            
            // Drawing from the minimal range to the current level, or -10dB.
            g.setColour(juce::Colour((juce::uint8)40, (juce::uint8)160, (juce::uint8)40, (juce::uint8)alpha));
            g.fillRect(dB2x(fMin), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(fMin), dB2x(-10)-dB2x(fMin)), (float)height-2);
            
            // Drawing from -10dB to the current level, or -6dB.
            if (dblevel > dB2Scale(-10)) {
                g.setColour(juce::Colour((juce::uint8)160, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(dB2x(-10), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(-10), dB2x(-6)-dB2x(-10)), (float)height-2);
            }
            // Drawing from -6dB to the current level, or -3dB.
            if (dblevel > dB2Scale(-6)) {
                g.setColour(juce::Colour((juce::uint8)220, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(dB2x(-6), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(-6), dB2x(-3)-dB2x(-6)), (float)height-2);
            }
            // Drawing from -3dB to the current level, or 0dB.
            if (dblevel > dB2Scale(-3)) {
                g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)160, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(dB2x(-3), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(-3), dB2x(0)-dB2x(-3)), (float)height-2);
            }
            // Drawing from 0dB to the current level, or the max range.
            if (dblevel > dB2Scale(0)) {
                g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)0, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(dB2x(0), y+1.0f, juce::jmin(dB2x(fLevel)-dB2x(0), dB2x(fMax)-dB2x(0)), (float)height-2);
            }
        }
        
        /**
         * Method in charge of drawing the level of a horizontal linear VU-meter.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   x       x coordinate of the VU-meter.
         * \param   y       y coordinate of the VU-meter.
         * \param   height  Height of the VU-meter.
         * \param   width   Width of the VU-meter.
         * \param   level   Current level of the VU-meter, in linear logic.
         */
        void drawHBargraphLin(juce::Graphics& g, int x, int y, int width, int height)
        {
            int alpha = 200;
            juce::Colour c = juce::Colour((juce::uint8)255, (juce::uint8)165, (juce::uint8)0, (juce::uint8)alpha);
            
            // Drawing from the minimal range to the current level, or 20% of the VU-meter
            g.setColour(c.brighter());
            g.fillRect(x+1.0f, y+1.0f, juce::jmin<float>(fLevel*(width-2), 0.2f*(width-2)), (float)height-2);
            // Drawing from 20% of the VU-meter to the current level, or 90% of the VU-meter
            if (fLevel > 0.2f) {
                g.setColour(c);
                g.fillRect(x+1.0f + 0.2f*(width-2), y+1.0f, juce::jmin<float>((fLevel-0.2f) * (width-2), (0.9f-0.2f) * (width-2)), (float)height-2);
            }
            // Drawing from 90% of the VU-meter to the current level, or the maximal range of the VU-meter
            if (fLevel > 0.9f) {
                g.setColour(c.darker());
                g.fillRect(x+1.0f + 0.9f*(width-2), y+1.0f, juce::jmin<float>((fLevel-0.9f) * (width-2), (1.0f-0.9f) * (width-2)), (float)height-2);
            }
        }
        /**
         * \brief   Generic method to draw a vertical VU-meter.
         * \details Draw the background of the bargraph, and the TextBox box, without taking
         *          care of the actual level of the VU-meter
         * \see     drawHBargraphDB
         * \see     drawHBargraphLin
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   width   Width of the VU-meter widget.
         * \param   height  Height of the VU-meter widget.
         * \param   level   Current level that needs to be displayed.
         * \param   dB      True if it's a db level, false otherwise.
         */
        void drawVBargraph(juce::Graphics& g, int width, int height)
        {
            float x = (float)(getWidth()-width)/2;
            float y;
            if (isNameDisplayed()) {
                y = (float)getHeight()-height+15;
                height -= 40;
                // VUMeter Name
                g.setColour(juce::Colours::black);
                g.drawText(getName(), getLocalBounds(), juce::Justification::centredTop);
            } else {
                y = (float)getHeight()-height;
                height -= 25;
            }
            
            // VUMeter Background
            g.setColour(juce::Colours::lightgrey);
            g.fillRect(x, y, (float)width, (float)height);
            g.setColour(juce::Colours::black);
            g.fillRect(x+1.0f, y+1.0f, (float)width-2, (float)height-2);
            
            // Label window
            g.setColour(juce::Colours::darkgrey);
            g.fillRect(juce::jmax((getWidth()-50)/2, 0), getHeight()-23, juce::jmin(getWidth(), 50), 22);
            g.setColour(juce::Colours::white.withAlpha(0.8f));
            g.fillRect(juce::jmax((getWidth()-48)/2, 1), getHeight()-22, juce::jmin(getWidth()-2, 48), 20);
            
            fDB ? drawVBargraphDB (g, x, width) : drawVBargraphLin(g, x, width);
        }
        
        /**
         * Method in charge of drawing the level of a vertical dB VU-meter.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   x       x coordinate of the VU-meter.
         * \param   width   Width of the VU-meter.
         * \param   level   Current level of the VU-meter, in dB.
         */
        void drawVBargraphDB(juce::Graphics& g, int x, int width)
        {
            // Drawing Scale
            g.setFont(9.0f);
            g.setColour(juce::Colours::white);
            for (int i = -10; i > fMin; i -= 10) {
                paintScale(g, i);
            }
            for (int i = -6; i < fMax; i += 3)  {
                paintScale(g, i);
            }
            
            int alpha = 200;
            FAUSTFLOAT dblevel = dB2Scale(fLevel);
            
            // We need to test here every color changing levels, to avoid to mix colors because of the alpha,
            // and so to start the new color rectangle at the end of the previous one.
            
            // Drawing from the minimal range to the current level, or -10dB.
            g.setColour(juce::Colour((juce::uint8)40, (juce::uint8)160, (juce::uint8)40, (juce::uint8)alpha));
            g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(-10)), (float)width-2, dB2y(fMin)-juce::jmax(dB2y(fLevel), dB2y(-10)));
            
            // Drawing from -10dB to the current level, or -6dB.
            if (dblevel > dB2Scale(-10)) {
                g.setColour(juce::Colour((juce::uint8)160, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(-6)), (float)width-2, dB2y(-10)-juce::jmax(dB2y(fLevel), dB2y(-6)));
            }
            // Drawing from -6dB to the current level, or -3dB.
            if (dblevel > dB2Scale(-6)) {
                g.setColour(juce::Colour((juce::uint8)220, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(-3)), (float)width-2, dB2y(-6)-juce::jmax(dB2y(fLevel), dB2y(-3)));
            }
            // Drawing from -3dB to the current level, or 0dB.
            if (dblevel > dB2Scale(-3)) {
                g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)160, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(0)), (float)width-2, dB2y(-3)-juce::jmax(dB2y(fLevel), dB2y(0)));
            }
            // Drawing from 0dB to the current level, or the maximum range.
            if (dblevel > dB2Scale(0)) {
                g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)0, (juce::uint8)20, (juce::uint8)alpha));
                g.fillRect(x+1.0f, juce::jmax(dB2y(fLevel), dB2y(fMax)), (float)width-2, dB2y(0)-juce::jmax(dB2y(fLevel), dB2y(fMax)));
            }
        }
        
        /**
         * Method in charge of drawing the level of a vertical linear VU-meter.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   x       x coordinate of the VU-meter.
         * \param   width   Width of the VU-meter.
         * \param   level   Current level of the VU-meter, in linear logic.
         */
        void drawVBargraphLin(juce::Graphics& g, int x, int width)
        {
            int alpha = 200;
            juce::Colour c = juce::Colour((juce::uint8)255, (juce::uint8)165, (juce::uint8)0, (juce::uint8)alpha);
            
            // Drawing from the minimal range to the current level, or 20% of the VU-meter.
            g.setColour(c.brighter());
            g.fillRect(x+1.0f, juce::jmax(lin2y(fLevel), lin2y(0.2)), (float)width-2, lin2y(fMin)-juce::jmax(lin2y(fLevel), lin2y(0.2)));
            
            // Drawing from 20% of the VU-meter to the current level, or 90% of the VU-meter.
            if (fLevel > 0.2f) {
                g.setColour(c);
                g.fillRect(x+1.0f, juce::jmax(lin2y(fLevel), lin2y(0.9)), (float)width-2, lin2y(0.2)-juce::jmax(lin2y(fLevel), lin2y(0.9)));
            }
            
            // Drawing from 90% of the VU-meter to the current level, or the maximum range.
            if (fLevel > 0.9f) {
                g.setColour(c.darker());
                g.fillRect(x+1.0f, juce::jmax(lin2y(fLevel), lin2y(fMax)), (float)width-2, lin2y(0.9)-juce::jmax(lin2y(fLevel), lin2y(fMax)));
            }
        }
        
        /**
         * Method in charge of drawing the LED VU-meter, dB or not.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   width   Width of the LED.
         * \param   height  Height of the LED.
         * \param   level   Current level of the VU-meter, dB or not.
         */
        void drawLed(juce::Graphics& g, int width, int height)
        {
            float x = (float)(getWidth() - width)/2;
            float y = (float)(getHeight() - height)/2;
            g.setColour(juce::Colours::black);
            g.fillEllipse(x, y, width, height);
            
            if (fDB) {
                int alpha = 200;
                FAUSTFLOAT dblevel = dB2Scale(fLevel);
                
                // Adjust the color depending on the current level
                g.setColour(juce::Colour((juce::uint8)40, (juce::uint8)160, (juce::uint8)40, (juce::uint8)alpha));
                if (dblevel > dB2Scale(-10)) {
                    g.setColour(juce::Colour((juce::uint8)160, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                }
                if (dblevel > dB2Scale(-6)) {
                    g.setColour(juce::Colour((juce::uint8)220, (juce::uint8)220, (juce::uint8)20, (juce::uint8)alpha));
                }
                if (dblevel > dB2Scale(-3)) {
                    g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)160, (juce::uint8)20, (juce::uint8)alpha));
                }
                if (dblevel > dB2Scale(0))  {
                    g.setColour(juce::Colour((juce::uint8)240, (juce::uint8)0, (juce::uint8)20, (juce::uint8)alpha));
                }
                
                g.fillEllipse(x+1, y+1, width-2, height-2);
            } else {
                // The alpha depend on the level, from 0 to 1
                g.setColour(juce::Colours::red.withAlpha((float)fLevel));
                g.fillEllipse(x+1, y+1, width-2, height-2);
            }
        }
        
        /**
         * Method in charge of drawing the Numerical Display VU-meter, dB or not.
         *
         * \param   g       JUCE graphics context, used to draw components or images.
         * \param   width   Width of the Numerical Display.
         * \param   height  Height of the Numerical Display.
         * \param   level   Current level of the VU-meter.
         */
        void drawNumDisplay(juce::Graphics& g, int width, int height)
        {
            // Centering it
            int x = (getWidth()-width) / 2;
            int y = (getHeight()-height) / 2;
            
            // Draw box.
            g.setColour(juce::Colours::darkgrey);
            g.fillRect(x, y, width, height);
            g.setColour(juce::Colours::white.withAlpha(0.8f));
            g.fillRect(x+1, y+1, width-2, height-2);
            
            // Text is handled by the setLabelPos() function
        }
        
        /** Convert a dB level to a y coordinate, for easier draw methods. */
        FAUSTFLOAT dB2y(FAUSTFLOAT dB)
        {
            FAUSTFLOAT s0 = fScaleMin;      // Minimal range.
            FAUSTFLOAT s1 = fScaleMax;      // Maximum range.
            FAUSTFLOAT sx = dB2Scale(dB);   // Current level.
            
            int h;
            int treshold;   // Value depend if the name is displayed
            
            if (isNameDisplayed()) {
                h = getHeight()-42; // 15 pixels for the VU-Meter name,
                // 25 for the textBox, 2 pixels margin.
                treshold = 16;      // 15 pixels for the VU-Meter name.
            } else {
                h = getHeight()-27; // 25 for the textBox, 2 pixels margin.
                treshold = 1;       // 1 pixel margin.
            }
            
            return (h - h*(s0-sx)/(s0-s1)) + treshold;
        }
        
        /** Convert a linear level to a y coordinate, for easier draw methods. */
        FAUSTFLOAT lin2y(FAUSTFLOAT level)
        {
            int h;
            int treshold;
            
            if (isNameDisplayed()) {
                h = getHeight()-42; // 15 pixels for the VU-Meter name,
                // 25 for the textBox, 2 pixels margin.
                treshold = 16;      // 15 pixels for the VU-Meter name.
            } else {
                h = getHeight()-27; // 25 for the textBox, 2 pixels margin.
                treshold = 1;       // 1 pixel margin.
            }
            
            return h * (1 - level) + treshold;
        }
        
        /** Convert a dB level to a x coordinate, for easier draw methods. */
        FAUSTFLOAT dB2x(FAUSTFLOAT dB)
        {
            FAUSTFLOAT s0 = fScaleMin;      // Minimal range.
            FAUSTFLOAT s1 = fScaleMax;      // Maximal range.
            FAUSTFLOAT sx = dB2Scale(dB);   // Current level.
            
            int w;
            int treshold;
            
            if (isNameDisplayed()) {
                w = getWidth()-122; // 60 pixels for the VU-Meter name,
                // 60 for the TextBox, 2 pixels margin.
                treshold = 121;     // 60 pixels for the VU-Meter name,
                // 60 for the TextBox, and 1 pixel margin.
            } else {
                w = getWidth()-62;  // 60 pixels for the TextBox, 2 pixels margin.
                treshold = 61;      // 60 pixels for the TextBox, 1 pixel margin.
            }
            
            return treshold + w - w*(s1-sx)/(s1-s0);
        }
        
        /** Write the different level included in the VU-Meter range. */
        void paintScale(juce::Graphics& g, float num)
        {
            juce::Rectangle<int> r;
            
            if (fStyle == VVUMeter) {
                r = juce::Rectangle<int>((getWidth()-(kVBargraphWidth/2))/2 + 1,  // Left side of the VU-Meter.
                                         dB2y(num),                               // Vertically centred with 20 height.
                                         (kVBargraphWidth/2)-2,                   // VU-Meter width with margin.
                                         20);                                     // 20 height.
                g.drawText(juce::String(num), r, juce::Justification::centredRight, false);
            } else {
                r = juce::Rectangle<int>(dB2x(num)-10,                            // Horizontally centred with 20 width.
                                        (getHeight()-kHBargraphHeight/2)/2 + 1,  // Top side of the VU-Meter.
                                        20,                                      // 20 width.
                                        (kHBargraphHeight/2)-2);                 // VU-Meter height with margin
                g.drawText(juce::String(num), r, juce::Justification::centredTop, false);
            }
        }
        
        /** Set the level, keep it in the range of the VU-Meter, and set the TextBox text. */
        void setLevel()
        {
            FAUSTFLOAT rawLevel = *fZone;
        #if JUCE_DEBUG
            if (std::isnan(rawLevel)) {
                std::cerr << "uiVUMeter: NAN\n";
            }
        #endif
            if (fDB) {
                fLevel = range(rawLevel);
            } else {
                fLevel = range((rawLevel-fMin)/(fMax-fMin));
            }
            fLabel.setText(juce::String((int)rawLevel) + " " + fUnit, juce::dontSendNotification);
        }
        
        FAUSTFLOAT range(FAUSTFLOAT level) { return (level > fMax) ? fMax : ((level < fMin) ? fMin : level); }
    
    public:
    
        /**
         * \brief   Constructor.
         * \details Initialize the uiComponent variables and the VU-meter specific ones.
         *
         * \param   gui, zone, w, h, tooltip, label     uiComponent variables.
         * \param   mini                                Minimal value of the VU-meter range.
         * \param   maxi                                Maximal value of the VU-meter range.
         * \param   unit                                Unit of the VU-meter (dB or not).
         * \param   style                               Type of the VU-meter (see VUMeterType).
         * \param   vert                                True if vertical, false if horizontal.
         */
        uiVUMeter (GUI* gui, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, juce::String label, FAUSTFLOAT mini, FAUSTFLOAT maxi, juce::String unit, juce::String tooltip, VUMeterType style, bool vert)
            : uiComponent(gui, zone, w, h, label), fMin(mini), fMax(maxi), fStyle(style)
        {
            fLevel = 0;         // Initialization of the level
            startTimer(50);     // Launch a timer that trigger a callback every 50ms
            this->fUnit = unit;
            fDB = (unit == "dB");
            
            if (fDB) {
                // Conversion in dB of the range
                fScaleMin = dB2Scale(fMin);
                fScaleMax = dB2Scale(fMax);
            }
            setTooltip(tooltip);
            
            // No text editor for LEDs
            if (fStyle != Led) {
                setupLabel(tooltip);
            }
        }
        
        /** Method called by the timer every 50ms, to refresh the VU-meter if it needs to */
        void timerCallback() override
        {
            if (isShowing()) {
                //Force painting at the initialisation
                bool forceRepaint = (fLevel == 0);
                FAUSTFLOAT lastLevel = fLevel;   //t-1
                setLevel(); //t
                
                // Following condition means that we're repainting our VUMeter only if
                // there's one or more changing pixels between last state and this one,
                // and if the curent level is included in the VUMeter range. It improves
                // performances a lot in IDLE. It's the same for the other style of VUMeter
                
                if (fDB) {
                    switch (fStyle) {
                        case VVUMeter:
                            if (((int)dB2y(lastLevel) != (int)dB2y(fLevel) && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case HVUMeter:
                            if (((int)dB2x(lastLevel) != (int)dB2x(fLevel) && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case NumDisplay:
                            if (((int)lastLevel != (int)fLevel && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case Led:
                            if ((dB2Scale(lastLevel) != dB2Scale(fLevel) && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        default:
                            break;
                    }
                } else {
                    switch (fStyle) {
                        case VVUMeter:
                            if (((int)lin2y(lastLevel) != (int)lin2y(fLevel) && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case HVUMeter:
                            if ((std::abs(lastLevel-fLevel) > 0.01 && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case NumDisplay:
                            if ((std::abs(lastLevel-fLevel) > 0.01 && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        case Led:
                            if (((int)lastLevel != (int)fLevel && fLevel >= fMin && fLevel <= fMax) || forceRepaint) {
                                repaint();
                            }
                            break;
                        default:
                            break;
                    }
                }
            } else {
                fLevel = 0;
            }
        }
        
        /**
         * Call the appropriate drawing method according to the VU-meter style
         * \see drawLed
         * \see drawNumDisplay
         * \see drawVBargraph
         * \see drawHBargraph
         */
        void paint(juce::Graphics& g) override
        {
            switch (fStyle) {
                case Led:
                    drawLed(g, kLedWidth, kLedHeight);
                    break;
                case NumDisplay:
                    drawNumDisplay(g, kNumDisplayWidth, kNumDisplayHeight/2);
                    break;
                case VVUMeter:
                    drawVBargraph(g, kVBargraphWidth/2, getHeight());
                    break;
                case HVUMeter:
                    drawHBargraph(g, getWidth(), kHBargraphHeight/2);
                    break;
                default:
                    break;
            }
        }
        
        /** Set the Label position whenever the layout size changes. */
        void resized() override
        {
            setLabelPos();
        }
        
        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
        }
    
};

/** Intern class for tab widget */
class uiTabBox : public uiBase, public juce::TabbedComponent
{
    
public:
    /**
     * \brief   Constructor.
     * \details Initalize the juce::TabbedComponent tabs to be at top, and the uiTabBox size at 0
     */
    uiTabBox():uiBase(),juce::TabbedComponent(juce::TabbedButtonBar::TabsAtTop)
    {}
    
    /**
     * Initialize all his child ratios (1 uiBox per tabs), the LookAndFeel
     * and the uiTabBox size to fit the biggest of its child.
     */
    void init(juce::Component* comp = nullptr) override
    {
        for (int i = 0; i < getNumTabs(); i++) {
            Component* comp = getTabContentComponent(i);
            uiBase* base_comp = dynamic_cast<uiBase*>(comp);
            base_comp->init(comp);
            
            // The TabbedComponent size should be as big as its bigger child's dimension, done here
            fTotalWidth = juce::jmax(fTotalWidth, base_comp->getTotalWidth());
            fTotalHeight = juce::jmax(fTotalHeight, base_comp->getTotalHeight());
        }
        
        fTotalHeight += 30;  // 30 height for the TabBar.
    }
    
    void setRecommendedSize() override
    {
        for (int i = 0; i < getNumTabs(); i++) {
            uiBase* comp = dynamic_cast<uiBase*>(getTabContentComponent(i));
            comp->setRecommendedSize();
            
            // The TabbedComponent size should be as big as its bigger child's dimension, done here
            fTotalWidth = juce::jmax(fTotalWidth, comp->getTotalWidth());
            fTotalHeight = juce::jmax(fTotalHeight, comp->getTotalHeight());
        }
        
        fTotalHeight += 30;  // 30 height for the TabBar
    }
    
    void add(Component* comp) override
    {
        // Name of the component is moved in Tab (so removed from component)
        juce::TabbedComponent::addTab(comp->getName(), juce::Colours::white, comp, true);
        comp->setName("");
    }
    
};

/**
 * \brief   Intern class for box widgets
 * \details That's the class where the whole layout is calculated.
 */
class uiBox : public uiBase, public juce::Component
{
  
    private:
    
        bool fIsVertical;
    
        bool isNameDisplayed()
        {
            return (!(getName().startsWith("0x")) && getName().isNotEmpty());
        }
    
        /**
         * \brief   Return the vertical dimension size for a child to be displayed in.
         *
         */
        int getVSpaceToRemove()
        {
            // Checking if the name is displayed, to give to good amount space for child components
            // kNameHeight pixels is the bix name, kMargin pixel per child components for the margins
            if (isNameDisplayed()) {
                return (getHeight() - kNameHeight - kMargin * getNumChildComponents());
            } else {
                return (getHeight() - kMargin * getNumChildComponents());
            }
        }
    
        /**
         * \brief   Return the vertical dimension size for a child to be displayed in.
         *
         */
        int getHSpaceToRemove()
        {
            // Don't need to check for an horizontal box, as it height doesn't matter
            return (getWidth() - kMargin * getNumChildComponents());
        }
    
    public:
        /**
         * \brief   Constructor.
         * \details Initialize uiBase variables and uiBox specific ones.
         *
         * \param   vert        True if it's a vertical box, false otherwise.
         * \param   boxName     Name of the uiBox.
         */
        uiBox(bool vert, juce::String boxName): uiBase(0,0), juce::Component(boxName), fIsVertical(vert)
        {}
    
        /**
         * \brief   Destructor.
         * \details Delete all uiBox recusively, but not the uiComponent,
         *          because it's handled by the uiItem FAUST objects.
         */
        virtual ~uiBox()
        {
            /*
             Deleting boxes, from leaves to root:
             - leaves (uiComponent) are deleted by the uiItem mechanism
             - containers (uiBox and uiTabBox) have to be explicitly deleted
             */
            for (int i = getNumChildComponents()-1; i >= 0; i--) {
                delete dynamic_cast<uiBox*>(getChildComponent(i));
                delete dynamic_cast<uiTabBox*>(getChildComponent(i));
            }
        }

        /**
         * \brief   Initialization of the DisplayRect and Total size.
         * \details Calculate the correct size for each box, depending on its child sizes.
         */
        void setRecommendedSize() override
        {
            // Initialized each time
            fDisplayRectWidth = fDisplayRectHeight = 0;
            
            // Display rectangle size is the sum of a dimension on a side, and the max of the other one
            // on the other side, depending on its orientation (horizontal/vertical).
            // Using child's totalSize, because the display rectangle size need to be as big as
            // all of its child components with their margins included.
            for (int j = 0; j < getNumChildComponents(); j++) {
                uiBase* base_comp = dynamic_cast<uiBase*>(getChildComponent(j));
                if (fIsVertical) {
                    fDisplayRectWidth = juce::jmax(fDisplayRectWidth, base_comp->getTotalWidth());
                    fDisplayRectHeight += base_comp->getTotalHeight();
                } else {
                    fDisplayRectWidth += base_comp->getTotalWidth();
                    fDisplayRectHeight = juce::jmax(fDisplayRectHeight, base_comp->getTotalHeight());
                }
            }
            
            fTotalHeight = fDisplayRectHeight;
            fTotalWidth = fDisplayRectWidth;
            
            // Adding kMargin pixels of margins per child component on a dimension, and just kMargin on
            // the other one, depending on its orientation
            
            if (fIsVertical) {
                fTotalHeight += kMargin * getNumChildComponents();
                fTotalWidth += kMargin;
            } else {
                fTotalWidth += kMargin * getNumChildComponents();
                fTotalHeight += kMargin;
            }
         
            // Adding kNameHeight pixels on its height to allow the name to be displayed
            if (isNameDisplayed()) {
                fTotalHeight += kNameHeight;
            }
        }

        /** Initiate the current box ratio, and its child's ones recursively. */
        void init(juce::Component* comp = nullptr) override
        {
            uiBase::init(this);
            
            // Going through the Component tree recursively
            for (int i = 0; i < getNumChildComponents(); i++) {
                Component* comp = getChildComponent(i);
                uiBase* base_comp = dynamic_cast<uiBase*>(comp);
                base_comp->init(comp);
            }
        }

        /**
         * \brief   Main layout function.
         * \details Allow to place all uiBase child correctly according to their ratios
         *          and the current box size.
         *
         * \param   displayRect    Absolute raw bounds of the current box (with margins
         *                          and space for the title).
         */
        void resized() override
        {
            juce::Rectangle<int> displayRect = getBounds();
            
            // Deleting space for the box name if it needs to be shown
            if (isNameDisplayed()) {
                displayRect.removeFromTop(kNameHeight);
            }
            
            // Putting the margins
            displayRect.reduce(kMargin/2, kMargin/2);
            
            // Give child components an adapt size depending on its ratio and the current box size
            for (int i = 0; i < getNumChildComponents(); i++) {
                juce::Component* comp = getChildComponent(i);
                uiBase* base_comp = dynamic_cast<uiBase*>(comp);
                
                if (fIsVertical) {
                    int heightToRemove = getVSpaceToRemove() * base_comp->getVRatio();
                    // Remove the space needed from the displayRect, and translate it to show the margins
                    base_comp->setRelativeSize(comp, displayRect.removeFromTop(heightToRemove).translated(0, kMargin * i));
                } else {
                    int widthToRemove = getHSpaceToRemove() * base_comp->getHRatio();
                    // Remove the space needed from the displayRect, and translate it to show the margins
                    base_comp->setRelativeSize(comp, displayRect.removeFromLeft(widthToRemove).translated(kMargin * i, 0));
                }
            }
        }

        /** 
         * Fill the uiBox bounds with a grey color, different shades depending on its order.
         * Write the uiBox name if it needs to.
         */
        void paint(juce::Graphics& g) override
        {
            // Fill the box background in gray shades
            g.setColour(juce::Colours::black.withAlpha(0.05f));
            g.fillRect(getLocalBounds());

            // Display the name if it's needed
            if (isNameDisplayed()) {
                g.setColour(juce::Colours::black);
                g.drawText(getName(), getLocalBounds().withHeight(kNameHeight), juce::Justification::centred);
            }
        }
        
        void add(juce::Component* comp) override
        {
            addAndMakeVisible(comp);
        }
    
};

/** Class in charge of doing the glue between FAUST and JUCE */
class JuceGUI : public GUI, public MetaDataUI, public juce::Component
{
    
    private:
    
        std::stack<uiBase*> fBoxStack;
        uiBase* fCurrentBox = nullptr;   // Current box used in buildUserInterface logic.
        
        int fRadioGroupID;               // In case of radio buttons.
        std::unique_ptr<juce::LookAndFeel> fLaf = std::make_unique<juce::LookAndFeel_V4>();
    
        /** Add generic box to the user interface. */
        void openBox(uiBase* box)
        {
            if (fCurrentBox) {
                fCurrentBox->add(dynamic_cast<juce::Component*>(box));
                fBoxStack.push(fCurrentBox);
            }
            fCurrentBox = box;
        }
     
        /** Add a slider to the user interface. */
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, int kWidth, int kHeight, SliderType type)
        {
            if (isKnob(zone)) {
                addKnob(label, zone, *zone, min, max, step);
            } else if (isRadio(zone)) {
                addRadioButtons(label, zone, *zone, min, max, step, fRadioDescription[zone].c_str(), false);
            } else if (isMenu(zone)) {
                addMenu(label, zone, *zone, min, max, step, fMenuDescription[zone].c_str());
            } else {
                fCurrentBox->add(new uiSlider(this, zone, kWidth, kHeight, *zone, min, max, step, juce::String(label), juce::String(fUnit[zone]), juce::String(fTooltip[zone]), getScale(zone), type));
            }
        }
        
        /** Add a radio buttons to the user interface. */
        void addRadioButtons(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, const char* mdescr, bool vert)
        {
            std::vector<std::string> names;
            std::vector<double> values;
            parseMenuList(mdescr, names, values); // Set names and values vectors
            
            // and not just n checkButtons :
            // TODO : check currently unused checkButtonWidth...
            int checkButtonWidth = 0;
            for (int i = 0; i < names.size(); i++) {
                // Checking the maximum of horizontal space needed to display the radio buttons
                checkButtonWidth = juce::jmax(juce::Font().getStringWidth(juce::String(names[i])) + 15, checkButtonWidth);
            }
            
            if (vert) {
                fCurrentBox->add(new uiRadioButton(this, zone, juce::String(label), kCheckButtonWidth, names.size() * (kRadioButtonHeight - 25) + 25, *zone, min, max, true, names, values, juce::String(fTooltip[zone]), fRadioGroupID++));
            } else {
                fCurrentBox->add(new uiRadioButton(this, zone, juce::String(label), kCheckButtonWidth, kRadioButtonHeight, *zone, min, max, false, names, values, juce::String(fTooltip[zone]), fRadioGroupID++));
            }
        }
        
        /** Add a menu to the user interface. */
        void addMenu(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, const char* mdescr)
        {
            fCurrentBox->add(new uiMenu(this, zone, juce::String(label), kMenuWidth, kMenuHeight, *zone, min, max, juce::String(fTooltip[zone]), mdescr));
        }
        
        /** Add a ciruclar slider to the user interface. */
        void addKnob(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {
            fCurrentBox->add(new uiSlider(this, zone, kKnobWidth, kKnobHeight, *zone, min, max, step, juce::String(label), juce::String(fUnit[zone]), juce::String(fTooltip[zone]), getScale(zone), Knob));
        }
        
        /** Add a bargraph to the user interface. */
        void addBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, int kWidth, int kHeight, VUMeterType type)
        {
            if (isLed(zone)) {
                addLed(juce::String(label), zone, min, max);
            } else if (isNumerical(zone)) {
                addNumericalDisplay(juce::String(label), zone, min, max);
            } else {
                fCurrentBox->add(new uiVUMeter (this, zone, kWidth, kHeight, juce::String(label), min, max, juce::String(fUnit[zone]), juce::String(fTooltip[zone]), type, false));
            }
        }
        
    public:
        /**
         * \brief   Constructor, displaying the *current state* of all controller zones.
         * \details Initialize the JuceGUI specific variables. 
         */
        JuceGUI():fRadioGroupID(1) // fRadioGroupID must start at 1
        {
            setLookAndFeel(fLaf.get());
        }
        
        /**
         * \brief   Destructor.
         * \details Delete root box used in buildUserInterface logic.
         */
        virtual ~JuceGUI()
        {
            setLookAndFeel(nullptr);
            delete fCurrentBox;
        }

        /** Return the size of the FAUST program */
        juce::Rectangle<int> getSize()
        {
            // Mininum size in case of empty GUI
            if (fCurrentBox) {
                juce::Rectangle<int> res = fCurrentBox->getSize();
                res.setSize(std::max<int>(1, res.getWidth()*0.8), std::max<int>(1, res.getHeight()*0.8));
                return res;
            } else {
                return juce::Rectangle<int>(0, 0, 1, 1);
            }
        }

        /** Initialize the uiTabBox component to be visible. */
        virtual void openTabBox(const char* label) override
        {
            openBox(new uiTabBox());
        }
        
        /** Add a new vertical box to the user interface. */
        virtual void openVerticalBox(const char* label) override
        {
            openBox(new uiBox(true, juce::String(label)));
        }

        /** Add a new horizontal box to the user interface. */
        virtual void openHorizontalBox(const char* label) override
        {
            openBox(new uiBox(false, juce::String(label)));
        }

        /** Close the current box. */
        virtual void closeBox() override
        {
            fCurrentBox->setRecommendedSize();
            
            if (fBoxStack.empty()) {
                // Add root box in JuceGUI component
                addAndMakeVisible(dynamic_cast<juce::Component*>(fCurrentBox));
                fCurrentBox->init();
                // Force correct draw
                resized();
            } else {
                fCurrentBox = fBoxStack.top();
                fBoxStack.pop();
            }
        }
     
        /** Add an horizontal slider to the user interface. */
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        {
            addSlider(label, zone, init, min, max, step, kHSliderWidth, kHSliderHeight, HSlider);
        }
        
        /** Add a vertical slider to the user interface. */
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        {
            int newWidth = juce::jmax(juce::Font().getStringWidth(juce::String(label)), kVSliderWidth) + kMargin;
            addSlider(label, zone, init, min, max, step, newWidth, kVSliderHeight, VSlider);
        }
        
        /** Add a button to the user interface. */
        virtual void addButton(const char* label, FAUSTFLOAT* zone) override
        {
            fCurrentBox->add(new uiButton(this, zone, kButtonWidth, kButtonHeight, juce::String(label), juce::String(fTooltip[zone])));
        }
        
        /** Add a check button to the user interface. */
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) override
        {
            // newWidth is his text size, plus the check box size
            int newWidth = juce::Font().getStringWidth(juce::String(label)) + kCheckButtonWidth;
            fCurrentBox->add(new uiCheckButton(this, zone, newWidth, kCheckButtonHeight, juce::String(label), juce::String(fTooltip[zone])));
        }
        
        /** Add a numerical entry to the user interface. */
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        {
            // kMargin pixels between the slider and his name
            int newWidth = juce::Font().getStringWidth(juce::String(label)) + kNumEntryWidth + kMargin;
            fCurrentBox->add(new uiSlider(this, zone, newWidth, kNumEntryHeight, *zone, min, max, step, juce::String(label), juce::String(fUnit[zone]), juce::String(fTooltip[zone]), getScale(zone), NumEntry));
        }
        
        /** Add a vertical bargraph to the user interface. */
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        {
            addBargraph(label, zone, min, max, kVBargraphWidth, kVBargraphHeight, VVUMeter);
        }
        
        /** Add a vertical bargraph to the user interface. */
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        {
            addBargraph(label, zone, min, max, kHBargraphWidth, kHBargraphHeight, HVUMeter);
        }
      
        /** Add a LED to the user interface. */
        void addLed(juce::String label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            fCurrentBox->add(new uiVUMeter(this, zone, kLedWidth, kLedHeight, label, min, max, juce::String(fUnit[zone]), juce::String(fTooltip[zone]), Led, false));
        }
        
        /** Add a numerical display to the user interface. */
        void addNumericalDisplay(juce::String label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {
            fCurrentBox->add(new uiVUMeter(this, zone, kNumDisplayWidth, kNumDisplayHeight, label, min, max, juce::String(fUnit[zone]), juce::String(fTooltip[zone]), NumDisplay, false));
        }
        
        /** Declare a metadata. */
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* value) override
        {
            MetaDataUI::declare(zone, key, value);
        }

        /** Resize its child to match the new bounds */
        void resized() override
        {
            if (fCurrentBox) {
                dynamic_cast<Component*>(fCurrentBox)->setBounds(getLocalBounds());
            }
        }
    
};

#endif
/**************************  END  JuceGUI.h **************************/
#endif
/************************** BEGIN JuceParameterUI.h *************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef JuceParameterUI_H
#define JuceParameterUI_H

#include "../JuceLibraryCode/JuceHeader.h"


// Link AudioParameterBool with on/off parameter

struct FaustPlugInAudioParameterBool : public juce::AudioParameterBool, public uiOwnedItem {
    
    FaustPlugInAudioParameterBool(GUI* gui, FAUSTFLOAT* zone, const std::string& path, const std::string& label)
    :juce::AudioParameterBool(path, label, false), uiOwnedItem(gui, zone)
    {}
    
    virtual ~FaustPlugInAudioParameterBool() {}
    
    void reflectZone() override
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        setValueNotifyingHost(float(v));
    }
    
    virtual void setValue (float newValue) override
    {
        modifyZone(FAUSTFLOAT(newValue));
    }
    
};

// Link AudioParameterFloat with range parameters

struct FaustPlugInAudioParameterFloat : public juce::AudioParameterFloat, public uiOwnedItem {
    
    FaustPlugInAudioParameterFloat(GUI* gui, FAUSTFLOAT* zone, const std::string& path, const std::string& label, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    :juce::AudioParameterFloat(path, label, float(min), float(max), float(init)), uiOwnedItem(gui, zone)
    {}
    
    virtual ~FaustPlugInAudioParameterFloat() {}
    
    void reflectZone() override
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        if (v >= range.start && v <= range.end) {
            setValueNotifyingHost(range.convertTo0to1(float(v)));
        }
    }
    
    virtual void setValue (float newValue) override
    {
        modifyZone(FAUSTFLOAT(range.convertFrom0to1(newValue)));
    }
    
};

// A class to create AudioProcessorParameter objects for each zone

class JuceParameterUI : public GUI, public PathBuilder {
    
    private:
        
        juce::AudioProcessor* fProcessor;
        
    public:
        
        JuceParameterUI(juce::AudioProcessor* processor):fProcessor(processor)
        {}
    
        virtual ~JuceParameterUI() {}
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        virtual void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        virtual void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        virtual void closeBox()
        {
            popLabel();
        }
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterBool(this, zone, buildPath(label), label));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterBool(this, zone, buildPath(label), label));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, init, min, max, step));
        }
        
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, init, min, max, step));
        }
        
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, init, min, max, step));
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, 0, min, max, 0));
        }
        
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            fProcessor->addParameter(new FaustPlugInAudioParameterFloat(this, zone, buildPath(label), label, 0, min, max, 0));
        }
    
};

#endif
/**************************  END  JuceParameterUI.h **************************/
/************************** BEGIN JuceStateUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef JuceStateUI_H
#define JuceStateUI_H

#include "../JuceLibraryCode/JuceHeader.h"


// A class to save/restore DSP state using JUCE, which also set default values at construction time.

struct JuceStateUI : public MapUI {
    
    bool fRestored;
    
    JuceStateUI():fRestored(false) {}
    virtual ~JuceStateUI() {}
    
    void getStateInformation (juce::MemoryBlock& destData)
    {
        juce::MemoryOutputStream stream (destData, true);
        
        // Write path and values
        if (sizeof(FAUSTFLOAT) == sizeof(float)) {
            for (const auto& it : getFullpathMap()) {
                stream.writeString(it.first);
                stream.writeFloat(*it.second);
            }
        } else {
            for (const auto& it : getFullpathMap()) {
                stream.writeString(it.first);
                stream.writeDouble(*it.second);
            }
        }
    }
    
    void setStateInformation (const void* data, int sizeInBytes)
    {
        fRestored = true;
        juce::MemoryInputStream stream (data, static_cast<size_t> (sizeInBytes), false);
        std::string path;
        
        // Read path then value and try to restore them
        if (sizeof(FAUSTFLOAT) == sizeof(float)) {
            while ((path = stream.readString().toStdString()) != "") {
                setParamValue(path, stream.readFloat());
            }
        } else {
            while ((path = stream.readString().toStdString()) != "") {
                setParamValue(path, stream.readDouble());
            }
        }
    }
    
    // -- active widgets
    // use MapUI derived methods
    
    // -- passive widgets
    // empty si we don't want to save/restore them
    void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax) {}
    void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax) {}
    
};

#endif
/**************************  END  JuceStateUI.h **************************/

// Always included otherwise -i mode sometimes fails...

#if defined(SOUNDFILE)
/************************** BEGIN SoundUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>
#include <iostream>


#if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
#include <CoreFoundation/CFBundle.h>
#endif

// Always included otherwise -i mode later on will not always include it (with the conditional includes)
/************************** BEGIN Soundfile.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __Soundfile__
#define __Soundfile__

#include <string.h>
#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define MAX_CHAN 64
#define MAX_SOUNDFILE_PARTS 256

#ifdef _MSC_VER
#define PRE_PACKED_STRUCTURE __pragma(pack(push, 1))
#define POST_PACKED_STRUCTURE \
    ;                         \
    __pragma(pack(pop))
#else
#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))
#endif

/*
 The soundfile structure to be used by the DSP code. Soundfile has a MAX_SOUNDFILE_PARTS parts 
 (even a single soundfile or an empty soundfile). 
 The fLength, fOffset and fSR fields are filled accordingly by repeating the actual parts if needed.
 The fBuffers contains MAX_CHAN non-interleaved arrays of samples.
 
 It has to be 'packed' to that the LLVM backend can correctly access it.

 Index computation:
    - p is the current part number [0..MAX_SOUNDFILE_PARTS-1] (must be proved by the type system)
    - i is the current position in the part. It will be constrained between [0..length]
    - idx(p,i) = fOffset[p] + max(0, min(i, fLength[p]));
*/

PRE_PACKED_STRUCTURE
struct Soundfile {
    void* fBuffers; // will correspond to a double** or float** pointer chosen at runtime
    int* fLength;   // length of each part (so fLength[P] contains the length in frames of part P)
    int* fSR;       // sample rate of each part (so fSR[P] contains the SR of part P)
    int* fOffset;   // offset of each part in the global buffer (so fOffset[P] contains the offset in frames of part P)
    int fChannels;  // max number of channels of all concatenated files
    int fParts;     // the total number of loaded parts
    bool fIsDouble; // keep the sample format (float or double)

    Soundfile(int cur_chan, int length, int max_chan, int total_parts, bool is_double)
    {
        fLength   = new int[MAX_SOUNDFILE_PARTS];
        fSR       = new int[MAX_SOUNDFILE_PARTS];
        fOffset   = new int[MAX_SOUNDFILE_PARTS];
        fIsDouble = is_double;
        fChannels = cur_chan;
        fParts    = total_parts;
        if (fIsDouble) {
            fBuffers = allocBufferReal<double>(cur_chan, length, max_chan);
        } else {
            fBuffers = allocBufferReal<float>(cur_chan, length, max_chan);
        }
    }
    
    template <typename REAL>
    void* allocBufferReal(int cur_chan, int length, int max_chan)
    {
        REAL** buffers = new REAL*[max_chan];
        for (int chan = 0; chan < cur_chan; chan++) {
            buffers[chan] = new REAL[length];
            memset(buffers[chan], 0, sizeof(REAL) * length);
        }
        return buffers;
    }
    
    void copyToOut(int size, int channels, int max_channels, int offset, void* buffer)
    {
        if (fIsDouble) {
            copyToOutReal<double>(size, channels, max_channels, offset, buffer);
       } else {
            copyToOutReal<float>(size, channels, max_channels, offset, buffer);
        }
    }
    
    void shareBuffers(int cur_chan, int max_chan)
    {
        // Share the same buffers for all other channels so that we have max_chan channels available
        if (fIsDouble) {
            for (int chan = cur_chan; chan < max_chan; chan++) {
                static_cast<double**>(fBuffers)[chan] = static_cast<double**>(fBuffers)[chan % cur_chan];
            }
        } else {
            for (int chan = cur_chan; chan < max_chan; chan++) {
                static_cast<float**>(fBuffers)[chan] = static_cast<float**>(fBuffers)[chan % cur_chan];
            }
        }
    }
    
    template <typename REAL>
    void copyToOutReal(int size, int channels, int max_channels, int offset, void* buffer)
    {
        for (int sample = 0; sample < size; sample++) {
            for (int chan = 0; chan < channels; chan++) {
                static_cast<REAL**>(fBuffers)[chan][offset + sample] = static_cast<REAL*>(buffer)[sample * max_channels + chan];
            }
        }
    }
    
    template <typename REAL>
    void getBuffersOffsetReal(void* buffers, int offset)
    {
        for (int chan = 0; chan < fChannels; chan++) {
            static_cast<REAL**>(buffers)[chan] = &(static_cast<REAL**>(fBuffers))[chan][offset];
        }
    }
    
    void emptyFile(int part, int& offset)
    {
        fLength[part] = BUFFER_SIZE;
        fSR[part] = SAMPLE_RATE;
        fOffset[part] = offset;
        // Update offset
        offset += fLength[part];
    }
 
    ~Soundfile()
    {
        // Free the real channels only
        if (fIsDouble) {
            for (int chan = 0; chan < fChannels; chan++) {
                delete[] static_cast<double**>(fBuffers)[chan];
            }
            delete[] static_cast<double**>(fBuffers);
        } else {
            for (int chan = 0; chan < fChannels; chan++) {
                delete[] static_cast<float**>(fBuffers)[chan];
            }
            delete[] static_cast<float**>(fBuffers);
        }
        delete[] fLength;
        delete[] fSR;
        delete[] fOffset;
    }

} POST_PACKED_STRUCTURE;

/*
 The generic soundfile reader.
 */

class SoundfileReader {
    
   protected:
    
    int fDriverSR;
   
    // Check if a soundfile exists and return its real path_name
    std::string checkFile(const std::vector<std::string>& sound_directories, const std::string& file_name)
    {
        if (checkFile(file_name)) {
            return file_name;
        } else {
            for (size_t i = 0; i < sound_directories.size(); i++) {
                std::string path_name = sound_directories[i] + "/" + file_name;
                if (checkFile(path_name)) { return path_name; }
            }
            return "";
        }
    }
    
    bool isResampling(int sample_rate) { return (fDriverSR > 0 && fDriverSR != sample_rate); }
 
    // To be implemented by subclasses

    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) = 0;
    
    /**
     * Check the availability of a sound resource.
     *
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     *
     * @return true if the sound resource is available, false otherwise.
     */

    virtual bool checkFile(unsigned char* buffer, size_t size) { return true; }

    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) = 0;
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length) {}

    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param soundfile - the soundfile to be filled
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) = 0;
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param soundfile - the soundfile to be filled
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, unsigned char* buffer, size_t size, int part, int& offset, int max_chan) {}

  public:
    
    virtual ~SoundfileReader() {}
    
    void setSampleRate(int sample_rate) { fDriverSR = sample_rate; }
   
    Soundfile* createSoundfile(const std::vector<std::string>& path_name_list, int max_chan, bool is_double)
    {
        try {
            int cur_chan = 1; // At least one channel
            int total_length = 0;
            
            // Compute total length and channels max of all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                int chan, length;
                if (path_name_list[i] == "__empty_sound__") {
                    length = BUFFER_SIZE;
                    chan = 1;
                } else {
                    getParamsFile(path_name_list[i], chan, length);
                }
                cur_chan = std::max<int>(cur_chan, chan);
                total_length += length;
            }
           
            // Complete with empty parts
            total_length += (MAX_SOUNDFILE_PARTS - path_name_list.size()) * BUFFER_SIZE;
            
            // Create the soundfile
            Soundfile* soundfile = new Soundfile(cur_chan, total_length, max_chan, path_name_list.size(), is_double);
            
            // Init offset
            int offset = 0;
            
            // Read all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                if (path_name_list[i] == "__empty_sound__") {
                    soundfile->emptyFile(i, offset);
                } else {
                    readFile(soundfile, path_name_list[i], i, offset, max_chan);
                }
            }
            
            // Complete with empty parts
            for (int i = int(path_name_list.size()); i < MAX_SOUNDFILE_PARTS; i++) {
                soundfile->emptyFile(i, offset);
            }
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            soundfile->shareBuffers(cur_chan, max_chan);
            return soundfile;
            
        } catch (...) {
            return nullptr;
        }
    }

    // Check if all soundfiles exist and return their real path_name
    std::vector<std::string> checkFiles(const std::vector<std::string>& sound_directories,
                                        const std::vector<std::string>& file_name_list)
    {
        std::vector<std::string> path_name_list;
        for (size_t i = 0; i < file_name_list.size(); i++) {
            std::string path_name = checkFile(sound_directories, file_name_list[i]);
            // If 'path_name' is not found, it is replaced by an empty sound (= silence)
            path_name_list.push_back((path_name == "") ? "__empty_sound__" : path_name);
        }
        return path_name_list;
    }

};

#endif
/**************************  END  Soundfile.h **************************/

#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
/************************** BEGIN JuceReader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JuceReader__
#define __JuceReader__

#include <assert.h>

#include "../JuceLibraryCode/JuceHeader.h"


struct JuceReader : public SoundfileReader {
    
    juce::AudioFormatManager fFormatManager;
    
    JuceReader() { fFormatManager.registerBasicFormats(); }
    virtual ~JuceReader()
    {}
    
    bool checkFile(const std::string& path_name)
    {
        juce::File file(path_name);
        if (file.existsAsFile()) {
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "'" << std::endl;
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        std::unique_ptr<juce::AudioFormatReader> formatReader (fFormatManager.createReaderFor (juce::File (path_name)));
        channels = int(formatReader->numChannels);
        length = int(formatReader->lengthInSamples);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        std::unique_ptr<juce::AudioFormatReader> formatReader (fFormatManager.createReaderFor (juce::File (path_name)));
        
        soundfile->fLength[part] = int(formatReader->lengthInSamples);
        soundfile->fSR[part] = int(formatReader->sampleRate);
        soundfile->fOffset[part] = offset;
        
        void* buffers;
        if (soundfile->fIsDouble) {
            buffers = alloca(soundfile->fChannels * sizeof(double*));
            soundfile->getBuffersOffsetReal<double>(buffers, offset);
        } else {
            buffers = alloca(soundfile->fChannels * sizeof(float*));
            soundfile->getBuffersOffsetReal<float>(buffers, offset);
        }
        
        if (formatReader->read(reinterpret_cast<int *const *>(buffers), int(formatReader->numChannels), 0, int(formatReader->lengthInSamples), false)) {
            
            // Possibly convert samples
            if (!formatReader->usesFloatingPointData) {
                for (int chan = 0; chan < int(formatReader->numChannels); ++chan) {
                    if (soundfile->fIsDouble) {
                        // TODO
                    } else {
                        float* buffer = &(static_cast<float**>(soundfile->fBuffers))[chan][soundfile->fOffset[part]];
                        juce::FloatVectorOperations::convertFixedToFloat(buffer, reinterpret_cast<const int*>(buffer),
                                                                         1.0f/0x7fffffff, int(formatReader->lengthInSamples));
                    }
                }
            }
            
        } else {
            std::cerr << "Error reading the file : " << path_name << std::endl;
        }
            
        // Update offset
        offset += soundfile->fLength[part];
    }
    
};

#endif
/**************************  END  JuceReader.h **************************/
static JuceReader gReader;
#elif defined(ESP32)
/************************** BEGIN Esp32Reader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef FAUST_ESP32READER_H
#define FAUST_ESP32READER_H

#include <stdio.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spi_flash.h"
#include "esp_vfs_fat.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"

/************************** BEGIN WaveReader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __WaveReader__
#define __WaveReader__

#include <string.h>
#include <assert.h>
#include <stdio.h>


// WAVE file description
typedef struct {
    
    // The canonical WAVE format starts with the RIFF header
    
    /**
     Variable: chunk_id
     Contains the letters "RIFF" in ASCII form (0x52494646 big-endian form).
     **/
    int chunk_id;
    
    /**
     Variable: chunk_size
     36 + SubChunk2Size, or more precisely: 4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
     This is the size of the rest of the chunk following this number.
     This is the size of the entire file in bytes minus 8 bytes for the
     two fields not included in this count: ChunkID and ChunkSize.
     **/
    int chunk_size;
    
    /**
     Variable: format
     Contains the letters "WAVE" (0x57415645 big-endian form).
     **/
    int format;
    
    // The "WAVE" format consists of two subchunks: "fmt " and "data":
    // The "fmt " subchunk describes the sound data's format:
    
    /**
     Variable: subchunk_1_id
     Contains the letters "fmt " (0x666d7420 big-endian form).
     **/
    int subchunk_1_id;
    
    /**
     Variable: subchunk_1_size
     16 for PCM. This is the size of the rest of the Subchunk which follows this number.
     **/
    int subchunk_1_size;
    
    /**
     Variable: audio_format
     PCM = 1 (i.e. Linear quantization) Values other than 1 indicate some form of compression.
     **/
    short audio_format;
    
    /**
     Variable: num_channels
     Mono = 1, Stereo = 2, etc.
     **/
    short num_channels;
    
    /**
     Variable: sample_rate
     8000, 44100, etc.
     **/
    int sample_rate;
    
    /**
     Variable: byte_rate
     == SampleRate * NumChannels * BitsPerSample/8
     **/
    int byte_rate;
    
    /**
     Variable: block_align
     == NumChannels * BitsPerSample/8
     The number of bytes for one sample including all channels. I wonder what happens
     when this number isn't an integer?
     **/
    short block_align;
    
    /**
     Variable: bits_per_sample
     8 bits = 8, 16 bits = 16, etc.
     **/
    short bits_per_sample;
    
    /**
     Here should come some extra parameters which i will avoid.
     **/
    
    // The "data" subchunk contains the size of the data and the actual sound:
    
    /**
     Variable: subchunk_2_id
     Contains the letters "data" (0x64617461 big-endian form).
     **/
    int subchunk_2_id;
    
    /**
     Variable: subchunk_2_size
     == NumSamples * NumChannels * BitsPerSample/8
     This is the number of bytes in the data. You can also think of this as the size
     of the read of the subchunk following this number.
     **/
    int subchunk_2_size;
    
    /**
     Variable: data
     The actual sound data.
     **/
    char* data;
    
} wave_t;

// Base reader
struct Reader {
    
    wave_t* fWave;

    inline int is_big_endian()
    {
        int a = 1;
        return !((char*)&a)[0];
    }
    
    inline int convert_to_int(char* buffer, int len)
    {
        int a = 0;
        if (!is_big_endian()) {
            for(int i = 0; i < len; i++) {
                ((char*)&a)[i] = buffer[i];
            }
        } else {
            for(int i = 0; i < len; i++) {
                ((char*)&a)[3-i] = buffer[i];
            }
        }
        return a;
    }
    
    Reader()
    {
        fWave = (wave_t*)calloc(1, sizeof(wave_t));
    }

    virtual ~Reader()
    {
        free(fWave->data);
        free(fWave);
    }

    bool load_wave_header()
    {
        char buffer[4];
        
        read(buffer, 4);
        if (strncmp(buffer, "RIFF", 4) != 0) {
            fprintf(stderr, "This is not valid WAV file!\n");
            return false;
        }
        fWave->chunk_id = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->chunk_size = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->format = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->subchunk_1_id = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->subchunk_1_size = convert_to_int(buffer, 4);
        
        read(buffer, 2);
        fWave->audio_format = convert_to_int(buffer, 2);
        
        read(buffer, 2);
        fWave->num_channels = convert_to_int(buffer, 2);
        
        read(buffer, 4);
        fWave->sample_rate = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->byte_rate = convert_to_int(buffer, 4);
        
        read(buffer, 2);
        fWave->block_align = convert_to_int(buffer, 2);
        
        read(buffer, 2);
        fWave->bits_per_sample = convert_to_int(buffer, 2);
        
        read(buffer, 4);
        if (strncmp(buffer, "data", 4) != 0) {
            read(buffer, 4);
            int _extra_size = convert_to_int(buffer, 4);
            char _extra_data[_extra_size];
            read(_extra_data, _extra_size);
            read(buffer, 4);
            fWave->subchunk_2_id = convert_to_int(buffer, 4);
        } else {
            fWave->subchunk_2_id = convert_to_int(buffer, 4);
        }
        
        read(buffer, 4);
        fWave->subchunk_2_size = convert_to_int(buffer, 4);
        return true;
    }
    
    void load_wave()
    {
        // Read sound data
        fWave->data = (char*)malloc(fWave->subchunk_2_size);
        read(fWave->data, fWave->subchunk_2_size);
    }

    virtual void read(char* buffer, unsigned int size) = 0;
   
};

struct FileReader : public Reader {
    
    FILE* fFile;
    
    FileReader(const std::string& file_path)
    {
        fFile = fopen(file_path.c_str(), "rb");
        if (!fFile) {
            fprintf(stderr, "FileReader : cannot open file!\n");
            throw -1;
        }
        if (!load_wave_header()) {
            fprintf(stderr, "FileReader : not a WAV file!\n");
            throw -1;
        }
    }
    
    virtual ~FileReader()
    {
        fclose(fFile);
    }
    
    void read(char* buffer, unsigned int size)
    {
        fread(buffer, 1, size, fFile);
    }
    
};

extern const uint8_t file_start[] asm("_binary_FILE_start");
extern const uint8_t file_end[]   asm("_binary_FILE_end");

struct MemoryReader : public Reader {
    
    int fPos;
    const uint8_t* fStart;
    const uint8_t* fEnd;
    
    MemoryReader(const uint8_t* start, const uint8_t* end):fPos(0)
    {
        fStart = start;
        fEnd = end;
        if (!load_wave_header()) {
            fprintf(stderr, "MemoryReader : not a WAV file!\n");
            throw -1;
        }
    }
    
    virtual ~MemoryReader()
    {}
    
    void read(char* buffer, unsigned int size)
    {
        memcpy(buffer, fStart + fPos, size);
        fPos += size;
    }
    
};

// Using a FileReader to implement SoundfileReader

struct WaveReader : public SoundfileReader {
    
    WaveReader() {}
    virtual ~WaveReader() {}
    
    virtual bool checkFile(const std::string& path_name)
    {
        try {
            FileReader reader(path_name);
            return true;
        } catch (...)  {
            return false;
        }
    }
    
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        FileReader reader(path_name);
        channels = reader.fWave->num_channels;
        length = (reader.fWave->subchunk_2_size * 8) / (reader.fWave->num_channels * reader.fWave->bits_per_sample);
    }
    
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        FileReader reader(path_name);
        reader.load_wave();
        
        soundfile->fLength[part] = (reader.fWave->subchunk_2_size * 8) / (reader.fWave->num_channels * reader.fWave->bits_per_sample);
        soundfile->fSR[part] = reader.fWave->sample_rate;
        soundfile->fOffset[part] = offset;
        
        // Audio frames have to be written for each chan
        if (reader.fWave->bits_per_sample == 16) {
            float factor = 1.f/32767.f;
            for (int sample = 0; sample < soundfile->fLength[part]; sample++) {
                short* frame = (short*)&reader.fWave->data[reader.fWave->block_align * sample];
                for (int chan = 0; chan < reader.fWave->num_channels; chan++) {
                    soundfile->fBuffers[chan][offset + sample] = frame[chan] * factor;
                }
            }
        } else if (reader.fWave->bits_per_sample == 32) {
            fprintf(stderr, "readFile : not implemented\n");
        }
        
        // Update offset
        offset += soundfile->fLength[part];
    }
};

#endif
/**************************  END  WaveReader.h **************************/

#define TAG "Esp32Reader"

#define SD_PIN_NUM_MISO GPIO_NUM_2
#define SD_PIN_NUM_MOSI GPIO_NUM_15
#define SD_PIN_NUM_CLK  GPIO_NUM_14
#define SD_PIN_NUM_CS   GPIO_NUM_13

struct Esp32Reader : public WaveReader {
    
    void sdcard_init()
    {
        ESP_LOGI(TAG, "Initializing SD card");
        ESP_LOGI(TAG, "Using SPI peripheral");
        
        sdmmc_host_t host = SDSPI_HOST_DEFAULT();
        sdspi_slot_config_t slot_config = SDSPI_SLOT_CONFIG_DEFAULT();
        slot_config.gpio_miso = SD_PIN_NUM_MISO;
        slot_config.gpio_mosi = SD_PIN_NUM_MOSI;
        slot_config.gpio_sck  = SD_PIN_NUM_CLK;
        slot_config.gpio_cs   = SD_PIN_NUM_CS;
        // This initializes the slot without card detect (CD) and write protect (WP) signals.
        // Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
        
        // Options for mounting the filesystem.
        // If format_if_mount_failed is set to true, SD card will be partitioned and
        // formatted in case when mounting fails.
        esp_vfs_fat_sdmmc_mount_config_t mount_config = {
            .format_if_mount_failed = false,
            .max_files = 5,
            .allocation_unit_size = 16 * 1024
        };
        
        // Use settings defined above to initialize SD card and mount FAT filesystem.
        // Note: esp_vfs_fat_sdmmc_mount is an all-in-one convenience function.
        // Please check its source code and implement error recovery when developing
        // production applications.
        sdmmc_card_t* card;
        esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);
        
        if (ret != ESP_OK) {
            if (ret == ESP_FAIL) {
                ESP_LOGE(TAG, "Failed to mount filesystem. "
                         "If you want the card to be formatted, set format_if_mount_failed = true.");
            } else {
                ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                         "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
            }
            return;
        }
        
        // Card has been initialized, print its properties
        sdmmc_card_print_info(stdout, card);
        ESP_LOGI(TAG, "SD card initialized");
    }
    
    Esp32Reader()
    {
        sdcard_init();
    }
   
    // Access methods inherited from WaveReader
};

#endif // FAUST_ESP32READER_H
/**************************  END  Esp32Reader.h **************************/
static Esp32Reader gReader;
#elif defined(DAISY)
static WaveReader gReader;
#elif defined(MEMORY_READER)
/************************** BEGIN MemoryReader.h ************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __MemoryReader__
#define __MemoryReader__


/*
 A 'MemoryReader' object can be used to prepare a set of sound resources in memory, to be used by SoundUI::addSoundfile.
 
 A Soundfile* object will have to be filled with a list of sound resources: the fLength, fOffset, fSampleRate and fBuffers fields 
 have to be completed with the appropriate values, and will be accessed in the DSP object while running.
 *
 */

// To adapt for a real case use

#define SOUND_CHAN      2
#define SOUND_LENGTH    4096
#define SOUND_SR        44100

struct MemoryReader : public SoundfileReader {
    
    MemoryReader()
    {}
    
    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) { return true; }
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        channels = SOUND_CHAN;
        length = SOUND_LENGTH;
    }
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        soundfile->fLength[part] = SOUND_LENGTH;
        soundfile->fSR[part] = SOUND_SR;
        soundfile->fOffset[part] = offset;
        
        // Audio frames have to be written for each chan
        if (soundfile->fIsDouble) {
            for (int sample = 0; sample < SOUND_LENGTH; sample++) {
                for (int chan = 0; chan < SOUND_CHAN; chan++) {
                    static_cast<double**>(soundfile->fBuffers)[chan][offset + sample] = 0.f;
                }
            }
        } else {
            for (int sample = 0; sample < SOUND_LENGTH; sample++) {
                for (int chan = 0; chan < SOUND_CHAN; chan++) {
                    static_cast<float**>(soundfile->fBuffers)[chan][offset + sample] = 0.f;
                }
            }
        }
        
        // Update offset
        offset += SOUND_LENGTH;
    }
    
};

#endif
/**************************  END  MemoryReader.h **************************/
static MemoryReader gReader;
#else
/************************** BEGIN LibsndfileReader.h *********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __LibsndfileReader__
#define __LibsndfileReader__

#ifdef SAMPLERATE
#include <samplerate.h>
#endif
#include <sndfile.h>
#include <string.h>
#include <assert.h>
#include <iostream>


struct VFLibsndfile {
    
    #define SIGNED_SIZEOF(x) ((int)sizeof(x))
    
    unsigned char* fBuffer;
    size_t fLength;
    size_t fOffset;
    SF_VIRTUAL_IO fVIO;
    
    VFLibsndfile(unsigned char* buffer, size_t length):fBuffer(buffer), fLength(length), fOffset(0)
    {
        fVIO.get_filelen = vfget_filelen;
        fVIO.seek = vfseek;
        fVIO.read = vfread;
        fVIO.write = vfwrite;
        fVIO.tell = vftell;
    }
    
    static sf_count_t vfget_filelen(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fLength;
    }
  
    static sf_count_t vfseek(sf_count_t offset, int whence, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        switch (whence) {
            case SEEK_SET:
                vf->fOffset = offset;
                break;
                
            case SEEK_CUR:
                vf->fOffset = vf->fOffset + offset;
                break;
                
            case SEEK_END:
                vf->fOffset = vf->fLength + offset;
                break;
                
            default:
                break;
        };
        
        return vf->fOffset;
    }
    
    static sf_count_t vfread(void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset + count > vf->fLength) {
            count = vf->fLength - vf->fOffset;
        }
        
        memcpy(ptr, vf->fBuffer + vf->fOffset, count);
        vf->fOffset += count;
        
        return count;
    }
    
    static sf_count_t vfwrite(const void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset >= SIGNED_SIZEOF(vf->fBuffer)) {
            return 0;
        }
        
        if (vf->fOffset + count > SIGNED_SIZEOF(vf->fBuffer)) {
            count = sizeof (vf->fBuffer) - vf->fOffset;
        }
        
        memcpy(vf->fBuffer + vf->fOffset, ptr, (size_t)count);
        vf->fOffset += count;
        
        if (vf->fOffset > vf->fLength) {
            vf->fLength = vf->fOffset;
        }
        
        return count;
    }
    
    static sf_count_t vftell(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fOffset;
    }
 
};

struct LibsndfileReader : public SoundfileReader {
	
    LibsndfileReader() {}
	
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, void* buffer, sf_count_t frames);
	
    // Check file
    bool checkFile(const std::string& path_name)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        return checkFileAux(snd_file, path_name);
    }
    
    bool checkFile(unsigned char* buffer, size_t length)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        return checkFileAux(snd_file, "virtual file");
    }
    
    bool checkFileAux(SNDFILE* snd_file, const std::string& path_name)
    {
        if (snd_file) {
            sf_close(snd_file);
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return false;
        }
    }

    // Open the file and returns its length and channels
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, size);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFileAux(SNDFILE* snd_file, const SF_INFO& snd_info, int& channels, int& length)
    {
        assert(snd_file);
        channels = int(snd_info.channels);
    #ifdef SAMPLERATE
        length = (isResampling(snd_info.samplerate)) ? ((double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate)) + BUFFER_SIZE) : int(snd_info.frames);
    #else
        length = int(snd_info.frames);
    #endif
        sf_close(snd_file);
    }
    
    // Read the file
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
    
    void readFile(Soundfile* soundfile, unsigned char* buffer, size_t length, int part, int& offset, int max_chan)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
	
    // Will be called to fill all parts from 0 to MAX_SOUNDFILE_PARTS-1
    void readFileAux(Soundfile* soundfile, SNDFILE* snd_file, const SF_INFO& snd_info, int part, int& offset, int max_chan)
    {
        assert(snd_file);
        int channels = std::min<int>(max_chan, snd_info.channels);
    #ifdef SAMPLERATE
        if (isResampling(snd_info.samplerate)) {
            soundfile->fLength[part] = int(double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate));
            soundfile->fSR[part] = fDriverSR;
        } else {
            soundfile->fLength[part] = int(snd_info.frames);
            soundfile->fSR[part] = snd_info.samplerate;
        }
    #else
        soundfile->fLength[part] = int(snd_info.frames);
        soundfile->fSR[part] = snd_info.samplerate;
    #endif
        soundfile->fOffset[part] = offset;
		
        // Read and fill snd_info.channels number of channels
        sf_count_t nbf;
        
        sample_read reader;
        void* buffer_in = nullptr;
        if (soundfile->fIsDouble) {
            buffer_in = static_cast<double*>(alloca(BUFFER_SIZE * sizeof(double) * snd_info.channels));
            reader = reinterpret_cast<sample_read>(sf_readf_double);
        } else {
            buffer_in = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
            reader = reinterpret_cast<sample_read>(sf_readf_float);
        }
        
    #ifdef SAMPLERATE
        // Resampling
        SRC_STATE* resampler = nullptr;
        float* src_buffer_out = nullptr;
        float* src_buffer_in = nullptr;
        void* buffer_out = nullptr;
        if  (isResampling(snd_info.samplerate)) {
            int error;
            resampler = src_new(SRC_SINC_FASTEST, channels, &error);
            if (error != 0) {
                std::cerr << "ERROR : src_new " << src_strerror(error) << std::endl;
                throw -1;
            }
            if (soundfile->fIsDouble) {
                // Additional buffers for SRC resampling
                src_buffer_in = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
                src_buffer_out = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
                buffer_out = static_cast<double*>(alloca(BUFFER_SIZE * sizeof(double) * snd_info.channels));
            } else {
                buffer_out = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
            }
        }
    #endif
        
        do {
            nbf = reader(snd_file, buffer_in, BUFFER_SIZE);
        #ifdef SAMPLERATE
            // Resampling
            if  (isResampling(snd_info.samplerate)) {
                int in_offset = 0;
                SRC_DATA src_data;
                src_data.src_ratio = double(fDriverSR)/double(snd_info.samplerate);
                if (soundfile->fIsDouble) {
                    for (int frame = 0; frame < (BUFFER_SIZE * snd_info.channels); frame++) {
                        src_buffer_in[frame] = float(static_cast<float*>(buffer_in)[frame]);
                    }
                }
                do {
                    if (soundfile->fIsDouble) {
                        src_data.data_in = src_buffer_in;
                        src_data.data_out = src_buffer_out;
                    } else {
                        src_data.data_in = static_cast<const float*>(buffer_in);
                        src_data.data_out = static_cast<float*>(buffer_out);
                    }
                    src_data.input_frames = nbf - in_offset;
                    src_data.output_frames = BUFFER_SIZE;
                    src_data.end_of_input = (nbf < BUFFER_SIZE);
                    int res = src_process(resampler, &src_data);
                    if (res != 0) {
                        std::cerr << "ERROR : src_process " << src_strerror(res) << std::endl;
                        throw -1;
                    }
                    if (soundfile->fIsDouble) {
                        for (int frame = 0; frame < (BUFFER_SIZE * snd_info.channels); frame++) {
                            static_cast<double*>(buffer_out)[frame] = double(src_buffer_out[frame]);
                        }
                    }
                    soundfile->copyToOut(src_data.output_frames_gen, channels, snd_info.channels, offset, buffer_out);
                    in_offset += src_data.input_frames_used;
                    // Update offset
                    offset += src_data.output_frames_gen;
                } while (in_offset < nbf);
            } else {
                soundfile->copyToOut(nbf, channels, snd_info.channels, offset, buffer_in);
                // Update offset
                offset += nbf;
            }
        #else
            soundfile->copyToOut(nbf, channels, snd_info.channels, offset, buffer_in);
            // Update offset
            offset += nbf;
        #endif
        } while (nbf == BUFFER_SIZE);
		
        sf_close(snd_file);
    #ifdef SAMPLERATE
        if (resampler) src_delete(resampler);
    #endif
    }

};

#endif
/**************************  END  LibsndfileReader.h **************************/
static LibsndfileReader gReader;
#endif

// To be used by DSP code if no SoundUI is used
static std::vector<std::string> path_name_list;
static Soundfile* defaultsound = nullptr;

class SoundUI : public SoundUIInterface
{
		
    protected:
    
        std::vector<std::string> fSoundfileDir;             // The soundfile directories
        std::map<std::string, Soundfile*> fSoundfileMap;    // Map to share loaded soundfiles
        SoundfileReader* fSoundReader;
        bool fIsDouble;

     public:
    
        /**
         * Create a soundfile loader which will typically use a concrete SoundfileReader like LibsndfileReader or JuceReader to load soundfiles.
         *
         * @param sound_directory - the base directory to look for files, which paths will be relative to this one
         * @param sample_rate - the audio driver SR which may be different from the file SR, to possibly resample files
         * @param reader - an alternative soundfile reader
         * @param is_double - whether Faust code has been compiled in -double mode and soundfile buffers have to be in double
         *
         * @return the soundfile loader.
         */
        SoundUI(const std::string& sound_directory = "", int sample_rate = -1, SoundfileReader* reader = nullptr, bool is_double = false)
        {
            fSoundfileDir.push_back(sound_directory);
            fSoundReader = (reader) ? reader : &gReader;
            fSoundReader->setSampleRate(sample_rate);
            fIsDouble = is_double;
            if (!defaultsound) defaultsound = gReader.createSoundfile(path_name_list, MAX_CHAN, is_double);
        }
    
        /**
         * Create a soundfile loader which will typically use a concrete SoundfileReader like LibsndfileReader or JuceReader to load soundfiles.
         *
         * @param sound_directories - a vector of base directories to look for files, which paths will be relative to these ones
         * @param sample_rate - the audio driver SR which may be different from the file SR, to possibly resample files
         * @param reader - an alternative soundfile reader
         * @param is_double - whether Faust code has been compiled in -double mode and soundfile buffers have to be in double
         *
         * @return the soundfile loader.
         */
        SoundUI(const std::vector<std::string>& sound_directories, int sample_rate = -1, SoundfileReader* reader = nullptr, bool is_double = false)
        :fSoundfileDir(sound_directories)
        {
            fSoundReader = (reader) ? reader : &gReader;
            fSoundReader->setSampleRate(sample_rate);
            fIsDouble = is_double;
            if (!defaultsound) defaultsound = gReader.createSoundfile(path_name_list, MAX_CHAN, is_double);
        }
    
        virtual ~SoundUI()
        {   
            // Delete all soundfiles
            for (const auto& it : fSoundfileMap) {
                delete it.second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            const char* saved_url = url; // 'url' is consumed by parseMenuList2
            std::vector<std::string> file_name_list;
            
            bool menu = parseMenuList2(url, file_name_list, true);
            // If not a list, we have as single file
            if (!menu) { file_name_list.push_back(saved_url); }
            
            // Parse the possible list
            std::string saved_url_real = std::string(saved_url) + "_" + std::to_string(fIsDouble); // fIsDouble is used in the key
            if (fSoundfileMap.find(saved_url_real) == fSoundfileMap.end()) {
                // Check all files and get their complete path
                std::vector<std::string> path_name_list = fSoundReader->checkFiles(fSoundfileDir, file_name_list);
                // Read them and create the Soundfile
                Soundfile* sound_file = fSoundReader->createSoundfile(path_name_list, MAX_CHAN, fIsDouble);
                if (sound_file) {
                    fSoundfileMap[saved_url_real] = sound_file;
                } else {
                    // If failure, use 'defaultsound'
                    std::cerr << "addSoundfile : soundfile for " << saved_url << " cannot be created !" << std::endl;
                    *sf_zone = defaultsound;
                    return;
                }
            }
            
            // Get the soundfile
            *sf_zone = fSoundfileMap[saved_url_real];
        }
    
        /**
         * An OS dependant function to get the path of the running executable or plugin.
         * This will typically be used when creating a SoundUI soundfile loader, like new SoundUI(SoundUI::getBinaryPath());
         *
         * @return the running executable or plugin path.
         */
        static std::string getBinaryPath()
        {
            std::string bundle_path_str;
        #if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
            CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
            if (!bundle_ref) { std::cerr << "getBinaryPath CFBundleCopyBundleURL error\n"; return ""; }
      
            UInt8 bundle_path[1024];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 1024)) {
                bundle_path_str = std::string((char*)bundle_path);
            } else {
                std::cerr << "getBinaryPath CFURLGetFileSystemRepresentation error\n";
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
    
        /**
         * An OS dependant function to get the path of the running executable or plugin.
         * This will typically be used when creating a SoundUI soundfile loader, like new SoundUI(SoundUI::getBinaryPathFrom());
         *
         * @param path - entry point to start getting the path of the running executable or plugin.
         *
         * @return the running executable or plugin path.
         */
        static std::string getBinaryPathFrom(const std::string& path)
        {
            std::string bundle_path_str;
        #if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
            CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
            if (!bundle) { std::cerr << "getBinaryPathFrom CFBundleGetBundleWithIdentifier error '" << path << "'" << std::endl; return ""; }
         
            CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
            if (!bundle_ref) { std::cerr << "getBinaryPathFrom CFBundleCopyBundleURL error\n"; return ""; }
            
            UInt8 bundle_path[1024];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 1024)) {
                bundle_path_str = std::string((char*)bundle_path);
            } else {
                std::cerr << "getBinaryPathFrom CFURLGetFileSystemRepresentation error\n";
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
};

#endif
/**************************  END  SoundUI.h **************************/
#endif

#if defined(OSCCTRL)
/************************** BEGIN JuceOSCUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __juce_osc__
#define __juce_osc__
 
#include "../JuceLibraryCode/JuceHeader.h"

/************************** BEGIN APIUI.h *****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef API_UI_H
#define API_UI_H

#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>


typedef unsigned int uint;

class APIUI : public PathBuilder, public Meta, public UI
{
    public:
        enum ItemType { kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph };
        enum Type { kAcc = 0, kGyr = 1, kNoType };

    protected:

        enum Mapping { kLin = 0, kLog = 1, kExp = 2 };

        struct Item {
            std::string fLabel;
            std::string fShortname;
            std::string fPath;
            ValueConverter* fConversion;
            FAUSTFLOAT* fZone;
            FAUSTFLOAT fInit;
            FAUSTFLOAT fMin;
            FAUSTFLOAT fMax;
            FAUSTFLOAT fStep;
            ItemType fItemType;
            
            Item(const std::string& label,
                 const std::string& short_name,
                 const std::string& path,
                 ValueConverter* conversion,
                 FAUSTFLOAT* zone,
                 FAUSTFLOAT init,
                 FAUSTFLOAT min,
                 FAUSTFLOAT max,
                 FAUSTFLOAT step,
                 ItemType item_type)
            :fLabel(label), fShortname(short_name), fPath(path), fConversion(conversion),
            fZone(zone), fInit(init), fMin(min), fMax(max), fStep(step), fItemType(item_type)
            {}
        };
        std::vector<Item> fItems;

        std::vector<std::map<std::string, std::string> > fMetaData;
        std::vector<ZoneControl*> fAcc[3];
        std::vector<ZoneControl*> fGyr[3];

        // Screen color control
        // "...[screencolor:red]..." etc.
        bool fHasScreenControl;      // true if control screen color metadata
        ZoneReader* fRedReader;
        ZoneReader* fGreenReader;
        ZoneReader* fBlueReader;

        // Current values controlled by metadata
        std::string fCurrentUnit;
        int fCurrentScale;
        std::string fCurrentAcc;
        std::string fCurrentGyr;
        std::string fCurrentColor;
        std::string fCurrentTooltip;
        std::map<std::string, std::string> fCurrentMetadata;

        // Add a generic parameter
        virtual void addParameter(const char* label,
                                  FAUSTFLOAT* zone,
                                  FAUSTFLOAT init,
                                  FAUSTFLOAT min,
                                  FAUSTFLOAT max,
                                  FAUSTFLOAT step,
                                  ItemType type)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);

            // handle scale metadata
            ValueConverter* converter = nullptr;
            switch (fCurrentScale) {
                case kLin:
                    converter = new LinearValueConverter(0, 1, min, max);
                    break;
                case kLog:
                    converter = new LogValueConverter(0, 1, min, max);
                    break;
                case kExp:
                    converter = new ExpValueConverter(0, 1, min, max);
                    break;
            }
            fCurrentScale = kLin;

            fItems.push_back(Item(label, "", path, converter, zone, init, min, max, step, type));
       
            if (fCurrentAcc.size() > 0 && fCurrentGyr.size() > 0) {
                fprintf(stderr, "warning : 'acc' and 'gyr' metadata used for the same %s parameter !!\n", label);
            }

            // handle acc metadata "...[acc : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentAcc.size() > 0) {
                std::istringstream iss(fCurrentAcc);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fAcc[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    fprintf(stderr, "incorrect acc metadata : %s \n", fCurrentAcc.c_str());
                }
                fCurrentAcc = "";
            }

            // handle gyr metadata "...[gyr : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentGyr.size() > 0) {
                std::istringstream iss(fCurrentGyr);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fGyr[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    fprintf(stderr, "incorrect gyr metadata : %s \n", fCurrentGyr.c_str());
                }
                fCurrentGyr = "";
            }

            // handle screencolor metadata "...[screencolor:red|green|blue|white]..."
            if (fCurrentColor.size() > 0) {
                if ((fCurrentColor == "red") && (fRedReader == nullptr)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "green") && (fGreenReader == nullptr)) {
                    fGreenReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "blue") && (fBlueReader == nullptr)) {
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "white") && (fRedReader == nullptr) && (fGreenReader == nullptr) && (fBlueReader == nullptr)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fGreenReader = new ZoneReader(zone, min, max);
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else {
                    fprintf(stderr, "incorrect screencolor metadata : %s \n", fCurrentColor.c_str());
                }
            }
            fCurrentColor = "";

            fMetaData.push_back(fCurrentMetadata);
            fCurrentMetadata.clear();
        }

        int getZoneIndex(std::vector<ZoneControl*>* table, int p, int val)
        {
            FAUSTFLOAT* zone = fItems[uint(p)].fZone;
            for (size_t i = 0; i < table[val].size(); i++) {
                if (zone == table[val][i]->getZone()) return int(i);
            }
            return -1;
        }

        void setConverter(std::vector<ZoneControl*>* table, int p, int val, int curve, double amin, double amid, double amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);

            // Deactivates everywhere..
            if (id1 != -1) table[0][uint(id1)]->setActive(false);
            if (id2 != -1) table[1][uint(id2)]->setActive(false);
            if (id3 != -1) table[2][uint(id3)]->setActive(false);

            if (val == -1) { // Means: no more mapping...
                // So stay all deactivated...
            } else {
                int id4 = getZoneIndex(table, p, val);
                if (id4 != -1) {
                    // Reactivate the one we edit...
                  table[val][uint(id4)]->setMappingValues(curve, amin, amid, amax, fItems[uint(p)].fMin, fItems[uint(p)].fInit, fItems[uint(p)].fMax);
                  table[val][uint(id4)]->setActive(true);
                } else {
                    // Allocate a new CurveZoneControl which is 'active' by default
                    FAUSTFLOAT* zone = fItems[uint(p)].fZone;
                    table[val].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, fItems[uint(p)].fMin, fItems[uint(p)].fInit, fItems[uint(p)].fMax));
                }
            }
        }

        void getConverter(std::vector<ZoneControl*>* table, int p, int& val, int& curve, double& amin, double& amid, double& amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);

            if (id1 != -1) {
                val = 0;
                curve = table[val][uint(id1)]->getCurve();
                table[val][uint(id1)]->getMappingValues(amin, amid, amax);
            } else if (id2 != -1) {
                val = 1;
                curve = table[val][uint(id2)]->getCurve();
                table[val][uint(id2)]->getMappingValues(amin, amid, amax);
            } else if (id3 != -1) {
                val = 2;
                curve = table[val][uint(id3)]->getCurve();
                table[val][uint(id3)]->getMappingValues(amin, amid, amax);
            } else {
                val = -1; // No mapping
                curve = 0;
                amin = -100.;
                amid = 0.;
                amax = 100.;
            }
        }

    public:

        APIUI() : fHasScreenControl(false), fRedReader(nullptr), fGreenReader(nullptr), fBlueReader(nullptr), fCurrentScale(kLin)
        {}

        virtual ~APIUI()
        {
            for (const auto& it : fItems) delete it.fConversion;
            for (int i = 0; i < 3; i++) {
                for (const auto& it : fAcc[i]) delete it;
                for (const auto& it : fGyr[i]) delete it;
            }
            delete fRedReader;
            delete fGreenReader;
            delete fBlueReader;
        }

        // -- widget's layouts

        virtual void openTabBox(const char* label) { pushLabel(label); }
        virtual void openHorizontalBox(const char* label) { pushLabel(label); }
        virtual void openVerticalBox(const char* label) { pushLabel(label); }
        virtual void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' field for each item
                for (const auto& it : fFull2Short) {
                    int index = getParamIndex(it.first.c_str());
                    fItems[index].fShortname = it.second;
                }
            }
        }

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kButton);
        }

        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kCheckButton);
        }

        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kVSlider);
        }

        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kHSlider);
        }

        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kNumEntry);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0f, kHBargraph);
        }

        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0f, kVBargraph);
        }

        // -- soundfiles

        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            // Keep metadata
            fCurrentMetadata[key] = val;

            if (strcmp(key, "scale") == 0) {
                if (strcmp(val, "log") == 0) {
                    fCurrentScale = kLog;
                } else if (strcmp(val, "exp") == 0) {
                    fCurrentScale = kExp;
                } else {
                    fCurrentScale = kLin;
                }
            } else if (strcmp(key, "unit") == 0) {
                fCurrentUnit = val;
            } else if (strcmp(key, "acc") == 0) {
                fCurrentAcc = val;
            } else if (strcmp(key, "gyr") == 0) {
                fCurrentGyr = val;
            } else if (strcmp(key, "screencolor") == 0) {
                fCurrentColor = val; // val = "red", "green", "blue" or "white"
            } else if (strcmp(key, "tooltip") == 0) {
                fCurrentTooltip = val;
            }
        }

        virtual void declare(const char* key, const char* val)
        {}

        //-------------------------------------------------------------------------------
        // Simple API part
        //-------------------------------------------------------------------------------
    
        /**
         * Return the number of parameters in the UI.
         *
         * @return the number of parameters
         */
        int getParamsCount() { return int(fItems.size()); }

        /**
         * Return the param index.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param index
         */
        int getParamIndex(const char* str)
        {
            std::string path = std::string(str);
            auto it = find_if(fItems.begin(), fItems.end(),
                              [=](const Item& it) { return (it.fLabel == path) || (it.fShortname == path) || (it.fPath == path); });
            return (it != fItems.end()) ? int(it - fItems.begin()) : -1;
        }
    
        /**
         * Return the param label.
         *
         * @param p - the UI parameter index
         *
         * @return the param label
         */
        const char* getParamLabel(int p) { return fItems[uint(p)].fLabel.c_str(); }
    
        /**
         * Return the param shortname.
         *
         * @param p - the UI parameter index
         *
         * @return the param shortname
         */
        const char* getParamShortname(int p) { return fItems[uint(p)].fShortname.c_str(); }
    
        /**
         * Return the param path.
         *
         * @param p - the UI parameter index
         *
         * @return the param path
         */
        const char* getParamAddress(int p) { return fItems[uint(p)].fPath.c_str(); }
    
        /**
         * Return the param metadata.
         *
         * @param p - the UI parameter index
         *
         * @return the param metadata as a map<key, value>
         */
        std::map<const char*, const char*> getMetadata(int p)
        {
            std::map<const char*, const char*> res;
            std::map<std::string, std::string> metadata = fMetaData[uint(p)];
            for (const auto& it : metadata) {
                res[it.first.c_str()] = it.second.c_str();
            }
            return res;
        }

        /**
         * Return the param metadata value.
         *
         * @param p - the UI parameter index
         * @param key - the UI parameter index
         *
         * @return the param metadata value associate to the key
         */
        const char* getMetadata(int p, const char* key)
        {
            return (fMetaData[uint(p)].find(key) != fMetaData[uint(p)].end()) ? fMetaData[uint(p)][key].c_str() : "";
        }
    
        /**
         * Return the param minimum value.
         *
         * @param p - the UI parameter index
         *
         * @return the param minimum value
         */
        FAUSTFLOAT getParamMin(int p) { return fItems[uint(p)].fMin; }
    
        /**
         * Return the param maximum value.
         *
         * @param p - the UI parameter index
         *
         * @return the param maximum value
         */
        FAUSTFLOAT getParamMax(int p) { return fItems[uint(p)].fMax; }
    
        /**
         * Return the param step value.
         *
         * @param p - the UI parameter index
         *
         * @return the param step value
         */
        FAUSTFLOAT getParamStep(int p) { return fItems[uint(p)].fStep; }
    
        /**
         * Return the param init value.
         *
         * @param p - the UI parameter index
         *
         * @return the param init value
         */
        FAUSTFLOAT getParamInit(int p) { return fItems[uint(p)].fInit; }

        /**
         * Return the param memory zone.
         *
         * @param p - the UI parameter index
         *
         * @return the param memory zone.
         */
        FAUSTFLOAT* getParamZone(int p) { return fItems[uint(p)].fZone; }

        /**
         * Return the param value.
         *
         * @param p - the UI parameter index
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(int p) { return *fItems[uint(p)].fZone; }
    
        /**
         * Return the param value.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(const char* str)
        {
            int index = getParamIndex(str);
            if (index >= 0) {
                return getParamValue(index);
            } else {
                fprintf(stderr, "getParamValue : '%s' not found\n", (str == nullptr ? "NULL" : str));
                return FAUSTFLOAT(0);
            }
        }

        /**
         * Set the param value.
         *
         * @param p - the UI parameter index
         * @param v - the UI parameter value
         *
         */
        void setParamValue(int p, FAUSTFLOAT v) { *fItems[uint(p)].fZone = v; }
        
        /**
         * Set the param value.
         *
         * @param p - the UI parameter label/shortname/path
         * @param v - the UI parameter value
         *
         */
        void setParamValue(const char* path, FAUSTFLOAT v)
        {
            int index = getParamIndex(path);
            if (index >= 0) {
                setParamValue(index, v);
            } else {
                fprintf(stderr, "setParamValue : '%s' not found\n", (path == nullptr ? "NULL" : path));
            }
        }

        double getParamRatio(int p) { return fItems[uint(p)].fConversion->faust2ui(*fItems[uint(p)].fZone); }
        void setParamRatio(int p, double r) { *fItems[uint(p)].fZone = FAUSTFLOAT(fItems[uint(p)].fConversion->ui2faust(r)); }

        double value2ratio(int p, double r)    { return fItems[uint(p)].fConversion->faust2ui(r); }
        double ratio2value(int p, double r)    { return fItems[uint(p)].fConversion->ui2faust(r); }

        /**
         * Return the control type (kAcc, kGyr, or -1) for a given parameter.
         *
         * @param p - the UI parameter index
         *
         * @return the type
         */
        Type getParamType(int p)
        {
            if (p >= 0) {
                if (getZoneIndex(fAcc, p, 0) != -1
                    || getZoneIndex(fAcc, p, 1) != -1
                    || getZoneIndex(fAcc, p, 2) != -1) {
                    return kAcc;
                } else if (getZoneIndex(fGyr, p, 0) != -1
                           || getZoneIndex(fGyr, p, 1) != -1
                           || getZoneIndex(fGyr, p, 2) != -1) {
                    return kGyr;
                }
            }
            return kNoType;
        }

        /**
         * Return the Item type (kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph) for a given parameter.
         *
         * @param p - the UI parameter index
         *
         * @return the Item type
         */
        ItemType getParamItemType(int p)
        {
            return fItems[uint(p)].fItemType;
        }

        /**
         * Set a new value coming from an accelerometer, propagate it to all relevant FAUSTFLOAT* zones.
         *
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer
         * @param value - the new value
         *
         */
        void propagateAcc(int acc, double value)
        {
            for (size_t i = 0; i < fAcc[acc].size(); i++) {
                fAcc[acc][i]->update(value);
            }
        }

        /**
         * Used to edit accelerometer curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer (-1 means "no mapping")
         * @param curve - between 0 and 3 (0: up, 1: down, 2: up and down, 2: down and up)
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setAccConverter(int p, int acc, int curve, double amin, double amid, double amax)
        {
            setConverter(fAcc, p, acc, curve, amin, amid, amax);
        }

        /**
         * Used to edit gyroscope curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope (-1 means "no mapping")
         * @param curve - between 0 and 3 (0: up, 1: down, 2: up and down, 2: down and up)
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setGyrConverter(int p, int gyr, int curve, double amin, double amid, double amax)
        {
            setConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }

        /**
         * Used to edit accelerometer curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - the acc value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved (between 0 and 3)
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getAccConverter(int p, int& acc, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fAcc, p, acc, curve, amin, amid, amax);
        }

        /**
         * Used to edit gyroscope curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param gyr - the gyr value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved (between 0 and 3)
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getGyrConverter(int p, int& gyr, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }

        /**
         * Set a new value coming from an gyroscope, propagate it to all relevant FAUSTFLOAT* zones.
         *
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope
         * @param value - the new value
         *
         */
        void propagateGyr(int gyr, double value)
        {
            for (size_t i = 0; i < fGyr[gyr].size(); i++) {
                fGyr[gyr][i]->update(value);
            }
        }

        /**
         * Get the number of FAUSTFLOAT* zones controlled with the accelerometer.
         *
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer
         * @return the number of zones
         *
         */
        int getAccCount(int acc)
        {
            return (acc >= 0 && acc < 3) ? int(fAcc[acc].size()) : 0;
        }

        /**
         * Get the number of FAUSTFLOAT* zones controlled with the gyroscope.
         *
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope
         * @param the number of zones
         *
         */
        int getGyrCount(int gyr)
        {
            return (gyr >= 0 && gyr < 3) ? int(fGyr[gyr].size()) : 0;
        }

        /**
         * Get the requested screen color.
         *
         * -1 means no screen color control (no screencolor metadata found)
         * otherwise return 0x00RRGGBB a ready to use color
         *
         */
        int getScreenColor()
        {
            if (fHasScreenControl) {
                int r = (fRedReader) ? fRedReader->getValue() : 0;
                int g = (fGreenReader) ? fGreenReader->getValue() : 0;
                int b = (fBlueReader) ? fBlueReader->getValue() : 0;
                return (r<<16) | (g<<8) | b;
            } else {
                return -1;
            }
        }

};

#endif
/**************************  END  APIUI.h **************************/

class oscItem : public uiItem {
    
    protected:
        
        juce::OSCSender* fSender;
        juce::String fPath;
        
    public:
        
        oscItem(juce::OSCSender* sender, GUI* ui, const juce::String& path, FAUSTFLOAT* zone)
        :uiItem(ui, zone), fSender(sender), fPath(path) {}
        virtual ~oscItem()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fSender->send(fPath, float(v));
        }
    
};

class JuceOSCUI : private juce::OSCReceiver, private juce::OSCReceiver::Listener<juce::OSCReceiver::RealtimeCallback>, public GUI {
    
    private:
        
        juce::OSCSender fSender;
        juce::String fIP;
        int fInputPort, fOutputPort;
        APIUI fAPIUI;
        juce::Array<oscItem*> fOSCItems;  // Pointers are kept and desallocated by the GUI class
        
    public:
        
        JuceOSCUI(const std::string& ip, int in_port, int out_port)
        :fIP(ip), fInputPort(in_port), fOutputPort(out_port)
        {}
        
        virtual ~JuceOSCUI()
        {}
        
        void oscMessageReceived(const juce::OSCMessage& message) override
        {
            juce::String address = message.getAddressPattern().toString();
            
            for (int i = 0; i < message.size(); ++i) {
                if (message[i].isFloat32()) {
                    fAPIUI.setParamValue(address.toStdString().c_str(), FAUSTFLOAT(message[i].getFloat32()));
                    // "get" message with correct address
                } else if (message[i].isString()
                           && message[i].getString().equalsIgnoreCase("get")
                           && juce::String(fAPIUI.getParamAddress(0)).startsWith(address)) {
                    for (int p = 0; p < fAPIUI.getParamsCount(); ++p) {
                        fSender.send(fAPIUI.getParamAddress(p), float(fAPIUI.getParamValue(p)), float(fAPIUI.getParamMin(p)), float(fAPIUI.getParamMax(p)));
                    }
                    // "hello" message
                } else if (message[i].isString()
                           && address.equalsIgnoreCase("/*")
                           && message[i].getString().equalsIgnoreCase("hello")) {
                    juce::String path = fAPIUI.getParamAddress(0);
                    int pos1 = path.indexOfChar('/');
                    int pos2 = path.indexOfChar(pos1 + 1, '/');
                    fSender.send(path.substring(pos1, pos2), fIP, fInputPort, fOutputPort);
                }
            }
        }
        
        bool run() override
        {
            // Keep all zones for update when OSC messages are received
            if (fOSCItems.size() == 0) {
                for (int p = 0; p < fAPIUI.getParamsCount(); ++p) {
                    fOSCItems.add(new oscItem(&fSender, this, fAPIUI.getParamAddress(p), fAPIUI.getParamZone(p)));
                }
            }
            
            if (!fSender.connect(fIP, fOutputPort)) {
                std::cerr << "Error: could not connect to UDP port " << fInputPort << std::endl;
                return false;
            }
            
            if (!connect(fInputPort)) {
                std::cerr << "Error: could not connect to UDP port " << fOutputPort << std::endl;
                return false;
            }
            addListener(this);
            return true;
        }
        
        void stop() override
        {
            fSender.disconnect();
            disconnect();
            removeListener(this);
        }
        
        // -- widget's layouts
        
        void openTabBox(const char* label) override { fAPIUI.openTabBox(label); }
        void openHorizontalBox(const char* label) override { fAPIUI.openHorizontalBox(label); }
        void openVerticalBox(const char* label) override { fAPIUI.openVerticalBox(label); }
        void closeBox() override { fAPIUI.closeBox(); }
        
        // -- active widgets
        
        void addButton(const char* label, FAUSTFLOAT* zone) override { fAPIUI.addButton(label, zone); }
        void addCheckButton(const char* label, FAUSTFLOAT* zone) override { fAPIUI.addCheckButton(label, zone); }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addVerticalSlider(label, zone, init, min, max, step); }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addHorizontalSlider(label, zone, init, min, max, step); }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        { fAPIUI.addHorizontalBargraph(label, zone, min, max); }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        { fAPIUI.addVerticalBargraph(label, zone, min, max); }
        
        // -- metadata declarations
        
        void declare(FAUSTFLOAT* zone, const char* key, const char* val) override { fAPIUI.declare(zone, key, val); }
    
};

#endif // __juce_osc__

/**************************  END  JuceOSCUI.h **************************/
#endif

#if defined(MIDICTRL)
/************************** BEGIN juce-midi.h ****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
***************************************************************************/

#ifndef __juce_midi__
#define __juce_midi__
 

class FAUST_API MapUI;

/**
 *  MIDI input/output handling using JUCE framework: https://juce.com
 */
class juce_midi_handler : public midi_handler {
    
    protected:
    
        juce::MidiBuffer fOutputBuffer;
        juce::CriticalSection fMutex;
    
        void decodeMessage(const juce::MidiMessage& message)
        {
            const juce::uint8* data = message.getRawData();
            int channel = message.getChannel() - 1; // which MIDI channel, 0-15
            double time = message.getTimeStamp();
            
            if (message.isNoteOff()) {
                handleKeyOff(time, channel, data[1], data[2]);
            } else if (message.isNoteOn()) {
                handleKeyOn(time, channel, data[1], data[2]);
            } else if (message.isAftertouch()) {
                handlePolyAfterTouch(time, channel, data[1], data[2]);
            } else if (message.isController()) {
                handleCtrlChange(time, channel, data[1], data[2]);
            } else if (message.isProgramChange()) {
                handleProgChange(time, channel, data[1]);
            } else if (message.isChannelPressure()) {
                handleAfterTouch(time, channel, data[1]);
            } else if (message.isPitchWheel()) {
                handlePitchWheel(time, channel, data[1], data[2]);
            } else if (message.isMidiClock()) {
                handleClock(time);
            // We can consider start and continue as identical messages.
            } else if (message.isMidiStart() || message.isMidiContinue()) {
                handleStart(time);
            } else if (message.isMidiStop()) {
                handleStop(time);
            } else if (message.isSysEx()) {
                std::vector<unsigned char> sysex(data, data + message.getRawDataSize());
                handleSysex(time, sysex);
            } else {
                std::cerr << "Unused MIDI message" << std::endl;
            }
        }
    
    public:
    
        juce_midi_handler():midi_handler("JUCE")
        {}
    
        virtual ~juce_midi_handler() {}
    
        // Used with MidiBuffer (containing several messages)
        void encodeBuffer(juce::MidiBuffer& buffer)
        {
            const juce::ScopedTryLock lock(fMutex);
            if (lock.isLocked()) {
                buffer.swapWith(fOutputBuffer);
                fOutputBuffer.clear();
            } else {
                std::cerr << "encodeBuffer fails..." << std::endl;
            }
        }
        
        void decodeBuffer(juce::MidiBuffer& buffer)
        {
            juce::MidiMessage msg;
            int ignore;
            for (juce::MidiBuffer::Iterator it(buffer); it.getNextEvent(msg, ignore);) {
                decodeMessage(msg);
            }
            buffer.clear();
        }
    
        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::noteOn(channel + 1, pitch, juce::uint8(velocity)), 0);
            return nullptr;
        }
        
        void keyOff(int channel, int pitch, int velocity)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::noteOff(channel + 1, pitch, juce::uint8(velocity)), 0);
        }
        
        void ctrlChange(int channel, int ctrl, int val)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::controllerEvent(channel + 1, ctrl, juce::uint8(val)), 0);
        }
        
        void chanPress(int channel, int press)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::channelPressureChange(channel + 1, press), 0);
        }
        
        void progChange(int channel, int pgm)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::programChange(channel + 1, pgm), 0);
        }
        
        void keyPress(int channel, int pitch, int press)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::aftertouchChange(channel + 1, pitch, press), 0);
        }
        
        void pitchWheel(int channel, int wheel)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::pitchWheel(channel + 1, range(0, 16383, wheel)), 0);
        }
        
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            // TODO
        }
        
        void startSync(double date)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::midiStart(), 0);
        }
        
        void stopSync(double date)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::midiStop(), 0);
        }
        
        void clock(double date)
        {
            fOutputBuffer.addEvent(juce::MidiMessage::midiClock(), 0);
        }
    
        void sysEx(double date, std::vector<unsigned char>& message)
        {
            fOutputBuffer.addEvent(juce::MidiMessage(message.data(), (int)message.size()), 0);
        }

};

class juce_midi : public juce_midi_handler, public juce::MidiInputCallback {

    private:
    
        std::unique_ptr<juce::MidiInput> fMidiIn;
        std::unique_ptr<juce::MidiOutput> fMidiOut;
    
        void handleIncomingMidiMessage(juce::MidiInput*, const juce::MidiMessage& message)
        {
            decodeMessage(message);
        }
    
    public:
    
        juce_midi():juce_midi_handler()
        {}
    
        virtual ~juce_midi()
        {
            stopMidi();
        }
        
        bool startMidi()
        {
            if ((fMidiIn = juce::MidiInput::openDevice(juce::MidiInput::getDefaultDeviceIndex(), this)) == nullptr) {
                return false;
            }
            if ((fMidiOut = juce::MidiOutput::openDevice(juce::MidiOutput::getDefaultDeviceIndex())) == nullptr) {
                return false;
            }
            fMidiIn->start();
            return true;
        }
        
        void stopMidi()
        { 
            fMidiIn->stop();
        }
    
        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::noteOn(channel + 1, pitch, juce::uint8(velocity)));
            return nullptr;
        }
        
        void keyOff(int channel, int pitch, int velocity) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::noteOff(channel + 1, pitch, juce::uint8(velocity)));
        }
        
        void ctrlChange(int channel, int ctrl, int val) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::controllerEvent(channel + 1, ctrl, juce::uint8(val)));
        }
        
        void chanPress(int channel, int press) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::channelPressureChange(channel + 1, press));
        }
        
        void progChange(int channel, int pgm) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::programChange(channel + 1, pgm));
        }
          
        void keyPress(int channel, int pitch, int press) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::aftertouchChange(channel + 1, pitch, press));
        }
   
        void pitchWheel(int channel, int wheel) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::pitchWheel(channel + 1, range(0, 16383, wheel)));
        }
        
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            // TODO
        }
    
        void startSync(double date) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::midiStart());
        }
       
        void stopSync(double date) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::midiStop());
        }
        
        void clock(double date) 
        {
            fMidiOut->sendMessageNow(juce::MidiMessage::midiClock());
        }
    
        void sysEx(double date, std::vector<unsigned char>& message)
        {
            fMidiOut->sendMessageNow(juce::MidiMessage(message.data(), (int)message.size()));
        }
    
};

#endif // __juce_midi__

/**************************  END  juce-midi.h **************************/
/************************** BEGIN timed-base_dsp.h *****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
***************************************************************************/

#ifndef __timed_dsp__
#define __timed_dsp__

#include <set>
#include <float.h>
#include <assert.h>


namespace {
    
#if __APPLE__
#if TARGET_OS_IPHONE
    //inline double GetCurrentTimeInUsec() { return double(CAHostTimeBase::GetCurrentTimeInNanos()) / 1000.; }
    // TODO
    inline double GetCurrentTimeInUsec() { return 0.0; }
#else
    #include <CoreAudio/HostTime.h>
    inline double GetCurrentTimeInUsec() { return double(AudioConvertHostTimeToNanos(AudioGetCurrentHostTime())) / 1000.; }
#endif
#endif

#if __linux__
#include <sys/time.h>
inline double GetCurrentTimeInUsec() 
{
    struct timeval tv;
    (void)gettimeofday(&tv, (struct timezone *)NULL);
    return double((tv.tv_sec * 1000000) + tv.tv_usec);
}
#endif

#if _WIN32
#include <windows.h>
inline double GetCurrentTimeInUsec(void)
{
    LARGE_INTEGER time;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&time);
    return double(time.QuadPart) / double(frequency.QuadPart) * 1000000.0;
}
#endif
    
}

/**
 * ZoneUI : this class collect zones in a set.
 */

struct ZoneUI : public GenericUI {
    
    std::set<FAUSTFLOAT*> fZoneSet;
    
    ZoneUI():GenericUI() {}
    virtual ~ZoneUI() {}
    
    void insertZone(FAUSTFLOAT* zone) 
    { 
        if (GUI::gTimedZoneMap.find(zone) != GUI::gTimedZoneMap.end()) {
            fZoneSet.insert(zone);
        } 
    }
    
    // -- active widgets
    void addButton(const char* label, FAUSTFLOAT* zone)
    {
        insertZone(zone);
    }
    void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        insertZone(zone);
    }
    void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    
    // -- passive widgets
    void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        insertZone(zone);
    }
    void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        insertZone(zone);
    }
  
};

/**
 * Timed signal processor that allows to handle the decorated DSP by 'slices'
 * that is, calling the 'compute' method several times and changing control
 * parameters between slices. Timestamps are in usec.
 */

class timed_dsp : public decorator_dsp {

    protected:
        
        double fDateUsec;       // Compute call date in usec
        double fOffsetUsec;     // Compute call offset in usec
        bool fFirstCallback;
        ZoneUI fZoneUI;
    
        FAUSTFLOAT** fInputsSlice;
        FAUSTFLOAT** fOutputsSlice;
    
        void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) 
        {
            if (slice > 0) {
                for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                    fInputsSlice[chan] = &(inputs[chan][offset]);
                }
                for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                    fOutputsSlice[chan] = &(outputs[chan][offset]);
                }
                fDSP->compute(slice, fInputsSlice, fOutputsSlice);
            } 
        }
        
        double convertUsecToSample(double usec)
        {
            return std::max<double>(0., (double(getSampleRate()) * (usec - fDateUsec)) / 1000000.);
        }
        
        ztimedmap::iterator getNextControl(DatedControl& res)
        {
            DatedControl date1(DBL_MAX, 0);
            ztimedmap::iterator it1, it2 = GUI::gTimedZoneMap.end();
            std::set<FAUSTFLOAT*>::iterator it3;
              
            // Find date of next audio slice to compute
            for (it3 = fZoneUI.fZoneSet.begin(); it3 != fZoneUI.fZoneSet.end(); it3++) {
                // If value list is not empty, get the date and keep the minimal one
                it1 = GUI::gTimedZoneMap.find(*it3);
                if (it1 != GUI::gTimedZoneMap.end()) { // Check if zone still in global GUI::gTimedZoneMap (since MidiUI may have been desallocated)
                    DatedControl date2;
                    if (ringbuffer_peek((*it1).second, (char*)&date2, sizeof(DatedControl)) == sizeof(DatedControl) 
                        && date2.fDate < date1.fDate) {
                        it2 = it1;
                        date1 = date2;
                    }
                }
            }
            
            res = date1;
            return it2;
        }
        
        virtual void computeAux(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs, bool convert_ts)
        {
            int slice, offset = 0;
            ztimedmap::iterator it;
            DatedControl next_control;
             
            // Do audio computation "slice" by "slice"
            while ((it = getNextControl(next_control)) != GUI::gTimedZoneMap.end()) {
                
                // If needed, convert next_control in samples from begining of the buffer, possible moving to 0 (if negative)
                if (convert_ts) {
                    next_control.fDate = convertUsecToSample(next_control.fDate);
                }
                     
                // Compute audio slice
                slice = int(next_control.fDate) - offset;
                computeSlice(offset, slice, inputs, outputs);
                offset += slice;
               
                // Update control
                ringbuffer_t* control_values = (*it).second;
                *((*it).first) = next_control.fValue;
                
                // Move ringbuffer pointer
                ringbuffer_read_advance(control_values, sizeof(DatedControl));
            } 
            
            // Compute last audio slice
            slice = count - offset;
            computeSlice(offset, slice, inputs, outputs);
        }

    public:

        timed_dsp(base_dsp* base_dsp):decorator_dsp(base_dsp), fDateUsec(0), fOffsetUsec(0), fFirstCallback(true)
        {
            fInputsSlice = new FAUSTFLOAT*[base_dsp->getNumInputs()];
            fOutputsSlice = new FAUSTFLOAT*[base_dsp->getNumOutputs()];
        }
        virtual ~timed_dsp() 
        {
            delete [] fInputsSlice;
            delete [] fOutputsSlice;
        }
        
        virtual void init(int sample_rate)
        {
            fDSP->init(sample_rate);
        }
        
        virtual void buildUserInterface(UI* ui_interface)   
        { 
            fDSP->buildUserInterface(ui_interface); 
            // Only keep zones that are in GUI::gTimedZoneMap
            fDSP->buildUserInterface(&fZoneUI);
        }
    
        virtual timed_dsp* clone()
        {
            return new timed_dsp(fDSP->clone());
        }
    
        // Default method take a timestamp at 'compute' call time
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(::GetCurrentTimeInUsec(), count, inputs, outputs);
        }    
        
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            if (date_usec == -1) {
                // Timestamp is expressed in frames
                computeAux(count, inputs, outputs, false);
            } else {
                // Save the timestamp offset in the first callback
                if (fFirstCallback) {
                    fFirstCallback = false;
                    double current_date_usec = ::GetCurrentTimeInUsec();
                    fDateUsec = current_date_usec;
                    fOffsetUsec = current_date_usec - date_usec;
                }
                
                // RtMidi mode: timestamp must be converted in frames
                computeAux(count, inputs, outputs, true);
                
                // Keep call date 
                fDateUsec = date_usec + fOffsetUsec;
            }
        }
        
};

#endif
/************************** END timed-base_dsp.h **************************/
#endif

#if defined(POLY2)
#include "effect.h"
#endif 

// we require macro declarations
#define FAUST_UIMACROS

// but we will ignore most of them
#define FAUST_ADDBUTTON(l,f)
#define FAUST_ADDCHECKBOX(l,f)
#define FAUST_ADDSOUNDFILE(l,s)
#define FAUST_ADDVERTICALSLIDER(l,f,i,a,b,s)
#define FAUST_ADDHORIZONTALSLIDER(l,f,i,a,b,s)
#define FAUST_ADDNUMENTRY(l,f,i,a,b,s)
#define FAUST_ADDVERTICALBARGRAPH(l,f,a,b)
#define FAUST_ADDHORIZONTALBARGRAPH(l,f,a,b)


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static double mydsp_faustpower2_f(double value) {
	return value * value;
}

class mydsp : public base_dsp {
	
 public:
	
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	int fSampleRate;
	double fConst1;
	double fConst2;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	double fConst3;
	double fRec0[3];
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fVslider6;
	double fRec1[3];
	double fRec2[3];
	double fRec3[3];
	double fRec4[3];
	double fRec5[3];
	double fRec6[3];
	double fRec7[3];
	double fRec8[3];
	double fRec9[3];
	double fRec10[3];
	double fRec11[3];
	double fRec12[3];
	double fRec13[3];
	double fRec14[3];
	double fRec15[3];
	double fRec16[3];
	double fRec17[3];
	double fRec18[3];
	double fRec19[3];
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fRec25[3];
	double fRec26[3];
	double fRec27[3];
	double fRec28[3];
	double fRec29[3];
	double fRec30[3];
	double fRec31[3];
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT fVslider10;
	FAUSTFLOAT fVslider11;
	FAUSTFLOAT fVslider12;
	double fRec32[3];
	FAUSTFLOAT fVslider13;
	FAUSTFLOAT fVslider14;
	double fRec33[3];
	double fRec34[3];
	double fRec35[3];
	double fRec36[3];
	double fRec37[3];
	double fRec38[3];
	double fRec39[3];
	double fRec40[3];
	double fRec41[3];
	double fRec42[3];
	double fRec43[3];
	double fRec44[3];
	double fRec45[3];
	double fRec46[3];
	double fRec47[3];
	double fRec48[3];
	double fRec49[3];
	double fRec50[3];
	double fRec51[3];
	double fRec52[3];
	double fRec53[3];
	double fRec54[3];
	double fRec55[3];
	double fRec56[3];
	double fRec57[3];
	double fRec58[3];
	double fRec59[3];
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fRec63[3];
	FAUSTFLOAT fVslider15;
	FAUSTFLOAT fVslider16;
	FAUSTFLOAT fVslider17;
	FAUSTFLOAT fVslider18;
	FAUSTFLOAT fVslider19;
	FAUSTFLOAT fVslider20;
	double fRec64[3];
	FAUSTFLOAT fVslider21;
	FAUSTFLOAT fVslider22;
	double fRec65[3];
	double fRec66[3];
	double fRec67[3];
	double fRec68[3];
	double fRec69[3];
	double fRec70[3];
	double fRec71[3];
	double fRec72[3];
	double fRec73[3];
	double fRec74[3];
	double fRec75[3];
	double fRec76[3];
	double fRec77[3];
	double fRec78[3];
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fRec83[3];
	double fRec84[3];
	double fRec85[3];
	double fRec86[3];
	double fRec87[3];
	double fRec88[3];
	double fRec89[3];
	double fRec90[3];
	double fRec91[3];
	double fRec92[3];
	double fRec93[3];
	double fRec94[3];
	double fRec95[3];
	FAUSTFLOAT fVslider23;
	FAUSTFLOAT fVslider24;
	FAUSTFLOAT fVslider25;
	FAUSTFLOAT fVslider26;
	FAUSTFLOAT fVslider27;
	FAUSTFLOAT fVslider28;
	double fRec96[3];
	FAUSTFLOAT fVslider29;
	FAUSTFLOAT fVslider30;
	double fRec97[3];
	double fRec98[3];
	double fRec99[3];
	double fRec100[3];
	double fRec101[3];
	double fRec102[3];
	double fRec103[3];
	double fRec104[3];
	double fRec105[3];
	double fRec106[3];
	double fRec107[3];
	double fRec108[3];
	double fRec109[3];
	double fRec110[3];
	double fRec111[3];
	double fRec112[3];
	double fRec113[3];
	double fRec114[3];
	double fRec115[3];
	double fRec116[3];
	double fRec117[3];
	double fRec118[3];
	double fRec119[3];
	double fRec120[3];
	double fRec121[3];
	double fRec122[3];
	double fRec123[3];
	double fRec124[3];
	double fRec125[3];
	double fRec126[3];
	double fRec127[3];
	FAUSTFLOAT fVslider31;
	FAUSTFLOAT fVslider32;
	FAUSTFLOAT fVslider33;
	FAUSTFLOAT fVslider34;
	FAUSTFLOAT fVslider35;
	FAUSTFLOAT fVslider36;
	double fRec128[3];
	FAUSTFLOAT fVslider37;
	FAUSTFLOAT fVslider38;
	double fRec129[3];
	double fRec130[3];
	double fRec131[3];
	double fRec132[3];
	double fRec133[3];
	double fRec134[3];
	double fRec135[3];
	double fRec136[3];
	double fRec137[3];
	double fRec138[3];
	double fRec139[3];
	double fRec140[3];
	double fRec141[3];
	double fRec142[3];
	double fRec143[3];
	double fRec144[3];
	double fRec145[3];
	double fRec146[3];
	double fRec147[3];
	double fRec148[3];
	double fRec149[3];
	double fRec150[3];
	double fRec151[3];
	double fRec152[3];
	double fRec153[3];
	double fRec154[3];
	double fRec155[3];
	double fRec156[3];
	double fRec157[3];
	double fRec158[3];
	double fRec159[3];
	FAUSTFLOAT fVslider39;
	FAUSTFLOAT fVslider40;
	FAUSTFLOAT fVslider41;
	FAUSTFLOAT fVslider42;
	FAUSTFLOAT fVslider43;
	FAUSTFLOAT fVslider44;
	double fRec160[3];
	FAUSTFLOAT fVslider45;
	FAUSTFLOAT fVslider46;
	double fRec161[3];
	double fRec162[3];
	double fRec163[3];
	double fRec164[3];
	double fRec165[3];
	double fRec166[3];
	double fRec167[3];
	double fRec168[3];
	double fRec169[3];
	double fRec170[3];
	double fRec171[3];
	double fRec172[3];
	double fRec173[3];
	double fRec174[3];
	double fRec175[3];
	double fRec176[3];
	double fRec177[3];
	double fRec178[3];
	double fRec179[3];
	double fRec180[3];
	double fRec181[3];
	double fRec182[3];
	double fRec183[3];
	double fRec184[3];
	double fRec185[3];
	double fRec186[3];
	double fRec187[3];
	double fRec188[3];
	double fRec189[3];
	double fRec190[3];
	double fRec191[3];
	FAUSTFLOAT fVslider47;
	FAUSTFLOAT fVslider48;
	FAUSTFLOAT fVslider49;
	FAUSTFLOAT fVslider50;
	FAUSTFLOAT fVslider51;
	FAUSTFLOAT fVslider52;
	double fRec192[3];
	FAUSTFLOAT fVslider53;
	FAUSTFLOAT fVslider54;
	double fRec193[3];
	double fRec194[3];
	double fRec195[3];
	double fRec196[3];
	double fRec197[3];
	double fRec198[3];
	double fRec199[3];
	double fRec200[3];
	double fRec201[3];
	double fRec202[3];
	double fRec203[3];
	double fRec204[3];
	double fRec205[3];
	double fRec206[3];
	double fRec207[3];
	double fRec208[3];
	double fRec209[3];
	double fRec210[3];
	double fRec211[3];
	double fRec212[3];
	double fRec213[3];
	double fRec214[3];
	double fRec215[3];
	double fRec216[3];
	double fRec217[3];
	double fRec218[3];
	double fRec219[3];
	double fRec220[3];
	double fRec221[3];
	double fRec222[3];
	double fRec223[3];
	FAUSTFLOAT fVslider55;
	FAUSTFLOAT fVslider56;
	FAUSTFLOAT fVslider57;
	FAUSTFLOAT fVslider58;
	FAUSTFLOAT fVslider59;
	FAUSTFLOAT fVslider60;
	double fRec224[3];
	FAUSTFLOAT fVslider61;
	FAUSTFLOAT fVslider62;
	double fRec225[3];
	double fRec226[3];
	double fRec227[3];
	double fRec228[3];
	double fRec229[3];
	double fRec230[3];
	double fRec231[3];
	double fRec232[3];
	double fRec233[3];
	double fRec234[3];
	double fRec235[3];
	double fRec236[3];
	double fRec237[3];
	double fRec238[3];
	double fRec239[3];
	double fRec240[3];
	double fRec241[3];
	double fRec242[3];
	double fRec243[3];
	double fRec244[3];
	double fRec245[3];
	double fRec246[3];
	double fRec247[3];
	double fRec248[3];
	double fRec249[3];
	double fRec250[3];
	double fRec251[3];
	double fRec252[3];
	double fRec253[3];
	double fRec254[3];
	double fRec255[3];
	FAUSTFLOAT fVslider63;
	double fRec256[3];
	double fRec257[3];
	double fRec258[3];
	double fRec259[3];
	double fRec260[3];
	double fRec261[3];
	double fRec262[3];
	double fRec263[3];
	double fRec264[3];
	double fRec265[3];
	double fRec266[3];
	double fRec267[3];
	double fRec268[3];
	double fRec269[3];
	double fRec270[3];
	double fRec271[3];
	double fRec272[3];
	double fRec273[3];
	double fRec274[3];
	double fRec275[3];
	double fRec276[3];
	double fRec277[3];
	double fRec278[3];
	double fRec279[3];
	double fRec280[3];
	double fRec281[3];
	double fRec282[3];
	double fRec283[3];
	double fRec284[3];
	double fRec285[3];
	double fRec286[3];
	double fRec287[3];
	double fRec288[3];
	double fRec289[3];
	double fRec290[3];
	double fRec291[3];
	double fRec292[3];
	double fRec293[3];
	double fRec294[3];
	double fRec295[3];
	double fRec296[3];
	double fRec297[3];
	double fRec298[3];
	double fRec299[3];
	double fRec300[3];
	double fRec301[3];
	double fRec302[3];
	double fRec303[3];
	double fRec304[3];
	double fRec305[3];
	double fRec306[3];
	double fRec307[3];
	double fRec308[3];
	double fRec309[3];
	double fRec310[3];
	double fRec311[3];
	double fRec312[3];
	double fRec313[3];
	double fRec314[3];
	double fRec315[3];
	double fRec316[3];
	double fRec317[3];
	double fRec318[3];
	double fRec319[3];
	double fRec320[3];
	double fRec321[3];
	double fRec322[3];
	double fRec323[3];
	double fRec324[3];
	double fRec325[3];
	double fRec326[3];
	double fRec327[3];
	double fRec328[3];
	double fRec329[3];
	double fRec330[3];
	double fRec331[3];
	double fRec332[3];
	double fRec333[3];
	double fRec334[3];
	double fRec335[3];
	double fRec336[3];
	double fRec337[3];
	double fRec338[3];
	double fRec339[3];
	double fRec340[3];
	double fRec341[3];
	double fRec342[3];
	double fRec343[3];
	double fRec344[3];
	double fRec345[3];
	double fRec346[3];
	double fRec347[3];
	double fRec348[3];
	double fRec349[3];
	double fRec350[3];
	double fRec351[3];
	double fRec352[3];
	double fRec353[3];
	double fRec354[3];
	double fRec355[3];
	double fRec356[3];
	double fRec357[3];
	double fRec358[3];
	double fRec359[3];
	double fRec360[3];
	double fRec361[3];
	double fRec362[3];
	double fRec363[3];
	double fRec364[3];
	double fRec365[3];
	double fRec366[3];
	double fRec367[3];
	double fRec368[3];
	double fRec369[3];
	double fRec370[3];
	double fRec371[3];
	double fRec372[3];
	double fRec373[3];
	double fRec374[3];
	double fRec375[3];
	double fRec376[3];
	double fRec377[3];
	double fRec378[3];
	double fRec379[3];
	double fRec380[3];
	double fRec381[3];
	double fRec382[3];
	double fRec383[3];
	double fRec384[3];
	double fRec385[3];
	double fRec386[3];
	double fRec387[3];
	double fRec388[3];
	double fRec389[3];
	double fRec390[3];
	double fRec391[3];
	double fRec392[3];
	double fRec393[3];
	double fRec394[3];
	double fRec395[3];
	double fRec396[3];
	double fRec397[3];
	double fRec398[3];
	double fRec399[3];
	double fRec400[3];
	double fRec401[3];
	double fRec402[3];
	double fRec403[3];
	double fRec404[3];
	double fRec405[3];
	double fRec406[3];
	double fRec407[3];
	double fRec408[3];
	double fRec409[3];
	double fRec410[3];
	double fRec411[3];
	double fRec412[3];
	double fRec413[3];
	double fRec414[3];
	double fRec415[3];
	double fRec416[3];
	double fRec417[3];
	double fRec418[3];
	double fRec419[3];
	double fRec420[3];
	double fRec421[3];
	double fRec422[3];
	double fRec423[3];
	double fRec424[3];
	double fRec425[3];
	double fRec426[3];
	double fRec427[3];
	double fRec428[3];
	double fRec429[3];
	double fRec430[3];
	double fRec431[3];
	double fRec432[3];
	double fRec433[3];
	double fRec434[3];
	double fRec435[3];
	double fRec436[3];
	double fRec437[3];
	double fRec438[3];
	double fRec439[3];
	double fRec440[3];
	double fRec441[3];
	double fRec442[3];
	double fRec443[3];
	double fRec444[3];
	double fRec445[3];
	double fRec446[3];
	double fRec447[3];
	double fRec448[3];
	double fRec449[3];
	double fRec450[3];
	double fRec451[3];
	double fRec452[3];
	double fRec453[3];
	double fRec454[3];
	double fRec455[3];
	double fRec456[3];
	double fRec457[3];
	double fRec458[3];
	double fRec459[3];
	double fRec460[3];
	double fRec461[3];
	double fRec462[3];
	double fRec463[3];
	double fRec464[3];
	double fRec465[3];
	double fRec466[3];
	double fRec467[3];
	double fRec468[3];
	double fRec469[3];
	double fRec470[3];
	double fRec471[3];
	double fRec472[3];
	double fRec473[3];
	double fRec474[3];
	double fRec475[3];
	double fRec476[3];
	double fRec477[3];
	double fRec478[3];
	double fRec479[3];
	double fRec480[3];
	double fRec481[3];
	double fRec482[3];
	double fRec483[3];
	double fRec484[3];
	double fRec485[3];
	double fRec486[3];
	double fRec487[3];
	double fRec488[3];
	double fRec489[3];
	double fRec490[3];
	double fRec491[3];
	double fRec492[3];
	double fRec493[3];
	double fRec494[3];
	double fRec495[3];
	double fRec496[3];
	double fRec497[3];
	double fRec498[3];
	double fRec499[3];
	double fRec500[3];
	double fRec501[3];
	double fRec502[3];
	double fRec503[3];
	double fRec504[3];
	double fRec505[3];
	double fRec506[3];
	double fRec507[3];
	double fRec508[3];
	double fRec509[3];
	double fRec510[3];
	double fRec511[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "amy universe");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -double -ftz 0");
		m->declare("filename", "moodygirl.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("license", "WTFPL");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "moodygirl");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("version", "0.14");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		double fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
		fConst1 = 1.0 / fConst0;
		fConst2 = 0.5 * fConst0;
		fConst3 = 6.283185307179586 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(1.0);
		fVslider1 = FAUSTFLOAT(1.0);
		fVslider2 = FAUSTFLOAT(0.0);
		fVslider3 = FAUSTFLOAT(1.0);
		fVslider4 = FAUSTFLOAT(2.2e+02);
		fVslider5 = FAUSTFLOAT(1.0);
		fVslider6 = FAUSTFLOAT(32.0);
		fVslider7 = FAUSTFLOAT(0.1);
		fVslider8 = FAUSTFLOAT(1.0);
		fVslider9 = FAUSTFLOAT(1.0);
		fVslider10 = FAUSTFLOAT(0.0);
		fVslider11 = FAUSTFLOAT(1.0);
		fVslider12 = FAUSTFLOAT(2.2e+02);
		fVslider13 = FAUSTFLOAT(1.0);
		fVslider14 = FAUSTFLOAT(32.0);
		fVslider15 = FAUSTFLOAT(0.1);
		fVslider16 = FAUSTFLOAT(1.0);
		fVslider17 = FAUSTFLOAT(1.0);
		fVslider18 = FAUSTFLOAT(0.0);
		fVslider19 = FAUSTFLOAT(1.0);
		fVslider20 = FAUSTFLOAT(2.2e+02);
		fVslider21 = FAUSTFLOAT(1.0);
		fVslider22 = FAUSTFLOAT(32.0);
		fVslider23 = FAUSTFLOAT(0.1);
		fVslider24 = FAUSTFLOAT(1.0);
		fVslider25 = FAUSTFLOAT(1.0);
		fVslider26 = FAUSTFLOAT(0.0);
		fVslider27 = FAUSTFLOAT(1.0);
		fVslider28 = FAUSTFLOAT(2.2e+02);
		fVslider29 = FAUSTFLOAT(1.0);
		fVslider30 = FAUSTFLOAT(32.0);
		fVslider31 = FAUSTFLOAT(0.1);
		fVslider32 = FAUSTFLOAT(1.0);
		fVslider33 = FAUSTFLOAT(1.0);
		fVslider34 = FAUSTFLOAT(0.0);
		fVslider35 = FAUSTFLOAT(1.0);
		fVslider36 = FAUSTFLOAT(2.2e+02);
		fVslider37 = FAUSTFLOAT(1.0);
		fVslider38 = FAUSTFLOAT(32.0);
		fVslider39 = FAUSTFLOAT(0.1);
		fVslider40 = FAUSTFLOAT(1.0);
		fVslider41 = FAUSTFLOAT(1.0);
		fVslider42 = FAUSTFLOAT(0.0);
		fVslider43 = FAUSTFLOAT(1.0);
		fVslider44 = FAUSTFLOAT(2.2e+02);
		fVslider45 = FAUSTFLOAT(1.0);
		fVslider46 = FAUSTFLOAT(32.0);
		fVslider47 = FAUSTFLOAT(0.1);
		fVslider48 = FAUSTFLOAT(1.0);
		fVslider49 = FAUSTFLOAT(1.0);
		fVslider50 = FAUSTFLOAT(0.0);
		fVslider51 = FAUSTFLOAT(1.0);
		fVslider52 = FAUSTFLOAT(2.2e+02);
		fVslider53 = FAUSTFLOAT(1.0);
		fVslider54 = FAUSTFLOAT(32.0);
		fVslider55 = FAUSTFLOAT(0.1);
		fVslider56 = FAUSTFLOAT(1.0);
		fVslider57 = FAUSTFLOAT(1.0);
		fVslider58 = FAUSTFLOAT(0.0);
		fVslider59 = FAUSTFLOAT(1.0);
		fVslider60 = FAUSTFLOAT(2.2e+02);
		fVslider61 = FAUSTFLOAT(1.0);
		fVslider62 = FAUSTFLOAT(32.0);
		fVslider63 = FAUSTFLOAT(0.1);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 3; l0 = l0 + 1) {
			fRec0[l0] = 0.0;
		}
		for (int l1 = 0; l1 < 3; l1 = l1 + 1) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 3; l2 = l2 + 1) {
			fRec2[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 3; l3 = l3 + 1) {
			fRec3[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 3; l4 = l4 + 1) {
			fRec4[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec5[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 3; l6 = l6 + 1) {
			fRec6[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 3; l7 = l7 + 1) {
			fRec7[l7] = 0.0;
		}
		for (int l8 = 0; l8 < 3; l8 = l8 + 1) {
			fRec8[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec9[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 3; l10 = l10 + 1) {
			fRec10[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 3; l11 = l11 + 1) {
			fRec11[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 3; l12 = l12 + 1) {
			fRec12[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec13[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 3; l14 = l14 + 1) {
			fRec14[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 3; l15 = l15 + 1) {
			fRec15[l15] = 0.0;
		}
		for (int l16 = 0; l16 < 3; l16 = l16 + 1) {
			fRec16[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 3; l17 = l17 + 1) {
			fRec17[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 3; l18 = l18 + 1) {
			fRec18[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 3; l19 = l19 + 1) {
			fRec19[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 3; l20 = l20 + 1) {
			fRec20[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 3; l21 = l21 + 1) {
			fRec21[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 3; l22 = l22 + 1) {
			fRec22[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 3; l23 = l23 + 1) {
			fRec23[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 3; l24 = l24 + 1) {
			fRec24[l24] = 0.0;
		}
		for (int l25 = 0; l25 < 3; l25 = l25 + 1) {
			fRec25[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 3; l26 = l26 + 1) {
			fRec26[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 3; l27 = l27 + 1) {
			fRec27[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 3; l28 = l28 + 1) {
			fRec28[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 3; l29 = l29 + 1) {
			fRec29[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 3; l30 = l30 + 1) {
			fRec30[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 3; l31 = l31 + 1) {
			fRec31[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 3; l32 = l32 + 1) {
			fRec32[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 3; l33 = l33 + 1) {
			fRec33[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 3; l34 = l34 + 1) {
			fRec34[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 3; l35 = l35 + 1) {
			fRec35[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 3; l36 = l36 + 1) {
			fRec36[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 3; l37 = l37 + 1) {
			fRec37[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 3; l38 = l38 + 1) {
			fRec38[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 3; l39 = l39 + 1) {
			fRec39[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 3; l40 = l40 + 1) {
			fRec40[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 3; l41 = l41 + 1) {
			fRec41[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 3; l42 = l42 + 1) {
			fRec42[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 3; l43 = l43 + 1) {
			fRec43[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 3; l44 = l44 + 1) {
			fRec44[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 3; l45 = l45 + 1) {
			fRec45[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 3; l46 = l46 + 1) {
			fRec46[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 3; l47 = l47 + 1) {
			fRec47[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 3; l48 = l48 + 1) {
			fRec48[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 3; l49 = l49 + 1) {
			fRec49[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 3; l50 = l50 + 1) {
			fRec50[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 3; l51 = l51 + 1) {
			fRec51[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 3; l52 = l52 + 1) {
			fRec52[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 3; l53 = l53 + 1) {
			fRec53[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 3; l54 = l54 + 1) {
			fRec54[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 3; l55 = l55 + 1) {
			fRec55[l55] = 0.0;
		}
		for (int l56 = 0; l56 < 3; l56 = l56 + 1) {
			fRec56[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 3; l57 = l57 + 1) {
			fRec57[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 3; l58 = l58 + 1) {
			fRec58[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 3; l59 = l59 + 1) {
			fRec59[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 3; l60 = l60 + 1) {
			fRec60[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 3; l61 = l61 + 1) {
			fRec61[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 3; l62 = l62 + 1) {
			fRec62[l62] = 0.0;
		}
		for (int l63 = 0; l63 < 3; l63 = l63 + 1) {
			fRec63[l63] = 0.0;
		}
		for (int l64 = 0; l64 < 3; l64 = l64 + 1) {
			fRec64[l64] = 0.0;
		}
		for (int l65 = 0; l65 < 3; l65 = l65 + 1) {
			fRec65[l65] = 0.0;
		}
		for (int l66 = 0; l66 < 3; l66 = l66 + 1) {
			fRec66[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 3; l67 = l67 + 1) {
			fRec67[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 3; l68 = l68 + 1) {
			fRec68[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 3; l69 = l69 + 1) {
			fRec69[l69] = 0.0;
		}
		for (int l70 = 0; l70 < 3; l70 = l70 + 1) {
			fRec70[l70] = 0.0;
		}
		for (int l71 = 0; l71 < 3; l71 = l71 + 1) {
			fRec71[l71] = 0.0;
		}
		for (int l72 = 0; l72 < 3; l72 = l72 + 1) {
			fRec72[l72] = 0.0;
		}
		for (int l73 = 0; l73 < 3; l73 = l73 + 1) {
			fRec73[l73] = 0.0;
		}
		for (int l74 = 0; l74 < 3; l74 = l74 + 1) {
			fRec74[l74] = 0.0;
		}
		for (int l75 = 0; l75 < 3; l75 = l75 + 1) {
			fRec75[l75] = 0.0;
		}
		for (int l76 = 0; l76 < 3; l76 = l76 + 1) {
			fRec76[l76] = 0.0;
		}
		for (int l77 = 0; l77 < 3; l77 = l77 + 1) {
			fRec77[l77] = 0.0;
		}
		for (int l78 = 0; l78 < 3; l78 = l78 + 1) {
			fRec78[l78] = 0.0;
		}
		for (int l79 = 0; l79 < 3; l79 = l79 + 1) {
			fRec79[l79] = 0.0;
		}
		for (int l80 = 0; l80 < 3; l80 = l80 + 1) {
			fRec80[l80] = 0.0;
		}
		for (int l81 = 0; l81 < 3; l81 = l81 + 1) {
			fRec81[l81] = 0.0;
		}
		for (int l82 = 0; l82 < 3; l82 = l82 + 1) {
			fRec82[l82] = 0.0;
		}
		for (int l83 = 0; l83 < 3; l83 = l83 + 1) {
			fRec83[l83] = 0.0;
		}
		for (int l84 = 0; l84 < 3; l84 = l84 + 1) {
			fRec84[l84] = 0.0;
		}
		for (int l85 = 0; l85 < 3; l85 = l85 + 1) {
			fRec85[l85] = 0.0;
		}
		for (int l86 = 0; l86 < 3; l86 = l86 + 1) {
			fRec86[l86] = 0.0;
		}
		for (int l87 = 0; l87 < 3; l87 = l87 + 1) {
			fRec87[l87] = 0.0;
		}
		for (int l88 = 0; l88 < 3; l88 = l88 + 1) {
			fRec88[l88] = 0.0;
		}
		for (int l89 = 0; l89 < 3; l89 = l89 + 1) {
			fRec89[l89] = 0.0;
		}
		for (int l90 = 0; l90 < 3; l90 = l90 + 1) {
			fRec90[l90] = 0.0;
		}
		for (int l91 = 0; l91 < 3; l91 = l91 + 1) {
			fRec91[l91] = 0.0;
		}
		for (int l92 = 0; l92 < 3; l92 = l92 + 1) {
			fRec92[l92] = 0.0;
		}
		for (int l93 = 0; l93 < 3; l93 = l93 + 1) {
			fRec93[l93] = 0.0;
		}
		for (int l94 = 0; l94 < 3; l94 = l94 + 1) {
			fRec94[l94] = 0.0;
		}
		for (int l95 = 0; l95 < 3; l95 = l95 + 1) {
			fRec95[l95] = 0.0;
		}
		for (int l96 = 0; l96 < 3; l96 = l96 + 1) {
			fRec96[l96] = 0.0;
		}
		for (int l97 = 0; l97 < 3; l97 = l97 + 1) {
			fRec97[l97] = 0.0;
		}
		for (int l98 = 0; l98 < 3; l98 = l98 + 1) {
			fRec98[l98] = 0.0;
		}
		for (int l99 = 0; l99 < 3; l99 = l99 + 1) {
			fRec99[l99] = 0.0;
		}
		for (int l100 = 0; l100 < 3; l100 = l100 + 1) {
			fRec100[l100] = 0.0;
		}
		for (int l101 = 0; l101 < 3; l101 = l101 + 1) {
			fRec101[l101] = 0.0;
		}
		for (int l102 = 0; l102 < 3; l102 = l102 + 1) {
			fRec102[l102] = 0.0;
		}
		for (int l103 = 0; l103 < 3; l103 = l103 + 1) {
			fRec103[l103] = 0.0;
		}
		for (int l104 = 0; l104 < 3; l104 = l104 + 1) {
			fRec104[l104] = 0.0;
		}
		for (int l105 = 0; l105 < 3; l105 = l105 + 1) {
			fRec105[l105] = 0.0;
		}
		for (int l106 = 0; l106 < 3; l106 = l106 + 1) {
			fRec106[l106] = 0.0;
		}
		for (int l107 = 0; l107 < 3; l107 = l107 + 1) {
			fRec107[l107] = 0.0;
		}
		for (int l108 = 0; l108 < 3; l108 = l108 + 1) {
			fRec108[l108] = 0.0;
		}
		for (int l109 = 0; l109 < 3; l109 = l109 + 1) {
			fRec109[l109] = 0.0;
		}
		for (int l110 = 0; l110 < 3; l110 = l110 + 1) {
			fRec110[l110] = 0.0;
		}
		for (int l111 = 0; l111 < 3; l111 = l111 + 1) {
			fRec111[l111] = 0.0;
		}
		for (int l112 = 0; l112 < 3; l112 = l112 + 1) {
			fRec112[l112] = 0.0;
		}
		for (int l113 = 0; l113 < 3; l113 = l113 + 1) {
			fRec113[l113] = 0.0;
		}
		for (int l114 = 0; l114 < 3; l114 = l114 + 1) {
			fRec114[l114] = 0.0;
		}
		for (int l115 = 0; l115 < 3; l115 = l115 + 1) {
			fRec115[l115] = 0.0;
		}
		for (int l116 = 0; l116 < 3; l116 = l116 + 1) {
			fRec116[l116] = 0.0;
		}
		for (int l117 = 0; l117 < 3; l117 = l117 + 1) {
			fRec117[l117] = 0.0;
		}
		for (int l118 = 0; l118 < 3; l118 = l118 + 1) {
			fRec118[l118] = 0.0;
		}
		for (int l119 = 0; l119 < 3; l119 = l119 + 1) {
			fRec119[l119] = 0.0;
		}
		for (int l120 = 0; l120 < 3; l120 = l120 + 1) {
			fRec120[l120] = 0.0;
		}
		for (int l121 = 0; l121 < 3; l121 = l121 + 1) {
			fRec121[l121] = 0.0;
		}
		for (int l122 = 0; l122 < 3; l122 = l122 + 1) {
			fRec122[l122] = 0.0;
		}
		for (int l123 = 0; l123 < 3; l123 = l123 + 1) {
			fRec123[l123] = 0.0;
		}
		for (int l124 = 0; l124 < 3; l124 = l124 + 1) {
			fRec124[l124] = 0.0;
		}
		for (int l125 = 0; l125 < 3; l125 = l125 + 1) {
			fRec125[l125] = 0.0;
		}
		for (int l126 = 0; l126 < 3; l126 = l126 + 1) {
			fRec126[l126] = 0.0;
		}
		for (int l127 = 0; l127 < 3; l127 = l127 + 1) {
			fRec127[l127] = 0.0;
		}
		for (int l128 = 0; l128 < 3; l128 = l128 + 1) {
			fRec128[l128] = 0.0;
		}
		for (int l129 = 0; l129 < 3; l129 = l129 + 1) {
			fRec129[l129] = 0.0;
		}
		for (int l130 = 0; l130 < 3; l130 = l130 + 1) {
			fRec130[l130] = 0.0;
		}
		for (int l131 = 0; l131 < 3; l131 = l131 + 1) {
			fRec131[l131] = 0.0;
		}
		for (int l132 = 0; l132 < 3; l132 = l132 + 1) {
			fRec132[l132] = 0.0;
		}
		for (int l133 = 0; l133 < 3; l133 = l133 + 1) {
			fRec133[l133] = 0.0;
		}
		for (int l134 = 0; l134 < 3; l134 = l134 + 1) {
			fRec134[l134] = 0.0;
		}
		for (int l135 = 0; l135 < 3; l135 = l135 + 1) {
			fRec135[l135] = 0.0;
		}
		for (int l136 = 0; l136 < 3; l136 = l136 + 1) {
			fRec136[l136] = 0.0;
		}
		for (int l137 = 0; l137 < 3; l137 = l137 + 1) {
			fRec137[l137] = 0.0;
		}
		for (int l138 = 0; l138 < 3; l138 = l138 + 1) {
			fRec138[l138] = 0.0;
		}
		for (int l139 = 0; l139 < 3; l139 = l139 + 1) {
			fRec139[l139] = 0.0;
		}
		for (int l140 = 0; l140 < 3; l140 = l140 + 1) {
			fRec140[l140] = 0.0;
		}
		for (int l141 = 0; l141 < 3; l141 = l141 + 1) {
			fRec141[l141] = 0.0;
		}
		for (int l142 = 0; l142 < 3; l142 = l142 + 1) {
			fRec142[l142] = 0.0;
		}
		for (int l143 = 0; l143 < 3; l143 = l143 + 1) {
			fRec143[l143] = 0.0;
		}
		for (int l144 = 0; l144 < 3; l144 = l144 + 1) {
			fRec144[l144] = 0.0;
		}
		for (int l145 = 0; l145 < 3; l145 = l145 + 1) {
			fRec145[l145] = 0.0;
		}
		for (int l146 = 0; l146 < 3; l146 = l146 + 1) {
			fRec146[l146] = 0.0;
		}
		for (int l147 = 0; l147 < 3; l147 = l147 + 1) {
			fRec147[l147] = 0.0;
		}
		for (int l148 = 0; l148 < 3; l148 = l148 + 1) {
			fRec148[l148] = 0.0;
		}
		for (int l149 = 0; l149 < 3; l149 = l149 + 1) {
			fRec149[l149] = 0.0;
		}
		for (int l150 = 0; l150 < 3; l150 = l150 + 1) {
			fRec150[l150] = 0.0;
		}
		for (int l151 = 0; l151 < 3; l151 = l151 + 1) {
			fRec151[l151] = 0.0;
		}
		for (int l152 = 0; l152 < 3; l152 = l152 + 1) {
			fRec152[l152] = 0.0;
		}
		for (int l153 = 0; l153 < 3; l153 = l153 + 1) {
			fRec153[l153] = 0.0;
		}
		for (int l154 = 0; l154 < 3; l154 = l154 + 1) {
			fRec154[l154] = 0.0;
		}
		for (int l155 = 0; l155 < 3; l155 = l155 + 1) {
			fRec155[l155] = 0.0;
		}
		for (int l156 = 0; l156 < 3; l156 = l156 + 1) {
			fRec156[l156] = 0.0;
		}
		for (int l157 = 0; l157 < 3; l157 = l157 + 1) {
			fRec157[l157] = 0.0;
		}
		for (int l158 = 0; l158 < 3; l158 = l158 + 1) {
			fRec158[l158] = 0.0;
		}
		for (int l159 = 0; l159 < 3; l159 = l159 + 1) {
			fRec159[l159] = 0.0;
		}
		for (int l160 = 0; l160 < 3; l160 = l160 + 1) {
			fRec160[l160] = 0.0;
		}
		for (int l161 = 0; l161 < 3; l161 = l161 + 1) {
			fRec161[l161] = 0.0;
		}
		for (int l162 = 0; l162 < 3; l162 = l162 + 1) {
			fRec162[l162] = 0.0;
		}
		for (int l163 = 0; l163 < 3; l163 = l163 + 1) {
			fRec163[l163] = 0.0;
		}
		for (int l164 = 0; l164 < 3; l164 = l164 + 1) {
			fRec164[l164] = 0.0;
		}
		for (int l165 = 0; l165 < 3; l165 = l165 + 1) {
			fRec165[l165] = 0.0;
		}
		for (int l166 = 0; l166 < 3; l166 = l166 + 1) {
			fRec166[l166] = 0.0;
		}
		for (int l167 = 0; l167 < 3; l167 = l167 + 1) {
			fRec167[l167] = 0.0;
		}
		for (int l168 = 0; l168 < 3; l168 = l168 + 1) {
			fRec168[l168] = 0.0;
		}
		for (int l169 = 0; l169 < 3; l169 = l169 + 1) {
			fRec169[l169] = 0.0;
		}
		for (int l170 = 0; l170 < 3; l170 = l170 + 1) {
			fRec170[l170] = 0.0;
		}
		for (int l171 = 0; l171 < 3; l171 = l171 + 1) {
			fRec171[l171] = 0.0;
		}
		for (int l172 = 0; l172 < 3; l172 = l172 + 1) {
			fRec172[l172] = 0.0;
		}
		for (int l173 = 0; l173 < 3; l173 = l173 + 1) {
			fRec173[l173] = 0.0;
		}
		for (int l174 = 0; l174 < 3; l174 = l174 + 1) {
			fRec174[l174] = 0.0;
		}
		for (int l175 = 0; l175 < 3; l175 = l175 + 1) {
			fRec175[l175] = 0.0;
		}
		for (int l176 = 0; l176 < 3; l176 = l176 + 1) {
			fRec176[l176] = 0.0;
		}
		for (int l177 = 0; l177 < 3; l177 = l177 + 1) {
			fRec177[l177] = 0.0;
		}
		for (int l178 = 0; l178 < 3; l178 = l178 + 1) {
			fRec178[l178] = 0.0;
		}
		for (int l179 = 0; l179 < 3; l179 = l179 + 1) {
			fRec179[l179] = 0.0;
		}
		for (int l180 = 0; l180 < 3; l180 = l180 + 1) {
			fRec180[l180] = 0.0;
		}
		for (int l181 = 0; l181 < 3; l181 = l181 + 1) {
			fRec181[l181] = 0.0;
		}
		for (int l182 = 0; l182 < 3; l182 = l182 + 1) {
			fRec182[l182] = 0.0;
		}
		for (int l183 = 0; l183 < 3; l183 = l183 + 1) {
			fRec183[l183] = 0.0;
		}
		for (int l184 = 0; l184 < 3; l184 = l184 + 1) {
			fRec184[l184] = 0.0;
		}
		for (int l185 = 0; l185 < 3; l185 = l185 + 1) {
			fRec185[l185] = 0.0;
		}
		for (int l186 = 0; l186 < 3; l186 = l186 + 1) {
			fRec186[l186] = 0.0;
		}
		for (int l187 = 0; l187 < 3; l187 = l187 + 1) {
			fRec187[l187] = 0.0;
		}
		for (int l188 = 0; l188 < 3; l188 = l188 + 1) {
			fRec188[l188] = 0.0;
		}
		for (int l189 = 0; l189 < 3; l189 = l189 + 1) {
			fRec189[l189] = 0.0;
		}
		for (int l190 = 0; l190 < 3; l190 = l190 + 1) {
			fRec190[l190] = 0.0;
		}
		for (int l191 = 0; l191 < 3; l191 = l191 + 1) {
			fRec191[l191] = 0.0;
		}
		for (int l192 = 0; l192 < 3; l192 = l192 + 1) {
			fRec192[l192] = 0.0;
		}
		for (int l193 = 0; l193 < 3; l193 = l193 + 1) {
			fRec193[l193] = 0.0;
		}
		for (int l194 = 0; l194 < 3; l194 = l194 + 1) {
			fRec194[l194] = 0.0;
		}
		for (int l195 = 0; l195 < 3; l195 = l195 + 1) {
			fRec195[l195] = 0.0;
		}
		for (int l196 = 0; l196 < 3; l196 = l196 + 1) {
			fRec196[l196] = 0.0;
		}
		for (int l197 = 0; l197 < 3; l197 = l197 + 1) {
			fRec197[l197] = 0.0;
		}
		for (int l198 = 0; l198 < 3; l198 = l198 + 1) {
			fRec198[l198] = 0.0;
		}
		for (int l199 = 0; l199 < 3; l199 = l199 + 1) {
			fRec199[l199] = 0.0;
		}
		for (int l200 = 0; l200 < 3; l200 = l200 + 1) {
			fRec200[l200] = 0.0;
		}
		for (int l201 = 0; l201 < 3; l201 = l201 + 1) {
			fRec201[l201] = 0.0;
		}
		for (int l202 = 0; l202 < 3; l202 = l202 + 1) {
			fRec202[l202] = 0.0;
		}
		for (int l203 = 0; l203 < 3; l203 = l203 + 1) {
			fRec203[l203] = 0.0;
		}
		for (int l204 = 0; l204 < 3; l204 = l204 + 1) {
			fRec204[l204] = 0.0;
		}
		for (int l205 = 0; l205 < 3; l205 = l205 + 1) {
			fRec205[l205] = 0.0;
		}
		for (int l206 = 0; l206 < 3; l206 = l206 + 1) {
			fRec206[l206] = 0.0;
		}
		for (int l207 = 0; l207 < 3; l207 = l207 + 1) {
			fRec207[l207] = 0.0;
		}
		for (int l208 = 0; l208 < 3; l208 = l208 + 1) {
			fRec208[l208] = 0.0;
		}
		for (int l209 = 0; l209 < 3; l209 = l209 + 1) {
			fRec209[l209] = 0.0;
		}
		for (int l210 = 0; l210 < 3; l210 = l210 + 1) {
			fRec210[l210] = 0.0;
		}
		for (int l211 = 0; l211 < 3; l211 = l211 + 1) {
			fRec211[l211] = 0.0;
		}
		for (int l212 = 0; l212 < 3; l212 = l212 + 1) {
			fRec212[l212] = 0.0;
		}
		for (int l213 = 0; l213 < 3; l213 = l213 + 1) {
			fRec213[l213] = 0.0;
		}
		for (int l214 = 0; l214 < 3; l214 = l214 + 1) {
			fRec214[l214] = 0.0;
		}
		for (int l215 = 0; l215 < 3; l215 = l215 + 1) {
			fRec215[l215] = 0.0;
		}
		for (int l216 = 0; l216 < 3; l216 = l216 + 1) {
			fRec216[l216] = 0.0;
		}
		for (int l217 = 0; l217 < 3; l217 = l217 + 1) {
			fRec217[l217] = 0.0;
		}
		for (int l218 = 0; l218 < 3; l218 = l218 + 1) {
			fRec218[l218] = 0.0;
		}
		for (int l219 = 0; l219 < 3; l219 = l219 + 1) {
			fRec219[l219] = 0.0;
		}
		for (int l220 = 0; l220 < 3; l220 = l220 + 1) {
			fRec220[l220] = 0.0;
		}
		for (int l221 = 0; l221 < 3; l221 = l221 + 1) {
			fRec221[l221] = 0.0;
		}
		for (int l222 = 0; l222 < 3; l222 = l222 + 1) {
			fRec222[l222] = 0.0;
		}
		for (int l223 = 0; l223 < 3; l223 = l223 + 1) {
			fRec223[l223] = 0.0;
		}
		for (int l224 = 0; l224 < 3; l224 = l224 + 1) {
			fRec224[l224] = 0.0;
		}
		for (int l225 = 0; l225 < 3; l225 = l225 + 1) {
			fRec225[l225] = 0.0;
		}
		for (int l226 = 0; l226 < 3; l226 = l226 + 1) {
			fRec226[l226] = 0.0;
		}
		for (int l227 = 0; l227 < 3; l227 = l227 + 1) {
			fRec227[l227] = 0.0;
		}
		for (int l228 = 0; l228 < 3; l228 = l228 + 1) {
			fRec228[l228] = 0.0;
		}
		for (int l229 = 0; l229 < 3; l229 = l229 + 1) {
			fRec229[l229] = 0.0;
		}
		for (int l230 = 0; l230 < 3; l230 = l230 + 1) {
			fRec230[l230] = 0.0;
		}
		for (int l231 = 0; l231 < 3; l231 = l231 + 1) {
			fRec231[l231] = 0.0;
		}
		for (int l232 = 0; l232 < 3; l232 = l232 + 1) {
			fRec232[l232] = 0.0;
		}
		for (int l233 = 0; l233 < 3; l233 = l233 + 1) {
			fRec233[l233] = 0.0;
		}
		for (int l234 = 0; l234 < 3; l234 = l234 + 1) {
			fRec234[l234] = 0.0;
		}
		for (int l235 = 0; l235 < 3; l235 = l235 + 1) {
			fRec235[l235] = 0.0;
		}
		for (int l236 = 0; l236 < 3; l236 = l236 + 1) {
			fRec236[l236] = 0.0;
		}
		for (int l237 = 0; l237 < 3; l237 = l237 + 1) {
			fRec237[l237] = 0.0;
		}
		for (int l238 = 0; l238 < 3; l238 = l238 + 1) {
			fRec238[l238] = 0.0;
		}
		for (int l239 = 0; l239 < 3; l239 = l239 + 1) {
			fRec239[l239] = 0.0;
		}
		for (int l240 = 0; l240 < 3; l240 = l240 + 1) {
			fRec240[l240] = 0.0;
		}
		for (int l241 = 0; l241 < 3; l241 = l241 + 1) {
			fRec241[l241] = 0.0;
		}
		for (int l242 = 0; l242 < 3; l242 = l242 + 1) {
			fRec242[l242] = 0.0;
		}
		for (int l243 = 0; l243 < 3; l243 = l243 + 1) {
			fRec243[l243] = 0.0;
		}
		for (int l244 = 0; l244 < 3; l244 = l244 + 1) {
			fRec244[l244] = 0.0;
		}
		for (int l245 = 0; l245 < 3; l245 = l245 + 1) {
			fRec245[l245] = 0.0;
		}
		for (int l246 = 0; l246 < 3; l246 = l246 + 1) {
			fRec246[l246] = 0.0;
		}
		for (int l247 = 0; l247 < 3; l247 = l247 + 1) {
			fRec247[l247] = 0.0;
		}
		for (int l248 = 0; l248 < 3; l248 = l248 + 1) {
			fRec248[l248] = 0.0;
		}
		for (int l249 = 0; l249 < 3; l249 = l249 + 1) {
			fRec249[l249] = 0.0;
		}
		for (int l250 = 0; l250 < 3; l250 = l250 + 1) {
			fRec250[l250] = 0.0;
		}
		for (int l251 = 0; l251 < 3; l251 = l251 + 1) {
			fRec251[l251] = 0.0;
		}
		for (int l252 = 0; l252 < 3; l252 = l252 + 1) {
			fRec252[l252] = 0.0;
		}
		for (int l253 = 0; l253 < 3; l253 = l253 + 1) {
			fRec253[l253] = 0.0;
		}
		for (int l254 = 0; l254 < 3; l254 = l254 + 1) {
			fRec254[l254] = 0.0;
		}
		for (int l255 = 0; l255 < 3; l255 = l255 + 1) {
			fRec255[l255] = 0.0;
		}
		for (int l256 = 0; l256 < 3; l256 = l256 + 1) {
			fRec256[l256] = 0.0;
		}
		for (int l257 = 0; l257 < 3; l257 = l257 + 1) {
			fRec257[l257] = 0.0;
		}
		for (int l258 = 0; l258 < 3; l258 = l258 + 1) {
			fRec258[l258] = 0.0;
		}
		for (int l259 = 0; l259 < 3; l259 = l259 + 1) {
			fRec259[l259] = 0.0;
		}
		for (int l260 = 0; l260 < 3; l260 = l260 + 1) {
			fRec260[l260] = 0.0;
		}
		for (int l261 = 0; l261 < 3; l261 = l261 + 1) {
			fRec261[l261] = 0.0;
		}
		for (int l262 = 0; l262 < 3; l262 = l262 + 1) {
			fRec262[l262] = 0.0;
		}
		for (int l263 = 0; l263 < 3; l263 = l263 + 1) {
			fRec263[l263] = 0.0;
		}
		for (int l264 = 0; l264 < 3; l264 = l264 + 1) {
			fRec264[l264] = 0.0;
		}
		for (int l265 = 0; l265 < 3; l265 = l265 + 1) {
			fRec265[l265] = 0.0;
		}
		for (int l266 = 0; l266 < 3; l266 = l266 + 1) {
			fRec266[l266] = 0.0;
		}
		for (int l267 = 0; l267 < 3; l267 = l267 + 1) {
			fRec267[l267] = 0.0;
		}
		for (int l268 = 0; l268 < 3; l268 = l268 + 1) {
			fRec268[l268] = 0.0;
		}
		for (int l269 = 0; l269 < 3; l269 = l269 + 1) {
			fRec269[l269] = 0.0;
		}
		for (int l270 = 0; l270 < 3; l270 = l270 + 1) {
			fRec270[l270] = 0.0;
		}
		for (int l271 = 0; l271 < 3; l271 = l271 + 1) {
			fRec271[l271] = 0.0;
		}
		for (int l272 = 0; l272 < 3; l272 = l272 + 1) {
			fRec272[l272] = 0.0;
		}
		for (int l273 = 0; l273 < 3; l273 = l273 + 1) {
			fRec273[l273] = 0.0;
		}
		for (int l274 = 0; l274 < 3; l274 = l274 + 1) {
			fRec274[l274] = 0.0;
		}
		for (int l275 = 0; l275 < 3; l275 = l275 + 1) {
			fRec275[l275] = 0.0;
		}
		for (int l276 = 0; l276 < 3; l276 = l276 + 1) {
			fRec276[l276] = 0.0;
		}
		for (int l277 = 0; l277 < 3; l277 = l277 + 1) {
			fRec277[l277] = 0.0;
		}
		for (int l278 = 0; l278 < 3; l278 = l278 + 1) {
			fRec278[l278] = 0.0;
		}
		for (int l279 = 0; l279 < 3; l279 = l279 + 1) {
			fRec279[l279] = 0.0;
		}
		for (int l280 = 0; l280 < 3; l280 = l280 + 1) {
			fRec280[l280] = 0.0;
		}
		for (int l281 = 0; l281 < 3; l281 = l281 + 1) {
			fRec281[l281] = 0.0;
		}
		for (int l282 = 0; l282 < 3; l282 = l282 + 1) {
			fRec282[l282] = 0.0;
		}
		for (int l283 = 0; l283 < 3; l283 = l283 + 1) {
			fRec283[l283] = 0.0;
		}
		for (int l284 = 0; l284 < 3; l284 = l284 + 1) {
			fRec284[l284] = 0.0;
		}
		for (int l285 = 0; l285 < 3; l285 = l285 + 1) {
			fRec285[l285] = 0.0;
		}
		for (int l286 = 0; l286 < 3; l286 = l286 + 1) {
			fRec286[l286] = 0.0;
		}
		for (int l287 = 0; l287 < 3; l287 = l287 + 1) {
			fRec287[l287] = 0.0;
		}
		for (int l288 = 0; l288 < 3; l288 = l288 + 1) {
			fRec288[l288] = 0.0;
		}
		for (int l289 = 0; l289 < 3; l289 = l289 + 1) {
			fRec289[l289] = 0.0;
		}
		for (int l290 = 0; l290 < 3; l290 = l290 + 1) {
			fRec290[l290] = 0.0;
		}
		for (int l291 = 0; l291 < 3; l291 = l291 + 1) {
			fRec291[l291] = 0.0;
		}
		for (int l292 = 0; l292 < 3; l292 = l292 + 1) {
			fRec292[l292] = 0.0;
		}
		for (int l293 = 0; l293 < 3; l293 = l293 + 1) {
			fRec293[l293] = 0.0;
		}
		for (int l294 = 0; l294 < 3; l294 = l294 + 1) {
			fRec294[l294] = 0.0;
		}
		for (int l295 = 0; l295 < 3; l295 = l295 + 1) {
			fRec295[l295] = 0.0;
		}
		for (int l296 = 0; l296 < 3; l296 = l296 + 1) {
			fRec296[l296] = 0.0;
		}
		for (int l297 = 0; l297 < 3; l297 = l297 + 1) {
			fRec297[l297] = 0.0;
		}
		for (int l298 = 0; l298 < 3; l298 = l298 + 1) {
			fRec298[l298] = 0.0;
		}
		for (int l299 = 0; l299 < 3; l299 = l299 + 1) {
			fRec299[l299] = 0.0;
		}
		for (int l300 = 0; l300 < 3; l300 = l300 + 1) {
			fRec300[l300] = 0.0;
		}
		for (int l301 = 0; l301 < 3; l301 = l301 + 1) {
			fRec301[l301] = 0.0;
		}
		for (int l302 = 0; l302 < 3; l302 = l302 + 1) {
			fRec302[l302] = 0.0;
		}
		for (int l303 = 0; l303 < 3; l303 = l303 + 1) {
			fRec303[l303] = 0.0;
		}
		for (int l304 = 0; l304 < 3; l304 = l304 + 1) {
			fRec304[l304] = 0.0;
		}
		for (int l305 = 0; l305 < 3; l305 = l305 + 1) {
			fRec305[l305] = 0.0;
		}
		for (int l306 = 0; l306 < 3; l306 = l306 + 1) {
			fRec306[l306] = 0.0;
		}
		for (int l307 = 0; l307 < 3; l307 = l307 + 1) {
			fRec307[l307] = 0.0;
		}
		for (int l308 = 0; l308 < 3; l308 = l308 + 1) {
			fRec308[l308] = 0.0;
		}
		for (int l309 = 0; l309 < 3; l309 = l309 + 1) {
			fRec309[l309] = 0.0;
		}
		for (int l310 = 0; l310 < 3; l310 = l310 + 1) {
			fRec310[l310] = 0.0;
		}
		for (int l311 = 0; l311 < 3; l311 = l311 + 1) {
			fRec311[l311] = 0.0;
		}
		for (int l312 = 0; l312 < 3; l312 = l312 + 1) {
			fRec312[l312] = 0.0;
		}
		for (int l313 = 0; l313 < 3; l313 = l313 + 1) {
			fRec313[l313] = 0.0;
		}
		for (int l314 = 0; l314 < 3; l314 = l314 + 1) {
			fRec314[l314] = 0.0;
		}
		for (int l315 = 0; l315 < 3; l315 = l315 + 1) {
			fRec315[l315] = 0.0;
		}
		for (int l316 = 0; l316 < 3; l316 = l316 + 1) {
			fRec316[l316] = 0.0;
		}
		for (int l317 = 0; l317 < 3; l317 = l317 + 1) {
			fRec317[l317] = 0.0;
		}
		for (int l318 = 0; l318 < 3; l318 = l318 + 1) {
			fRec318[l318] = 0.0;
		}
		for (int l319 = 0; l319 < 3; l319 = l319 + 1) {
			fRec319[l319] = 0.0;
		}
		for (int l320 = 0; l320 < 3; l320 = l320 + 1) {
			fRec320[l320] = 0.0;
		}
		for (int l321 = 0; l321 < 3; l321 = l321 + 1) {
			fRec321[l321] = 0.0;
		}
		for (int l322 = 0; l322 < 3; l322 = l322 + 1) {
			fRec322[l322] = 0.0;
		}
		for (int l323 = 0; l323 < 3; l323 = l323 + 1) {
			fRec323[l323] = 0.0;
		}
		for (int l324 = 0; l324 < 3; l324 = l324 + 1) {
			fRec324[l324] = 0.0;
		}
		for (int l325 = 0; l325 < 3; l325 = l325 + 1) {
			fRec325[l325] = 0.0;
		}
		for (int l326 = 0; l326 < 3; l326 = l326 + 1) {
			fRec326[l326] = 0.0;
		}
		for (int l327 = 0; l327 < 3; l327 = l327 + 1) {
			fRec327[l327] = 0.0;
		}
		for (int l328 = 0; l328 < 3; l328 = l328 + 1) {
			fRec328[l328] = 0.0;
		}
		for (int l329 = 0; l329 < 3; l329 = l329 + 1) {
			fRec329[l329] = 0.0;
		}
		for (int l330 = 0; l330 < 3; l330 = l330 + 1) {
			fRec330[l330] = 0.0;
		}
		for (int l331 = 0; l331 < 3; l331 = l331 + 1) {
			fRec331[l331] = 0.0;
		}
		for (int l332 = 0; l332 < 3; l332 = l332 + 1) {
			fRec332[l332] = 0.0;
		}
		for (int l333 = 0; l333 < 3; l333 = l333 + 1) {
			fRec333[l333] = 0.0;
		}
		for (int l334 = 0; l334 < 3; l334 = l334 + 1) {
			fRec334[l334] = 0.0;
		}
		for (int l335 = 0; l335 < 3; l335 = l335 + 1) {
			fRec335[l335] = 0.0;
		}
		for (int l336 = 0; l336 < 3; l336 = l336 + 1) {
			fRec336[l336] = 0.0;
		}
		for (int l337 = 0; l337 < 3; l337 = l337 + 1) {
			fRec337[l337] = 0.0;
		}
		for (int l338 = 0; l338 < 3; l338 = l338 + 1) {
			fRec338[l338] = 0.0;
		}
		for (int l339 = 0; l339 < 3; l339 = l339 + 1) {
			fRec339[l339] = 0.0;
		}
		for (int l340 = 0; l340 < 3; l340 = l340 + 1) {
			fRec340[l340] = 0.0;
		}
		for (int l341 = 0; l341 < 3; l341 = l341 + 1) {
			fRec341[l341] = 0.0;
		}
		for (int l342 = 0; l342 < 3; l342 = l342 + 1) {
			fRec342[l342] = 0.0;
		}
		for (int l343 = 0; l343 < 3; l343 = l343 + 1) {
			fRec343[l343] = 0.0;
		}
		for (int l344 = 0; l344 < 3; l344 = l344 + 1) {
			fRec344[l344] = 0.0;
		}
		for (int l345 = 0; l345 < 3; l345 = l345 + 1) {
			fRec345[l345] = 0.0;
		}
		for (int l346 = 0; l346 < 3; l346 = l346 + 1) {
			fRec346[l346] = 0.0;
		}
		for (int l347 = 0; l347 < 3; l347 = l347 + 1) {
			fRec347[l347] = 0.0;
		}
		for (int l348 = 0; l348 < 3; l348 = l348 + 1) {
			fRec348[l348] = 0.0;
		}
		for (int l349 = 0; l349 < 3; l349 = l349 + 1) {
			fRec349[l349] = 0.0;
		}
		for (int l350 = 0; l350 < 3; l350 = l350 + 1) {
			fRec350[l350] = 0.0;
		}
		for (int l351 = 0; l351 < 3; l351 = l351 + 1) {
			fRec351[l351] = 0.0;
		}
		for (int l352 = 0; l352 < 3; l352 = l352 + 1) {
			fRec352[l352] = 0.0;
		}
		for (int l353 = 0; l353 < 3; l353 = l353 + 1) {
			fRec353[l353] = 0.0;
		}
		for (int l354 = 0; l354 < 3; l354 = l354 + 1) {
			fRec354[l354] = 0.0;
		}
		for (int l355 = 0; l355 < 3; l355 = l355 + 1) {
			fRec355[l355] = 0.0;
		}
		for (int l356 = 0; l356 < 3; l356 = l356 + 1) {
			fRec356[l356] = 0.0;
		}
		for (int l357 = 0; l357 < 3; l357 = l357 + 1) {
			fRec357[l357] = 0.0;
		}
		for (int l358 = 0; l358 < 3; l358 = l358 + 1) {
			fRec358[l358] = 0.0;
		}
		for (int l359 = 0; l359 < 3; l359 = l359 + 1) {
			fRec359[l359] = 0.0;
		}
		for (int l360 = 0; l360 < 3; l360 = l360 + 1) {
			fRec360[l360] = 0.0;
		}
		for (int l361 = 0; l361 < 3; l361 = l361 + 1) {
			fRec361[l361] = 0.0;
		}
		for (int l362 = 0; l362 < 3; l362 = l362 + 1) {
			fRec362[l362] = 0.0;
		}
		for (int l363 = 0; l363 < 3; l363 = l363 + 1) {
			fRec363[l363] = 0.0;
		}
		for (int l364 = 0; l364 < 3; l364 = l364 + 1) {
			fRec364[l364] = 0.0;
		}
		for (int l365 = 0; l365 < 3; l365 = l365 + 1) {
			fRec365[l365] = 0.0;
		}
		for (int l366 = 0; l366 < 3; l366 = l366 + 1) {
			fRec366[l366] = 0.0;
		}
		for (int l367 = 0; l367 < 3; l367 = l367 + 1) {
			fRec367[l367] = 0.0;
		}
		for (int l368 = 0; l368 < 3; l368 = l368 + 1) {
			fRec368[l368] = 0.0;
		}
		for (int l369 = 0; l369 < 3; l369 = l369 + 1) {
			fRec369[l369] = 0.0;
		}
		for (int l370 = 0; l370 < 3; l370 = l370 + 1) {
			fRec370[l370] = 0.0;
		}
		for (int l371 = 0; l371 < 3; l371 = l371 + 1) {
			fRec371[l371] = 0.0;
		}
		for (int l372 = 0; l372 < 3; l372 = l372 + 1) {
			fRec372[l372] = 0.0;
		}
		for (int l373 = 0; l373 < 3; l373 = l373 + 1) {
			fRec373[l373] = 0.0;
		}
		for (int l374 = 0; l374 < 3; l374 = l374 + 1) {
			fRec374[l374] = 0.0;
		}
		for (int l375 = 0; l375 < 3; l375 = l375 + 1) {
			fRec375[l375] = 0.0;
		}
		for (int l376 = 0; l376 < 3; l376 = l376 + 1) {
			fRec376[l376] = 0.0;
		}
		for (int l377 = 0; l377 < 3; l377 = l377 + 1) {
			fRec377[l377] = 0.0;
		}
		for (int l378 = 0; l378 < 3; l378 = l378 + 1) {
			fRec378[l378] = 0.0;
		}
		for (int l379 = 0; l379 < 3; l379 = l379 + 1) {
			fRec379[l379] = 0.0;
		}
		for (int l380 = 0; l380 < 3; l380 = l380 + 1) {
			fRec380[l380] = 0.0;
		}
		for (int l381 = 0; l381 < 3; l381 = l381 + 1) {
			fRec381[l381] = 0.0;
		}
		for (int l382 = 0; l382 < 3; l382 = l382 + 1) {
			fRec382[l382] = 0.0;
		}
		for (int l383 = 0; l383 < 3; l383 = l383 + 1) {
			fRec383[l383] = 0.0;
		}
		for (int l384 = 0; l384 < 3; l384 = l384 + 1) {
			fRec384[l384] = 0.0;
		}
		for (int l385 = 0; l385 < 3; l385 = l385 + 1) {
			fRec385[l385] = 0.0;
		}
		for (int l386 = 0; l386 < 3; l386 = l386 + 1) {
			fRec386[l386] = 0.0;
		}
		for (int l387 = 0; l387 < 3; l387 = l387 + 1) {
			fRec387[l387] = 0.0;
		}
		for (int l388 = 0; l388 < 3; l388 = l388 + 1) {
			fRec388[l388] = 0.0;
		}
		for (int l389 = 0; l389 < 3; l389 = l389 + 1) {
			fRec389[l389] = 0.0;
		}
		for (int l390 = 0; l390 < 3; l390 = l390 + 1) {
			fRec390[l390] = 0.0;
		}
		for (int l391 = 0; l391 < 3; l391 = l391 + 1) {
			fRec391[l391] = 0.0;
		}
		for (int l392 = 0; l392 < 3; l392 = l392 + 1) {
			fRec392[l392] = 0.0;
		}
		for (int l393 = 0; l393 < 3; l393 = l393 + 1) {
			fRec393[l393] = 0.0;
		}
		for (int l394 = 0; l394 < 3; l394 = l394 + 1) {
			fRec394[l394] = 0.0;
		}
		for (int l395 = 0; l395 < 3; l395 = l395 + 1) {
			fRec395[l395] = 0.0;
		}
		for (int l396 = 0; l396 < 3; l396 = l396 + 1) {
			fRec396[l396] = 0.0;
		}
		for (int l397 = 0; l397 < 3; l397 = l397 + 1) {
			fRec397[l397] = 0.0;
		}
		for (int l398 = 0; l398 < 3; l398 = l398 + 1) {
			fRec398[l398] = 0.0;
		}
		for (int l399 = 0; l399 < 3; l399 = l399 + 1) {
			fRec399[l399] = 0.0;
		}
		for (int l400 = 0; l400 < 3; l400 = l400 + 1) {
			fRec400[l400] = 0.0;
		}
		for (int l401 = 0; l401 < 3; l401 = l401 + 1) {
			fRec401[l401] = 0.0;
		}
		for (int l402 = 0; l402 < 3; l402 = l402 + 1) {
			fRec402[l402] = 0.0;
		}
		for (int l403 = 0; l403 < 3; l403 = l403 + 1) {
			fRec403[l403] = 0.0;
		}
		for (int l404 = 0; l404 < 3; l404 = l404 + 1) {
			fRec404[l404] = 0.0;
		}
		for (int l405 = 0; l405 < 3; l405 = l405 + 1) {
			fRec405[l405] = 0.0;
		}
		for (int l406 = 0; l406 < 3; l406 = l406 + 1) {
			fRec406[l406] = 0.0;
		}
		for (int l407 = 0; l407 < 3; l407 = l407 + 1) {
			fRec407[l407] = 0.0;
		}
		for (int l408 = 0; l408 < 3; l408 = l408 + 1) {
			fRec408[l408] = 0.0;
		}
		for (int l409 = 0; l409 < 3; l409 = l409 + 1) {
			fRec409[l409] = 0.0;
		}
		for (int l410 = 0; l410 < 3; l410 = l410 + 1) {
			fRec410[l410] = 0.0;
		}
		for (int l411 = 0; l411 < 3; l411 = l411 + 1) {
			fRec411[l411] = 0.0;
		}
		for (int l412 = 0; l412 < 3; l412 = l412 + 1) {
			fRec412[l412] = 0.0;
		}
		for (int l413 = 0; l413 < 3; l413 = l413 + 1) {
			fRec413[l413] = 0.0;
		}
		for (int l414 = 0; l414 < 3; l414 = l414 + 1) {
			fRec414[l414] = 0.0;
		}
		for (int l415 = 0; l415 < 3; l415 = l415 + 1) {
			fRec415[l415] = 0.0;
		}
		for (int l416 = 0; l416 < 3; l416 = l416 + 1) {
			fRec416[l416] = 0.0;
		}
		for (int l417 = 0; l417 < 3; l417 = l417 + 1) {
			fRec417[l417] = 0.0;
		}
		for (int l418 = 0; l418 < 3; l418 = l418 + 1) {
			fRec418[l418] = 0.0;
		}
		for (int l419 = 0; l419 < 3; l419 = l419 + 1) {
			fRec419[l419] = 0.0;
		}
		for (int l420 = 0; l420 < 3; l420 = l420 + 1) {
			fRec420[l420] = 0.0;
		}
		for (int l421 = 0; l421 < 3; l421 = l421 + 1) {
			fRec421[l421] = 0.0;
		}
		for (int l422 = 0; l422 < 3; l422 = l422 + 1) {
			fRec422[l422] = 0.0;
		}
		for (int l423 = 0; l423 < 3; l423 = l423 + 1) {
			fRec423[l423] = 0.0;
		}
		for (int l424 = 0; l424 < 3; l424 = l424 + 1) {
			fRec424[l424] = 0.0;
		}
		for (int l425 = 0; l425 < 3; l425 = l425 + 1) {
			fRec425[l425] = 0.0;
		}
		for (int l426 = 0; l426 < 3; l426 = l426 + 1) {
			fRec426[l426] = 0.0;
		}
		for (int l427 = 0; l427 < 3; l427 = l427 + 1) {
			fRec427[l427] = 0.0;
		}
		for (int l428 = 0; l428 < 3; l428 = l428 + 1) {
			fRec428[l428] = 0.0;
		}
		for (int l429 = 0; l429 < 3; l429 = l429 + 1) {
			fRec429[l429] = 0.0;
		}
		for (int l430 = 0; l430 < 3; l430 = l430 + 1) {
			fRec430[l430] = 0.0;
		}
		for (int l431 = 0; l431 < 3; l431 = l431 + 1) {
			fRec431[l431] = 0.0;
		}
		for (int l432 = 0; l432 < 3; l432 = l432 + 1) {
			fRec432[l432] = 0.0;
		}
		for (int l433 = 0; l433 < 3; l433 = l433 + 1) {
			fRec433[l433] = 0.0;
		}
		for (int l434 = 0; l434 < 3; l434 = l434 + 1) {
			fRec434[l434] = 0.0;
		}
		for (int l435 = 0; l435 < 3; l435 = l435 + 1) {
			fRec435[l435] = 0.0;
		}
		for (int l436 = 0; l436 < 3; l436 = l436 + 1) {
			fRec436[l436] = 0.0;
		}
		for (int l437 = 0; l437 < 3; l437 = l437 + 1) {
			fRec437[l437] = 0.0;
		}
		for (int l438 = 0; l438 < 3; l438 = l438 + 1) {
			fRec438[l438] = 0.0;
		}
		for (int l439 = 0; l439 < 3; l439 = l439 + 1) {
			fRec439[l439] = 0.0;
		}
		for (int l440 = 0; l440 < 3; l440 = l440 + 1) {
			fRec440[l440] = 0.0;
		}
		for (int l441 = 0; l441 < 3; l441 = l441 + 1) {
			fRec441[l441] = 0.0;
		}
		for (int l442 = 0; l442 < 3; l442 = l442 + 1) {
			fRec442[l442] = 0.0;
		}
		for (int l443 = 0; l443 < 3; l443 = l443 + 1) {
			fRec443[l443] = 0.0;
		}
		for (int l444 = 0; l444 < 3; l444 = l444 + 1) {
			fRec444[l444] = 0.0;
		}
		for (int l445 = 0; l445 < 3; l445 = l445 + 1) {
			fRec445[l445] = 0.0;
		}
		for (int l446 = 0; l446 < 3; l446 = l446 + 1) {
			fRec446[l446] = 0.0;
		}
		for (int l447 = 0; l447 < 3; l447 = l447 + 1) {
			fRec447[l447] = 0.0;
		}
		for (int l448 = 0; l448 < 3; l448 = l448 + 1) {
			fRec448[l448] = 0.0;
		}
		for (int l449 = 0; l449 < 3; l449 = l449 + 1) {
			fRec449[l449] = 0.0;
		}
		for (int l450 = 0; l450 < 3; l450 = l450 + 1) {
			fRec450[l450] = 0.0;
		}
		for (int l451 = 0; l451 < 3; l451 = l451 + 1) {
			fRec451[l451] = 0.0;
		}
		for (int l452 = 0; l452 < 3; l452 = l452 + 1) {
			fRec452[l452] = 0.0;
		}
		for (int l453 = 0; l453 < 3; l453 = l453 + 1) {
			fRec453[l453] = 0.0;
		}
		for (int l454 = 0; l454 < 3; l454 = l454 + 1) {
			fRec454[l454] = 0.0;
		}
		for (int l455 = 0; l455 < 3; l455 = l455 + 1) {
			fRec455[l455] = 0.0;
		}
		for (int l456 = 0; l456 < 3; l456 = l456 + 1) {
			fRec456[l456] = 0.0;
		}
		for (int l457 = 0; l457 < 3; l457 = l457 + 1) {
			fRec457[l457] = 0.0;
		}
		for (int l458 = 0; l458 < 3; l458 = l458 + 1) {
			fRec458[l458] = 0.0;
		}
		for (int l459 = 0; l459 < 3; l459 = l459 + 1) {
			fRec459[l459] = 0.0;
		}
		for (int l460 = 0; l460 < 3; l460 = l460 + 1) {
			fRec460[l460] = 0.0;
		}
		for (int l461 = 0; l461 < 3; l461 = l461 + 1) {
			fRec461[l461] = 0.0;
		}
		for (int l462 = 0; l462 < 3; l462 = l462 + 1) {
			fRec462[l462] = 0.0;
		}
		for (int l463 = 0; l463 < 3; l463 = l463 + 1) {
			fRec463[l463] = 0.0;
		}
		for (int l464 = 0; l464 < 3; l464 = l464 + 1) {
			fRec464[l464] = 0.0;
		}
		for (int l465 = 0; l465 < 3; l465 = l465 + 1) {
			fRec465[l465] = 0.0;
		}
		for (int l466 = 0; l466 < 3; l466 = l466 + 1) {
			fRec466[l466] = 0.0;
		}
		for (int l467 = 0; l467 < 3; l467 = l467 + 1) {
			fRec467[l467] = 0.0;
		}
		for (int l468 = 0; l468 < 3; l468 = l468 + 1) {
			fRec468[l468] = 0.0;
		}
		for (int l469 = 0; l469 < 3; l469 = l469 + 1) {
			fRec469[l469] = 0.0;
		}
		for (int l470 = 0; l470 < 3; l470 = l470 + 1) {
			fRec470[l470] = 0.0;
		}
		for (int l471 = 0; l471 < 3; l471 = l471 + 1) {
			fRec471[l471] = 0.0;
		}
		for (int l472 = 0; l472 < 3; l472 = l472 + 1) {
			fRec472[l472] = 0.0;
		}
		for (int l473 = 0; l473 < 3; l473 = l473 + 1) {
			fRec473[l473] = 0.0;
		}
		for (int l474 = 0; l474 < 3; l474 = l474 + 1) {
			fRec474[l474] = 0.0;
		}
		for (int l475 = 0; l475 < 3; l475 = l475 + 1) {
			fRec475[l475] = 0.0;
		}
		for (int l476 = 0; l476 < 3; l476 = l476 + 1) {
			fRec476[l476] = 0.0;
		}
		for (int l477 = 0; l477 < 3; l477 = l477 + 1) {
			fRec477[l477] = 0.0;
		}
		for (int l478 = 0; l478 < 3; l478 = l478 + 1) {
			fRec478[l478] = 0.0;
		}
		for (int l479 = 0; l479 < 3; l479 = l479 + 1) {
			fRec479[l479] = 0.0;
		}
		for (int l480 = 0; l480 < 3; l480 = l480 + 1) {
			fRec480[l480] = 0.0;
		}
		for (int l481 = 0; l481 < 3; l481 = l481 + 1) {
			fRec481[l481] = 0.0;
		}
		for (int l482 = 0; l482 < 3; l482 = l482 + 1) {
			fRec482[l482] = 0.0;
		}
		for (int l483 = 0; l483 < 3; l483 = l483 + 1) {
			fRec483[l483] = 0.0;
		}
		for (int l484 = 0; l484 < 3; l484 = l484 + 1) {
			fRec484[l484] = 0.0;
		}
		for (int l485 = 0; l485 < 3; l485 = l485 + 1) {
			fRec485[l485] = 0.0;
		}
		for (int l486 = 0; l486 < 3; l486 = l486 + 1) {
			fRec486[l486] = 0.0;
		}
		for (int l487 = 0; l487 < 3; l487 = l487 + 1) {
			fRec487[l487] = 0.0;
		}
		for (int l488 = 0; l488 < 3; l488 = l488 + 1) {
			fRec488[l488] = 0.0;
		}
		for (int l489 = 0; l489 < 3; l489 = l489 + 1) {
			fRec489[l489] = 0.0;
		}
		for (int l490 = 0; l490 < 3; l490 = l490 + 1) {
			fRec490[l490] = 0.0;
		}
		for (int l491 = 0; l491 < 3; l491 = l491 + 1) {
			fRec491[l491] = 0.0;
		}
		for (int l492 = 0; l492 < 3; l492 = l492 + 1) {
			fRec492[l492] = 0.0;
		}
		for (int l493 = 0; l493 < 3; l493 = l493 + 1) {
			fRec493[l493] = 0.0;
		}
		for (int l494 = 0; l494 < 3; l494 = l494 + 1) {
			fRec494[l494] = 0.0;
		}
		for (int l495 = 0; l495 < 3; l495 = l495 + 1) {
			fRec495[l495] = 0.0;
		}
		for (int l496 = 0; l496 < 3; l496 = l496 + 1) {
			fRec496[l496] = 0.0;
		}
		for (int l497 = 0; l497 < 3; l497 = l497 + 1) {
			fRec497[l497] = 0.0;
		}
		for (int l498 = 0; l498 < 3; l498 = l498 + 1) {
			fRec498[l498] = 0.0;
		}
		for (int l499 = 0; l499 < 3; l499 = l499 + 1) {
			fRec499[l499] = 0.0;
		}
		for (int l500 = 0; l500 < 3; l500 = l500 + 1) {
			fRec500[l500] = 0.0;
		}
		for (int l501 = 0; l501 < 3; l501 = l501 + 1) {
			fRec501[l501] = 0.0;
		}
		for (int l502 = 0; l502 < 3; l502 = l502 + 1) {
			fRec502[l502] = 0.0;
		}
		for (int l503 = 0; l503 < 3; l503 = l503 + 1) {
			fRec503[l503] = 0.0;
		}
		for (int l504 = 0; l504 < 3; l504 = l504 + 1) {
			fRec504[l504] = 0.0;
		}
		for (int l505 = 0; l505 < 3; l505 = l505 + 1) {
			fRec505[l505] = 0.0;
		}
		for (int l506 = 0; l506 < 3; l506 = l506 + 1) {
			fRec506[l506] = 0.0;
		}
		for (int l507 = 0; l507 < 3; l507 = l507 + 1) {
			fRec507[l507] = 0.0;
		}
		for (int l508 = 0; l508 < 3; l508 = l508 + 1) {
			fRec508[l508] = 0.0;
		}
		for (int l509 = 0; l509 < 3; l509 = l509 + 1) {
			fRec509[l509] = 0.0;
		}
		for (int l510 = 0; l510 < 3; l510 = l510 + 1) {
			fRec510[l510] = 0.0;
		}
		for (int l511 = 0; l511 < 3; l511 = l511 + 1) {
			fRec511[l511] = 0.0;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("moodygirl 0.14");
		ui_interface->openVerticalBox("0");
		ui_interface->declare(&fVslider62, "-1", "");
		ui_interface->declare(&fVslider62, "style", "knob");
		ui_interface->declare(&fVslider62, "tooltip", "number of active modes in group");
		ui_interface->addVerticalSlider("modes", &fVslider62, FAUSTFLOAT(32.0), FAUSTFLOAT(0.0), FAUSTFLOAT(32.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider60, "0", "");
		ui_interface->declare(&fVslider60, "style", "knob");
		ui_interface->declare(&fVslider60, "tooltip", "frequency of first mode in group");
		ui_interface->addVerticalSlider("base freq", &fVslider60, FAUSTFLOAT(2.2e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(1.5e+04), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider59, "1", "");
		ui_interface->declare(&fVslider59, "style", "knob");
		ui_interface->declare(&fVslider59, "tooltip", "multiplier for each mode's freq");
		ui_interface->addVerticalSlider("freq mult", &fVslider59, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider58, "2", "");
		ui_interface->declare(&fVslider58, "style", "knob");
		ui_interface->declare(&fVslider58, "tooltip", "spacing between modes in hz (added to mult)");
		ui_interface->addVerticalSlider("freq shift", &fVslider58, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider57, "3", "");
		ui_interface->declare(&fVslider57, "style", "knob");
		ui_interface->declare(&fVslider57, "tooltip", "duration of resonance for modes (seconds)");
		ui_interface->addVerticalSlider("base dur", &fVslider57, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider56, "5", "");
		ui_interface->declare(&fVslider56, "style", "knob");
		ui_interface->declare(&fVslider56, "tooltip", "divider for each mode's duration (2 to disable)");
		ui_interface->addVerticalSlider("dur div", &fVslider56, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider63, "6", "");
		ui_interface->declare(&fVslider63, "style", "knob");
		ui_interface->declare(&fVslider63, "tooltip", "amplitude of modes");
		ui_interface->addVerticalSlider("base amp", &fVslider63, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider61, "7", "");
		ui_interface->declare(&fVslider61, "style", "knob");
		ui_interface->declare(&fVslider61, "tooltip", "divider for each mode's amp (2 to disable)");
		ui_interface->addVerticalSlider("amp div", &fVslider61, FAUSTFLOAT(1.0), FAUSTFLOAT(0.01), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("1");
		ui_interface->declare(&fVslider54, "-1", "");
		ui_interface->declare(&fVslider54, "style", "knob");
		ui_interface->declare(&fVslider54, "tooltip", "number of active modes in group");
		ui_interface->addVerticalSlider("modes", &fVslider54, FAUSTFLOAT(32.0), FAUSTFLOAT(0.0), FAUSTFLOAT(32.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider52, "0", "");
		ui_interface->declare(&fVslider52, "style", "knob");
		ui_interface->declare(&fVslider52, "tooltip", "frequency of first mode in group");
		ui_interface->addVerticalSlider("base freq", &fVslider52, FAUSTFLOAT(2.2e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(1.5e+04), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider51, "1", "");
		ui_interface->declare(&fVslider51, "style", "knob");
		ui_interface->declare(&fVslider51, "tooltip", "multiplier for each mode's freq");
		ui_interface->addVerticalSlider("freq mult", &fVslider51, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider50, "2", "");
		ui_interface->declare(&fVslider50, "style", "knob");
		ui_interface->declare(&fVslider50, "tooltip", "spacing between modes in hz (added to mult)");
		ui_interface->addVerticalSlider("freq shift", &fVslider50, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider49, "3", "");
		ui_interface->declare(&fVslider49, "style", "knob");
		ui_interface->declare(&fVslider49, "tooltip", "duration of resonance for modes (seconds)");
		ui_interface->addVerticalSlider("base dur", &fVslider49, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider48, "5", "");
		ui_interface->declare(&fVslider48, "style", "knob");
		ui_interface->declare(&fVslider48, "tooltip", "divider for each mode's duration (2 to disable)");
		ui_interface->addVerticalSlider("dur div", &fVslider48, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider55, "6", "");
		ui_interface->declare(&fVslider55, "style", "knob");
		ui_interface->declare(&fVslider55, "tooltip", "amplitude of modes");
		ui_interface->addVerticalSlider("base amp", &fVslider55, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider53, "7", "");
		ui_interface->declare(&fVslider53, "style", "knob");
		ui_interface->declare(&fVslider53, "tooltip", "divider for each mode's amp (2 to disable)");
		ui_interface->addVerticalSlider("amp div", &fVslider53, FAUSTFLOAT(1.0), FAUSTFLOAT(0.01), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("2");
		ui_interface->declare(&fVslider46, "-1", "");
		ui_interface->declare(&fVslider46, "style", "knob");
		ui_interface->declare(&fVslider46, "tooltip", "number of active modes in group");
		ui_interface->addVerticalSlider("modes", &fVslider46, FAUSTFLOAT(32.0), FAUSTFLOAT(0.0), FAUSTFLOAT(32.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider44, "0", "");
		ui_interface->declare(&fVslider44, "style", "knob");
		ui_interface->declare(&fVslider44, "tooltip", "frequency of first mode in group");
		ui_interface->addVerticalSlider("base freq", &fVslider44, FAUSTFLOAT(2.2e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(1.5e+04), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider43, "1", "");
		ui_interface->declare(&fVslider43, "style", "knob");
		ui_interface->declare(&fVslider43, "tooltip", "multiplier for each mode's freq");
		ui_interface->addVerticalSlider("freq mult", &fVslider43, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider42, "2", "");
		ui_interface->declare(&fVslider42, "style", "knob");
		ui_interface->declare(&fVslider42, "tooltip", "spacing between modes in hz (added to mult)");
		ui_interface->addVerticalSlider("freq shift", &fVslider42, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider41, "3", "");
		ui_interface->declare(&fVslider41, "style", "knob");
		ui_interface->declare(&fVslider41, "tooltip", "duration of resonance for modes (seconds)");
		ui_interface->addVerticalSlider("base dur", &fVslider41, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider40, "5", "");
		ui_interface->declare(&fVslider40, "style", "knob");
		ui_interface->declare(&fVslider40, "tooltip", "divider for each mode's duration (2 to disable)");
		ui_interface->addVerticalSlider("dur div", &fVslider40, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider47, "6", "");
		ui_interface->declare(&fVslider47, "style", "knob");
		ui_interface->declare(&fVslider47, "tooltip", "amplitude of modes");
		ui_interface->addVerticalSlider("base amp", &fVslider47, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider45, "7", "");
		ui_interface->declare(&fVslider45, "style", "knob");
		ui_interface->declare(&fVslider45, "tooltip", "divider for each mode's amp (2 to disable)");
		ui_interface->addVerticalSlider("amp div", &fVslider45, FAUSTFLOAT(1.0), FAUSTFLOAT(0.01), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("3");
		ui_interface->declare(&fVslider38, "-1", "");
		ui_interface->declare(&fVslider38, "style", "knob");
		ui_interface->declare(&fVslider38, "tooltip", "number of active modes in group");
		ui_interface->addVerticalSlider("modes", &fVslider38, FAUSTFLOAT(32.0), FAUSTFLOAT(0.0), FAUSTFLOAT(32.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider36, "0", "");
		ui_interface->declare(&fVslider36, "style", "knob");
		ui_interface->declare(&fVslider36, "tooltip", "frequency of first mode in group");
		ui_interface->addVerticalSlider("base freq", &fVslider36, FAUSTFLOAT(2.2e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(1.5e+04), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider35, "1", "");
		ui_interface->declare(&fVslider35, "style", "knob");
		ui_interface->declare(&fVslider35, "tooltip", "multiplier for each mode's freq");
		ui_interface->addVerticalSlider("freq mult", &fVslider35, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider34, "2", "");
		ui_interface->declare(&fVslider34, "style", "knob");
		ui_interface->declare(&fVslider34, "tooltip", "spacing between modes in hz (added to mult)");
		ui_interface->addVerticalSlider("freq shift", &fVslider34, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider33, "3", "");
		ui_interface->declare(&fVslider33, "style", "knob");
		ui_interface->declare(&fVslider33, "tooltip", "duration of resonance for modes (seconds)");
		ui_interface->addVerticalSlider("base dur", &fVslider33, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider32, "5", "");
		ui_interface->declare(&fVslider32, "style", "knob");
		ui_interface->declare(&fVslider32, "tooltip", "divider for each mode's duration (2 to disable)");
		ui_interface->addVerticalSlider("dur div", &fVslider32, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider39, "6", "");
		ui_interface->declare(&fVslider39, "style", "knob");
		ui_interface->declare(&fVslider39, "tooltip", "amplitude of modes");
		ui_interface->addVerticalSlider("base amp", &fVslider39, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider37, "7", "");
		ui_interface->declare(&fVslider37, "style", "knob");
		ui_interface->declare(&fVslider37, "tooltip", "divider for each mode's amp (2 to disable)");
		ui_interface->addVerticalSlider("amp div", &fVslider37, FAUSTFLOAT(1.0), FAUSTFLOAT(0.01), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("4");
		ui_interface->declare(&fVslider30, "-1", "");
		ui_interface->declare(&fVslider30, "style", "knob");
		ui_interface->declare(&fVslider30, "tooltip", "number of active modes in group");
		ui_interface->addVerticalSlider("modes", &fVslider30, FAUSTFLOAT(32.0), FAUSTFLOAT(0.0), FAUSTFLOAT(32.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider28, "0", "");
		ui_interface->declare(&fVslider28, "style", "knob");
		ui_interface->declare(&fVslider28, "tooltip", "frequency of first mode in group");
		ui_interface->addVerticalSlider("base freq", &fVslider28, FAUSTFLOAT(2.2e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(1.5e+04), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider27, "1", "");
		ui_interface->declare(&fVslider27, "style", "knob");
		ui_interface->declare(&fVslider27, "tooltip", "multiplier for each mode's freq");
		ui_interface->addVerticalSlider("freq mult", &fVslider27, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider26, "2", "");
		ui_interface->declare(&fVslider26, "style", "knob");
		ui_interface->declare(&fVslider26, "tooltip", "spacing between modes in hz (added to mult)");
		ui_interface->addVerticalSlider("freq shift", &fVslider26, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider25, "3", "");
		ui_interface->declare(&fVslider25, "style", "knob");
		ui_interface->declare(&fVslider25, "tooltip", "duration of resonance for modes (seconds)");
		ui_interface->addVerticalSlider("base dur", &fVslider25, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider24, "5", "");
		ui_interface->declare(&fVslider24, "style", "knob");
		ui_interface->declare(&fVslider24, "tooltip", "divider for each mode's duration (2 to disable)");
		ui_interface->addVerticalSlider("dur div", &fVslider24, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider31, "6", "");
		ui_interface->declare(&fVslider31, "style", "knob");
		ui_interface->declare(&fVslider31, "tooltip", "amplitude of modes");
		ui_interface->addVerticalSlider("base amp", &fVslider31, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider29, "7", "");
		ui_interface->declare(&fVslider29, "style", "knob");
		ui_interface->declare(&fVslider29, "tooltip", "divider for each mode's amp (2 to disable)");
		ui_interface->addVerticalSlider("amp div", &fVslider29, FAUSTFLOAT(1.0), FAUSTFLOAT(0.01), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("5");
		ui_interface->declare(&fVslider22, "-1", "");
		ui_interface->declare(&fVslider22, "style", "knob");
		ui_interface->declare(&fVslider22, "tooltip", "number of active modes in group");
		ui_interface->addVerticalSlider("modes", &fVslider22, FAUSTFLOAT(32.0), FAUSTFLOAT(0.0), FAUSTFLOAT(32.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider20, "0", "");
		ui_interface->declare(&fVslider20, "style", "knob");
		ui_interface->declare(&fVslider20, "tooltip", "frequency of first mode in group");
		ui_interface->addVerticalSlider("base freq", &fVslider20, FAUSTFLOAT(2.2e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(1.5e+04), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider19, "1", "");
		ui_interface->declare(&fVslider19, "style", "knob");
		ui_interface->declare(&fVslider19, "tooltip", "multiplier for each mode's freq");
		ui_interface->addVerticalSlider("freq mult", &fVslider19, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider18, "2", "");
		ui_interface->declare(&fVslider18, "style", "knob");
		ui_interface->declare(&fVslider18, "tooltip", "spacing between modes in hz (added to mult)");
		ui_interface->addVerticalSlider("freq shift", &fVslider18, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider17, "3", "");
		ui_interface->declare(&fVslider17, "style", "knob");
		ui_interface->declare(&fVslider17, "tooltip", "duration of resonance for modes (seconds)");
		ui_interface->addVerticalSlider("base dur", &fVslider17, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider16, "5", "");
		ui_interface->declare(&fVslider16, "style", "knob");
		ui_interface->declare(&fVslider16, "tooltip", "divider for each mode's duration (2 to disable)");
		ui_interface->addVerticalSlider("dur div", &fVslider16, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider23, "6", "");
		ui_interface->declare(&fVslider23, "style", "knob");
		ui_interface->declare(&fVslider23, "tooltip", "amplitude of modes");
		ui_interface->addVerticalSlider("base amp", &fVslider23, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider21, "7", "");
		ui_interface->declare(&fVslider21, "style", "knob");
		ui_interface->declare(&fVslider21, "tooltip", "divider for each mode's amp (2 to disable)");
		ui_interface->addVerticalSlider("amp div", &fVslider21, FAUSTFLOAT(1.0), FAUSTFLOAT(0.01), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("6");
		ui_interface->declare(&fVslider14, "-1", "");
		ui_interface->declare(&fVslider14, "style", "knob");
		ui_interface->declare(&fVslider14, "tooltip", "number of active modes in group");
		ui_interface->addVerticalSlider("modes", &fVslider14, FAUSTFLOAT(32.0), FAUSTFLOAT(0.0), FAUSTFLOAT(32.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider12, "0", "");
		ui_interface->declare(&fVslider12, "style", "knob");
		ui_interface->declare(&fVslider12, "tooltip", "frequency of first mode in group");
		ui_interface->addVerticalSlider("base freq", &fVslider12, FAUSTFLOAT(2.2e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(1.5e+04), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider11, "1", "");
		ui_interface->declare(&fVslider11, "style", "knob");
		ui_interface->declare(&fVslider11, "tooltip", "multiplier for each mode's freq");
		ui_interface->addVerticalSlider("freq mult", &fVslider11, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider10, "2", "");
		ui_interface->declare(&fVslider10, "style", "knob");
		ui_interface->declare(&fVslider10, "tooltip", "spacing between modes in hz (added to mult)");
		ui_interface->addVerticalSlider("freq shift", &fVslider10, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider9, "3", "");
		ui_interface->declare(&fVslider9, "style", "knob");
		ui_interface->declare(&fVslider9, "tooltip", "duration of resonance for modes (seconds)");
		ui_interface->addVerticalSlider("base dur", &fVslider9, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider8, "5", "");
		ui_interface->declare(&fVslider8, "style", "knob");
		ui_interface->declare(&fVslider8, "tooltip", "divider for each mode's duration (2 to disable)");
		ui_interface->addVerticalSlider("dur div", &fVslider8, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider15, "6", "");
		ui_interface->declare(&fVslider15, "style", "knob");
		ui_interface->declare(&fVslider15, "tooltip", "amplitude of modes");
		ui_interface->addVerticalSlider("base amp", &fVslider15, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider13, "7", "");
		ui_interface->declare(&fVslider13, "style", "knob");
		ui_interface->declare(&fVslider13, "tooltip", "divider for each mode's amp (2 to disable)");
		ui_interface->addVerticalSlider("amp div", &fVslider13, FAUSTFLOAT(1.0), FAUSTFLOAT(0.01), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("7");
		ui_interface->declare(&fVslider6, "-1", "");
		ui_interface->declare(&fVslider6, "style", "knob");
		ui_interface->declare(&fVslider6, "tooltip", "number of active modes in group");
		ui_interface->addVerticalSlider("modes", &fVslider6, FAUSTFLOAT(32.0), FAUSTFLOAT(0.0), FAUSTFLOAT(32.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fVslider4, "0", "");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "frequency of first mode in group");
		ui_interface->addVerticalSlider("base freq", &fVslider4, FAUSTFLOAT(2.2e+02), FAUSTFLOAT(1.0), FAUSTFLOAT(1.5e+04), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider3, "1", "");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "multiplier for each mode's freq");
		ui_interface->addVerticalSlider("freq mult", &fVslider3, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider2, "2", "");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "spacing between modes in hz (added to mult)");
		ui_interface->addVerticalSlider("freq shift", &fVslider2, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5e+03), FAUSTFLOAT(0.1));
		ui_interface->declare(&fVslider1, "3", "");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "duration of resonance for modes (seconds)");
		ui_interface->addVerticalSlider("base dur", &fVslider1, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider0, "5", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "divider for each mode's duration (2 to disable)");
		ui_interface->addVerticalSlider("dur div", &fVslider0, FAUSTFLOAT(1.0), FAUSTFLOAT(0.001), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider7, "6", "");
		ui_interface->declare(&fVslider7, "style", "knob");
		ui_interface->declare(&fVslider7, "tooltip", "amplitude of modes");
		ui_interface->addVerticalSlider("base amp", &fVslider7, FAUSTFLOAT(0.1), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(0.001));
		ui_interface->declare(&fVslider5, "7", "");
		ui_interface->declare(&fVslider5, "style", "knob");
		ui_interface->declare(&fVslider5, "tooltip", "divider for each mode's amp (2 to disable)");
		ui_interface->addVerticalSlider("amp div", &fVslider5, FAUSTFLOAT(1.0), FAUSTFLOAT(0.01), FAUSTFLOAT(2.0), FAUSTFLOAT(0.001));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		double fSlow0 = double(fVslider0);
		int iSlow1 = fSlow0 != 2.0;
		double fSlow2 = double(iSlow1);
		double fSlow3 = fSlow2 / fSlow0;
		double fSlow4 = double(1 - iSlow1);
		double fSlow5 = double(fVslider1);
		double fSlow6 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.03225806451612903 * fSlow3)));
		double fSlow7 = mydsp_faustpower2_f(fSlow6);
		double fSlow8 = double(fVslider2);
		double fSlow9 = double(fVslider3);
		double fSlow10 = 31.0 * fSlow9;
		double fSlow11 = double(fVslider4);
		double fSlow12 = (0.0 - 2.0 * fSlow6) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow10 + double(fSlow10 == 0.0)) + 31.0 * fSlow8));
		double fSlow13 = double(fVslider5);
		int iSlow14 = fSlow13 != 2.0;
		double fSlow15 = double(iSlow14);
		double fSlow16 = fSlow15 / fSlow13;
		double fSlow17 = double(1 - iSlow14);
		double fSlow18 = double(fVslider6);
		double fSlow19 = double(31.0 < fSlow18) * (fSlow17 + 0.03225806451612903 * fSlow16);
		double fSlow20 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.03333333333333333 * fSlow3)));
		double fSlow21 = mydsp_faustpower2_f(fSlow20);
		double fSlow22 = 3e+01 * fSlow9;
		double fSlow23 = (0.0 - 2.0 * fSlow20) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow22 + double(fSlow22 == 0.0)) + 3e+01 * fSlow8));
		double fSlow24 = double(3e+01 < fSlow18) * (fSlow17 + 0.03333333333333333 * fSlow16);
		double fSlow25 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.034482758620689655 * fSlow3)));
		double fSlow26 = mydsp_faustpower2_f(fSlow25);
		double fSlow27 = 29.0 * fSlow9;
		double fSlow28 = (0.0 - 2.0 * fSlow25) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow27 + double(fSlow27 == 0.0)) + 29.0 * fSlow8));
		double fSlow29 = double(29.0 < fSlow18) * (fSlow17 + 0.034482758620689655 * fSlow16);
		double fSlow30 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.03571428571428571 * fSlow3)));
		double fSlow31 = mydsp_faustpower2_f(fSlow30);
		double fSlow32 = 28.0 * fSlow9;
		double fSlow33 = (0.0 - 2.0 * fSlow30) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow32 + double(fSlow32 == 0.0)) + 28.0 * fSlow8));
		double fSlow34 = double(28.0 < fSlow18) * (fSlow17 + 0.03571428571428571 * fSlow16);
		double fSlow35 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.037037037037037035 * fSlow3)));
		double fSlow36 = mydsp_faustpower2_f(fSlow35);
		double fSlow37 = 27.0 * fSlow9;
		double fSlow38 = (0.0 - 2.0 * fSlow35) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow37 + double(fSlow37 == 0.0)) + 27.0 * fSlow8));
		double fSlow39 = double(27.0 < fSlow18) * (fSlow17 + 0.037037037037037035 * fSlow16);
		double fSlow40 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.038461538461538464 * fSlow3)));
		double fSlow41 = mydsp_faustpower2_f(fSlow40);
		double fSlow42 = 26.0 * fSlow9;
		double fSlow43 = (0.0 - 2.0 * fSlow40) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow42 + double(fSlow42 == 0.0)) + 26.0 * fSlow8));
		double fSlow44 = double(26.0 < fSlow18) * (fSlow17 + 0.038461538461538464 * fSlow16);
		double fSlow45 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.04 * fSlow3)));
		double fSlow46 = mydsp_faustpower2_f(fSlow45);
		double fSlow47 = 25.0 * fSlow9;
		double fSlow48 = (0.0 - 2.0 * fSlow45) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow47 + double(fSlow47 == 0.0)) + 25.0 * fSlow8));
		double fSlow49 = double(25.0 < fSlow18) * (fSlow17 + 0.04 * fSlow16);
		double fSlow50 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.041666666666666664 * fSlow3)));
		double fSlow51 = mydsp_faustpower2_f(fSlow50);
		double fSlow52 = 24.0 * fSlow9;
		double fSlow53 = (0.0 - 2.0 * fSlow50) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow52 + double(fSlow52 == 0.0)) + 24.0 * fSlow8));
		double fSlow54 = double(24.0 < fSlow18) * (fSlow17 + 0.041666666666666664 * fSlow16);
		double fSlow55 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.043478260869565216 * fSlow3)));
		double fSlow56 = mydsp_faustpower2_f(fSlow55);
		double fSlow57 = 23.0 * fSlow9;
		double fSlow58 = (0.0 - 2.0 * fSlow55) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow57 + double(fSlow57 == 0.0)) + 23.0 * fSlow8));
		double fSlow59 = double(23.0 < fSlow18) * (fSlow17 + 0.043478260869565216 * fSlow16);
		double fSlow60 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.045454545454545456 * fSlow3)));
		double fSlow61 = mydsp_faustpower2_f(fSlow60);
		double fSlow62 = 22.0 * fSlow9;
		double fSlow63 = (0.0 - 2.0 * fSlow60) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow62 + double(fSlow62 == 0.0)) + 22.0 * fSlow8));
		double fSlow64 = double(22.0 < fSlow18) * (fSlow17 + 0.045454545454545456 * fSlow16);
		double fSlow65 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.047619047619047616 * fSlow3)));
		double fSlow66 = mydsp_faustpower2_f(fSlow65);
		double fSlow67 = 21.0 * fSlow9;
		double fSlow68 = (0.0 - 2.0 * fSlow65) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow67 + double(fSlow67 == 0.0)) + 21.0 * fSlow8));
		double fSlow69 = double(21.0 < fSlow18) * (fSlow17 + 0.047619047619047616 * fSlow16);
		double fSlow70 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.05 * fSlow3)));
		double fSlow71 = mydsp_faustpower2_f(fSlow70);
		double fSlow72 = 2e+01 * fSlow9;
		double fSlow73 = (0.0 - 2.0 * fSlow70) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow72 + double(fSlow72 == 0.0)) + 2e+01 * fSlow8));
		double fSlow74 = double(2e+01 < fSlow18) * (fSlow17 + 0.05 * fSlow16);
		double fSlow75 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.05263157894736842 * fSlow3)));
		double fSlow76 = mydsp_faustpower2_f(fSlow75);
		double fSlow77 = 19.0 * fSlow9;
		double fSlow78 = (0.0 - 2.0 * fSlow75) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow77 + double(fSlow77 == 0.0)) + 19.0 * fSlow8));
		double fSlow79 = double(19.0 < fSlow18) * (fSlow17 + 0.05263157894736842 * fSlow16);
		double fSlow80 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.05555555555555555 * fSlow3)));
		double fSlow81 = mydsp_faustpower2_f(fSlow80);
		double fSlow82 = 18.0 * fSlow9;
		double fSlow83 = (0.0 - 2.0 * fSlow80) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow82 + double(fSlow82 == 0.0)) + 18.0 * fSlow8));
		double fSlow84 = double(18.0 < fSlow18) * (fSlow17 + 0.05555555555555555 * fSlow16);
		double fSlow85 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.058823529411764705 * fSlow3)));
		double fSlow86 = mydsp_faustpower2_f(fSlow85);
		double fSlow87 = 17.0 * fSlow9;
		double fSlow88 = (0.0 - 2.0 * fSlow85) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow87 + double(fSlow87 == 0.0)) + 17.0 * fSlow8));
		double fSlow89 = double(17.0 < fSlow18) * (fSlow17 + 0.058823529411764705 * fSlow16);
		double fSlow90 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.0625 * fSlow3)));
		double fSlow91 = mydsp_faustpower2_f(fSlow90);
		double fSlow92 = 16.0 * fSlow9;
		double fSlow93 = (0.0 - 2.0 * fSlow90) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow92 + double(fSlow92 == 0.0)) + 16.0 * fSlow8));
		double fSlow94 = double(16.0 < fSlow18) * (fSlow17 + 0.0625 * fSlow16);
		double fSlow95 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.06666666666666667 * fSlow3)));
		double fSlow96 = mydsp_faustpower2_f(fSlow95);
		double fSlow97 = 15.0 * fSlow9;
		double fSlow98 = (0.0 - 2.0 * fSlow95) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow97 + double(fSlow97 == 0.0)) + 15.0 * fSlow8));
		double fSlow99 = double(15.0 < fSlow18) * (fSlow17 + 0.06666666666666667 * fSlow16);
		double fSlow100 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.07142857142857142 * fSlow3)));
		double fSlow101 = mydsp_faustpower2_f(fSlow100);
		double fSlow102 = 14.0 * fSlow9;
		double fSlow103 = (0.0 - 2.0 * fSlow100) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow102 + double(fSlow102 == 0.0)) + 14.0 * fSlow8));
		double fSlow104 = double(14.0 < fSlow18) * (fSlow17 + 0.07142857142857142 * fSlow16);
		double fSlow105 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.07692307692307693 * fSlow3)));
		double fSlow106 = mydsp_faustpower2_f(fSlow105);
		double fSlow107 = 13.0 * fSlow9;
		double fSlow108 = (0.0 - 2.0 * fSlow105) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow107 + double(fSlow107 == 0.0)) + 13.0 * fSlow8));
		double fSlow109 = double(13.0 < fSlow18) * (fSlow17 + 0.07692307692307693 * fSlow16);
		double fSlow110 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.08333333333333333 * fSlow3)));
		double fSlow111 = mydsp_faustpower2_f(fSlow110);
		double fSlow112 = 12.0 * fSlow9;
		double fSlow113 = (0.0 - 2.0 * fSlow110) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow112 + double(fSlow112 == 0.0)) + 12.0 * fSlow8));
		double fSlow114 = double(12.0 < fSlow18) * (fSlow17 + 0.08333333333333333 * fSlow16);
		double fSlow115 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.09090909090909091 * fSlow3)));
		double fSlow116 = mydsp_faustpower2_f(fSlow115);
		double fSlow117 = 11.0 * fSlow9;
		double fSlow118 = (0.0 - 2.0 * fSlow115) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow117 + double(fSlow117 == 0.0)) + 11.0 * fSlow8));
		double fSlow119 = double(11.0 < fSlow18) * (fSlow17 + 0.09090909090909091 * fSlow16);
		double fSlow120 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.1 * fSlow3)));
		double fSlow121 = mydsp_faustpower2_f(fSlow120);
		double fSlow122 = 1e+01 * fSlow9;
		double fSlow123 = (0.0 - 2.0 * fSlow120) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow122 + double(fSlow122 == 0.0)) + 1e+01 * fSlow8));
		double fSlow124 = double(1e+01 < fSlow18) * (fSlow17 + 0.1 * fSlow16);
		double fSlow125 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.1111111111111111 * fSlow3)));
		double fSlow126 = mydsp_faustpower2_f(fSlow125);
		double fSlow127 = 9.0 * fSlow9;
		double fSlow128 = (0.0 - 2.0 * fSlow125) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow127 + double(fSlow127 == 0.0)) + 9.0 * fSlow8));
		double fSlow129 = double(9.0 < fSlow18) * (fSlow17 + 0.1111111111111111 * fSlow16);
		double fSlow130 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.125 * fSlow3)));
		double fSlow131 = mydsp_faustpower2_f(fSlow130);
		double fSlow132 = 8.0 * fSlow9;
		double fSlow133 = (0.0 - 2.0 * fSlow130) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow132 + double(fSlow132 == 0.0)) + 8.0 * fSlow8));
		double fSlow134 = double(8.0 < fSlow18) * (fSlow17 + 0.125 * fSlow16);
		double fSlow135 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.14285714285714285 * fSlow3)));
		double fSlow136 = mydsp_faustpower2_f(fSlow135);
		double fSlow137 = 7.0 * fSlow9;
		double fSlow138 = (0.0 - 2.0 * fSlow135) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow137 + double(fSlow137 == 0.0)) + 7.0 * fSlow8));
		double fSlow139 = double(7.0 < fSlow18) * (fSlow17 + 0.14285714285714285 * fSlow16);
		double fSlow140 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.16666666666666666 * fSlow3)));
		double fSlow141 = mydsp_faustpower2_f(fSlow140);
		double fSlow142 = 6.0 * fSlow9;
		double fSlow143 = (0.0 - 2.0 * fSlow140) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow142 + double(fSlow142 == 0.0)) + 6.0 * fSlow8));
		double fSlow144 = double(6.0 < fSlow18) * (fSlow17 + 0.16666666666666666 * fSlow16);
		double fSlow145 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.2 * fSlow3)));
		double fSlow146 = mydsp_faustpower2_f(fSlow145);
		double fSlow147 = 5.0 * fSlow9;
		double fSlow148 = (0.0 - 2.0 * fSlow145) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow147 + double(fSlow147 == 0.0)) + 5.0 * fSlow8));
		double fSlow149 = double(5.0 < fSlow18) * (fSlow17 + 0.2 * fSlow16);
		double fSlow150 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.25 * fSlow3)));
		double fSlow151 = mydsp_faustpower2_f(fSlow150);
		double fSlow152 = 4.0 * fSlow9;
		double fSlow153 = (0.0 - 2.0 * fSlow150) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow152 + double(fSlow152 == 0.0)) + 4.0 * fSlow8));
		double fSlow154 = double(4.0 < fSlow18) * (fSlow17 + 0.25 * fSlow16);
		double fSlow155 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.3333333333333333 * fSlow3)));
		double fSlow156 = mydsp_faustpower2_f(fSlow155);
		double fSlow157 = 3.0 * fSlow9;
		double fSlow158 = (0.0 - 2.0 * fSlow155) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow157 + double(fSlow157 == 0.0)) + 3.0 * fSlow8));
		double fSlow159 = double(3.0 < fSlow18) * (fSlow17 + 0.3333333333333333 * fSlow16);
		double fSlow160 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + 0.5 * fSlow3)));
		double fSlow161 = mydsp_faustpower2_f(fSlow160);
		double fSlow162 = 2.0 * fSlow9;
		double fSlow163 = (0.0 - 2.0 * fSlow160) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11 * (fSlow162 + double(fSlow162 == 0.0)) + 2.0 * fSlow8));
		double fSlow164 = double(2.0 < fSlow18) * (fSlow17 + 0.5 * fSlow16);
		double fSlow165 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + fSlow3)));
		double fSlow166 = mydsp_faustpower2_f(fSlow165);
		double fSlow167 = (0.0 - 2.0 * fSlow165) * std::cos(fConst3 * std::min<double>(fConst2, fSlow8 + fSlow11 * (fSlow9 + double(fSlow9 == 0.0))));
		double fSlow168 = double(1.0 < fSlow18) * (fSlow17 + fSlow16);
		double fSlow169 = std::pow(0.001, fConst1 / (fSlow5 * (fSlow4 + fSlow2)));
		double fSlow170 = mydsp_faustpower2_f(fSlow169);
		double fSlow171 = (0.0 - 2.0 * fSlow169) * std::cos(fConst3 * std::min<double>(fConst2, fSlow11));
		double fSlow172 = double(0.0 < fSlow18) * (fSlow17 + fSlow15);
		double fSlow173 = double(fVslider7);
		double fSlow174 = double(fVslider8);
		int iSlow175 = fSlow174 != 2.0;
		double fSlow176 = double(iSlow175);
		double fSlow177 = fSlow176 / fSlow174;
		double fSlow178 = double(1 - iSlow175);
		double fSlow179 = double(fVslider9);
		double fSlow180 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.03225806451612903 * fSlow177)));
		double fSlow181 = mydsp_faustpower2_f(fSlow180);
		double fSlow182 = double(fVslider10);
		double fSlow183 = double(fVslider11);
		double fSlow184 = 31.0 * fSlow183;
		double fSlow185 = double(fVslider12);
		double fSlow186 = (0.0 - 2.0 * fSlow180) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow184 + double(fSlow184 == 0.0)) + 31.0 * fSlow182));
		double fSlow187 = double(fVslider13);
		int iSlow188 = fSlow187 != 2.0;
		double fSlow189 = double(iSlow188);
		double fSlow190 = fSlow189 / fSlow187;
		double fSlow191 = double(1 - iSlow188);
		double fSlow192 = double(fVslider14);
		double fSlow193 = double(31.0 < fSlow192) * (fSlow191 + 0.03225806451612903 * fSlow190);
		double fSlow194 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.03333333333333333 * fSlow177)));
		double fSlow195 = mydsp_faustpower2_f(fSlow194);
		double fSlow196 = 3e+01 * fSlow183;
		double fSlow197 = (0.0 - 2.0 * fSlow194) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow196 + double(fSlow196 == 0.0)) + 3e+01 * fSlow182));
		double fSlow198 = double(3e+01 < fSlow192) * (fSlow191 + 0.03333333333333333 * fSlow190);
		double fSlow199 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.034482758620689655 * fSlow177)));
		double fSlow200 = mydsp_faustpower2_f(fSlow199);
		double fSlow201 = 29.0 * fSlow183;
		double fSlow202 = (0.0 - 2.0 * fSlow199) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow201 + double(fSlow201 == 0.0)) + 29.0 * fSlow182));
		double fSlow203 = double(29.0 < fSlow192) * (fSlow191 + 0.034482758620689655 * fSlow190);
		double fSlow204 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.03571428571428571 * fSlow177)));
		double fSlow205 = mydsp_faustpower2_f(fSlow204);
		double fSlow206 = 28.0 * fSlow183;
		double fSlow207 = (0.0 - 2.0 * fSlow204) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow206 + double(fSlow206 == 0.0)) + 28.0 * fSlow182));
		double fSlow208 = double(28.0 < fSlow192) * (fSlow191 + 0.03571428571428571 * fSlow190);
		double fSlow209 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.037037037037037035 * fSlow177)));
		double fSlow210 = mydsp_faustpower2_f(fSlow209);
		double fSlow211 = 27.0 * fSlow183;
		double fSlow212 = (0.0 - 2.0 * fSlow209) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow211 + double(fSlow211 == 0.0)) + 27.0 * fSlow182));
		double fSlow213 = double(27.0 < fSlow192) * (fSlow191 + 0.037037037037037035 * fSlow190);
		double fSlow214 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.038461538461538464 * fSlow177)));
		double fSlow215 = mydsp_faustpower2_f(fSlow214);
		double fSlow216 = 26.0 * fSlow183;
		double fSlow217 = (0.0 - 2.0 * fSlow214) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow216 + double(fSlow216 == 0.0)) + 26.0 * fSlow182));
		double fSlow218 = double(26.0 < fSlow192) * (fSlow191 + 0.038461538461538464 * fSlow190);
		double fSlow219 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.04 * fSlow177)));
		double fSlow220 = mydsp_faustpower2_f(fSlow219);
		double fSlow221 = 25.0 * fSlow183;
		double fSlow222 = (0.0 - 2.0 * fSlow219) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow221 + double(fSlow221 == 0.0)) + 25.0 * fSlow182));
		double fSlow223 = double(25.0 < fSlow192) * (fSlow191 + 0.04 * fSlow190);
		double fSlow224 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.041666666666666664 * fSlow177)));
		double fSlow225 = mydsp_faustpower2_f(fSlow224);
		double fSlow226 = 24.0 * fSlow183;
		double fSlow227 = (0.0 - 2.0 * fSlow224) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow226 + double(fSlow226 == 0.0)) + 24.0 * fSlow182));
		double fSlow228 = double(24.0 < fSlow192) * (fSlow191 + 0.041666666666666664 * fSlow190);
		double fSlow229 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.043478260869565216 * fSlow177)));
		double fSlow230 = mydsp_faustpower2_f(fSlow229);
		double fSlow231 = 23.0 * fSlow183;
		double fSlow232 = (0.0 - 2.0 * fSlow229) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow231 + double(fSlow231 == 0.0)) + 23.0 * fSlow182));
		double fSlow233 = double(23.0 < fSlow192) * (fSlow191 + 0.043478260869565216 * fSlow190);
		double fSlow234 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.045454545454545456 * fSlow177)));
		double fSlow235 = mydsp_faustpower2_f(fSlow234);
		double fSlow236 = 22.0 * fSlow183;
		double fSlow237 = (0.0 - 2.0 * fSlow234) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow236 + double(fSlow236 == 0.0)) + 22.0 * fSlow182));
		double fSlow238 = double(22.0 < fSlow192) * (fSlow191 + 0.045454545454545456 * fSlow190);
		double fSlow239 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.047619047619047616 * fSlow177)));
		double fSlow240 = mydsp_faustpower2_f(fSlow239);
		double fSlow241 = 21.0 * fSlow183;
		double fSlow242 = (0.0 - 2.0 * fSlow239) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow241 + double(fSlow241 == 0.0)) + 21.0 * fSlow182));
		double fSlow243 = double(21.0 < fSlow192) * (fSlow191 + 0.047619047619047616 * fSlow190);
		double fSlow244 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.05 * fSlow177)));
		double fSlow245 = mydsp_faustpower2_f(fSlow244);
		double fSlow246 = 2e+01 * fSlow183;
		double fSlow247 = (0.0 - 2.0 * fSlow244) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow246 + double(fSlow246 == 0.0)) + 2e+01 * fSlow182));
		double fSlow248 = double(2e+01 < fSlow192) * (fSlow191 + 0.05 * fSlow190);
		double fSlow249 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.05263157894736842 * fSlow177)));
		double fSlow250 = mydsp_faustpower2_f(fSlow249);
		double fSlow251 = 19.0 * fSlow183;
		double fSlow252 = (0.0 - 2.0 * fSlow249) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow251 + double(fSlow251 == 0.0)) + 19.0 * fSlow182));
		double fSlow253 = double(19.0 < fSlow192) * (fSlow191 + 0.05263157894736842 * fSlow190);
		double fSlow254 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.05555555555555555 * fSlow177)));
		double fSlow255 = mydsp_faustpower2_f(fSlow254);
		double fSlow256 = 18.0 * fSlow183;
		double fSlow257 = (0.0 - 2.0 * fSlow254) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow256 + double(fSlow256 == 0.0)) + 18.0 * fSlow182));
		double fSlow258 = double(18.0 < fSlow192) * (fSlow191 + 0.05555555555555555 * fSlow190);
		double fSlow259 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.058823529411764705 * fSlow177)));
		double fSlow260 = mydsp_faustpower2_f(fSlow259);
		double fSlow261 = 17.0 * fSlow183;
		double fSlow262 = (0.0 - 2.0 * fSlow259) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow261 + double(fSlow261 == 0.0)) + 17.0 * fSlow182));
		double fSlow263 = double(17.0 < fSlow192) * (fSlow191 + 0.058823529411764705 * fSlow190);
		double fSlow264 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.0625 * fSlow177)));
		double fSlow265 = mydsp_faustpower2_f(fSlow264);
		double fSlow266 = 16.0 * fSlow183;
		double fSlow267 = (0.0 - 2.0 * fSlow264) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow266 + double(fSlow266 == 0.0)) + 16.0 * fSlow182));
		double fSlow268 = double(16.0 < fSlow192) * (fSlow191 + 0.0625 * fSlow190);
		double fSlow269 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.06666666666666667 * fSlow177)));
		double fSlow270 = mydsp_faustpower2_f(fSlow269);
		double fSlow271 = 15.0 * fSlow183;
		double fSlow272 = (0.0 - 2.0 * fSlow269) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow271 + double(fSlow271 == 0.0)) + 15.0 * fSlow182));
		double fSlow273 = double(15.0 < fSlow192) * (fSlow191 + 0.06666666666666667 * fSlow190);
		double fSlow274 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.07142857142857142 * fSlow177)));
		double fSlow275 = mydsp_faustpower2_f(fSlow274);
		double fSlow276 = 14.0 * fSlow183;
		double fSlow277 = (0.0 - 2.0 * fSlow274) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow276 + double(fSlow276 == 0.0)) + 14.0 * fSlow182));
		double fSlow278 = double(14.0 < fSlow192) * (fSlow191 + 0.07142857142857142 * fSlow190);
		double fSlow279 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.07692307692307693 * fSlow177)));
		double fSlow280 = mydsp_faustpower2_f(fSlow279);
		double fSlow281 = 13.0 * fSlow183;
		double fSlow282 = (0.0 - 2.0 * fSlow279) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow281 + double(fSlow281 == 0.0)) + 13.0 * fSlow182));
		double fSlow283 = double(13.0 < fSlow192) * (fSlow191 + 0.07692307692307693 * fSlow190);
		double fSlow284 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.08333333333333333 * fSlow177)));
		double fSlow285 = mydsp_faustpower2_f(fSlow284);
		double fSlow286 = 12.0 * fSlow183;
		double fSlow287 = (0.0 - 2.0 * fSlow284) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow286 + double(fSlow286 == 0.0)) + 12.0 * fSlow182));
		double fSlow288 = double(12.0 < fSlow192) * (fSlow191 + 0.08333333333333333 * fSlow190);
		double fSlow289 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.09090909090909091 * fSlow177)));
		double fSlow290 = mydsp_faustpower2_f(fSlow289);
		double fSlow291 = 11.0 * fSlow183;
		double fSlow292 = (0.0 - 2.0 * fSlow289) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow291 + double(fSlow291 == 0.0)) + 11.0 * fSlow182));
		double fSlow293 = double(11.0 < fSlow192) * (fSlow191 + 0.09090909090909091 * fSlow190);
		double fSlow294 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.1 * fSlow177)));
		double fSlow295 = mydsp_faustpower2_f(fSlow294);
		double fSlow296 = 1e+01 * fSlow183;
		double fSlow297 = (0.0 - 2.0 * fSlow294) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow296 + double(fSlow296 == 0.0)) + 1e+01 * fSlow182));
		double fSlow298 = double(1e+01 < fSlow192) * (fSlow191 + 0.1 * fSlow190);
		double fSlow299 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.1111111111111111 * fSlow177)));
		double fSlow300 = mydsp_faustpower2_f(fSlow299);
		double fSlow301 = 9.0 * fSlow183;
		double fSlow302 = (0.0 - 2.0 * fSlow299) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow301 + double(fSlow301 == 0.0)) + 9.0 * fSlow182));
		double fSlow303 = double(9.0 < fSlow192) * (fSlow191 + 0.1111111111111111 * fSlow190);
		double fSlow304 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.125 * fSlow177)));
		double fSlow305 = mydsp_faustpower2_f(fSlow304);
		double fSlow306 = 8.0 * fSlow183;
		double fSlow307 = (0.0 - 2.0 * fSlow304) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow306 + double(fSlow306 == 0.0)) + 8.0 * fSlow182));
		double fSlow308 = double(8.0 < fSlow192) * (fSlow191 + 0.125 * fSlow190);
		double fSlow309 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.14285714285714285 * fSlow177)));
		double fSlow310 = mydsp_faustpower2_f(fSlow309);
		double fSlow311 = 7.0 * fSlow183;
		double fSlow312 = (0.0 - 2.0 * fSlow309) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow311 + double(fSlow311 == 0.0)) + 7.0 * fSlow182));
		double fSlow313 = double(7.0 < fSlow192) * (fSlow191 + 0.14285714285714285 * fSlow190);
		double fSlow314 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.16666666666666666 * fSlow177)));
		double fSlow315 = mydsp_faustpower2_f(fSlow314);
		double fSlow316 = 6.0 * fSlow183;
		double fSlow317 = (0.0 - 2.0 * fSlow314) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow316 + double(fSlow316 == 0.0)) + 6.0 * fSlow182));
		double fSlow318 = double(6.0 < fSlow192) * (fSlow191 + 0.16666666666666666 * fSlow190);
		double fSlow319 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.2 * fSlow177)));
		double fSlow320 = mydsp_faustpower2_f(fSlow319);
		double fSlow321 = 5.0 * fSlow183;
		double fSlow322 = (0.0 - 2.0 * fSlow319) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow321 + double(fSlow321 == 0.0)) + 5.0 * fSlow182));
		double fSlow323 = double(5.0 < fSlow192) * (fSlow191 + 0.2 * fSlow190);
		double fSlow324 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.25 * fSlow177)));
		double fSlow325 = mydsp_faustpower2_f(fSlow324);
		double fSlow326 = 4.0 * fSlow183;
		double fSlow327 = (0.0 - 2.0 * fSlow324) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow326 + double(fSlow326 == 0.0)) + 4.0 * fSlow182));
		double fSlow328 = double(4.0 < fSlow192) * (fSlow191 + 0.25 * fSlow190);
		double fSlow329 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.3333333333333333 * fSlow177)));
		double fSlow330 = mydsp_faustpower2_f(fSlow329);
		double fSlow331 = 3.0 * fSlow183;
		double fSlow332 = (0.0 - 2.0 * fSlow329) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow331 + double(fSlow331 == 0.0)) + 3.0 * fSlow182));
		double fSlow333 = double(3.0 < fSlow192) * (fSlow191 + 0.3333333333333333 * fSlow190);
		double fSlow334 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + 0.5 * fSlow177)));
		double fSlow335 = mydsp_faustpower2_f(fSlow334);
		double fSlow336 = 2.0 * fSlow183;
		double fSlow337 = (0.0 - 2.0 * fSlow334) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185 * (fSlow336 + double(fSlow336 == 0.0)) + 2.0 * fSlow182));
		double fSlow338 = double(2.0 < fSlow192) * (fSlow191 + 0.5 * fSlow190);
		double fSlow339 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + fSlow177)));
		double fSlow340 = mydsp_faustpower2_f(fSlow339);
		double fSlow341 = (0.0 - 2.0 * fSlow339) * std::cos(fConst3 * std::min<double>(fConst2, fSlow182 + fSlow185 * (fSlow183 + double(fSlow183 == 0.0))));
		double fSlow342 = double(1.0 < fSlow192) * (fSlow191 + fSlow190);
		double fSlow343 = std::pow(0.001, fConst1 / (fSlow179 * (fSlow178 + fSlow176)));
		double fSlow344 = mydsp_faustpower2_f(fSlow343);
		double fSlow345 = (0.0 - 2.0 * fSlow343) * std::cos(fConst3 * std::min<double>(fConst2, fSlow185));
		double fSlow346 = double(0.0 < fSlow192) * (fSlow191 + fSlow189);
		double fSlow347 = double(fVslider15);
		double fSlow348 = double(fVslider16);
		int iSlow349 = fSlow348 != 2.0;
		double fSlow350 = double(iSlow349);
		double fSlow351 = fSlow350 / fSlow348;
		double fSlow352 = double(1 - iSlow349);
		double fSlow353 = double(fVslider17);
		double fSlow354 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.03225806451612903 * fSlow351)));
		double fSlow355 = mydsp_faustpower2_f(fSlow354);
		double fSlow356 = double(fVslider18);
		double fSlow357 = double(fVslider19);
		double fSlow358 = 31.0 * fSlow357;
		double fSlow359 = double(fVslider20);
		double fSlow360 = (0.0 - 2.0 * fSlow354) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow358 + double(fSlow358 == 0.0)) + 31.0 * fSlow356));
		double fSlow361 = double(fVslider21);
		int iSlow362 = fSlow361 != 2.0;
		double fSlow363 = double(iSlow362);
		double fSlow364 = fSlow363 / fSlow361;
		double fSlow365 = double(1 - iSlow362);
		double fSlow366 = double(fVslider22);
		double fSlow367 = double(31.0 < fSlow366) * (fSlow365 + 0.03225806451612903 * fSlow364);
		double fSlow368 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.03333333333333333 * fSlow351)));
		double fSlow369 = mydsp_faustpower2_f(fSlow368);
		double fSlow370 = 3e+01 * fSlow357;
		double fSlow371 = (0.0 - 2.0 * fSlow368) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow370 + double(fSlow370 == 0.0)) + 3e+01 * fSlow356));
		double fSlow372 = double(3e+01 < fSlow366) * (fSlow365 + 0.03333333333333333 * fSlow364);
		double fSlow373 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.034482758620689655 * fSlow351)));
		double fSlow374 = mydsp_faustpower2_f(fSlow373);
		double fSlow375 = 29.0 * fSlow357;
		double fSlow376 = (0.0 - 2.0 * fSlow373) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow375 + double(fSlow375 == 0.0)) + 29.0 * fSlow356));
		double fSlow377 = double(29.0 < fSlow366) * (fSlow365 + 0.034482758620689655 * fSlow364);
		double fSlow378 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.03571428571428571 * fSlow351)));
		double fSlow379 = mydsp_faustpower2_f(fSlow378);
		double fSlow380 = 28.0 * fSlow357;
		double fSlow381 = (0.0 - 2.0 * fSlow378) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow380 + double(fSlow380 == 0.0)) + 28.0 * fSlow356));
		double fSlow382 = double(28.0 < fSlow366) * (fSlow365 + 0.03571428571428571 * fSlow364);
		double fSlow383 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.037037037037037035 * fSlow351)));
		double fSlow384 = mydsp_faustpower2_f(fSlow383);
		double fSlow385 = 27.0 * fSlow357;
		double fSlow386 = (0.0 - 2.0 * fSlow383) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow385 + double(fSlow385 == 0.0)) + 27.0 * fSlow356));
		double fSlow387 = double(27.0 < fSlow366) * (fSlow365 + 0.037037037037037035 * fSlow364);
		double fSlow388 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.038461538461538464 * fSlow351)));
		double fSlow389 = mydsp_faustpower2_f(fSlow388);
		double fSlow390 = 26.0 * fSlow357;
		double fSlow391 = (0.0 - 2.0 * fSlow388) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow390 + double(fSlow390 == 0.0)) + 26.0 * fSlow356));
		double fSlow392 = double(26.0 < fSlow366) * (fSlow365 + 0.038461538461538464 * fSlow364);
		double fSlow393 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.04 * fSlow351)));
		double fSlow394 = mydsp_faustpower2_f(fSlow393);
		double fSlow395 = 25.0 * fSlow357;
		double fSlow396 = (0.0 - 2.0 * fSlow393) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow395 + double(fSlow395 == 0.0)) + 25.0 * fSlow356));
		double fSlow397 = double(25.0 < fSlow366) * (fSlow365 + 0.04 * fSlow364);
		double fSlow398 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.041666666666666664 * fSlow351)));
		double fSlow399 = mydsp_faustpower2_f(fSlow398);
		double fSlow400 = 24.0 * fSlow357;
		double fSlow401 = (0.0 - 2.0 * fSlow398) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow400 + double(fSlow400 == 0.0)) + 24.0 * fSlow356));
		double fSlow402 = double(24.0 < fSlow366) * (fSlow365 + 0.041666666666666664 * fSlow364);
		double fSlow403 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.043478260869565216 * fSlow351)));
		double fSlow404 = mydsp_faustpower2_f(fSlow403);
		double fSlow405 = 23.0 * fSlow357;
		double fSlow406 = (0.0 - 2.0 * fSlow403) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow405 + double(fSlow405 == 0.0)) + 23.0 * fSlow356));
		double fSlow407 = double(23.0 < fSlow366) * (fSlow365 + 0.043478260869565216 * fSlow364);
		double fSlow408 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.045454545454545456 * fSlow351)));
		double fSlow409 = mydsp_faustpower2_f(fSlow408);
		double fSlow410 = 22.0 * fSlow357;
		double fSlow411 = (0.0 - 2.0 * fSlow408) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow410 + double(fSlow410 == 0.0)) + 22.0 * fSlow356));
		double fSlow412 = double(22.0 < fSlow366) * (fSlow365 + 0.045454545454545456 * fSlow364);
		double fSlow413 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.047619047619047616 * fSlow351)));
		double fSlow414 = mydsp_faustpower2_f(fSlow413);
		double fSlow415 = 21.0 * fSlow357;
		double fSlow416 = (0.0 - 2.0 * fSlow413) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow415 + double(fSlow415 == 0.0)) + 21.0 * fSlow356));
		double fSlow417 = double(21.0 < fSlow366) * (fSlow365 + 0.047619047619047616 * fSlow364);
		double fSlow418 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.05 * fSlow351)));
		double fSlow419 = mydsp_faustpower2_f(fSlow418);
		double fSlow420 = 2e+01 * fSlow357;
		double fSlow421 = (0.0 - 2.0 * fSlow418) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow420 + double(fSlow420 == 0.0)) + 2e+01 * fSlow356));
		double fSlow422 = double(2e+01 < fSlow366) * (fSlow365 + 0.05 * fSlow364);
		double fSlow423 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.05263157894736842 * fSlow351)));
		double fSlow424 = mydsp_faustpower2_f(fSlow423);
		double fSlow425 = 19.0 * fSlow357;
		double fSlow426 = (0.0 - 2.0 * fSlow423) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow425 + double(fSlow425 == 0.0)) + 19.0 * fSlow356));
		double fSlow427 = double(19.0 < fSlow366) * (fSlow365 + 0.05263157894736842 * fSlow364);
		double fSlow428 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.05555555555555555 * fSlow351)));
		double fSlow429 = mydsp_faustpower2_f(fSlow428);
		double fSlow430 = 18.0 * fSlow357;
		double fSlow431 = (0.0 - 2.0 * fSlow428) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow430 + double(fSlow430 == 0.0)) + 18.0 * fSlow356));
		double fSlow432 = double(18.0 < fSlow366) * (fSlow365 + 0.05555555555555555 * fSlow364);
		double fSlow433 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.058823529411764705 * fSlow351)));
		double fSlow434 = mydsp_faustpower2_f(fSlow433);
		double fSlow435 = 17.0 * fSlow357;
		double fSlow436 = (0.0 - 2.0 * fSlow433) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow435 + double(fSlow435 == 0.0)) + 17.0 * fSlow356));
		double fSlow437 = double(17.0 < fSlow366) * (fSlow365 + 0.058823529411764705 * fSlow364);
		double fSlow438 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.0625 * fSlow351)));
		double fSlow439 = mydsp_faustpower2_f(fSlow438);
		double fSlow440 = 16.0 * fSlow357;
		double fSlow441 = (0.0 - 2.0 * fSlow438) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow440 + double(fSlow440 == 0.0)) + 16.0 * fSlow356));
		double fSlow442 = double(16.0 < fSlow366) * (fSlow365 + 0.0625 * fSlow364);
		double fSlow443 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.06666666666666667 * fSlow351)));
		double fSlow444 = mydsp_faustpower2_f(fSlow443);
		double fSlow445 = 15.0 * fSlow357;
		double fSlow446 = (0.0 - 2.0 * fSlow443) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow445 + double(fSlow445 == 0.0)) + 15.0 * fSlow356));
		double fSlow447 = double(15.0 < fSlow366) * (fSlow365 + 0.06666666666666667 * fSlow364);
		double fSlow448 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.07142857142857142 * fSlow351)));
		double fSlow449 = mydsp_faustpower2_f(fSlow448);
		double fSlow450 = 14.0 * fSlow357;
		double fSlow451 = (0.0 - 2.0 * fSlow448) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow450 + double(fSlow450 == 0.0)) + 14.0 * fSlow356));
		double fSlow452 = double(14.0 < fSlow366) * (fSlow365 + 0.07142857142857142 * fSlow364);
		double fSlow453 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.07692307692307693 * fSlow351)));
		double fSlow454 = mydsp_faustpower2_f(fSlow453);
		double fSlow455 = 13.0 * fSlow357;
		double fSlow456 = (0.0 - 2.0 * fSlow453) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow455 + double(fSlow455 == 0.0)) + 13.0 * fSlow356));
		double fSlow457 = double(13.0 < fSlow366) * (fSlow365 + 0.07692307692307693 * fSlow364);
		double fSlow458 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.08333333333333333 * fSlow351)));
		double fSlow459 = mydsp_faustpower2_f(fSlow458);
		double fSlow460 = 12.0 * fSlow357;
		double fSlow461 = (0.0 - 2.0 * fSlow458) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow460 + double(fSlow460 == 0.0)) + 12.0 * fSlow356));
		double fSlow462 = double(12.0 < fSlow366) * (fSlow365 + 0.08333333333333333 * fSlow364);
		double fSlow463 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.09090909090909091 * fSlow351)));
		double fSlow464 = mydsp_faustpower2_f(fSlow463);
		double fSlow465 = 11.0 * fSlow357;
		double fSlow466 = (0.0 - 2.0 * fSlow463) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow465 + double(fSlow465 == 0.0)) + 11.0 * fSlow356));
		double fSlow467 = double(11.0 < fSlow366) * (fSlow365 + 0.09090909090909091 * fSlow364);
		double fSlow468 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.1 * fSlow351)));
		double fSlow469 = mydsp_faustpower2_f(fSlow468);
		double fSlow470 = 1e+01 * fSlow357;
		double fSlow471 = (0.0 - 2.0 * fSlow468) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow470 + double(fSlow470 == 0.0)) + 1e+01 * fSlow356));
		double fSlow472 = double(1e+01 < fSlow366) * (fSlow365 + 0.1 * fSlow364);
		double fSlow473 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.1111111111111111 * fSlow351)));
		double fSlow474 = mydsp_faustpower2_f(fSlow473);
		double fSlow475 = 9.0 * fSlow357;
		double fSlow476 = (0.0 - 2.0 * fSlow473) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow475 + double(fSlow475 == 0.0)) + 9.0 * fSlow356));
		double fSlow477 = double(9.0 < fSlow366) * (fSlow365 + 0.1111111111111111 * fSlow364);
		double fSlow478 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.125 * fSlow351)));
		double fSlow479 = mydsp_faustpower2_f(fSlow478);
		double fSlow480 = 8.0 * fSlow357;
		double fSlow481 = (0.0 - 2.0 * fSlow478) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow480 + double(fSlow480 == 0.0)) + 8.0 * fSlow356));
		double fSlow482 = double(8.0 < fSlow366) * (fSlow365 + 0.125 * fSlow364);
		double fSlow483 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.14285714285714285 * fSlow351)));
		double fSlow484 = mydsp_faustpower2_f(fSlow483);
		double fSlow485 = 7.0 * fSlow357;
		double fSlow486 = (0.0 - 2.0 * fSlow483) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow485 + double(fSlow485 == 0.0)) + 7.0 * fSlow356));
		double fSlow487 = double(7.0 < fSlow366) * (fSlow365 + 0.14285714285714285 * fSlow364);
		double fSlow488 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.16666666666666666 * fSlow351)));
		double fSlow489 = mydsp_faustpower2_f(fSlow488);
		double fSlow490 = 6.0 * fSlow357;
		double fSlow491 = (0.0 - 2.0 * fSlow488) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow490 + double(fSlow490 == 0.0)) + 6.0 * fSlow356));
		double fSlow492 = double(6.0 < fSlow366) * (fSlow365 + 0.16666666666666666 * fSlow364);
		double fSlow493 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.2 * fSlow351)));
		double fSlow494 = mydsp_faustpower2_f(fSlow493);
		double fSlow495 = 5.0 * fSlow357;
		double fSlow496 = (0.0 - 2.0 * fSlow493) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow495 + double(fSlow495 == 0.0)) + 5.0 * fSlow356));
		double fSlow497 = double(5.0 < fSlow366) * (fSlow365 + 0.2 * fSlow364);
		double fSlow498 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.25 * fSlow351)));
		double fSlow499 = mydsp_faustpower2_f(fSlow498);
		double fSlow500 = 4.0 * fSlow357;
		double fSlow501 = (0.0 - 2.0 * fSlow498) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow500 + double(fSlow500 == 0.0)) + 4.0 * fSlow356));
		double fSlow502 = double(4.0 < fSlow366) * (fSlow365 + 0.25 * fSlow364);
		double fSlow503 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.3333333333333333 * fSlow351)));
		double fSlow504 = mydsp_faustpower2_f(fSlow503);
		double fSlow505 = 3.0 * fSlow357;
		double fSlow506 = (0.0 - 2.0 * fSlow503) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow505 + double(fSlow505 == 0.0)) + 3.0 * fSlow356));
		double fSlow507 = double(3.0 < fSlow366) * (fSlow365 + 0.3333333333333333 * fSlow364);
		double fSlow508 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + 0.5 * fSlow351)));
		double fSlow509 = mydsp_faustpower2_f(fSlow508);
		double fSlow510 = 2.0 * fSlow357;
		double fSlow511 = (0.0 - 2.0 * fSlow508) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359 * (fSlow510 + double(fSlow510 == 0.0)) + 2.0 * fSlow356));
		double fSlow512 = double(2.0 < fSlow366) * (fSlow365 + 0.5 * fSlow364);
		double fSlow513 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + fSlow351)));
		double fSlow514 = mydsp_faustpower2_f(fSlow513);
		double fSlow515 = (0.0 - 2.0 * fSlow513) * std::cos(fConst3 * std::min<double>(fConst2, fSlow356 + fSlow359 * (fSlow357 + double(fSlow357 == 0.0))));
		double fSlow516 = double(1.0 < fSlow366) * (fSlow365 + fSlow364);
		double fSlow517 = std::pow(0.001, fConst1 / (fSlow353 * (fSlow352 + fSlow350)));
		double fSlow518 = mydsp_faustpower2_f(fSlow517);
		double fSlow519 = (0.0 - 2.0 * fSlow517) * std::cos(fConst3 * std::min<double>(fConst2, fSlow359));
		double fSlow520 = double(0.0 < fSlow366) * (fSlow365 + fSlow363);
		double fSlow521 = double(fVslider23);
		double fSlow522 = double(fVslider24);
		int iSlow523 = fSlow522 != 2.0;
		double fSlow524 = double(iSlow523);
		double fSlow525 = fSlow524 / fSlow522;
		double fSlow526 = double(1 - iSlow523);
		double fSlow527 = double(fVslider25);
		double fSlow528 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.03225806451612903 * fSlow525)));
		double fSlow529 = mydsp_faustpower2_f(fSlow528);
		double fSlow530 = double(fVslider26);
		double fSlow531 = double(fVslider27);
		double fSlow532 = 31.0 * fSlow531;
		double fSlow533 = double(fVslider28);
		double fSlow534 = (0.0 - 2.0 * fSlow528) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow532 + double(fSlow532 == 0.0)) + 31.0 * fSlow530));
		double fSlow535 = double(fVslider29);
		int iSlow536 = fSlow535 != 2.0;
		double fSlow537 = double(iSlow536);
		double fSlow538 = fSlow537 / fSlow535;
		double fSlow539 = double(1 - iSlow536);
		double fSlow540 = double(fVslider30);
		double fSlow541 = double(31.0 < fSlow540) * (fSlow539 + 0.03225806451612903 * fSlow538);
		double fSlow542 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.03333333333333333 * fSlow525)));
		double fSlow543 = mydsp_faustpower2_f(fSlow542);
		double fSlow544 = 3e+01 * fSlow531;
		double fSlow545 = (0.0 - 2.0 * fSlow542) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow544 + double(fSlow544 == 0.0)) + 3e+01 * fSlow530));
		double fSlow546 = double(3e+01 < fSlow540) * (fSlow539 + 0.03333333333333333 * fSlow538);
		double fSlow547 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.034482758620689655 * fSlow525)));
		double fSlow548 = mydsp_faustpower2_f(fSlow547);
		double fSlow549 = 29.0 * fSlow531;
		double fSlow550 = (0.0 - 2.0 * fSlow547) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow549 + double(fSlow549 == 0.0)) + 29.0 * fSlow530));
		double fSlow551 = double(29.0 < fSlow540) * (fSlow539 + 0.034482758620689655 * fSlow538);
		double fSlow552 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.03571428571428571 * fSlow525)));
		double fSlow553 = mydsp_faustpower2_f(fSlow552);
		double fSlow554 = 28.0 * fSlow531;
		double fSlow555 = (0.0 - 2.0 * fSlow552) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow554 + double(fSlow554 == 0.0)) + 28.0 * fSlow530));
		double fSlow556 = double(28.0 < fSlow540) * (fSlow539 + 0.03571428571428571 * fSlow538);
		double fSlow557 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.037037037037037035 * fSlow525)));
		double fSlow558 = mydsp_faustpower2_f(fSlow557);
		double fSlow559 = 27.0 * fSlow531;
		double fSlow560 = (0.0 - 2.0 * fSlow557) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow559 + double(fSlow559 == 0.0)) + 27.0 * fSlow530));
		double fSlow561 = double(27.0 < fSlow540) * (fSlow539 + 0.037037037037037035 * fSlow538);
		double fSlow562 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.038461538461538464 * fSlow525)));
		double fSlow563 = mydsp_faustpower2_f(fSlow562);
		double fSlow564 = 26.0 * fSlow531;
		double fSlow565 = (0.0 - 2.0 * fSlow562) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow564 + double(fSlow564 == 0.0)) + 26.0 * fSlow530));
		double fSlow566 = double(26.0 < fSlow540) * (fSlow539 + 0.038461538461538464 * fSlow538);
		double fSlow567 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.04 * fSlow525)));
		double fSlow568 = mydsp_faustpower2_f(fSlow567);
		double fSlow569 = 25.0 * fSlow531;
		double fSlow570 = (0.0 - 2.0 * fSlow567) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow569 + double(fSlow569 == 0.0)) + 25.0 * fSlow530));
		double fSlow571 = double(25.0 < fSlow540) * (fSlow539 + 0.04 * fSlow538);
		double fSlow572 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.041666666666666664 * fSlow525)));
		double fSlow573 = mydsp_faustpower2_f(fSlow572);
		double fSlow574 = 24.0 * fSlow531;
		double fSlow575 = (0.0 - 2.0 * fSlow572) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow574 + double(fSlow574 == 0.0)) + 24.0 * fSlow530));
		double fSlow576 = double(24.0 < fSlow540) * (fSlow539 + 0.041666666666666664 * fSlow538);
		double fSlow577 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.043478260869565216 * fSlow525)));
		double fSlow578 = mydsp_faustpower2_f(fSlow577);
		double fSlow579 = 23.0 * fSlow531;
		double fSlow580 = (0.0 - 2.0 * fSlow577) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow579 + double(fSlow579 == 0.0)) + 23.0 * fSlow530));
		double fSlow581 = double(23.0 < fSlow540) * (fSlow539 + 0.043478260869565216 * fSlow538);
		double fSlow582 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.045454545454545456 * fSlow525)));
		double fSlow583 = mydsp_faustpower2_f(fSlow582);
		double fSlow584 = 22.0 * fSlow531;
		double fSlow585 = (0.0 - 2.0 * fSlow582) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow584 + double(fSlow584 == 0.0)) + 22.0 * fSlow530));
		double fSlow586 = double(22.0 < fSlow540) * (fSlow539 + 0.045454545454545456 * fSlow538);
		double fSlow587 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.047619047619047616 * fSlow525)));
		double fSlow588 = mydsp_faustpower2_f(fSlow587);
		double fSlow589 = 21.0 * fSlow531;
		double fSlow590 = (0.0 - 2.0 * fSlow587) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow589 + double(fSlow589 == 0.0)) + 21.0 * fSlow530));
		double fSlow591 = double(21.0 < fSlow540) * (fSlow539 + 0.047619047619047616 * fSlow538);
		double fSlow592 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.05 * fSlow525)));
		double fSlow593 = mydsp_faustpower2_f(fSlow592);
		double fSlow594 = 2e+01 * fSlow531;
		double fSlow595 = (0.0 - 2.0 * fSlow592) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow594 + double(fSlow594 == 0.0)) + 2e+01 * fSlow530));
		double fSlow596 = double(2e+01 < fSlow540) * (fSlow539 + 0.05 * fSlow538);
		double fSlow597 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.05263157894736842 * fSlow525)));
		double fSlow598 = mydsp_faustpower2_f(fSlow597);
		double fSlow599 = 19.0 * fSlow531;
		double fSlow600 = (0.0 - 2.0 * fSlow597) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow599 + double(fSlow599 == 0.0)) + 19.0 * fSlow530));
		double fSlow601 = double(19.0 < fSlow540) * (fSlow539 + 0.05263157894736842 * fSlow538);
		double fSlow602 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.05555555555555555 * fSlow525)));
		double fSlow603 = mydsp_faustpower2_f(fSlow602);
		double fSlow604 = 18.0 * fSlow531;
		double fSlow605 = (0.0 - 2.0 * fSlow602) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow604 + double(fSlow604 == 0.0)) + 18.0 * fSlow530));
		double fSlow606 = double(18.0 < fSlow540) * (fSlow539 + 0.05555555555555555 * fSlow538);
		double fSlow607 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.058823529411764705 * fSlow525)));
		double fSlow608 = mydsp_faustpower2_f(fSlow607);
		double fSlow609 = 17.0 * fSlow531;
		double fSlow610 = (0.0 - 2.0 * fSlow607) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow609 + double(fSlow609 == 0.0)) + 17.0 * fSlow530));
		double fSlow611 = double(17.0 < fSlow540) * (fSlow539 + 0.058823529411764705 * fSlow538);
		double fSlow612 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.0625 * fSlow525)));
		double fSlow613 = mydsp_faustpower2_f(fSlow612);
		double fSlow614 = 16.0 * fSlow531;
		double fSlow615 = (0.0 - 2.0 * fSlow612) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow614 + double(fSlow614 == 0.0)) + 16.0 * fSlow530));
		double fSlow616 = double(16.0 < fSlow540) * (fSlow539 + 0.0625 * fSlow538);
		double fSlow617 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.06666666666666667 * fSlow525)));
		double fSlow618 = mydsp_faustpower2_f(fSlow617);
		double fSlow619 = 15.0 * fSlow531;
		double fSlow620 = (0.0 - 2.0 * fSlow617) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow619 + double(fSlow619 == 0.0)) + 15.0 * fSlow530));
		double fSlow621 = double(15.0 < fSlow540) * (fSlow539 + 0.06666666666666667 * fSlow538);
		double fSlow622 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.07142857142857142 * fSlow525)));
		double fSlow623 = mydsp_faustpower2_f(fSlow622);
		double fSlow624 = 14.0 * fSlow531;
		double fSlow625 = (0.0 - 2.0 * fSlow622) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow624 + double(fSlow624 == 0.0)) + 14.0 * fSlow530));
		double fSlow626 = double(14.0 < fSlow540) * (fSlow539 + 0.07142857142857142 * fSlow538);
		double fSlow627 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.07692307692307693 * fSlow525)));
		double fSlow628 = mydsp_faustpower2_f(fSlow627);
		double fSlow629 = 13.0 * fSlow531;
		double fSlow630 = (0.0 - 2.0 * fSlow627) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow629 + double(fSlow629 == 0.0)) + 13.0 * fSlow530));
		double fSlow631 = double(13.0 < fSlow540) * (fSlow539 + 0.07692307692307693 * fSlow538);
		double fSlow632 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.08333333333333333 * fSlow525)));
		double fSlow633 = mydsp_faustpower2_f(fSlow632);
		double fSlow634 = 12.0 * fSlow531;
		double fSlow635 = (0.0 - 2.0 * fSlow632) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow634 + double(fSlow634 == 0.0)) + 12.0 * fSlow530));
		double fSlow636 = double(12.0 < fSlow540) * (fSlow539 + 0.08333333333333333 * fSlow538);
		double fSlow637 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.09090909090909091 * fSlow525)));
		double fSlow638 = mydsp_faustpower2_f(fSlow637);
		double fSlow639 = 11.0 * fSlow531;
		double fSlow640 = (0.0 - 2.0 * fSlow637) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow639 + double(fSlow639 == 0.0)) + 11.0 * fSlow530));
		double fSlow641 = double(11.0 < fSlow540) * (fSlow539 + 0.09090909090909091 * fSlow538);
		double fSlow642 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.1 * fSlow525)));
		double fSlow643 = mydsp_faustpower2_f(fSlow642);
		double fSlow644 = 1e+01 * fSlow531;
		double fSlow645 = (0.0 - 2.0 * fSlow642) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow644 + double(fSlow644 == 0.0)) + 1e+01 * fSlow530));
		double fSlow646 = double(1e+01 < fSlow540) * (fSlow539 + 0.1 * fSlow538);
		double fSlow647 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.1111111111111111 * fSlow525)));
		double fSlow648 = mydsp_faustpower2_f(fSlow647);
		double fSlow649 = 9.0 * fSlow531;
		double fSlow650 = (0.0 - 2.0 * fSlow647) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow649 + double(fSlow649 == 0.0)) + 9.0 * fSlow530));
		double fSlow651 = double(9.0 < fSlow540) * (fSlow539 + 0.1111111111111111 * fSlow538);
		double fSlow652 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.125 * fSlow525)));
		double fSlow653 = mydsp_faustpower2_f(fSlow652);
		double fSlow654 = 8.0 * fSlow531;
		double fSlow655 = (0.0 - 2.0 * fSlow652) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow654 + double(fSlow654 == 0.0)) + 8.0 * fSlow530));
		double fSlow656 = double(8.0 < fSlow540) * (fSlow539 + 0.125 * fSlow538);
		double fSlow657 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.14285714285714285 * fSlow525)));
		double fSlow658 = mydsp_faustpower2_f(fSlow657);
		double fSlow659 = 7.0 * fSlow531;
		double fSlow660 = (0.0 - 2.0 * fSlow657) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow659 + double(fSlow659 == 0.0)) + 7.0 * fSlow530));
		double fSlow661 = double(7.0 < fSlow540) * (fSlow539 + 0.14285714285714285 * fSlow538);
		double fSlow662 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.16666666666666666 * fSlow525)));
		double fSlow663 = mydsp_faustpower2_f(fSlow662);
		double fSlow664 = 6.0 * fSlow531;
		double fSlow665 = (0.0 - 2.0 * fSlow662) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow664 + double(fSlow664 == 0.0)) + 6.0 * fSlow530));
		double fSlow666 = double(6.0 < fSlow540) * (fSlow539 + 0.16666666666666666 * fSlow538);
		double fSlow667 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.2 * fSlow525)));
		double fSlow668 = mydsp_faustpower2_f(fSlow667);
		double fSlow669 = 5.0 * fSlow531;
		double fSlow670 = (0.0 - 2.0 * fSlow667) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow669 + double(fSlow669 == 0.0)) + 5.0 * fSlow530));
		double fSlow671 = double(5.0 < fSlow540) * (fSlow539 + 0.2 * fSlow538);
		double fSlow672 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.25 * fSlow525)));
		double fSlow673 = mydsp_faustpower2_f(fSlow672);
		double fSlow674 = 4.0 * fSlow531;
		double fSlow675 = (0.0 - 2.0 * fSlow672) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow674 + double(fSlow674 == 0.0)) + 4.0 * fSlow530));
		double fSlow676 = double(4.0 < fSlow540) * (fSlow539 + 0.25 * fSlow538);
		double fSlow677 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.3333333333333333 * fSlow525)));
		double fSlow678 = mydsp_faustpower2_f(fSlow677);
		double fSlow679 = 3.0 * fSlow531;
		double fSlow680 = (0.0 - 2.0 * fSlow677) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow679 + double(fSlow679 == 0.0)) + 3.0 * fSlow530));
		double fSlow681 = double(3.0 < fSlow540) * (fSlow539 + 0.3333333333333333 * fSlow538);
		double fSlow682 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + 0.5 * fSlow525)));
		double fSlow683 = mydsp_faustpower2_f(fSlow682);
		double fSlow684 = 2.0 * fSlow531;
		double fSlow685 = (0.0 - 2.0 * fSlow682) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533 * (fSlow684 + double(fSlow684 == 0.0)) + 2.0 * fSlow530));
		double fSlow686 = double(2.0 < fSlow540) * (fSlow539 + 0.5 * fSlow538);
		double fSlow687 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + fSlow525)));
		double fSlow688 = mydsp_faustpower2_f(fSlow687);
		double fSlow689 = (0.0 - 2.0 * fSlow687) * std::cos(fConst3 * std::min<double>(fConst2, fSlow530 + fSlow533 * (fSlow531 + double(fSlow531 == 0.0))));
		double fSlow690 = double(1.0 < fSlow540) * (fSlow539 + fSlow538);
		double fSlow691 = std::pow(0.001, fConst1 / (fSlow527 * (fSlow526 + fSlow524)));
		double fSlow692 = mydsp_faustpower2_f(fSlow691);
		double fSlow693 = (0.0 - 2.0 * fSlow691) * std::cos(fConst3 * std::min<double>(fConst2, fSlow533));
		double fSlow694 = double(0.0 < fSlow540) * (fSlow539 + fSlow537);
		double fSlow695 = double(fVslider31);
		double fSlow696 = double(fVslider32);
		int iSlow697 = fSlow696 != 2.0;
		double fSlow698 = double(iSlow697);
		double fSlow699 = fSlow698 / fSlow696;
		double fSlow700 = double(1 - iSlow697);
		double fSlow701 = double(fVslider33);
		double fSlow702 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.03225806451612903 * fSlow699)));
		double fSlow703 = mydsp_faustpower2_f(fSlow702);
		double fSlow704 = double(fVslider34);
		double fSlow705 = double(fVslider35);
		double fSlow706 = 31.0 * fSlow705;
		double fSlow707 = double(fVslider36);
		double fSlow708 = (0.0 - 2.0 * fSlow702) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow706 + double(fSlow706 == 0.0)) + 31.0 * fSlow704));
		double fSlow709 = double(fVslider37);
		int iSlow710 = fSlow709 != 2.0;
		double fSlow711 = double(iSlow710);
		double fSlow712 = fSlow711 / fSlow709;
		double fSlow713 = double(1 - iSlow710);
		double fSlow714 = double(fVslider38);
		double fSlow715 = double(31.0 < fSlow714) * (fSlow713 + 0.03225806451612903 * fSlow712);
		double fSlow716 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.03333333333333333 * fSlow699)));
		double fSlow717 = mydsp_faustpower2_f(fSlow716);
		double fSlow718 = 3e+01 * fSlow705;
		double fSlow719 = (0.0 - 2.0 * fSlow716) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow718 + double(fSlow718 == 0.0)) + 3e+01 * fSlow704));
		double fSlow720 = double(3e+01 < fSlow714) * (fSlow713 + 0.03333333333333333 * fSlow712);
		double fSlow721 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.034482758620689655 * fSlow699)));
		double fSlow722 = mydsp_faustpower2_f(fSlow721);
		double fSlow723 = 29.0 * fSlow705;
		double fSlow724 = (0.0 - 2.0 * fSlow721) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow723 + double(fSlow723 == 0.0)) + 29.0 * fSlow704));
		double fSlow725 = double(29.0 < fSlow714) * (fSlow713 + 0.034482758620689655 * fSlow712);
		double fSlow726 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.03571428571428571 * fSlow699)));
		double fSlow727 = mydsp_faustpower2_f(fSlow726);
		double fSlow728 = 28.0 * fSlow705;
		double fSlow729 = (0.0 - 2.0 * fSlow726) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow728 + double(fSlow728 == 0.0)) + 28.0 * fSlow704));
		double fSlow730 = double(28.0 < fSlow714) * (fSlow713 + 0.03571428571428571 * fSlow712);
		double fSlow731 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.037037037037037035 * fSlow699)));
		double fSlow732 = mydsp_faustpower2_f(fSlow731);
		double fSlow733 = 27.0 * fSlow705;
		double fSlow734 = (0.0 - 2.0 * fSlow731) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow733 + double(fSlow733 == 0.0)) + 27.0 * fSlow704));
		double fSlow735 = double(27.0 < fSlow714) * (fSlow713 + 0.037037037037037035 * fSlow712);
		double fSlow736 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.038461538461538464 * fSlow699)));
		double fSlow737 = mydsp_faustpower2_f(fSlow736);
		double fSlow738 = 26.0 * fSlow705;
		double fSlow739 = (0.0 - 2.0 * fSlow736) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow738 + double(fSlow738 == 0.0)) + 26.0 * fSlow704));
		double fSlow740 = double(26.0 < fSlow714) * (fSlow713 + 0.038461538461538464 * fSlow712);
		double fSlow741 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.04 * fSlow699)));
		double fSlow742 = mydsp_faustpower2_f(fSlow741);
		double fSlow743 = 25.0 * fSlow705;
		double fSlow744 = (0.0 - 2.0 * fSlow741) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow743 + double(fSlow743 == 0.0)) + 25.0 * fSlow704));
		double fSlow745 = double(25.0 < fSlow714) * (fSlow713 + 0.04 * fSlow712);
		double fSlow746 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.041666666666666664 * fSlow699)));
		double fSlow747 = mydsp_faustpower2_f(fSlow746);
		double fSlow748 = 24.0 * fSlow705;
		double fSlow749 = (0.0 - 2.0 * fSlow746) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow748 + double(fSlow748 == 0.0)) + 24.0 * fSlow704));
		double fSlow750 = double(24.0 < fSlow714) * (fSlow713 + 0.041666666666666664 * fSlow712);
		double fSlow751 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.043478260869565216 * fSlow699)));
		double fSlow752 = mydsp_faustpower2_f(fSlow751);
		double fSlow753 = 23.0 * fSlow705;
		double fSlow754 = (0.0 - 2.0 * fSlow751) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow753 + double(fSlow753 == 0.0)) + 23.0 * fSlow704));
		double fSlow755 = double(23.0 < fSlow714) * (fSlow713 + 0.043478260869565216 * fSlow712);
		double fSlow756 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.045454545454545456 * fSlow699)));
		double fSlow757 = mydsp_faustpower2_f(fSlow756);
		double fSlow758 = 22.0 * fSlow705;
		double fSlow759 = (0.0 - 2.0 * fSlow756) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow758 + double(fSlow758 == 0.0)) + 22.0 * fSlow704));
		double fSlow760 = double(22.0 < fSlow714) * (fSlow713 + 0.045454545454545456 * fSlow712);
		double fSlow761 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.047619047619047616 * fSlow699)));
		double fSlow762 = mydsp_faustpower2_f(fSlow761);
		double fSlow763 = 21.0 * fSlow705;
		double fSlow764 = (0.0 - 2.0 * fSlow761) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow763 + double(fSlow763 == 0.0)) + 21.0 * fSlow704));
		double fSlow765 = double(21.0 < fSlow714) * (fSlow713 + 0.047619047619047616 * fSlow712);
		double fSlow766 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.05 * fSlow699)));
		double fSlow767 = mydsp_faustpower2_f(fSlow766);
		double fSlow768 = 2e+01 * fSlow705;
		double fSlow769 = (0.0 - 2.0 * fSlow766) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow768 + double(fSlow768 == 0.0)) + 2e+01 * fSlow704));
		double fSlow770 = double(2e+01 < fSlow714) * (fSlow713 + 0.05 * fSlow712);
		double fSlow771 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.05263157894736842 * fSlow699)));
		double fSlow772 = mydsp_faustpower2_f(fSlow771);
		double fSlow773 = 19.0 * fSlow705;
		double fSlow774 = (0.0 - 2.0 * fSlow771) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow773 + double(fSlow773 == 0.0)) + 19.0 * fSlow704));
		double fSlow775 = double(19.0 < fSlow714) * (fSlow713 + 0.05263157894736842 * fSlow712);
		double fSlow776 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.05555555555555555 * fSlow699)));
		double fSlow777 = mydsp_faustpower2_f(fSlow776);
		double fSlow778 = 18.0 * fSlow705;
		double fSlow779 = (0.0 - 2.0 * fSlow776) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow778 + double(fSlow778 == 0.0)) + 18.0 * fSlow704));
		double fSlow780 = double(18.0 < fSlow714) * (fSlow713 + 0.05555555555555555 * fSlow712);
		double fSlow781 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.058823529411764705 * fSlow699)));
		double fSlow782 = mydsp_faustpower2_f(fSlow781);
		double fSlow783 = 17.0 * fSlow705;
		double fSlow784 = (0.0 - 2.0 * fSlow781) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow783 + double(fSlow783 == 0.0)) + 17.0 * fSlow704));
		double fSlow785 = double(17.0 < fSlow714) * (fSlow713 + 0.058823529411764705 * fSlow712);
		double fSlow786 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.0625 * fSlow699)));
		double fSlow787 = mydsp_faustpower2_f(fSlow786);
		double fSlow788 = 16.0 * fSlow705;
		double fSlow789 = (0.0 - 2.0 * fSlow786) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow788 + double(fSlow788 == 0.0)) + 16.0 * fSlow704));
		double fSlow790 = double(16.0 < fSlow714) * (fSlow713 + 0.0625 * fSlow712);
		double fSlow791 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.06666666666666667 * fSlow699)));
		double fSlow792 = mydsp_faustpower2_f(fSlow791);
		double fSlow793 = 15.0 * fSlow705;
		double fSlow794 = (0.0 - 2.0 * fSlow791) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow793 + double(fSlow793 == 0.0)) + 15.0 * fSlow704));
		double fSlow795 = double(15.0 < fSlow714) * (fSlow713 + 0.06666666666666667 * fSlow712);
		double fSlow796 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.07142857142857142 * fSlow699)));
		double fSlow797 = mydsp_faustpower2_f(fSlow796);
		double fSlow798 = 14.0 * fSlow705;
		double fSlow799 = (0.0 - 2.0 * fSlow796) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow798 + double(fSlow798 == 0.0)) + 14.0 * fSlow704));
		double fSlow800 = double(14.0 < fSlow714) * (fSlow713 + 0.07142857142857142 * fSlow712);
		double fSlow801 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.07692307692307693 * fSlow699)));
		double fSlow802 = mydsp_faustpower2_f(fSlow801);
		double fSlow803 = 13.0 * fSlow705;
		double fSlow804 = (0.0 - 2.0 * fSlow801) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow803 + double(fSlow803 == 0.0)) + 13.0 * fSlow704));
		double fSlow805 = double(13.0 < fSlow714) * (fSlow713 + 0.07692307692307693 * fSlow712);
		double fSlow806 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.08333333333333333 * fSlow699)));
		double fSlow807 = mydsp_faustpower2_f(fSlow806);
		double fSlow808 = 12.0 * fSlow705;
		double fSlow809 = (0.0 - 2.0 * fSlow806) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow808 + double(fSlow808 == 0.0)) + 12.0 * fSlow704));
		double fSlow810 = double(12.0 < fSlow714) * (fSlow713 + 0.08333333333333333 * fSlow712);
		double fSlow811 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.09090909090909091 * fSlow699)));
		double fSlow812 = mydsp_faustpower2_f(fSlow811);
		double fSlow813 = 11.0 * fSlow705;
		double fSlow814 = (0.0 - 2.0 * fSlow811) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow813 + double(fSlow813 == 0.0)) + 11.0 * fSlow704));
		double fSlow815 = double(11.0 < fSlow714) * (fSlow713 + 0.09090909090909091 * fSlow712);
		double fSlow816 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.1 * fSlow699)));
		double fSlow817 = mydsp_faustpower2_f(fSlow816);
		double fSlow818 = 1e+01 * fSlow705;
		double fSlow819 = (0.0 - 2.0 * fSlow816) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow818 + double(fSlow818 == 0.0)) + 1e+01 * fSlow704));
		double fSlow820 = double(1e+01 < fSlow714) * (fSlow713 + 0.1 * fSlow712);
		double fSlow821 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.1111111111111111 * fSlow699)));
		double fSlow822 = mydsp_faustpower2_f(fSlow821);
		double fSlow823 = 9.0 * fSlow705;
		double fSlow824 = (0.0 - 2.0 * fSlow821) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow823 + double(fSlow823 == 0.0)) + 9.0 * fSlow704));
		double fSlow825 = double(9.0 < fSlow714) * (fSlow713 + 0.1111111111111111 * fSlow712);
		double fSlow826 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.125 * fSlow699)));
		double fSlow827 = mydsp_faustpower2_f(fSlow826);
		double fSlow828 = 8.0 * fSlow705;
		double fSlow829 = (0.0 - 2.0 * fSlow826) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow828 + double(fSlow828 == 0.0)) + 8.0 * fSlow704));
		double fSlow830 = double(8.0 < fSlow714) * (fSlow713 + 0.125 * fSlow712);
		double fSlow831 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.14285714285714285 * fSlow699)));
		double fSlow832 = mydsp_faustpower2_f(fSlow831);
		double fSlow833 = 7.0 * fSlow705;
		double fSlow834 = (0.0 - 2.0 * fSlow831) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow833 + double(fSlow833 == 0.0)) + 7.0 * fSlow704));
		double fSlow835 = double(7.0 < fSlow714) * (fSlow713 + 0.14285714285714285 * fSlow712);
		double fSlow836 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.16666666666666666 * fSlow699)));
		double fSlow837 = mydsp_faustpower2_f(fSlow836);
		double fSlow838 = 6.0 * fSlow705;
		double fSlow839 = (0.0 - 2.0 * fSlow836) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow838 + double(fSlow838 == 0.0)) + 6.0 * fSlow704));
		double fSlow840 = double(6.0 < fSlow714) * (fSlow713 + 0.16666666666666666 * fSlow712);
		double fSlow841 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.2 * fSlow699)));
		double fSlow842 = mydsp_faustpower2_f(fSlow841);
		double fSlow843 = 5.0 * fSlow705;
		double fSlow844 = (0.0 - 2.0 * fSlow841) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow843 + double(fSlow843 == 0.0)) + 5.0 * fSlow704));
		double fSlow845 = double(5.0 < fSlow714) * (fSlow713 + 0.2 * fSlow712);
		double fSlow846 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.25 * fSlow699)));
		double fSlow847 = mydsp_faustpower2_f(fSlow846);
		double fSlow848 = 4.0 * fSlow705;
		double fSlow849 = (0.0 - 2.0 * fSlow846) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow848 + double(fSlow848 == 0.0)) + 4.0 * fSlow704));
		double fSlow850 = double(4.0 < fSlow714) * (fSlow713 + 0.25 * fSlow712);
		double fSlow851 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.3333333333333333 * fSlow699)));
		double fSlow852 = mydsp_faustpower2_f(fSlow851);
		double fSlow853 = 3.0 * fSlow705;
		double fSlow854 = (0.0 - 2.0 * fSlow851) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow853 + double(fSlow853 == 0.0)) + 3.0 * fSlow704));
		double fSlow855 = double(3.0 < fSlow714) * (fSlow713 + 0.3333333333333333 * fSlow712);
		double fSlow856 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + 0.5 * fSlow699)));
		double fSlow857 = mydsp_faustpower2_f(fSlow856);
		double fSlow858 = 2.0 * fSlow705;
		double fSlow859 = (0.0 - 2.0 * fSlow856) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707 * (fSlow858 + double(fSlow858 == 0.0)) + 2.0 * fSlow704));
		double fSlow860 = double(2.0 < fSlow714) * (fSlow713 + 0.5 * fSlow712);
		double fSlow861 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + fSlow699)));
		double fSlow862 = mydsp_faustpower2_f(fSlow861);
		double fSlow863 = (0.0 - 2.0 * fSlow861) * std::cos(fConst3 * std::min<double>(fConst2, fSlow704 + fSlow707 * (fSlow705 + double(fSlow705 == 0.0))));
		double fSlow864 = double(1.0 < fSlow714) * (fSlow713 + fSlow712);
		double fSlow865 = std::pow(0.001, fConst1 / (fSlow701 * (fSlow700 + fSlow698)));
		double fSlow866 = mydsp_faustpower2_f(fSlow865);
		double fSlow867 = (0.0 - 2.0 * fSlow865) * std::cos(fConst3 * std::min<double>(fConst2, fSlow707));
		double fSlow868 = double(0.0 < fSlow714) * (fSlow713 + fSlow711);
		double fSlow869 = double(fVslider39);
		double fSlow870 = double(fVslider40);
		int iSlow871 = fSlow870 != 2.0;
		double fSlow872 = double(iSlow871);
		double fSlow873 = fSlow872 / fSlow870;
		double fSlow874 = double(1 - iSlow871);
		double fSlow875 = double(fVslider41);
		double fSlow876 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.03225806451612903 * fSlow873)));
		double fSlow877 = mydsp_faustpower2_f(fSlow876);
		double fSlow878 = double(fVslider42);
		double fSlow879 = double(fVslider43);
		double fSlow880 = 31.0 * fSlow879;
		double fSlow881 = double(fVslider44);
		double fSlow882 = (0.0 - 2.0 * fSlow876) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow880 + double(fSlow880 == 0.0)) + 31.0 * fSlow878));
		double fSlow883 = double(fVslider45);
		int iSlow884 = fSlow883 != 2.0;
		double fSlow885 = double(iSlow884);
		double fSlow886 = fSlow885 / fSlow883;
		double fSlow887 = double(1 - iSlow884);
		double fSlow888 = double(fVslider46);
		double fSlow889 = double(31.0 < fSlow888) * (fSlow887 + 0.03225806451612903 * fSlow886);
		double fSlow890 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.03333333333333333 * fSlow873)));
		double fSlow891 = mydsp_faustpower2_f(fSlow890);
		double fSlow892 = 3e+01 * fSlow879;
		double fSlow893 = (0.0 - 2.0 * fSlow890) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow892 + double(fSlow892 == 0.0)) + 3e+01 * fSlow878));
		double fSlow894 = double(3e+01 < fSlow888) * (fSlow887 + 0.03333333333333333 * fSlow886);
		double fSlow895 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.034482758620689655 * fSlow873)));
		double fSlow896 = mydsp_faustpower2_f(fSlow895);
		double fSlow897 = 29.0 * fSlow879;
		double fSlow898 = (0.0 - 2.0 * fSlow895) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow897 + double(fSlow897 == 0.0)) + 29.0 * fSlow878));
		double fSlow899 = double(29.0 < fSlow888) * (fSlow887 + 0.034482758620689655 * fSlow886);
		double fSlow900 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.03571428571428571 * fSlow873)));
		double fSlow901 = mydsp_faustpower2_f(fSlow900);
		double fSlow902 = 28.0 * fSlow879;
		double fSlow903 = (0.0 - 2.0 * fSlow900) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow902 + double(fSlow902 == 0.0)) + 28.0 * fSlow878));
		double fSlow904 = double(28.0 < fSlow888) * (fSlow887 + 0.03571428571428571 * fSlow886);
		double fSlow905 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.037037037037037035 * fSlow873)));
		double fSlow906 = mydsp_faustpower2_f(fSlow905);
		double fSlow907 = 27.0 * fSlow879;
		double fSlow908 = (0.0 - 2.0 * fSlow905) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow907 + double(fSlow907 == 0.0)) + 27.0 * fSlow878));
		double fSlow909 = double(27.0 < fSlow888) * (fSlow887 + 0.037037037037037035 * fSlow886);
		double fSlow910 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.038461538461538464 * fSlow873)));
		double fSlow911 = mydsp_faustpower2_f(fSlow910);
		double fSlow912 = 26.0 * fSlow879;
		double fSlow913 = (0.0 - 2.0 * fSlow910) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow912 + double(fSlow912 == 0.0)) + 26.0 * fSlow878));
		double fSlow914 = double(26.0 < fSlow888) * (fSlow887 + 0.038461538461538464 * fSlow886);
		double fSlow915 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.04 * fSlow873)));
		double fSlow916 = mydsp_faustpower2_f(fSlow915);
		double fSlow917 = 25.0 * fSlow879;
		double fSlow918 = (0.0 - 2.0 * fSlow915) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow917 + double(fSlow917 == 0.0)) + 25.0 * fSlow878));
		double fSlow919 = double(25.0 < fSlow888) * (fSlow887 + 0.04 * fSlow886);
		double fSlow920 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.041666666666666664 * fSlow873)));
		double fSlow921 = mydsp_faustpower2_f(fSlow920);
		double fSlow922 = 24.0 * fSlow879;
		double fSlow923 = (0.0 - 2.0 * fSlow920) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow922 + double(fSlow922 == 0.0)) + 24.0 * fSlow878));
		double fSlow924 = double(24.0 < fSlow888) * (fSlow887 + 0.041666666666666664 * fSlow886);
		double fSlow925 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.043478260869565216 * fSlow873)));
		double fSlow926 = mydsp_faustpower2_f(fSlow925);
		double fSlow927 = 23.0 * fSlow879;
		double fSlow928 = (0.0 - 2.0 * fSlow925) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow927 + double(fSlow927 == 0.0)) + 23.0 * fSlow878));
		double fSlow929 = double(23.0 < fSlow888) * (fSlow887 + 0.043478260869565216 * fSlow886);
		double fSlow930 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.045454545454545456 * fSlow873)));
		double fSlow931 = mydsp_faustpower2_f(fSlow930);
		double fSlow932 = 22.0 * fSlow879;
		double fSlow933 = (0.0 - 2.0 * fSlow930) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow932 + double(fSlow932 == 0.0)) + 22.0 * fSlow878));
		double fSlow934 = double(22.0 < fSlow888) * (fSlow887 + 0.045454545454545456 * fSlow886);
		double fSlow935 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.047619047619047616 * fSlow873)));
		double fSlow936 = mydsp_faustpower2_f(fSlow935);
		double fSlow937 = 21.0 * fSlow879;
		double fSlow938 = (0.0 - 2.0 * fSlow935) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow937 + double(fSlow937 == 0.0)) + 21.0 * fSlow878));
		double fSlow939 = double(21.0 < fSlow888) * (fSlow887 + 0.047619047619047616 * fSlow886);
		double fSlow940 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.05 * fSlow873)));
		double fSlow941 = mydsp_faustpower2_f(fSlow940);
		double fSlow942 = 2e+01 * fSlow879;
		double fSlow943 = (0.0 - 2.0 * fSlow940) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow942 + double(fSlow942 == 0.0)) + 2e+01 * fSlow878));
		double fSlow944 = double(2e+01 < fSlow888) * (fSlow887 + 0.05 * fSlow886);
		double fSlow945 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.05263157894736842 * fSlow873)));
		double fSlow946 = mydsp_faustpower2_f(fSlow945);
		double fSlow947 = 19.0 * fSlow879;
		double fSlow948 = (0.0 - 2.0 * fSlow945) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow947 + double(fSlow947 == 0.0)) + 19.0 * fSlow878));
		double fSlow949 = double(19.0 < fSlow888) * (fSlow887 + 0.05263157894736842 * fSlow886);
		double fSlow950 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.05555555555555555 * fSlow873)));
		double fSlow951 = mydsp_faustpower2_f(fSlow950);
		double fSlow952 = 18.0 * fSlow879;
		double fSlow953 = (0.0 - 2.0 * fSlow950) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow952 + double(fSlow952 == 0.0)) + 18.0 * fSlow878));
		double fSlow954 = double(18.0 < fSlow888) * (fSlow887 + 0.05555555555555555 * fSlow886);
		double fSlow955 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.058823529411764705 * fSlow873)));
		double fSlow956 = mydsp_faustpower2_f(fSlow955);
		double fSlow957 = 17.0 * fSlow879;
		double fSlow958 = (0.0 - 2.0 * fSlow955) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow957 + double(fSlow957 == 0.0)) + 17.0 * fSlow878));
		double fSlow959 = double(17.0 < fSlow888) * (fSlow887 + 0.058823529411764705 * fSlow886);
		double fSlow960 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.0625 * fSlow873)));
		double fSlow961 = mydsp_faustpower2_f(fSlow960);
		double fSlow962 = 16.0 * fSlow879;
		double fSlow963 = (0.0 - 2.0 * fSlow960) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow962 + double(fSlow962 == 0.0)) + 16.0 * fSlow878));
		double fSlow964 = double(16.0 < fSlow888) * (fSlow887 + 0.0625 * fSlow886);
		double fSlow965 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.06666666666666667 * fSlow873)));
		double fSlow966 = mydsp_faustpower2_f(fSlow965);
		double fSlow967 = 15.0 * fSlow879;
		double fSlow968 = (0.0 - 2.0 * fSlow965) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow967 + double(fSlow967 == 0.0)) + 15.0 * fSlow878));
		double fSlow969 = double(15.0 < fSlow888) * (fSlow887 + 0.06666666666666667 * fSlow886);
		double fSlow970 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.07142857142857142 * fSlow873)));
		double fSlow971 = mydsp_faustpower2_f(fSlow970);
		double fSlow972 = 14.0 * fSlow879;
		double fSlow973 = (0.0 - 2.0 * fSlow970) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow972 + double(fSlow972 == 0.0)) + 14.0 * fSlow878));
		double fSlow974 = double(14.0 < fSlow888) * (fSlow887 + 0.07142857142857142 * fSlow886);
		double fSlow975 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.07692307692307693 * fSlow873)));
		double fSlow976 = mydsp_faustpower2_f(fSlow975);
		double fSlow977 = 13.0 * fSlow879;
		double fSlow978 = (0.0 - 2.0 * fSlow975) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow977 + double(fSlow977 == 0.0)) + 13.0 * fSlow878));
		double fSlow979 = double(13.0 < fSlow888) * (fSlow887 + 0.07692307692307693 * fSlow886);
		double fSlow980 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.08333333333333333 * fSlow873)));
		double fSlow981 = mydsp_faustpower2_f(fSlow980);
		double fSlow982 = 12.0 * fSlow879;
		double fSlow983 = (0.0 - 2.0 * fSlow980) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow982 + double(fSlow982 == 0.0)) + 12.0 * fSlow878));
		double fSlow984 = double(12.0 < fSlow888) * (fSlow887 + 0.08333333333333333 * fSlow886);
		double fSlow985 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.09090909090909091 * fSlow873)));
		double fSlow986 = mydsp_faustpower2_f(fSlow985);
		double fSlow987 = 11.0 * fSlow879;
		double fSlow988 = (0.0 - 2.0 * fSlow985) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow987 + double(fSlow987 == 0.0)) + 11.0 * fSlow878));
		double fSlow989 = double(11.0 < fSlow888) * (fSlow887 + 0.09090909090909091 * fSlow886);
		double fSlow990 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.1 * fSlow873)));
		double fSlow991 = mydsp_faustpower2_f(fSlow990);
		double fSlow992 = 1e+01 * fSlow879;
		double fSlow993 = (0.0 - 2.0 * fSlow990) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow992 + double(fSlow992 == 0.0)) + 1e+01 * fSlow878));
		double fSlow994 = double(1e+01 < fSlow888) * (fSlow887 + 0.1 * fSlow886);
		double fSlow995 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.1111111111111111 * fSlow873)));
		double fSlow996 = mydsp_faustpower2_f(fSlow995);
		double fSlow997 = 9.0 * fSlow879;
		double fSlow998 = (0.0 - 2.0 * fSlow995) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow997 + double(fSlow997 == 0.0)) + 9.0 * fSlow878));
		double fSlow999 = double(9.0 < fSlow888) * (fSlow887 + 0.1111111111111111 * fSlow886);
		double fSlow1000 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.125 * fSlow873)));
		double fSlow1001 = mydsp_faustpower2_f(fSlow1000);
		double fSlow1002 = 8.0 * fSlow879;
		double fSlow1003 = (0.0 - 2.0 * fSlow1000) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow1002 + double(fSlow1002 == 0.0)) + 8.0 * fSlow878));
		double fSlow1004 = double(8.0 < fSlow888) * (fSlow887 + 0.125 * fSlow886);
		double fSlow1005 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.14285714285714285 * fSlow873)));
		double fSlow1006 = mydsp_faustpower2_f(fSlow1005);
		double fSlow1007 = 7.0 * fSlow879;
		double fSlow1008 = (0.0 - 2.0 * fSlow1005) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow1007 + double(fSlow1007 == 0.0)) + 7.0 * fSlow878));
		double fSlow1009 = double(7.0 < fSlow888) * (fSlow887 + 0.14285714285714285 * fSlow886);
		double fSlow1010 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.16666666666666666 * fSlow873)));
		double fSlow1011 = mydsp_faustpower2_f(fSlow1010);
		double fSlow1012 = 6.0 * fSlow879;
		double fSlow1013 = (0.0 - 2.0 * fSlow1010) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow1012 + double(fSlow1012 == 0.0)) + 6.0 * fSlow878));
		double fSlow1014 = double(6.0 < fSlow888) * (fSlow887 + 0.16666666666666666 * fSlow886);
		double fSlow1015 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.2 * fSlow873)));
		double fSlow1016 = mydsp_faustpower2_f(fSlow1015);
		double fSlow1017 = 5.0 * fSlow879;
		double fSlow1018 = (0.0 - 2.0 * fSlow1015) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow1017 + double(fSlow1017 == 0.0)) + 5.0 * fSlow878));
		double fSlow1019 = double(5.0 < fSlow888) * (fSlow887 + 0.2 * fSlow886);
		double fSlow1020 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.25 * fSlow873)));
		double fSlow1021 = mydsp_faustpower2_f(fSlow1020);
		double fSlow1022 = 4.0 * fSlow879;
		double fSlow1023 = (0.0 - 2.0 * fSlow1020) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow1022 + double(fSlow1022 == 0.0)) + 4.0 * fSlow878));
		double fSlow1024 = double(4.0 < fSlow888) * (fSlow887 + 0.25 * fSlow886);
		double fSlow1025 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.3333333333333333 * fSlow873)));
		double fSlow1026 = mydsp_faustpower2_f(fSlow1025);
		double fSlow1027 = 3.0 * fSlow879;
		double fSlow1028 = (0.0 - 2.0 * fSlow1025) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow1027 + double(fSlow1027 == 0.0)) + 3.0 * fSlow878));
		double fSlow1029 = double(3.0 < fSlow888) * (fSlow887 + 0.3333333333333333 * fSlow886);
		double fSlow1030 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + 0.5 * fSlow873)));
		double fSlow1031 = mydsp_faustpower2_f(fSlow1030);
		double fSlow1032 = 2.0 * fSlow879;
		double fSlow1033 = (0.0 - 2.0 * fSlow1030) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881 * (fSlow1032 + double(fSlow1032 == 0.0)) + 2.0 * fSlow878));
		double fSlow1034 = double(2.0 < fSlow888) * (fSlow887 + 0.5 * fSlow886);
		double fSlow1035 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + fSlow873)));
		double fSlow1036 = mydsp_faustpower2_f(fSlow1035);
		double fSlow1037 = (0.0 - 2.0 * fSlow1035) * std::cos(fConst3 * std::min<double>(fConst2, fSlow878 + fSlow881 * (fSlow879 + double(fSlow879 == 0.0))));
		double fSlow1038 = double(1.0 < fSlow888) * (fSlow887 + fSlow886);
		double fSlow1039 = std::pow(0.001, fConst1 / (fSlow875 * (fSlow874 + fSlow872)));
		double fSlow1040 = mydsp_faustpower2_f(fSlow1039);
		double fSlow1041 = (0.0 - 2.0 * fSlow1039) * std::cos(fConst3 * std::min<double>(fConst2, fSlow881));
		double fSlow1042 = double(0.0 < fSlow888) * (fSlow887 + fSlow885);
		double fSlow1043 = double(fVslider47);
		double fSlow1044 = double(fVslider48);
		int iSlow1045 = fSlow1044 != 2.0;
		double fSlow1046 = double(iSlow1045);
		double fSlow1047 = fSlow1046 / fSlow1044;
		double fSlow1048 = double(1 - iSlow1045);
		double fSlow1049 = double(fVslider49);
		double fSlow1050 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.03225806451612903 * fSlow1047)));
		double fSlow1051 = mydsp_faustpower2_f(fSlow1050);
		double fSlow1052 = double(fVslider50);
		double fSlow1053 = double(fVslider51);
		double fSlow1054 = 31.0 * fSlow1053;
		double fSlow1055 = double(fVslider52);
		double fSlow1056 = (0.0 - 2.0 * fSlow1050) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1054 + double(fSlow1054 == 0.0)) + 31.0 * fSlow1052));
		double fSlow1057 = double(fVslider53);
		int iSlow1058 = fSlow1057 != 2.0;
		double fSlow1059 = double(iSlow1058);
		double fSlow1060 = fSlow1059 / fSlow1057;
		double fSlow1061 = double(1 - iSlow1058);
		double fSlow1062 = double(fVslider54);
		double fSlow1063 = double(31.0 < fSlow1062) * (fSlow1061 + 0.03225806451612903 * fSlow1060);
		double fSlow1064 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.03333333333333333 * fSlow1047)));
		double fSlow1065 = mydsp_faustpower2_f(fSlow1064);
		double fSlow1066 = 3e+01 * fSlow1053;
		double fSlow1067 = (0.0 - 2.0 * fSlow1064) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1066 + double(fSlow1066 == 0.0)) + 3e+01 * fSlow1052));
		double fSlow1068 = double(3e+01 < fSlow1062) * (fSlow1061 + 0.03333333333333333 * fSlow1060);
		double fSlow1069 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.034482758620689655 * fSlow1047)));
		double fSlow1070 = mydsp_faustpower2_f(fSlow1069);
		double fSlow1071 = 29.0 * fSlow1053;
		double fSlow1072 = (0.0 - 2.0 * fSlow1069) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1071 + double(fSlow1071 == 0.0)) + 29.0 * fSlow1052));
		double fSlow1073 = double(29.0 < fSlow1062) * (fSlow1061 + 0.034482758620689655 * fSlow1060);
		double fSlow1074 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.03571428571428571 * fSlow1047)));
		double fSlow1075 = mydsp_faustpower2_f(fSlow1074);
		double fSlow1076 = 28.0 * fSlow1053;
		double fSlow1077 = (0.0 - 2.0 * fSlow1074) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1076 + double(fSlow1076 == 0.0)) + 28.0 * fSlow1052));
		double fSlow1078 = double(28.0 < fSlow1062) * (fSlow1061 + 0.03571428571428571 * fSlow1060);
		double fSlow1079 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.037037037037037035 * fSlow1047)));
		double fSlow1080 = mydsp_faustpower2_f(fSlow1079);
		double fSlow1081 = 27.0 * fSlow1053;
		double fSlow1082 = (0.0 - 2.0 * fSlow1079) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1081 + double(fSlow1081 == 0.0)) + 27.0 * fSlow1052));
		double fSlow1083 = double(27.0 < fSlow1062) * (fSlow1061 + 0.037037037037037035 * fSlow1060);
		double fSlow1084 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.038461538461538464 * fSlow1047)));
		double fSlow1085 = mydsp_faustpower2_f(fSlow1084);
		double fSlow1086 = 26.0 * fSlow1053;
		double fSlow1087 = (0.0 - 2.0 * fSlow1084) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1086 + double(fSlow1086 == 0.0)) + 26.0 * fSlow1052));
		double fSlow1088 = double(26.0 < fSlow1062) * (fSlow1061 + 0.038461538461538464 * fSlow1060);
		double fSlow1089 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.04 * fSlow1047)));
		double fSlow1090 = mydsp_faustpower2_f(fSlow1089);
		double fSlow1091 = 25.0 * fSlow1053;
		double fSlow1092 = (0.0 - 2.0 * fSlow1089) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1091 + double(fSlow1091 == 0.0)) + 25.0 * fSlow1052));
		double fSlow1093 = double(25.0 < fSlow1062) * (fSlow1061 + 0.04 * fSlow1060);
		double fSlow1094 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.041666666666666664 * fSlow1047)));
		double fSlow1095 = mydsp_faustpower2_f(fSlow1094);
		double fSlow1096 = 24.0 * fSlow1053;
		double fSlow1097 = (0.0 - 2.0 * fSlow1094) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1096 + double(fSlow1096 == 0.0)) + 24.0 * fSlow1052));
		double fSlow1098 = double(24.0 < fSlow1062) * (fSlow1061 + 0.041666666666666664 * fSlow1060);
		double fSlow1099 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.043478260869565216 * fSlow1047)));
		double fSlow1100 = mydsp_faustpower2_f(fSlow1099);
		double fSlow1101 = 23.0 * fSlow1053;
		double fSlow1102 = (0.0 - 2.0 * fSlow1099) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1101 + double(fSlow1101 == 0.0)) + 23.0 * fSlow1052));
		double fSlow1103 = double(23.0 < fSlow1062) * (fSlow1061 + 0.043478260869565216 * fSlow1060);
		double fSlow1104 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.045454545454545456 * fSlow1047)));
		double fSlow1105 = mydsp_faustpower2_f(fSlow1104);
		double fSlow1106 = 22.0 * fSlow1053;
		double fSlow1107 = (0.0 - 2.0 * fSlow1104) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1106 + double(fSlow1106 == 0.0)) + 22.0 * fSlow1052));
		double fSlow1108 = double(22.0 < fSlow1062) * (fSlow1061 + 0.045454545454545456 * fSlow1060);
		double fSlow1109 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.047619047619047616 * fSlow1047)));
		double fSlow1110 = mydsp_faustpower2_f(fSlow1109);
		double fSlow1111 = 21.0 * fSlow1053;
		double fSlow1112 = (0.0 - 2.0 * fSlow1109) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1111 + double(fSlow1111 == 0.0)) + 21.0 * fSlow1052));
		double fSlow1113 = double(21.0 < fSlow1062) * (fSlow1061 + 0.047619047619047616 * fSlow1060);
		double fSlow1114 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.05 * fSlow1047)));
		double fSlow1115 = mydsp_faustpower2_f(fSlow1114);
		double fSlow1116 = 2e+01 * fSlow1053;
		double fSlow1117 = (0.0 - 2.0 * fSlow1114) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1116 + double(fSlow1116 == 0.0)) + 2e+01 * fSlow1052));
		double fSlow1118 = double(2e+01 < fSlow1062) * (fSlow1061 + 0.05 * fSlow1060);
		double fSlow1119 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.05263157894736842 * fSlow1047)));
		double fSlow1120 = mydsp_faustpower2_f(fSlow1119);
		double fSlow1121 = 19.0 * fSlow1053;
		double fSlow1122 = (0.0 - 2.0 * fSlow1119) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1121 + double(fSlow1121 == 0.0)) + 19.0 * fSlow1052));
		double fSlow1123 = double(19.0 < fSlow1062) * (fSlow1061 + 0.05263157894736842 * fSlow1060);
		double fSlow1124 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.05555555555555555 * fSlow1047)));
		double fSlow1125 = mydsp_faustpower2_f(fSlow1124);
		double fSlow1126 = 18.0 * fSlow1053;
		double fSlow1127 = (0.0 - 2.0 * fSlow1124) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1126 + double(fSlow1126 == 0.0)) + 18.0 * fSlow1052));
		double fSlow1128 = double(18.0 < fSlow1062) * (fSlow1061 + 0.05555555555555555 * fSlow1060);
		double fSlow1129 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.058823529411764705 * fSlow1047)));
		double fSlow1130 = mydsp_faustpower2_f(fSlow1129);
		double fSlow1131 = 17.0 * fSlow1053;
		double fSlow1132 = (0.0 - 2.0 * fSlow1129) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1131 + double(fSlow1131 == 0.0)) + 17.0 * fSlow1052));
		double fSlow1133 = double(17.0 < fSlow1062) * (fSlow1061 + 0.058823529411764705 * fSlow1060);
		double fSlow1134 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.0625 * fSlow1047)));
		double fSlow1135 = mydsp_faustpower2_f(fSlow1134);
		double fSlow1136 = 16.0 * fSlow1053;
		double fSlow1137 = (0.0 - 2.0 * fSlow1134) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1136 + double(fSlow1136 == 0.0)) + 16.0 * fSlow1052));
		double fSlow1138 = double(16.0 < fSlow1062) * (fSlow1061 + 0.0625 * fSlow1060);
		double fSlow1139 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.06666666666666667 * fSlow1047)));
		double fSlow1140 = mydsp_faustpower2_f(fSlow1139);
		double fSlow1141 = 15.0 * fSlow1053;
		double fSlow1142 = (0.0 - 2.0 * fSlow1139) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1141 + double(fSlow1141 == 0.0)) + 15.0 * fSlow1052));
		double fSlow1143 = double(15.0 < fSlow1062) * (fSlow1061 + 0.06666666666666667 * fSlow1060);
		double fSlow1144 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.07142857142857142 * fSlow1047)));
		double fSlow1145 = mydsp_faustpower2_f(fSlow1144);
		double fSlow1146 = 14.0 * fSlow1053;
		double fSlow1147 = (0.0 - 2.0 * fSlow1144) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1146 + double(fSlow1146 == 0.0)) + 14.0 * fSlow1052));
		double fSlow1148 = double(14.0 < fSlow1062) * (fSlow1061 + 0.07142857142857142 * fSlow1060);
		double fSlow1149 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.07692307692307693 * fSlow1047)));
		double fSlow1150 = mydsp_faustpower2_f(fSlow1149);
		double fSlow1151 = 13.0 * fSlow1053;
		double fSlow1152 = (0.0 - 2.0 * fSlow1149) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1151 + double(fSlow1151 == 0.0)) + 13.0 * fSlow1052));
		double fSlow1153 = double(13.0 < fSlow1062) * (fSlow1061 + 0.07692307692307693 * fSlow1060);
		double fSlow1154 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.08333333333333333 * fSlow1047)));
		double fSlow1155 = mydsp_faustpower2_f(fSlow1154);
		double fSlow1156 = 12.0 * fSlow1053;
		double fSlow1157 = (0.0 - 2.0 * fSlow1154) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1156 + double(fSlow1156 == 0.0)) + 12.0 * fSlow1052));
		double fSlow1158 = double(12.0 < fSlow1062) * (fSlow1061 + 0.08333333333333333 * fSlow1060);
		double fSlow1159 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.09090909090909091 * fSlow1047)));
		double fSlow1160 = mydsp_faustpower2_f(fSlow1159);
		double fSlow1161 = 11.0 * fSlow1053;
		double fSlow1162 = (0.0 - 2.0 * fSlow1159) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1161 + double(fSlow1161 == 0.0)) + 11.0 * fSlow1052));
		double fSlow1163 = double(11.0 < fSlow1062) * (fSlow1061 + 0.09090909090909091 * fSlow1060);
		double fSlow1164 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.1 * fSlow1047)));
		double fSlow1165 = mydsp_faustpower2_f(fSlow1164);
		double fSlow1166 = 1e+01 * fSlow1053;
		double fSlow1167 = (0.0 - 2.0 * fSlow1164) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1166 + double(fSlow1166 == 0.0)) + 1e+01 * fSlow1052));
		double fSlow1168 = double(1e+01 < fSlow1062) * (fSlow1061 + 0.1 * fSlow1060);
		double fSlow1169 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.1111111111111111 * fSlow1047)));
		double fSlow1170 = mydsp_faustpower2_f(fSlow1169);
		double fSlow1171 = 9.0 * fSlow1053;
		double fSlow1172 = (0.0 - 2.0 * fSlow1169) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1171 + double(fSlow1171 == 0.0)) + 9.0 * fSlow1052));
		double fSlow1173 = double(9.0 < fSlow1062) * (fSlow1061 + 0.1111111111111111 * fSlow1060);
		double fSlow1174 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.125 * fSlow1047)));
		double fSlow1175 = mydsp_faustpower2_f(fSlow1174);
		double fSlow1176 = 8.0 * fSlow1053;
		double fSlow1177 = (0.0 - 2.0 * fSlow1174) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1176 + double(fSlow1176 == 0.0)) + 8.0 * fSlow1052));
		double fSlow1178 = double(8.0 < fSlow1062) * (fSlow1061 + 0.125 * fSlow1060);
		double fSlow1179 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.14285714285714285 * fSlow1047)));
		double fSlow1180 = mydsp_faustpower2_f(fSlow1179);
		double fSlow1181 = 7.0 * fSlow1053;
		double fSlow1182 = (0.0 - 2.0 * fSlow1179) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1181 + double(fSlow1181 == 0.0)) + 7.0 * fSlow1052));
		double fSlow1183 = double(7.0 < fSlow1062) * (fSlow1061 + 0.14285714285714285 * fSlow1060);
		double fSlow1184 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.16666666666666666 * fSlow1047)));
		double fSlow1185 = mydsp_faustpower2_f(fSlow1184);
		double fSlow1186 = 6.0 * fSlow1053;
		double fSlow1187 = (0.0 - 2.0 * fSlow1184) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1186 + double(fSlow1186 == 0.0)) + 6.0 * fSlow1052));
		double fSlow1188 = double(6.0 < fSlow1062) * (fSlow1061 + 0.16666666666666666 * fSlow1060);
		double fSlow1189 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.2 * fSlow1047)));
		double fSlow1190 = mydsp_faustpower2_f(fSlow1189);
		double fSlow1191 = 5.0 * fSlow1053;
		double fSlow1192 = (0.0 - 2.0 * fSlow1189) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1191 + double(fSlow1191 == 0.0)) + 5.0 * fSlow1052));
		double fSlow1193 = double(5.0 < fSlow1062) * (fSlow1061 + 0.2 * fSlow1060);
		double fSlow1194 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.25 * fSlow1047)));
		double fSlow1195 = mydsp_faustpower2_f(fSlow1194);
		double fSlow1196 = 4.0 * fSlow1053;
		double fSlow1197 = (0.0 - 2.0 * fSlow1194) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1196 + double(fSlow1196 == 0.0)) + 4.0 * fSlow1052));
		double fSlow1198 = double(4.0 < fSlow1062) * (fSlow1061 + 0.25 * fSlow1060);
		double fSlow1199 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.3333333333333333 * fSlow1047)));
		double fSlow1200 = mydsp_faustpower2_f(fSlow1199);
		double fSlow1201 = 3.0 * fSlow1053;
		double fSlow1202 = (0.0 - 2.0 * fSlow1199) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1201 + double(fSlow1201 == 0.0)) + 3.0 * fSlow1052));
		double fSlow1203 = double(3.0 < fSlow1062) * (fSlow1061 + 0.3333333333333333 * fSlow1060);
		double fSlow1204 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + 0.5 * fSlow1047)));
		double fSlow1205 = mydsp_faustpower2_f(fSlow1204);
		double fSlow1206 = 2.0 * fSlow1053;
		double fSlow1207 = (0.0 - 2.0 * fSlow1204) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055 * (fSlow1206 + double(fSlow1206 == 0.0)) + 2.0 * fSlow1052));
		double fSlow1208 = double(2.0 < fSlow1062) * (fSlow1061 + 0.5 * fSlow1060);
		double fSlow1209 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + fSlow1047)));
		double fSlow1210 = mydsp_faustpower2_f(fSlow1209);
		double fSlow1211 = (0.0 - 2.0 * fSlow1209) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1052 + fSlow1055 * (fSlow1053 + double(fSlow1053 == 0.0))));
		double fSlow1212 = double(1.0 < fSlow1062) * (fSlow1061 + fSlow1060);
		double fSlow1213 = std::pow(0.001, fConst1 / (fSlow1049 * (fSlow1048 + fSlow1046)));
		double fSlow1214 = mydsp_faustpower2_f(fSlow1213);
		double fSlow1215 = (0.0 - 2.0 * fSlow1213) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1055));
		double fSlow1216 = double(0.0 < fSlow1062) * (fSlow1061 + fSlow1059);
		double fSlow1217 = double(fVslider55);
		double fSlow1218 = double(fVslider56);
		int iSlow1219 = fSlow1218 != 2.0;
		double fSlow1220 = double(iSlow1219);
		double fSlow1221 = fSlow1220 / fSlow1218;
		double fSlow1222 = double(1 - iSlow1219);
		double fSlow1223 = double(fVslider57);
		double fSlow1224 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.03225806451612903 * fSlow1221)));
		double fSlow1225 = mydsp_faustpower2_f(fSlow1224);
		double fSlow1226 = double(fVslider58);
		double fSlow1227 = double(fVslider59);
		double fSlow1228 = 31.0 * fSlow1227;
		double fSlow1229 = double(fVslider60);
		double fSlow1230 = (0.0 - 2.0 * fSlow1224) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1228 + double(fSlow1228 == 0.0)) + 31.0 * fSlow1226));
		double fSlow1231 = double(fVslider61);
		int iSlow1232 = fSlow1231 != 2.0;
		double fSlow1233 = double(iSlow1232);
		double fSlow1234 = fSlow1233 / fSlow1231;
		double fSlow1235 = double(1 - iSlow1232);
		double fSlow1236 = double(fVslider62);
		double fSlow1237 = double(31.0 < fSlow1236) * (fSlow1235 + 0.03225806451612903 * fSlow1234);
		double fSlow1238 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.03333333333333333 * fSlow1221)));
		double fSlow1239 = mydsp_faustpower2_f(fSlow1238);
		double fSlow1240 = 3e+01 * fSlow1227;
		double fSlow1241 = (0.0 - 2.0 * fSlow1238) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1240 + double(fSlow1240 == 0.0)) + 3e+01 * fSlow1226));
		double fSlow1242 = double(3e+01 < fSlow1236) * (fSlow1235 + 0.03333333333333333 * fSlow1234);
		double fSlow1243 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.034482758620689655 * fSlow1221)));
		double fSlow1244 = mydsp_faustpower2_f(fSlow1243);
		double fSlow1245 = 29.0 * fSlow1227;
		double fSlow1246 = (0.0 - 2.0 * fSlow1243) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1245 + double(fSlow1245 == 0.0)) + 29.0 * fSlow1226));
		double fSlow1247 = double(29.0 < fSlow1236) * (fSlow1235 + 0.034482758620689655 * fSlow1234);
		double fSlow1248 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.03571428571428571 * fSlow1221)));
		double fSlow1249 = mydsp_faustpower2_f(fSlow1248);
		double fSlow1250 = 28.0 * fSlow1227;
		double fSlow1251 = (0.0 - 2.0 * fSlow1248) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1250 + double(fSlow1250 == 0.0)) + 28.0 * fSlow1226));
		double fSlow1252 = double(28.0 < fSlow1236) * (fSlow1235 + 0.03571428571428571 * fSlow1234);
		double fSlow1253 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.037037037037037035 * fSlow1221)));
		double fSlow1254 = mydsp_faustpower2_f(fSlow1253);
		double fSlow1255 = 27.0 * fSlow1227;
		double fSlow1256 = (0.0 - 2.0 * fSlow1253) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1255 + double(fSlow1255 == 0.0)) + 27.0 * fSlow1226));
		double fSlow1257 = double(27.0 < fSlow1236) * (fSlow1235 + 0.037037037037037035 * fSlow1234);
		double fSlow1258 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.038461538461538464 * fSlow1221)));
		double fSlow1259 = mydsp_faustpower2_f(fSlow1258);
		double fSlow1260 = 26.0 * fSlow1227;
		double fSlow1261 = (0.0 - 2.0 * fSlow1258) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1260 + double(fSlow1260 == 0.0)) + 26.0 * fSlow1226));
		double fSlow1262 = double(26.0 < fSlow1236) * (fSlow1235 + 0.038461538461538464 * fSlow1234);
		double fSlow1263 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.04 * fSlow1221)));
		double fSlow1264 = mydsp_faustpower2_f(fSlow1263);
		double fSlow1265 = 25.0 * fSlow1227;
		double fSlow1266 = (0.0 - 2.0 * fSlow1263) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1265 + double(fSlow1265 == 0.0)) + 25.0 * fSlow1226));
		double fSlow1267 = double(25.0 < fSlow1236) * (fSlow1235 + 0.04 * fSlow1234);
		double fSlow1268 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.041666666666666664 * fSlow1221)));
		double fSlow1269 = mydsp_faustpower2_f(fSlow1268);
		double fSlow1270 = 24.0 * fSlow1227;
		double fSlow1271 = (0.0 - 2.0 * fSlow1268) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1270 + double(fSlow1270 == 0.0)) + 24.0 * fSlow1226));
		double fSlow1272 = double(24.0 < fSlow1236) * (fSlow1235 + 0.041666666666666664 * fSlow1234);
		double fSlow1273 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.043478260869565216 * fSlow1221)));
		double fSlow1274 = mydsp_faustpower2_f(fSlow1273);
		double fSlow1275 = 23.0 * fSlow1227;
		double fSlow1276 = (0.0 - 2.0 * fSlow1273) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1275 + double(fSlow1275 == 0.0)) + 23.0 * fSlow1226));
		double fSlow1277 = double(23.0 < fSlow1236) * (fSlow1235 + 0.043478260869565216 * fSlow1234);
		double fSlow1278 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.045454545454545456 * fSlow1221)));
		double fSlow1279 = mydsp_faustpower2_f(fSlow1278);
		double fSlow1280 = 22.0 * fSlow1227;
		double fSlow1281 = (0.0 - 2.0 * fSlow1278) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1280 + double(fSlow1280 == 0.0)) + 22.0 * fSlow1226));
		double fSlow1282 = double(22.0 < fSlow1236) * (fSlow1235 + 0.045454545454545456 * fSlow1234);
		double fSlow1283 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.047619047619047616 * fSlow1221)));
		double fSlow1284 = mydsp_faustpower2_f(fSlow1283);
		double fSlow1285 = 21.0 * fSlow1227;
		double fSlow1286 = (0.0 - 2.0 * fSlow1283) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1285 + double(fSlow1285 == 0.0)) + 21.0 * fSlow1226));
		double fSlow1287 = double(21.0 < fSlow1236) * (fSlow1235 + 0.047619047619047616 * fSlow1234);
		double fSlow1288 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.05 * fSlow1221)));
		double fSlow1289 = mydsp_faustpower2_f(fSlow1288);
		double fSlow1290 = 2e+01 * fSlow1227;
		double fSlow1291 = (0.0 - 2.0 * fSlow1288) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1290 + double(fSlow1290 == 0.0)) + 2e+01 * fSlow1226));
		double fSlow1292 = double(2e+01 < fSlow1236) * (fSlow1235 + 0.05 * fSlow1234);
		double fSlow1293 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.05263157894736842 * fSlow1221)));
		double fSlow1294 = mydsp_faustpower2_f(fSlow1293);
		double fSlow1295 = 19.0 * fSlow1227;
		double fSlow1296 = (0.0 - 2.0 * fSlow1293) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1295 + double(fSlow1295 == 0.0)) + 19.0 * fSlow1226));
		double fSlow1297 = double(19.0 < fSlow1236) * (fSlow1235 + 0.05263157894736842 * fSlow1234);
		double fSlow1298 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.05555555555555555 * fSlow1221)));
		double fSlow1299 = mydsp_faustpower2_f(fSlow1298);
		double fSlow1300 = 18.0 * fSlow1227;
		double fSlow1301 = (0.0 - 2.0 * fSlow1298) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1300 + double(fSlow1300 == 0.0)) + 18.0 * fSlow1226));
		double fSlow1302 = double(18.0 < fSlow1236) * (fSlow1235 + 0.05555555555555555 * fSlow1234);
		double fSlow1303 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.058823529411764705 * fSlow1221)));
		double fSlow1304 = mydsp_faustpower2_f(fSlow1303);
		double fSlow1305 = 17.0 * fSlow1227;
		double fSlow1306 = (0.0 - 2.0 * fSlow1303) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1305 + double(fSlow1305 == 0.0)) + 17.0 * fSlow1226));
		double fSlow1307 = double(17.0 < fSlow1236) * (fSlow1235 + 0.058823529411764705 * fSlow1234);
		double fSlow1308 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.0625 * fSlow1221)));
		double fSlow1309 = mydsp_faustpower2_f(fSlow1308);
		double fSlow1310 = 16.0 * fSlow1227;
		double fSlow1311 = (0.0 - 2.0 * fSlow1308) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1310 + double(fSlow1310 == 0.0)) + 16.0 * fSlow1226));
		double fSlow1312 = double(16.0 < fSlow1236) * (fSlow1235 + 0.0625 * fSlow1234);
		double fSlow1313 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.06666666666666667 * fSlow1221)));
		double fSlow1314 = mydsp_faustpower2_f(fSlow1313);
		double fSlow1315 = 15.0 * fSlow1227;
		double fSlow1316 = (0.0 - 2.0 * fSlow1313) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1315 + double(fSlow1315 == 0.0)) + 15.0 * fSlow1226));
		double fSlow1317 = double(15.0 < fSlow1236) * (fSlow1235 + 0.06666666666666667 * fSlow1234);
		double fSlow1318 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.07142857142857142 * fSlow1221)));
		double fSlow1319 = mydsp_faustpower2_f(fSlow1318);
		double fSlow1320 = 14.0 * fSlow1227;
		double fSlow1321 = (0.0 - 2.0 * fSlow1318) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1320 + double(fSlow1320 == 0.0)) + 14.0 * fSlow1226));
		double fSlow1322 = double(14.0 < fSlow1236) * (fSlow1235 + 0.07142857142857142 * fSlow1234);
		double fSlow1323 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.07692307692307693 * fSlow1221)));
		double fSlow1324 = mydsp_faustpower2_f(fSlow1323);
		double fSlow1325 = 13.0 * fSlow1227;
		double fSlow1326 = (0.0 - 2.0 * fSlow1323) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1325 + double(fSlow1325 == 0.0)) + 13.0 * fSlow1226));
		double fSlow1327 = double(13.0 < fSlow1236) * (fSlow1235 + 0.07692307692307693 * fSlow1234);
		double fSlow1328 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.08333333333333333 * fSlow1221)));
		double fSlow1329 = mydsp_faustpower2_f(fSlow1328);
		double fSlow1330 = 12.0 * fSlow1227;
		double fSlow1331 = (0.0 - 2.0 * fSlow1328) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1330 + double(fSlow1330 == 0.0)) + 12.0 * fSlow1226));
		double fSlow1332 = double(12.0 < fSlow1236) * (fSlow1235 + 0.08333333333333333 * fSlow1234);
		double fSlow1333 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.09090909090909091 * fSlow1221)));
		double fSlow1334 = mydsp_faustpower2_f(fSlow1333);
		double fSlow1335 = 11.0 * fSlow1227;
		double fSlow1336 = (0.0 - 2.0 * fSlow1333) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1335 + double(fSlow1335 == 0.0)) + 11.0 * fSlow1226));
		double fSlow1337 = double(11.0 < fSlow1236) * (fSlow1235 + 0.09090909090909091 * fSlow1234);
		double fSlow1338 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.1 * fSlow1221)));
		double fSlow1339 = mydsp_faustpower2_f(fSlow1338);
		double fSlow1340 = 1e+01 * fSlow1227;
		double fSlow1341 = (0.0 - 2.0 * fSlow1338) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1340 + double(fSlow1340 == 0.0)) + 1e+01 * fSlow1226));
		double fSlow1342 = double(1e+01 < fSlow1236) * (fSlow1235 + 0.1 * fSlow1234);
		double fSlow1343 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.1111111111111111 * fSlow1221)));
		double fSlow1344 = mydsp_faustpower2_f(fSlow1343);
		double fSlow1345 = 9.0 * fSlow1227;
		double fSlow1346 = (0.0 - 2.0 * fSlow1343) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1345 + double(fSlow1345 == 0.0)) + 9.0 * fSlow1226));
		double fSlow1347 = double(9.0 < fSlow1236) * (fSlow1235 + 0.1111111111111111 * fSlow1234);
		double fSlow1348 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.125 * fSlow1221)));
		double fSlow1349 = mydsp_faustpower2_f(fSlow1348);
		double fSlow1350 = 8.0 * fSlow1227;
		double fSlow1351 = (0.0 - 2.0 * fSlow1348) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1350 + double(fSlow1350 == 0.0)) + 8.0 * fSlow1226));
		double fSlow1352 = double(8.0 < fSlow1236) * (fSlow1235 + 0.125 * fSlow1234);
		double fSlow1353 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.14285714285714285 * fSlow1221)));
		double fSlow1354 = mydsp_faustpower2_f(fSlow1353);
		double fSlow1355 = 7.0 * fSlow1227;
		double fSlow1356 = (0.0 - 2.0 * fSlow1353) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1355 + double(fSlow1355 == 0.0)) + 7.0 * fSlow1226));
		double fSlow1357 = double(7.0 < fSlow1236) * (fSlow1235 + 0.14285714285714285 * fSlow1234);
		double fSlow1358 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.16666666666666666 * fSlow1221)));
		double fSlow1359 = mydsp_faustpower2_f(fSlow1358);
		double fSlow1360 = 6.0 * fSlow1227;
		double fSlow1361 = (0.0 - 2.0 * fSlow1358) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1360 + double(fSlow1360 == 0.0)) + 6.0 * fSlow1226));
		double fSlow1362 = double(6.0 < fSlow1236) * (fSlow1235 + 0.16666666666666666 * fSlow1234);
		double fSlow1363 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.2 * fSlow1221)));
		double fSlow1364 = mydsp_faustpower2_f(fSlow1363);
		double fSlow1365 = 5.0 * fSlow1227;
		double fSlow1366 = (0.0 - 2.0 * fSlow1363) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1365 + double(fSlow1365 == 0.0)) + 5.0 * fSlow1226));
		double fSlow1367 = double(5.0 < fSlow1236) * (fSlow1235 + 0.2 * fSlow1234);
		double fSlow1368 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.25 * fSlow1221)));
		double fSlow1369 = mydsp_faustpower2_f(fSlow1368);
		double fSlow1370 = 4.0 * fSlow1227;
		double fSlow1371 = (0.0 - 2.0 * fSlow1368) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1370 + double(fSlow1370 == 0.0)) + 4.0 * fSlow1226));
		double fSlow1372 = double(4.0 < fSlow1236) * (fSlow1235 + 0.25 * fSlow1234);
		double fSlow1373 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.3333333333333333 * fSlow1221)));
		double fSlow1374 = mydsp_faustpower2_f(fSlow1373);
		double fSlow1375 = 3.0 * fSlow1227;
		double fSlow1376 = (0.0 - 2.0 * fSlow1373) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1375 + double(fSlow1375 == 0.0)) + 3.0 * fSlow1226));
		double fSlow1377 = double(3.0 < fSlow1236) * (fSlow1235 + 0.3333333333333333 * fSlow1234);
		double fSlow1378 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + 0.5 * fSlow1221)));
		double fSlow1379 = mydsp_faustpower2_f(fSlow1378);
		double fSlow1380 = 2.0 * fSlow1227;
		double fSlow1381 = (0.0 - 2.0 * fSlow1378) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229 * (fSlow1380 + double(fSlow1380 == 0.0)) + 2.0 * fSlow1226));
		double fSlow1382 = double(2.0 < fSlow1236) * (fSlow1235 + 0.5 * fSlow1234);
		double fSlow1383 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + fSlow1221)));
		double fSlow1384 = mydsp_faustpower2_f(fSlow1383);
		double fSlow1385 = (0.0 - 2.0 * fSlow1383) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1226 + fSlow1229 * (fSlow1227 + double(fSlow1227 == 0.0))));
		double fSlow1386 = double(1.0 < fSlow1236) * (fSlow1235 + fSlow1234);
		double fSlow1387 = std::pow(0.001, fConst1 / (fSlow1223 * (fSlow1222 + fSlow1220)));
		double fSlow1388 = mydsp_faustpower2_f(fSlow1387);
		double fSlow1389 = (0.0 - 2.0 * fSlow1387) * std::cos(fConst3 * std::min<double>(fConst2, fSlow1229));
		double fSlow1390 = double(0.0 < fSlow1236) * (fSlow1235 + fSlow1233);
		double fSlow1391 = double(fVslider63);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			double fTemp0 = double(input0[i0]);
			fRec0[0] = fTemp0 - (fSlow12 * fRec0[1] + fSlow7 * fRec0[2]);
			fRec1[0] = fTemp0 - (fSlow23 * fRec1[1] + fSlow21 * fRec1[2]);
			fRec2[0] = fTemp0 - (fSlow28 * fRec2[1] + fSlow26 * fRec2[2]);
			fRec3[0] = fTemp0 - (fSlow33 * fRec3[1] + fSlow31 * fRec3[2]);
			fRec4[0] = fTemp0 - (fSlow38 * fRec4[1] + fSlow36 * fRec4[2]);
			fRec5[0] = fTemp0 - (fSlow43 * fRec5[1] + fSlow41 * fRec5[2]);
			fRec6[0] = fTemp0 - (fSlow48 * fRec6[1] + fSlow46 * fRec6[2]);
			fRec7[0] = fTemp0 - (fSlow53 * fRec7[1] + fSlow51 * fRec7[2]);
			fRec8[0] = fTemp0 - (fSlow58 * fRec8[1] + fSlow56 * fRec8[2]);
			fRec9[0] = fTemp0 - (fSlow63 * fRec9[1] + fSlow61 * fRec9[2]);
			fRec10[0] = fTemp0 - (fSlow68 * fRec10[1] + fSlow66 * fRec10[2]);
			fRec11[0] = fTemp0 - (fSlow73 * fRec11[1] + fSlow71 * fRec11[2]);
			fRec12[0] = fTemp0 - (fSlow78 * fRec12[1] + fSlow76 * fRec12[2]);
			fRec13[0] = fTemp0 - (fSlow83 * fRec13[1] + fSlow81 * fRec13[2]);
			fRec14[0] = fTemp0 - (fSlow88 * fRec14[1] + fSlow86 * fRec14[2]);
			fRec15[0] = fTemp0 - (fSlow93 * fRec15[1] + fSlow91 * fRec15[2]);
			fRec16[0] = fTemp0 - (fSlow98 * fRec16[1] + fSlow96 * fRec16[2]);
			fRec17[0] = fTemp0 - (fSlow103 * fRec17[1] + fSlow101 * fRec17[2]);
			fRec18[0] = fTemp0 - (fSlow108 * fRec18[1] + fSlow106 * fRec18[2]);
			fRec19[0] = fTemp0 - (fSlow113 * fRec19[1] + fSlow111 * fRec19[2]);
			fRec20[0] = fTemp0 - (fSlow118 * fRec20[1] + fSlow116 * fRec20[2]);
			fRec21[0] = fTemp0 - (fSlow123 * fRec21[1] + fSlow121 * fRec21[2]);
			fRec22[0] = fTemp0 - (fSlow128 * fRec22[1] + fSlow126 * fRec22[2]);
			fRec23[0] = fTemp0 - (fSlow133 * fRec23[1] + fSlow131 * fRec23[2]);
			fRec24[0] = fTemp0 - (fSlow138 * fRec24[1] + fSlow136 * fRec24[2]);
			fRec25[0] = fTemp0 - (fSlow143 * fRec25[1] + fSlow141 * fRec25[2]);
			fRec26[0] = fTemp0 - (fSlow148 * fRec26[1] + fSlow146 * fRec26[2]);
			fRec27[0] = fTemp0 - (fSlow153 * fRec27[1] + fSlow151 * fRec27[2]);
			fRec28[0] = fTemp0 - (fSlow158 * fRec28[1] + fSlow156 * fRec28[2]);
			fRec29[0] = fTemp0 - (fSlow163 * fRec29[1] + fSlow161 * fRec29[2]);
			fRec30[0] = fTemp0 - (fSlow167 * fRec30[1] + fSlow166 * fRec30[2]);
			fRec31[0] = fTemp0 - (fSlow171 * fRec31[1] + fSlow170 * fRec31[2]);
			fRec32[0] = fTemp0 - (fSlow186 * fRec32[1] + fSlow181 * fRec32[2]);
			fRec33[0] = fTemp0 - (fSlow197 * fRec33[1] + fSlow195 * fRec33[2]);
			fRec34[0] = fTemp0 - (fSlow202 * fRec34[1] + fSlow200 * fRec34[2]);
			fRec35[0] = fTemp0 - (fSlow207 * fRec35[1] + fSlow205 * fRec35[2]);
			fRec36[0] = fTemp0 - (fSlow212 * fRec36[1] + fSlow210 * fRec36[2]);
			fRec37[0] = fTemp0 - (fSlow217 * fRec37[1] + fSlow215 * fRec37[2]);
			fRec38[0] = fTemp0 - (fSlow222 * fRec38[1] + fSlow220 * fRec38[2]);
			fRec39[0] = fTemp0 - (fSlow227 * fRec39[1] + fSlow225 * fRec39[2]);
			fRec40[0] = fTemp0 - (fSlow232 * fRec40[1] + fSlow230 * fRec40[2]);
			fRec41[0] = fTemp0 - (fSlow237 * fRec41[1] + fSlow235 * fRec41[2]);
			fRec42[0] = fTemp0 - (fSlow242 * fRec42[1] + fSlow240 * fRec42[2]);
			fRec43[0] = fTemp0 - (fSlow247 * fRec43[1] + fSlow245 * fRec43[2]);
			fRec44[0] = fTemp0 - (fSlow252 * fRec44[1] + fSlow250 * fRec44[2]);
			fRec45[0] = fTemp0 - (fSlow257 * fRec45[1] + fSlow255 * fRec45[2]);
			fRec46[0] = fTemp0 - (fSlow262 * fRec46[1] + fSlow260 * fRec46[2]);
			fRec47[0] = fTemp0 - (fSlow267 * fRec47[1] + fSlow265 * fRec47[2]);
			fRec48[0] = fTemp0 - (fSlow272 * fRec48[1] + fSlow270 * fRec48[2]);
			fRec49[0] = fTemp0 - (fSlow277 * fRec49[1] + fSlow275 * fRec49[2]);
			fRec50[0] = fTemp0 - (fSlow282 * fRec50[1] + fSlow280 * fRec50[2]);
			fRec51[0] = fTemp0 - (fSlow287 * fRec51[1] + fSlow285 * fRec51[2]);
			fRec52[0] = fTemp0 - (fSlow292 * fRec52[1] + fSlow290 * fRec52[2]);
			fRec53[0] = fTemp0 - (fSlow297 * fRec53[1] + fSlow295 * fRec53[2]);
			fRec54[0] = fTemp0 - (fSlow302 * fRec54[1] + fSlow300 * fRec54[2]);
			fRec55[0] = fTemp0 - (fSlow307 * fRec55[1] + fSlow305 * fRec55[2]);
			fRec56[0] = fTemp0 - (fSlow312 * fRec56[1] + fSlow310 * fRec56[2]);
			fRec57[0] = fTemp0 - (fSlow317 * fRec57[1] + fSlow315 * fRec57[2]);
			fRec58[0] = fTemp0 - (fSlow322 * fRec58[1] + fSlow320 * fRec58[2]);
			fRec59[0] = fTemp0 - (fSlow327 * fRec59[1] + fSlow325 * fRec59[2]);
			fRec60[0] = fTemp0 - (fSlow332 * fRec60[1] + fSlow330 * fRec60[2]);
			fRec61[0] = fTemp0 - (fSlow337 * fRec61[1] + fSlow335 * fRec61[2]);
			fRec62[0] = fTemp0 - (fSlow341 * fRec62[1] + fSlow340 * fRec62[2]);
			fRec63[0] = fTemp0 - (fSlow345 * fRec63[1] + fSlow344 * fRec63[2]);
			fRec64[0] = fTemp0 - (fSlow360 * fRec64[1] + fSlow355 * fRec64[2]);
			fRec65[0] = fTemp0 - (fSlow371 * fRec65[1] + fSlow369 * fRec65[2]);
			fRec66[0] = fTemp0 - (fSlow376 * fRec66[1] + fSlow374 * fRec66[2]);
			fRec67[0] = fTemp0 - (fSlow381 * fRec67[1] + fSlow379 * fRec67[2]);
			fRec68[0] = fTemp0 - (fSlow386 * fRec68[1] + fSlow384 * fRec68[2]);
			fRec69[0] = fTemp0 - (fSlow391 * fRec69[1] + fSlow389 * fRec69[2]);
			fRec70[0] = fTemp0 - (fSlow396 * fRec70[1] + fSlow394 * fRec70[2]);
			fRec71[0] = fTemp0 - (fSlow401 * fRec71[1] + fSlow399 * fRec71[2]);
			fRec72[0] = fTemp0 - (fSlow406 * fRec72[1] + fSlow404 * fRec72[2]);
			fRec73[0] = fTemp0 - (fSlow411 * fRec73[1] + fSlow409 * fRec73[2]);
			fRec74[0] = fTemp0 - (fSlow416 * fRec74[1] + fSlow414 * fRec74[2]);
			fRec75[0] = fTemp0 - (fSlow421 * fRec75[1] + fSlow419 * fRec75[2]);
			fRec76[0] = fTemp0 - (fSlow426 * fRec76[1] + fSlow424 * fRec76[2]);
			fRec77[0] = fTemp0 - (fSlow431 * fRec77[1] + fSlow429 * fRec77[2]);
			fRec78[0] = fTemp0 - (fSlow436 * fRec78[1] + fSlow434 * fRec78[2]);
			fRec79[0] = fTemp0 - (fSlow441 * fRec79[1] + fSlow439 * fRec79[2]);
			fRec80[0] = fTemp0 - (fSlow446 * fRec80[1] + fSlow444 * fRec80[2]);
			fRec81[0] = fTemp0 - (fSlow451 * fRec81[1] + fSlow449 * fRec81[2]);
			fRec82[0] = fTemp0 - (fSlow456 * fRec82[1] + fSlow454 * fRec82[2]);
			fRec83[0] = fTemp0 - (fSlow461 * fRec83[1] + fSlow459 * fRec83[2]);
			fRec84[0] = fTemp0 - (fSlow466 * fRec84[1] + fSlow464 * fRec84[2]);
			fRec85[0] = fTemp0 - (fSlow471 * fRec85[1] + fSlow469 * fRec85[2]);
			fRec86[0] = fTemp0 - (fSlow476 * fRec86[1] + fSlow474 * fRec86[2]);
			fRec87[0] = fTemp0 - (fSlow481 * fRec87[1] + fSlow479 * fRec87[2]);
			fRec88[0] = fTemp0 - (fSlow486 * fRec88[1] + fSlow484 * fRec88[2]);
			fRec89[0] = fTemp0 - (fSlow491 * fRec89[1] + fSlow489 * fRec89[2]);
			fRec90[0] = fTemp0 - (fSlow496 * fRec90[1] + fSlow494 * fRec90[2]);
			fRec91[0] = fTemp0 - (fSlow501 * fRec91[1] + fSlow499 * fRec91[2]);
			fRec92[0] = fTemp0 - (fSlow506 * fRec92[1] + fSlow504 * fRec92[2]);
			fRec93[0] = fTemp0 - (fSlow511 * fRec93[1] + fSlow509 * fRec93[2]);
			fRec94[0] = fTemp0 - (fSlow515 * fRec94[1] + fSlow514 * fRec94[2]);
			fRec95[0] = fTemp0 - (fSlow519 * fRec95[1] + fSlow518 * fRec95[2]);
			fRec96[0] = fTemp0 - (fSlow534 * fRec96[1] + fSlow529 * fRec96[2]);
			fRec97[0] = fTemp0 - (fSlow545 * fRec97[1] + fSlow543 * fRec97[2]);
			fRec98[0] = fTemp0 - (fSlow550 * fRec98[1] + fSlow548 * fRec98[2]);
			fRec99[0] = fTemp0 - (fSlow555 * fRec99[1] + fSlow553 * fRec99[2]);
			fRec100[0] = fTemp0 - (fSlow560 * fRec100[1] + fSlow558 * fRec100[2]);
			fRec101[0] = fTemp0 - (fSlow565 * fRec101[1] + fSlow563 * fRec101[2]);
			fRec102[0] = fTemp0 - (fSlow570 * fRec102[1] + fSlow568 * fRec102[2]);
			fRec103[0] = fTemp0 - (fSlow575 * fRec103[1] + fSlow573 * fRec103[2]);
			fRec104[0] = fTemp0 - (fSlow580 * fRec104[1] + fSlow578 * fRec104[2]);
			fRec105[0] = fTemp0 - (fSlow585 * fRec105[1] + fSlow583 * fRec105[2]);
			fRec106[0] = fTemp0 - (fSlow590 * fRec106[1] + fSlow588 * fRec106[2]);
			fRec107[0] = fTemp0 - (fSlow595 * fRec107[1] + fSlow593 * fRec107[2]);
			fRec108[0] = fTemp0 - (fSlow600 * fRec108[1] + fSlow598 * fRec108[2]);
			fRec109[0] = fTemp0 - (fSlow605 * fRec109[1] + fSlow603 * fRec109[2]);
			fRec110[0] = fTemp0 - (fSlow610 * fRec110[1] + fSlow608 * fRec110[2]);
			fRec111[0] = fTemp0 - (fSlow615 * fRec111[1] + fSlow613 * fRec111[2]);
			fRec112[0] = fTemp0 - (fSlow620 * fRec112[1] + fSlow618 * fRec112[2]);
			fRec113[0] = fTemp0 - (fSlow625 * fRec113[1] + fSlow623 * fRec113[2]);
			fRec114[0] = fTemp0 - (fSlow630 * fRec114[1] + fSlow628 * fRec114[2]);
			fRec115[0] = fTemp0 - (fSlow635 * fRec115[1] + fSlow633 * fRec115[2]);
			fRec116[0] = fTemp0 - (fSlow640 * fRec116[1] + fSlow638 * fRec116[2]);
			fRec117[0] = fTemp0 - (fSlow645 * fRec117[1] + fSlow643 * fRec117[2]);
			fRec118[0] = fTemp0 - (fSlow650 * fRec118[1] + fSlow648 * fRec118[2]);
			fRec119[0] = fTemp0 - (fSlow655 * fRec119[1] + fSlow653 * fRec119[2]);
			fRec120[0] = fTemp0 - (fSlow660 * fRec120[1] + fSlow658 * fRec120[2]);
			fRec121[0] = fTemp0 - (fSlow665 * fRec121[1] + fSlow663 * fRec121[2]);
			fRec122[0] = fTemp0 - (fSlow670 * fRec122[1] + fSlow668 * fRec122[2]);
			fRec123[0] = fTemp0 - (fSlow675 * fRec123[1] + fSlow673 * fRec123[2]);
			fRec124[0] = fTemp0 - (fSlow680 * fRec124[1] + fSlow678 * fRec124[2]);
			fRec125[0] = fTemp0 - (fSlow685 * fRec125[1] + fSlow683 * fRec125[2]);
			fRec126[0] = fTemp0 - (fSlow689 * fRec126[1] + fSlow688 * fRec126[2]);
			fRec127[0] = fTemp0 - (fSlow693 * fRec127[1] + fSlow692 * fRec127[2]);
			fRec128[0] = fTemp0 - (fSlow708 * fRec128[1] + fSlow703 * fRec128[2]);
			fRec129[0] = fTemp0 - (fSlow719 * fRec129[1] + fSlow717 * fRec129[2]);
			fRec130[0] = fTemp0 - (fSlow724 * fRec130[1] + fSlow722 * fRec130[2]);
			fRec131[0] = fTemp0 - (fSlow729 * fRec131[1] + fSlow727 * fRec131[2]);
			fRec132[0] = fTemp0 - (fSlow734 * fRec132[1] + fSlow732 * fRec132[2]);
			fRec133[0] = fTemp0 - (fSlow739 * fRec133[1] + fSlow737 * fRec133[2]);
			fRec134[0] = fTemp0 - (fSlow744 * fRec134[1] + fSlow742 * fRec134[2]);
			fRec135[0] = fTemp0 - (fSlow749 * fRec135[1] + fSlow747 * fRec135[2]);
			fRec136[0] = fTemp0 - (fSlow754 * fRec136[1] + fSlow752 * fRec136[2]);
			fRec137[0] = fTemp0 - (fSlow759 * fRec137[1] + fSlow757 * fRec137[2]);
			fRec138[0] = fTemp0 - (fSlow764 * fRec138[1] + fSlow762 * fRec138[2]);
			fRec139[0] = fTemp0 - (fSlow769 * fRec139[1] + fSlow767 * fRec139[2]);
			fRec140[0] = fTemp0 - (fSlow774 * fRec140[1] + fSlow772 * fRec140[2]);
			fRec141[0] = fTemp0 - (fSlow779 * fRec141[1] + fSlow777 * fRec141[2]);
			fRec142[0] = fTemp0 - (fSlow784 * fRec142[1] + fSlow782 * fRec142[2]);
			fRec143[0] = fTemp0 - (fSlow789 * fRec143[1] + fSlow787 * fRec143[2]);
			fRec144[0] = fTemp0 - (fSlow794 * fRec144[1] + fSlow792 * fRec144[2]);
			fRec145[0] = fTemp0 - (fSlow799 * fRec145[1] + fSlow797 * fRec145[2]);
			fRec146[0] = fTemp0 - (fSlow804 * fRec146[1] + fSlow802 * fRec146[2]);
			fRec147[0] = fTemp0 - (fSlow809 * fRec147[1] + fSlow807 * fRec147[2]);
			fRec148[0] = fTemp0 - (fSlow814 * fRec148[1] + fSlow812 * fRec148[2]);
			fRec149[0] = fTemp0 - (fSlow819 * fRec149[1] + fSlow817 * fRec149[2]);
			fRec150[0] = fTemp0 - (fSlow824 * fRec150[1] + fSlow822 * fRec150[2]);
			fRec151[0] = fTemp0 - (fSlow829 * fRec151[1] + fSlow827 * fRec151[2]);
			fRec152[0] = fTemp0 - (fSlow834 * fRec152[1] + fSlow832 * fRec152[2]);
			fRec153[0] = fTemp0 - (fSlow839 * fRec153[1] + fSlow837 * fRec153[2]);
			fRec154[0] = fTemp0 - (fSlow844 * fRec154[1] + fSlow842 * fRec154[2]);
			fRec155[0] = fTemp0 - (fSlow849 * fRec155[1] + fSlow847 * fRec155[2]);
			fRec156[0] = fTemp0 - (fSlow854 * fRec156[1] + fSlow852 * fRec156[2]);
			fRec157[0] = fTemp0 - (fSlow859 * fRec157[1] + fSlow857 * fRec157[2]);
			fRec158[0] = fTemp0 - (fSlow863 * fRec158[1] + fSlow862 * fRec158[2]);
			fRec159[0] = fTemp0 - (fSlow867 * fRec159[1] + fSlow866 * fRec159[2]);
			fRec160[0] = fTemp0 - (fSlow882 * fRec160[1] + fSlow877 * fRec160[2]);
			fRec161[0] = fTemp0 - (fSlow893 * fRec161[1] + fSlow891 * fRec161[2]);
			fRec162[0] = fTemp0 - (fSlow898 * fRec162[1] + fSlow896 * fRec162[2]);
			fRec163[0] = fTemp0 - (fSlow903 * fRec163[1] + fSlow901 * fRec163[2]);
			fRec164[0] = fTemp0 - (fSlow908 * fRec164[1] + fSlow906 * fRec164[2]);
			fRec165[0] = fTemp0 - (fSlow913 * fRec165[1] + fSlow911 * fRec165[2]);
			fRec166[0] = fTemp0 - (fSlow918 * fRec166[1] + fSlow916 * fRec166[2]);
			fRec167[0] = fTemp0 - (fSlow923 * fRec167[1] + fSlow921 * fRec167[2]);
			fRec168[0] = fTemp0 - (fSlow928 * fRec168[1] + fSlow926 * fRec168[2]);
			fRec169[0] = fTemp0 - (fSlow933 * fRec169[1] + fSlow931 * fRec169[2]);
			fRec170[0] = fTemp0 - (fSlow938 * fRec170[1] + fSlow936 * fRec170[2]);
			fRec171[0] = fTemp0 - (fSlow943 * fRec171[1] + fSlow941 * fRec171[2]);
			fRec172[0] = fTemp0 - (fSlow948 * fRec172[1] + fSlow946 * fRec172[2]);
			fRec173[0] = fTemp0 - (fSlow953 * fRec173[1] + fSlow951 * fRec173[2]);
			fRec174[0] = fTemp0 - (fSlow958 * fRec174[1] + fSlow956 * fRec174[2]);
			fRec175[0] = fTemp0 - (fSlow963 * fRec175[1] + fSlow961 * fRec175[2]);
			fRec176[0] = fTemp0 - (fSlow968 * fRec176[1] + fSlow966 * fRec176[2]);
			fRec177[0] = fTemp0 - (fSlow973 * fRec177[1] + fSlow971 * fRec177[2]);
			fRec178[0] = fTemp0 - (fSlow978 * fRec178[1] + fSlow976 * fRec178[2]);
			fRec179[0] = fTemp0 - (fSlow983 * fRec179[1] + fSlow981 * fRec179[2]);
			fRec180[0] = fTemp0 - (fSlow988 * fRec180[1] + fSlow986 * fRec180[2]);
			fRec181[0] = fTemp0 - (fSlow993 * fRec181[1] + fSlow991 * fRec181[2]);
			fRec182[0] = fTemp0 - (fSlow998 * fRec182[1] + fSlow996 * fRec182[2]);
			fRec183[0] = fTemp0 - (fSlow1003 * fRec183[1] + fSlow1001 * fRec183[2]);
			fRec184[0] = fTemp0 - (fSlow1008 * fRec184[1] + fSlow1006 * fRec184[2]);
			fRec185[0] = fTemp0 - (fSlow1013 * fRec185[1] + fSlow1011 * fRec185[2]);
			fRec186[0] = fTemp0 - (fSlow1018 * fRec186[1] + fSlow1016 * fRec186[2]);
			fRec187[0] = fTemp0 - (fSlow1023 * fRec187[1] + fSlow1021 * fRec187[2]);
			fRec188[0] = fTemp0 - (fSlow1028 * fRec188[1] + fSlow1026 * fRec188[2]);
			fRec189[0] = fTemp0 - (fSlow1033 * fRec189[1] + fSlow1031 * fRec189[2]);
			fRec190[0] = fTemp0 - (fSlow1037 * fRec190[1] + fSlow1036 * fRec190[2]);
			fRec191[0] = fTemp0 - (fSlow1041 * fRec191[1] + fSlow1040 * fRec191[2]);
			fRec192[0] = fTemp0 - (fSlow1056 * fRec192[1] + fSlow1051 * fRec192[2]);
			fRec193[0] = fTemp0 - (fSlow1067 * fRec193[1] + fSlow1065 * fRec193[2]);
			fRec194[0] = fTemp0 - (fSlow1072 * fRec194[1] + fSlow1070 * fRec194[2]);
			fRec195[0] = fTemp0 - (fSlow1077 * fRec195[1] + fSlow1075 * fRec195[2]);
			fRec196[0] = fTemp0 - (fSlow1082 * fRec196[1] + fSlow1080 * fRec196[2]);
			fRec197[0] = fTemp0 - (fSlow1087 * fRec197[1] + fSlow1085 * fRec197[2]);
			fRec198[0] = fTemp0 - (fSlow1092 * fRec198[1] + fSlow1090 * fRec198[2]);
			fRec199[0] = fTemp0 - (fSlow1097 * fRec199[1] + fSlow1095 * fRec199[2]);
			fRec200[0] = fTemp0 - (fSlow1102 * fRec200[1] + fSlow1100 * fRec200[2]);
			fRec201[0] = fTemp0 - (fSlow1107 * fRec201[1] + fSlow1105 * fRec201[2]);
			fRec202[0] = fTemp0 - (fSlow1112 * fRec202[1] + fSlow1110 * fRec202[2]);
			fRec203[0] = fTemp0 - (fSlow1117 * fRec203[1] + fSlow1115 * fRec203[2]);
			fRec204[0] = fTemp0 - (fSlow1122 * fRec204[1] + fSlow1120 * fRec204[2]);
			fRec205[0] = fTemp0 - (fSlow1127 * fRec205[1] + fSlow1125 * fRec205[2]);
			fRec206[0] = fTemp0 - (fSlow1132 * fRec206[1] + fSlow1130 * fRec206[2]);
			fRec207[0] = fTemp0 - (fSlow1137 * fRec207[1] + fSlow1135 * fRec207[2]);
			fRec208[0] = fTemp0 - (fSlow1142 * fRec208[1] + fSlow1140 * fRec208[2]);
			fRec209[0] = fTemp0 - (fSlow1147 * fRec209[1] + fSlow1145 * fRec209[2]);
			fRec210[0] = fTemp0 - (fSlow1152 * fRec210[1] + fSlow1150 * fRec210[2]);
			fRec211[0] = fTemp0 - (fSlow1157 * fRec211[1] + fSlow1155 * fRec211[2]);
			fRec212[0] = fTemp0 - (fSlow1162 * fRec212[1] + fSlow1160 * fRec212[2]);
			fRec213[0] = fTemp0 - (fSlow1167 * fRec213[1] + fSlow1165 * fRec213[2]);
			fRec214[0] = fTemp0 - (fSlow1172 * fRec214[1] + fSlow1170 * fRec214[2]);
			fRec215[0] = fTemp0 - (fSlow1177 * fRec215[1] + fSlow1175 * fRec215[2]);
			fRec216[0] = fTemp0 - (fSlow1182 * fRec216[1] + fSlow1180 * fRec216[2]);
			fRec217[0] = fTemp0 - (fSlow1187 * fRec217[1] + fSlow1185 * fRec217[2]);
			fRec218[0] = fTemp0 - (fSlow1192 * fRec218[1] + fSlow1190 * fRec218[2]);
			fRec219[0] = fTemp0 - (fSlow1197 * fRec219[1] + fSlow1195 * fRec219[2]);
			fRec220[0] = fTemp0 - (fSlow1202 * fRec220[1] + fSlow1200 * fRec220[2]);
			fRec221[0] = fTemp0 - (fSlow1207 * fRec221[1] + fSlow1205 * fRec221[2]);
			fRec222[0] = fTemp0 - (fSlow1211 * fRec222[1] + fSlow1210 * fRec222[2]);
			fRec223[0] = fTemp0 - (fSlow1215 * fRec223[1] + fSlow1214 * fRec223[2]);
			fRec224[0] = fTemp0 - (fSlow1230 * fRec224[1] + fSlow1225 * fRec224[2]);
			fRec225[0] = fTemp0 - (fSlow1241 * fRec225[1] + fSlow1239 * fRec225[2]);
			fRec226[0] = fTemp0 - (fSlow1246 * fRec226[1] + fSlow1244 * fRec226[2]);
			fRec227[0] = fTemp0 - (fSlow1251 * fRec227[1] + fSlow1249 * fRec227[2]);
			fRec228[0] = fTemp0 - (fSlow1256 * fRec228[1] + fSlow1254 * fRec228[2]);
			fRec229[0] = fTemp0 - (fSlow1261 * fRec229[1] + fSlow1259 * fRec229[2]);
			fRec230[0] = fTemp0 - (fSlow1266 * fRec230[1] + fSlow1264 * fRec230[2]);
			fRec231[0] = fTemp0 - (fSlow1271 * fRec231[1] + fSlow1269 * fRec231[2]);
			fRec232[0] = fTemp0 - (fSlow1276 * fRec232[1] + fSlow1274 * fRec232[2]);
			fRec233[0] = fTemp0 - (fSlow1281 * fRec233[1] + fSlow1279 * fRec233[2]);
			fRec234[0] = fTemp0 - (fSlow1286 * fRec234[1] + fSlow1284 * fRec234[2]);
			fRec235[0] = fTemp0 - (fSlow1291 * fRec235[1] + fSlow1289 * fRec235[2]);
			fRec236[0] = fTemp0 - (fSlow1296 * fRec236[1] + fSlow1294 * fRec236[2]);
			fRec237[0] = fTemp0 - (fSlow1301 * fRec237[1] + fSlow1299 * fRec237[2]);
			fRec238[0] = fTemp0 - (fSlow1306 * fRec238[1] + fSlow1304 * fRec238[2]);
			fRec239[0] = fTemp0 - (fSlow1311 * fRec239[1] + fSlow1309 * fRec239[2]);
			fRec240[0] = fTemp0 - (fSlow1316 * fRec240[1] + fSlow1314 * fRec240[2]);
			fRec241[0] = fTemp0 - (fSlow1321 * fRec241[1] + fSlow1319 * fRec241[2]);
			fRec242[0] = fTemp0 - (fSlow1326 * fRec242[1] + fSlow1324 * fRec242[2]);
			fRec243[0] = fTemp0 - (fSlow1331 * fRec243[1] + fSlow1329 * fRec243[2]);
			fRec244[0] = fTemp0 - (fSlow1336 * fRec244[1] + fSlow1334 * fRec244[2]);
			fRec245[0] = fTemp0 - (fSlow1341 * fRec245[1] + fSlow1339 * fRec245[2]);
			fRec246[0] = fTemp0 - (fSlow1346 * fRec246[1] + fSlow1344 * fRec246[2]);
			fRec247[0] = fTemp0 - (fSlow1351 * fRec247[1] + fSlow1349 * fRec247[2]);
			fRec248[0] = fTemp0 - (fSlow1356 * fRec248[1] + fSlow1354 * fRec248[2]);
			fRec249[0] = fTemp0 - (fSlow1361 * fRec249[1] + fSlow1359 * fRec249[2]);
			fRec250[0] = fTemp0 - (fSlow1366 * fRec250[1] + fSlow1364 * fRec250[2]);
			fRec251[0] = fTemp0 - (fSlow1371 * fRec251[1] + fSlow1369 * fRec251[2]);
			fRec252[0] = fTemp0 - (fSlow1376 * fRec252[1] + fSlow1374 * fRec252[2]);
			fRec253[0] = fTemp0 - (fSlow1381 * fRec253[1] + fSlow1379 * fRec253[2]);
			fRec254[0] = fTemp0 - (fSlow1385 * fRec254[1] + fSlow1384 * fRec254[2]);
			fRec255[0] = fTemp0 - (fSlow1389 * fRec255[1] + fSlow1388 * fRec255[2]);
			output0[i0] = FAUSTFLOAT(0.00390625 * (fSlow1391 * (fSlow1390 * (fRec255[0] - fRec255[2]) + fSlow1386 * (fRec254[0] - fRec254[2]) + fSlow1382 * (fRec253[0] - fRec253[2]) + fSlow1377 * (fRec252[0] - fRec252[2]) + fSlow1372 * (fRec251[0] - fRec251[2]) + fSlow1367 * (fRec250[0] - fRec250[2]) + fSlow1362 * (fRec249[0] - fRec249[2]) + fSlow1357 * (fRec248[0] - fRec248[2]) + fSlow1352 * (fRec247[0] - fRec247[2]) + fSlow1347 * (fRec246[0] - fRec246[2]) + fSlow1342 * (fRec245[0] - fRec245[2]) + fSlow1337 * (fRec244[0] - fRec244[2]) + fSlow1332 * (fRec243[0] - fRec243[2]) + fSlow1327 * (fRec242[0] - fRec242[2]) + fSlow1322 * (fRec241[0] - fRec241[2]) + fSlow1317 * (fRec240[0] - fRec240[2]) + fSlow1312 * (fRec239[0] - fRec239[2]) + fSlow1307 * (fRec238[0] - fRec238[2]) + fSlow1302 * (fRec237[0] - fRec237[2]) + fSlow1297 * (fRec236[0] - fRec236[2]) + fSlow1292 * (fRec235[0] - fRec235[2]) + fSlow1287 * (fRec234[0] - fRec234[2]) + fSlow1282 * (fRec233[0] - fRec233[2]) + fSlow1277 * (fRec232[0] - fRec232[2]) + fSlow1272 * (fRec231[0] - fRec231[2]) + fSlow1267 * (fRec230[0] - fRec230[2]) + fSlow1262 * (fRec229[0] - fRec229[2]) + fSlow1257 * (fRec228[0] - fRec228[2]) + fSlow1252 * (fRec227[0] - fRec227[2]) + fSlow1247 * (fRec226[0] - fRec226[2]) + fSlow1242 * (fRec225[0] - fRec225[2]) + fSlow1237 * (fRec224[0] - fRec224[2])) + fSlow1217 * (fSlow1216 * (fRec223[0] - fRec223[2]) + fSlow1212 * (fRec222[0] - fRec222[2]) + fSlow1208 * (fRec221[0] - fRec221[2]) + fSlow1203 * (fRec220[0] - fRec220[2]) + fSlow1198 * (fRec219[0] - fRec219[2]) + fSlow1193 * (fRec218[0] - fRec218[2]) + fSlow1188 * (fRec217[0] - fRec217[2]) + fSlow1183 * (fRec216[0] - fRec216[2]) + fSlow1178 * (fRec215[0] - fRec215[2]) + fSlow1173 * (fRec214[0] - fRec214[2]) + fSlow1168 * (fRec213[0] - fRec213[2]) + fSlow1163 * (fRec212[0] - fRec212[2]) + fSlow1158 * (fRec211[0] - fRec211[2]) + fSlow1153 * (fRec210[0] - fRec210[2]) + fSlow1148 * (fRec209[0] - fRec209[2]) + fSlow1143 * (fRec208[0] - fRec208[2]) + fSlow1138 * (fRec207[0] - fRec207[2]) + fSlow1133 * (fRec206[0] - fRec206[2]) + fSlow1128 * (fRec205[0] - fRec205[2]) + fSlow1123 * (fRec204[0] - fRec204[2]) + fSlow1118 * (fRec203[0] - fRec203[2]) + fSlow1113 * (fRec202[0] - fRec202[2]) + fSlow1108 * (fRec201[0] - fRec201[2]) + fSlow1103 * (fRec200[0] - fRec200[2]) + fSlow1098 * (fRec199[0] - fRec199[2]) + fSlow1093 * (fRec198[0] - fRec198[2]) + fSlow1088 * (fRec197[0] - fRec197[2]) + fSlow1083 * (fRec196[0] - fRec196[2]) + fSlow1078 * (fRec195[0] - fRec195[2]) + fSlow1073 * (fRec194[0] - fRec194[2]) + fSlow1068 * (fRec193[0] - fRec193[2]) + fSlow1063 * (fRec192[0] - fRec192[2])) + fSlow1043 * (fSlow1042 * (fRec191[0] - fRec191[2]) + fSlow1038 * (fRec190[0] - fRec190[2]) + fSlow1034 * (fRec189[0] - fRec189[2]) + fSlow1029 * (fRec188[0] - fRec188[2]) + fSlow1024 * (fRec187[0] - fRec187[2]) + fSlow1019 * (fRec186[0] - fRec186[2]) + fSlow1014 * (fRec185[0] - fRec185[2]) + fSlow1009 * (fRec184[0] - fRec184[2]) + fSlow1004 * (fRec183[0] - fRec183[2]) + fSlow999 * (fRec182[0] - fRec182[2]) + fSlow994 * (fRec181[0] - fRec181[2]) + fSlow989 * (fRec180[0] - fRec180[2]) + fSlow984 * (fRec179[0] - fRec179[2]) + fSlow979 * (fRec178[0] - fRec178[2]) + fSlow974 * (fRec177[0] - fRec177[2]) + fSlow969 * (fRec176[0] - fRec176[2]) + fSlow964 * (fRec175[0] - fRec175[2]) + fSlow959 * (fRec174[0] - fRec174[2]) + fSlow954 * (fRec173[0] - fRec173[2]) + fSlow949 * (fRec172[0] - fRec172[2]) + fSlow944 * (fRec171[0] - fRec171[2]) + fSlow939 * (fRec170[0] - fRec170[2]) + fSlow934 * (fRec169[0] - fRec169[2]) + fSlow929 * (fRec168[0] - fRec168[2]) + fSlow924 * (fRec167[0] - fRec167[2]) + fSlow919 * (fRec166[0] - fRec166[2]) + fSlow914 * (fRec165[0] - fRec165[2]) + fSlow909 * (fRec164[0] - fRec164[2]) + fSlow904 * (fRec163[0] - fRec163[2]) + fSlow899 * (fRec162[0] - fRec162[2]) + fSlow894 * (fRec161[0] - fRec161[2]) + fSlow889 * (fRec160[0] - fRec160[2])) + fSlow869 * (fSlow868 * (fRec159[0] - fRec159[2]) + fSlow864 * (fRec158[0] - fRec158[2]) + fSlow860 * (fRec157[0] - fRec157[2]) + fSlow855 * (fRec156[0] - fRec156[2]) + fSlow850 * (fRec155[0] - fRec155[2]) + fSlow845 * (fRec154[0] - fRec154[2]) + fSlow840 * (fRec153[0] - fRec153[2]) + fSlow835 * (fRec152[0] - fRec152[2]) + fSlow830 * (fRec151[0] - fRec151[2]) + fSlow825 * (fRec150[0] - fRec150[2]) + fSlow820 * (fRec149[0] - fRec149[2]) + fSlow815 * (fRec148[0] - fRec148[2]) + fSlow810 * (fRec147[0] - fRec147[2]) + fSlow805 * (fRec146[0] - fRec146[2]) + fSlow800 * (fRec145[0] - fRec145[2]) + fSlow795 * (fRec144[0] - fRec144[2]) + fSlow790 * (fRec143[0] - fRec143[2]) + fSlow785 * (fRec142[0] - fRec142[2]) + fSlow780 * (fRec141[0] - fRec141[2]) + fSlow775 * (fRec140[0] - fRec140[2]) + fSlow770 * (fRec139[0] - fRec139[2]) + fSlow765 * (fRec138[0] - fRec138[2]) + fSlow760 * (fRec137[0] - fRec137[2]) + fSlow755 * (fRec136[0] - fRec136[2]) + fSlow750 * (fRec135[0] - fRec135[2]) + fSlow745 * (fRec134[0] - fRec134[2]) + fSlow740 * (fRec133[0] - fRec133[2]) + fSlow735 * (fRec132[0] - fRec132[2]) + fSlow730 * (fRec131[0] - fRec131[2]) + fSlow725 * (fRec130[0] - fRec130[2]) + fSlow720 * (fRec129[0] - fRec129[2]) + fSlow715 * (fRec128[0] - fRec128[2])) + fSlow695 * (fSlow694 * (fRec127[0] - fRec127[2]) + fSlow690 * (fRec126[0] - fRec126[2]) + fSlow686 * (fRec125[0] - fRec125[2]) + fSlow681 * (fRec124[0] - fRec124[2]) + fSlow676 * (fRec123[0] - fRec123[2]) + fSlow671 * (fRec122[0] - fRec122[2]) + fSlow666 * (fRec121[0] - fRec121[2]) + fSlow661 * (fRec120[0] - fRec120[2]) + fSlow656 * (fRec119[0] - fRec119[2]) + fSlow651 * (fRec118[0] - fRec118[2]) + fSlow646 * (fRec117[0] - fRec117[2]) + fSlow641 * (fRec116[0] - fRec116[2]) + fSlow636 * (fRec115[0] - fRec115[2]) + fSlow631 * (fRec114[0] - fRec114[2]) + fSlow626 * (fRec113[0] - fRec113[2]) + fSlow621 * (fRec112[0] - fRec112[2]) + fSlow616 * (fRec111[0] - fRec111[2]) + fSlow611 * (fRec110[0] - fRec110[2]) + fSlow606 * (fRec109[0] - fRec109[2]) + fSlow601 * (fRec108[0] - fRec108[2]) + fSlow596 * (fRec107[0] - fRec107[2]) + fSlow591 * (fRec106[0] - fRec106[2]) + fSlow586 * (fRec105[0] - fRec105[2]) + fSlow581 * (fRec104[0] - fRec104[2]) + fSlow576 * (fRec103[0] - fRec103[2]) + fSlow571 * (fRec102[0] - fRec102[2]) + fSlow566 * (fRec101[0] - fRec101[2]) + fSlow561 * (fRec100[0] - fRec100[2]) + fSlow556 * (fRec99[0] - fRec99[2]) + fSlow551 * (fRec98[0] - fRec98[2]) + fSlow546 * (fRec97[0] - fRec97[2]) + fSlow541 * (fRec96[0] - fRec96[2])) + fSlow521 * (fSlow520 * (fRec95[0] - fRec95[2]) + fSlow516 * (fRec94[0] - fRec94[2]) + fSlow512 * (fRec93[0] - fRec93[2]) + fSlow507 * (fRec92[0] - fRec92[2]) + fSlow502 * (fRec91[0] - fRec91[2]) + fSlow497 * (fRec90[0] - fRec90[2]) + fSlow492 * (fRec89[0] - fRec89[2]) + fSlow487 * (fRec88[0] - fRec88[2]) + fSlow482 * (fRec87[0] - fRec87[2]) + fSlow477 * (fRec86[0] - fRec86[2]) + fSlow472 * (fRec85[0] - fRec85[2]) + fSlow467 * (fRec84[0] - fRec84[2]) + fSlow462 * (fRec83[0] - fRec83[2]) + fSlow457 * (fRec82[0] - fRec82[2]) + fSlow452 * (fRec81[0] - fRec81[2]) + fSlow447 * (fRec80[0] - fRec80[2]) + fSlow442 * (fRec79[0] - fRec79[2]) + fSlow437 * (fRec78[0] - fRec78[2]) + fSlow432 * (fRec77[0] - fRec77[2]) + fSlow427 * (fRec76[0] - fRec76[2]) + fSlow422 * (fRec75[0] - fRec75[2]) + fSlow417 * (fRec74[0] - fRec74[2]) + fSlow412 * (fRec73[0] - fRec73[2]) + fSlow407 * (fRec72[0] - fRec72[2]) + fSlow402 * (fRec71[0] - fRec71[2]) + fSlow397 * (fRec70[0] - fRec70[2]) + fSlow392 * (fRec69[0] - fRec69[2]) + fSlow387 * (fRec68[0] - fRec68[2]) + fSlow382 * (fRec67[0] - fRec67[2]) + fSlow377 * (fRec66[0] - fRec66[2]) + fSlow372 * (fRec65[0] - fRec65[2]) + fSlow367 * (fRec64[0] - fRec64[2])) + fSlow347 * (fSlow346 * (fRec63[0] - fRec63[2]) + fSlow342 * (fRec62[0] - fRec62[2]) + fSlow338 * (fRec61[0] - fRec61[2]) + fSlow333 * (fRec60[0] - fRec60[2]) + fSlow328 * (fRec59[0] - fRec59[2]) + fSlow323 * (fRec58[0] - fRec58[2]) + fSlow318 * (fRec57[0] - fRec57[2]) + fSlow313 * (fRec56[0] - fRec56[2]) + fSlow308 * (fRec55[0] - fRec55[2]) + fSlow303 * (fRec54[0] - fRec54[2]) + fSlow298 * (fRec53[0] - fRec53[2]) + fSlow293 * (fRec52[0] - fRec52[2]) + fSlow288 * (fRec51[0] - fRec51[2]) + fSlow283 * (fRec50[0] - fRec50[2]) + fSlow278 * (fRec49[0] - fRec49[2]) + fSlow273 * (fRec48[0] - fRec48[2]) + fSlow268 * (fRec47[0] - fRec47[2]) + fSlow263 * (fRec46[0] - fRec46[2]) + fSlow258 * (fRec45[0] - fRec45[2]) + fSlow253 * (fRec44[0] - fRec44[2]) + fSlow248 * (fRec43[0] - fRec43[2]) + fSlow243 * (fRec42[0] - fRec42[2]) + fSlow238 * (fRec41[0] - fRec41[2]) + fSlow233 * (fRec40[0] - fRec40[2]) + fSlow228 * (fRec39[0] - fRec39[2]) + fSlow223 * (fRec38[0] - fRec38[2]) + fSlow218 * (fRec37[0] - fRec37[2]) + fSlow213 * (fRec36[0] - fRec36[2]) + fSlow208 * (fRec35[0] - fRec35[2]) + fSlow203 * (fRec34[0] - fRec34[2]) + fSlow198 * (fRec33[0] - fRec33[2]) + fSlow193 * (fRec32[0] - fRec32[2])) + fSlow173 * (fSlow172 * (fRec31[0] - fRec31[2]) + fSlow168 * (fRec30[0] - fRec30[2]) + fSlow164 * (fRec29[0] - fRec29[2]) + fSlow159 * (fRec28[0] - fRec28[2]) + fSlow154 * (fRec27[0] - fRec27[2]) + fSlow149 * (fRec26[0] - fRec26[2]) + fSlow144 * (fRec25[0] - fRec25[2]) + fSlow139 * (fRec24[0] - fRec24[2]) + fSlow134 * (fRec23[0] - fRec23[2]) + fSlow129 * (fRec22[0] - fRec22[2]) + fSlow124 * (fRec21[0] - fRec21[2]) + fSlow119 * (fRec20[0] - fRec20[2]) + fSlow114 * (fRec19[0] - fRec19[2]) + fSlow109 * (fRec18[0] - fRec18[2]) + fSlow104 * (fRec17[0] - fRec17[2]) + fSlow99 * (fRec16[0] - fRec16[2]) + fSlow94 * (fRec15[0] - fRec15[2]) + fSlow89 * (fRec14[0] - fRec14[2]) + fSlow84 * (fRec13[0] - fRec13[2]) + fSlow79 * (fRec12[0] - fRec12[2]) + fSlow74 * (fRec11[0] - fRec11[2]) + fSlow69 * (fRec10[0] - fRec10[2]) + fSlow64 * (fRec9[0] - fRec9[2]) + fSlow59 * (fRec8[0] - fRec8[2]) + fSlow54 * (fRec7[0] - fRec7[2]) + fSlow49 * (fRec6[0] - fRec6[2]) + fSlow44 * (fRec5[0] - fRec5[2]) + fSlow39 * (fRec4[0] - fRec4[2]) + fSlow34 * (fRec3[0] - fRec3[2]) + fSlow29 * (fRec2[0] - fRec2[2]) + fSlow24 * (fRec1[0] - fRec1[2]) + fSlow19 * (fRec0[0] - fRec0[2]))));
			double fTemp1 = double(input1[i0]);
			fRec256[0] = fTemp1 - (fSlow12 * fRec256[1] + fSlow7 * fRec256[2]);
			fRec257[0] = fTemp1 - (fSlow23 * fRec257[1] + fSlow21 * fRec257[2]);
			fRec258[0] = fTemp1 - (fSlow28 * fRec258[1] + fSlow26 * fRec258[2]);
			fRec259[0] = fTemp1 - (fSlow33 * fRec259[1] + fSlow31 * fRec259[2]);
			fRec260[0] = fTemp1 - (fSlow38 * fRec260[1] + fSlow36 * fRec260[2]);
			fRec261[0] = fTemp1 - (fSlow43 * fRec261[1] + fSlow41 * fRec261[2]);
			fRec262[0] = fTemp1 - (fSlow48 * fRec262[1] + fSlow46 * fRec262[2]);
			fRec263[0] = fTemp1 - (fSlow53 * fRec263[1] + fSlow51 * fRec263[2]);
			fRec264[0] = fTemp1 - (fSlow58 * fRec264[1] + fSlow56 * fRec264[2]);
			fRec265[0] = fTemp1 - (fSlow63 * fRec265[1] + fSlow61 * fRec265[2]);
			fRec266[0] = fTemp1 - (fSlow68 * fRec266[1] + fSlow66 * fRec266[2]);
			fRec267[0] = fTemp1 - (fSlow73 * fRec267[1] + fSlow71 * fRec267[2]);
			fRec268[0] = fTemp1 - (fSlow78 * fRec268[1] + fSlow76 * fRec268[2]);
			fRec269[0] = fTemp1 - (fSlow83 * fRec269[1] + fSlow81 * fRec269[2]);
			fRec270[0] = fTemp1 - (fSlow88 * fRec270[1] + fSlow86 * fRec270[2]);
			fRec271[0] = fTemp1 - (fSlow93 * fRec271[1] + fSlow91 * fRec271[2]);
			fRec272[0] = fTemp1 - (fSlow98 * fRec272[1] + fSlow96 * fRec272[2]);
			fRec273[0] = fTemp1 - (fSlow103 * fRec273[1] + fSlow101 * fRec273[2]);
			fRec274[0] = fTemp1 - (fSlow108 * fRec274[1] + fSlow106 * fRec274[2]);
			fRec275[0] = fTemp1 - (fSlow113 * fRec275[1] + fSlow111 * fRec275[2]);
			fRec276[0] = fTemp1 - (fSlow118 * fRec276[1] + fSlow116 * fRec276[2]);
			fRec277[0] = fTemp1 - (fSlow123 * fRec277[1] + fSlow121 * fRec277[2]);
			fRec278[0] = fTemp1 - (fSlow128 * fRec278[1] + fSlow126 * fRec278[2]);
			fRec279[0] = fTemp1 - (fSlow133 * fRec279[1] + fSlow131 * fRec279[2]);
			fRec280[0] = fTemp1 - (fSlow138 * fRec280[1] + fSlow136 * fRec280[2]);
			fRec281[0] = fTemp1 - (fSlow143 * fRec281[1] + fSlow141 * fRec281[2]);
			fRec282[0] = fTemp1 - (fSlow148 * fRec282[1] + fSlow146 * fRec282[2]);
			fRec283[0] = fTemp1 - (fSlow153 * fRec283[1] + fSlow151 * fRec283[2]);
			fRec284[0] = fTemp1 - (fSlow158 * fRec284[1] + fSlow156 * fRec284[2]);
			fRec285[0] = fTemp1 - (fSlow163 * fRec285[1] + fSlow161 * fRec285[2]);
			fRec286[0] = fTemp1 - (fSlow167 * fRec286[1] + fSlow166 * fRec286[2]);
			fRec287[0] = fTemp1 - (fSlow171 * fRec287[1] + fSlow170 * fRec287[2]);
			fRec288[0] = fTemp1 - (fSlow186 * fRec288[1] + fSlow181 * fRec288[2]);
			fRec289[0] = fTemp1 - (fSlow197 * fRec289[1] + fSlow195 * fRec289[2]);
			fRec290[0] = fTemp1 - (fSlow202 * fRec290[1] + fSlow200 * fRec290[2]);
			fRec291[0] = fTemp1 - (fSlow207 * fRec291[1] + fSlow205 * fRec291[2]);
			fRec292[0] = fTemp1 - (fSlow212 * fRec292[1] + fSlow210 * fRec292[2]);
			fRec293[0] = fTemp1 - (fSlow217 * fRec293[1] + fSlow215 * fRec293[2]);
			fRec294[0] = fTemp1 - (fSlow222 * fRec294[1] + fSlow220 * fRec294[2]);
			fRec295[0] = fTemp1 - (fSlow227 * fRec295[1] + fSlow225 * fRec295[2]);
			fRec296[0] = fTemp1 - (fSlow232 * fRec296[1] + fSlow230 * fRec296[2]);
			fRec297[0] = fTemp1 - (fSlow237 * fRec297[1] + fSlow235 * fRec297[2]);
			fRec298[0] = fTemp1 - (fSlow242 * fRec298[1] + fSlow240 * fRec298[2]);
			fRec299[0] = fTemp1 - (fSlow247 * fRec299[1] + fSlow245 * fRec299[2]);
			fRec300[0] = fTemp1 - (fSlow252 * fRec300[1] + fSlow250 * fRec300[2]);
			fRec301[0] = fTemp1 - (fSlow257 * fRec301[1] + fSlow255 * fRec301[2]);
			fRec302[0] = fTemp1 - (fSlow262 * fRec302[1] + fSlow260 * fRec302[2]);
			fRec303[0] = fTemp1 - (fSlow267 * fRec303[1] + fSlow265 * fRec303[2]);
			fRec304[0] = fTemp1 - (fSlow272 * fRec304[1] + fSlow270 * fRec304[2]);
			fRec305[0] = fTemp1 - (fSlow277 * fRec305[1] + fSlow275 * fRec305[2]);
			fRec306[0] = fTemp1 - (fSlow282 * fRec306[1] + fSlow280 * fRec306[2]);
			fRec307[0] = fTemp1 - (fSlow287 * fRec307[1] + fSlow285 * fRec307[2]);
			fRec308[0] = fTemp1 - (fSlow292 * fRec308[1] + fSlow290 * fRec308[2]);
			fRec309[0] = fTemp1 - (fSlow297 * fRec309[1] + fSlow295 * fRec309[2]);
			fRec310[0] = fTemp1 - (fSlow302 * fRec310[1] + fSlow300 * fRec310[2]);
			fRec311[0] = fTemp1 - (fSlow307 * fRec311[1] + fSlow305 * fRec311[2]);
			fRec312[0] = fTemp1 - (fSlow312 * fRec312[1] + fSlow310 * fRec312[2]);
			fRec313[0] = fTemp1 - (fSlow317 * fRec313[1] + fSlow315 * fRec313[2]);
			fRec314[0] = fTemp1 - (fSlow322 * fRec314[1] + fSlow320 * fRec314[2]);
			fRec315[0] = fTemp1 - (fSlow327 * fRec315[1] + fSlow325 * fRec315[2]);
			fRec316[0] = fTemp1 - (fSlow332 * fRec316[1] + fSlow330 * fRec316[2]);
			fRec317[0] = fTemp1 - (fSlow337 * fRec317[1] + fSlow335 * fRec317[2]);
			fRec318[0] = fTemp1 - (fSlow341 * fRec318[1] + fSlow340 * fRec318[2]);
			fRec319[0] = fTemp1 - (fSlow345 * fRec319[1] + fSlow344 * fRec319[2]);
			fRec320[0] = fTemp1 - (fSlow360 * fRec320[1] + fSlow355 * fRec320[2]);
			fRec321[0] = fTemp1 - (fSlow371 * fRec321[1] + fSlow369 * fRec321[2]);
			fRec322[0] = fTemp1 - (fSlow376 * fRec322[1] + fSlow374 * fRec322[2]);
			fRec323[0] = fTemp1 - (fSlow381 * fRec323[1] + fSlow379 * fRec323[2]);
			fRec324[0] = fTemp1 - (fSlow386 * fRec324[1] + fSlow384 * fRec324[2]);
			fRec325[0] = fTemp1 - (fSlow391 * fRec325[1] + fSlow389 * fRec325[2]);
			fRec326[0] = fTemp1 - (fSlow396 * fRec326[1] + fSlow394 * fRec326[2]);
			fRec327[0] = fTemp1 - (fSlow401 * fRec327[1] + fSlow399 * fRec327[2]);
			fRec328[0] = fTemp1 - (fSlow406 * fRec328[1] + fSlow404 * fRec328[2]);
			fRec329[0] = fTemp1 - (fSlow411 * fRec329[1] + fSlow409 * fRec329[2]);
			fRec330[0] = fTemp1 - (fSlow416 * fRec330[1] + fSlow414 * fRec330[2]);
			fRec331[0] = fTemp1 - (fSlow421 * fRec331[1] + fSlow419 * fRec331[2]);
			fRec332[0] = fTemp1 - (fSlow426 * fRec332[1] + fSlow424 * fRec332[2]);
			fRec333[0] = fTemp1 - (fSlow431 * fRec333[1] + fSlow429 * fRec333[2]);
			fRec334[0] = fTemp1 - (fSlow436 * fRec334[1] + fSlow434 * fRec334[2]);
			fRec335[0] = fTemp1 - (fSlow441 * fRec335[1] + fSlow439 * fRec335[2]);
			fRec336[0] = fTemp1 - (fSlow446 * fRec336[1] + fSlow444 * fRec336[2]);
			fRec337[0] = fTemp1 - (fSlow451 * fRec337[1] + fSlow449 * fRec337[2]);
			fRec338[0] = fTemp1 - (fSlow456 * fRec338[1] + fSlow454 * fRec338[2]);
			fRec339[0] = fTemp1 - (fSlow461 * fRec339[1] + fSlow459 * fRec339[2]);
			fRec340[0] = fTemp1 - (fSlow466 * fRec340[1] + fSlow464 * fRec340[2]);
			fRec341[0] = fTemp1 - (fSlow471 * fRec341[1] + fSlow469 * fRec341[2]);
			fRec342[0] = fTemp1 - (fSlow476 * fRec342[1] + fSlow474 * fRec342[2]);
			fRec343[0] = fTemp1 - (fSlow481 * fRec343[1] + fSlow479 * fRec343[2]);
			fRec344[0] = fTemp1 - (fSlow486 * fRec344[1] + fSlow484 * fRec344[2]);
			fRec345[0] = fTemp1 - (fSlow491 * fRec345[1] + fSlow489 * fRec345[2]);
			fRec346[0] = fTemp1 - (fSlow496 * fRec346[1] + fSlow494 * fRec346[2]);
			fRec347[0] = fTemp1 - (fSlow501 * fRec347[1] + fSlow499 * fRec347[2]);
			fRec348[0] = fTemp1 - (fSlow506 * fRec348[1] + fSlow504 * fRec348[2]);
			fRec349[0] = fTemp1 - (fSlow511 * fRec349[1] + fSlow509 * fRec349[2]);
			fRec350[0] = fTemp1 - (fSlow515 * fRec350[1] + fSlow514 * fRec350[2]);
			fRec351[0] = fTemp1 - (fSlow519 * fRec351[1] + fSlow518 * fRec351[2]);
			fRec352[0] = fTemp1 - (fSlow534 * fRec352[1] + fSlow529 * fRec352[2]);
			fRec353[0] = fTemp1 - (fSlow545 * fRec353[1] + fSlow543 * fRec353[2]);
			fRec354[0] = fTemp1 - (fSlow550 * fRec354[1] + fSlow548 * fRec354[2]);
			fRec355[0] = fTemp1 - (fSlow555 * fRec355[1] + fSlow553 * fRec355[2]);
			fRec356[0] = fTemp1 - (fSlow560 * fRec356[1] + fSlow558 * fRec356[2]);
			fRec357[0] = fTemp1 - (fSlow565 * fRec357[1] + fSlow563 * fRec357[2]);
			fRec358[0] = fTemp1 - (fSlow570 * fRec358[1] + fSlow568 * fRec358[2]);
			fRec359[0] = fTemp1 - (fSlow575 * fRec359[1] + fSlow573 * fRec359[2]);
			fRec360[0] = fTemp1 - (fSlow580 * fRec360[1] + fSlow578 * fRec360[2]);
			fRec361[0] = fTemp1 - (fSlow585 * fRec361[1] + fSlow583 * fRec361[2]);
			fRec362[0] = fTemp1 - (fSlow590 * fRec362[1] + fSlow588 * fRec362[2]);
			fRec363[0] = fTemp1 - (fSlow595 * fRec363[1] + fSlow593 * fRec363[2]);
			fRec364[0] = fTemp1 - (fSlow600 * fRec364[1] + fSlow598 * fRec364[2]);
			fRec365[0] = fTemp1 - (fSlow605 * fRec365[1] + fSlow603 * fRec365[2]);
			fRec366[0] = fTemp1 - (fSlow610 * fRec366[1] + fSlow608 * fRec366[2]);
			fRec367[0] = fTemp1 - (fSlow615 * fRec367[1] + fSlow613 * fRec367[2]);
			fRec368[0] = fTemp1 - (fSlow620 * fRec368[1] + fSlow618 * fRec368[2]);
			fRec369[0] = fTemp1 - (fSlow625 * fRec369[1] + fSlow623 * fRec369[2]);
			fRec370[0] = fTemp1 - (fSlow630 * fRec370[1] + fSlow628 * fRec370[2]);
			fRec371[0] = fTemp1 - (fSlow635 * fRec371[1] + fSlow633 * fRec371[2]);
			fRec372[0] = fTemp1 - (fSlow640 * fRec372[1] + fSlow638 * fRec372[2]);
			fRec373[0] = fTemp1 - (fSlow645 * fRec373[1] + fSlow643 * fRec373[2]);
			fRec374[0] = fTemp1 - (fSlow650 * fRec374[1] + fSlow648 * fRec374[2]);
			fRec375[0] = fTemp1 - (fSlow655 * fRec375[1] + fSlow653 * fRec375[2]);
			fRec376[0] = fTemp1 - (fSlow660 * fRec376[1] + fSlow658 * fRec376[2]);
			fRec377[0] = fTemp1 - (fSlow665 * fRec377[1] + fSlow663 * fRec377[2]);
			fRec378[0] = fTemp1 - (fSlow670 * fRec378[1] + fSlow668 * fRec378[2]);
			fRec379[0] = fTemp1 - (fSlow675 * fRec379[1] + fSlow673 * fRec379[2]);
			fRec380[0] = fTemp1 - (fSlow680 * fRec380[1] + fSlow678 * fRec380[2]);
			fRec381[0] = fTemp1 - (fSlow685 * fRec381[1] + fSlow683 * fRec381[2]);
			fRec382[0] = fTemp1 - (fSlow689 * fRec382[1] + fSlow688 * fRec382[2]);
			fRec383[0] = fTemp1 - (fSlow693 * fRec383[1] + fSlow692 * fRec383[2]);
			fRec384[0] = fTemp1 - (fSlow708 * fRec384[1] + fSlow703 * fRec384[2]);
			fRec385[0] = fTemp1 - (fSlow719 * fRec385[1] + fSlow717 * fRec385[2]);
			fRec386[0] = fTemp1 - (fSlow724 * fRec386[1] + fSlow722 * fRec386[2]);
			fRec387[0] = fTemp1 - (fSlow729 * fRec387[1] + fSlow727 * fRec387[2]);
			fRec388[0] = fTemp1 - (fSlow734 * fRec388[1] + fSlow732 * fRec388[2]);
			fRec389[0] = fTemp1 - (fSlow739 * fRec389[1] + fSlow737 * fRec389[2]);
			fRec390[0] = fTemp1 - (fSlow744 * fRec390[1] + fSlow742 * fRec390[2]);
			fRec391[0] = fTemp1 - (fSlow749 * fRec391[1] + fSlow747 * fRec391[2]);
			fRec392[0] = fTemp1 - (fSlow754 * fRec392[1] + fSlow752 * fRec392[2]);
			fRec393[0] = fTemp1 - (fSlow759 * fRec393[1] + fSlow757 * fRec393[2]);
			fRec394[0] = fTemp1 - (fSlow764 * fRec394[1] + fSlow762 * fRec394[2]);
			fRec395[0] = fTemp1 - (fSlow769 * fRec395[1] + fSlow767 * fRec395[2]);
			fRec396[0] = fTemp1 - (fSlow774 * fRec396[1] + fSlow772 * fRec396[2]);
			fRec397[0] = fTemp1 - (fSlow779 * fRec397[1] + fSlow777 * fRec397[2]);
			fRec398[0] = fTemp1 - (fSlow784 * fRec398[1] + fSlow782 * fRec398[2]);
			fRec399[0] = fTemp1 - (fSlow789 * fRec399[1] + fSlow787 * fRec399[2]);
			fRec400[0] = fTemp1 - (fSlow794 * fRec400[1] + fSlow792 * fRec400[2]);
			fRec401[0] = fTemp1 - (fSlow799 * fRec401[1] + fSlow797 * fRec401[2]);
			fRec402[0] = fTemp1 - (fSlow804 * fRec402[1] + fSlow802 * fRec402[2]);
			fRec403[0] = fTemp1 - (fSlow809 * fRec403[1] + fSlow807 * fRec403[2]);
			fRec404[0] = fTemp1 - (fSlow814 * fRec404[1] + fSlow812 * fRec404[2]);
			fRec405[0] = fTemp1 - (fSlow819 * fRec405[1] + fSlow817 * fRec405[2]);
			fRec406[0] = fTemp1 - (fSlow824 * fRec406[1] + fSlow822 * fRec406[2]);
			fRec407[0] = fTemp1 - (fSlow829 * fRec407[1] + fSlow827 * fRec407[2]);
			fRec408[0] = fTemp1 - (fSlow834 * fRec408[1] + fSlow832 * fRec408[2]);
			fRec409[0] = fTemp1 - (fSlow839 * fRec409[1] + fSlow837 * fRec409[2]);
			fRec410[0] = fTemp1 - (fSlow844 * fRec410[1] + fSlow842 * fRec410[2]);
			fRec411[0] = fTemp1 - (fSlow849 * fRec411[1] + fSlow847 * fRec411[2]);
			fRec412[0] = fTemp1 - (fSlow854 * fRec412[1] + fSlow852 * fRec412[2]);
			fRec413[0] = fTemp1 - (fSlow859 * fRec413[1] + fSlow857 * fRec413[2]);
			fRec414[0] = fTemp1 - (fSlow863 * fRec414[1] + fSlow862 * fRec414[2]);
			fRec415[0] = fTemp1 - (fSlow867 * fRec415[1] + fSlow866 * fRec415[2]);
			fRec416[0] = fTemp1 - (fSlow882 * fRec416[1] + fSlow877 * fRec416[2]);
			fRec417[0] = fTemp1 - (fSlow893 * fRec417[1] + fSlow891 * fRec417[2]);
			fRec418[0] = fTemp1 - (fSlow898 * fRec418[1] + fSlow896 * fRec418[2]);
			fRec419[0] = fTemp1 - (fSlow903 * fRec419[1] + fSlow901 * fRec419[2]);
			fRec420[0] = fTemp1 - (fSlow908 * fRec420[1] + fSlow906 * fRec420[2]);
			fRec421[0] = fTemp1 - (fSlow913 * fRec421[1] + fSlow911 * fRec421[2]);
			fRec422[0] = fTemp1 - (fSlow918 * fRec422[1] + fSlow916 * fRec422[2]);
			fRec423[0] = fTemp1 - (fSlow923 * fRec423[1] + fSlow921 * fRec423[2]);
			fRec424[0] = fTemp1 - (fSlow928 * fRec424[1] + fSlow926 * fRec424[2]);
			fRec425[0] = fTemp1 - (fSlow933 * fRec425[1] + fSlow931 * fRec425[2]);
			fRec426[0] = fTemp1 - (fSlow938 * fRec426[1] + fSlow936 * fRec426[2]);
			fRec427[0] = fTemp1 - (fSlow943 * fRec427[1] + fSlow941 * fRec427[2]);
			fRec428[0] = fTemp1 - (fSlow948 * fRec428[1] + fSlow946 * fRec428[2]);
			fRec429[0] = fTemp1 - (fSlow953 * fRec429[1] + fSlow951 * fRec429[2]);
			fRec430[0] = fTemp1 - (fSlow958 * fRec430[1] + fSlow956 * fRec430[2]);
			fRec431[0] = fTemp1 - (fSlow963 * fRec431[1] + fSlow961 * fRec431[2]);
			fRec432[0] = fTemp1 - (fSlow968 * fRec432[1] + fSlow966 * fRec432[2]);
			fRec433[0] = fTemp1 - (fSlow973 * fRec433[1] + fSlow971 * fRec433[2]);
			fRec434[0] = fTemp1 - (fSlow978 * fRec434[1] + fSlow976 * fRec434[2]);
			fRec435[0] = fTemp1 - (fSlow983 * fRec435[1] + fSlow981 * fRec435[2]);
			fRec436[0] = fTemp1 - (fSlow988 * fRec436[1] + fSlow986 * fRec436[2]);
			fRec437[0] = fTemp1 - (fSlow993 * fRec437[1] + fSlow991 * fRec437[2]);
			fRec438[0] = fTemp1 - (fSlow998 * fRec438[1] + fSlow996 * fRec438[2]);
			fRec439[0] = fTemp1 - (fSlow1003 * fRec439[1] + fSlow1001 * fRec439[2]);
			fRec440[0] = fTemp1 - (fSlow1008 * fRec440[1] + fSlow1006 * fRec440[2]);
			fRec441[0] = fTemp1 - (fSlow1013 * fRec441[1] + fSlow1011 * fRec441[2]);
			fRec442[0] = fTemp1 - (fSlow1018 * fRec442[1] + fSlow1016 * fRec442[2]);
			fRec443[0] = fTemp1 - (fSlow1023 * fRec443[1] + fSlow1021 * fRec443[2]);
			fRec444[0] = fTemp1 - (fSlow1028 * fRec444[1] + fSlow1026 * fRec444[2]);
			fRec445[0] = fTemp1 - (fSlow1033 * fRec445[1] + fSlow1031 * fRec445[2]);
			fRec446[0] = fTemp1 - (fSlow1037 * fRec446[1] + fSlow1036 * fRec446[2]);
			fRec447[0] = fTemp1 - (fSlow1041 * fRec447[1] + fSlow1040 * fRec447[2]);
			fRec448[0] = fTemp1 - (fSlow1056 * fRec448[1] + fSlow1051 * fRec448[2]);
			fRec449[0] = fTemp1 - (fSlow1067 * fRec449[1] + fSlow1065 * fRec449[2]);
			fRec450[0] = fTemp1 - (fSlow1072 * fRec450[1] + fSlow1070 * fRec450[2]);
			fRec451[0] = fTemp1 - (fSlow1077 * fRec451[1] + fSlow1075 * fRec451[2]);
			fRec452[0] = fTemp1 - (fSlow1082 * fRec452[1] + fSlow1080 * fRec452[2]);
			fRec453[0] = fTemp1 - (fSlow1087 * fRec453[1] + fSlow1085 * fRec453[2]);
			fRec454[0] = fTemp1 - (fSlow1092 * fRec454[1] + fSlow1090 * fRec454[2]);
			fRec455[0] = fTemp1 - (fSlow1097 * fRec455[1] + fSlow1095 * fRec455[2]);
			fRec456[0] = fTemp1 - (fSlow1102 * fRec456[1] + fSlow1100 * fRec456[2]);
			fRec457[0] = fTemp1 - (fSlow1107 * fRec457[1] + fSlow1105 * fRec457[2]);
			fRec458[0] = fTemp1 - (fSlow1112 * fRec458[1] + fSlow1110 * fRec458[2]);
			fRec459[0] = fTemp1 - (fSlow1117 * fRec459[1] + fSlow1115 * fRec459[2]);
			fRec460[0] = fTemp1 - (fSlow1122 * fRec460[1] + fSlow1120 * fRec460[2]);
			fRec461[0] = fTemp1 - (fSlow1127 * fRec461[1] + fSlow1125 * fRec461[2]);
			fRec462[0] = fTemp1 - (fSlow1132 * fRec462[1] + fSlow1130 * fRec462[2]);
			fRec463[0] = fTemp1 - (fSlow1137 * fRec463[1] + fSlow1135 * fRec463[2]);
			fRec464[0] = fTemp1 - (fSlow1142 * fRec464[1] + fSlow1140 * fRec464[2]);
			fRec465[0] = fTemp1 - (fSlow1147 * fRec465[1] + fSlow1145 * fRec465[2]);
			fRec466[0] = fTemp1 - (fSlow1152 * fRec466[1] + fSlow1150 * fRec466[2]);
			fRec467[0] = fTemp1 - (fSlow1157 * fRec467[1] + fSlow1155 * fRec467[2]);
			fRec468[0] = fTemp1 - (fSlow1162 * fRec468[1] + fSlow1160 * fRec468[2]);
			fRec469[0] = fTemp1 - (fSlow1167 * fRec469[1] + fSlow1165 * fRec469[2]);
			fRec470[0] = fTemp1 - (fSlow1172 * fRec470[1] + fSlow1170 * fRec470[2]);
			fRec471[0] = fTemp1 - (fSlow1177 * fRec471[1] + fSlow1175 * fRec471[2]);
			fRec472[0] = fTemp1 - (fSlow1182 * fRec472[1] + fSlow1180 * fRec472[2]);
			fRec473[0] = fTemp1 - (fSlow1187 * fRec473[1] + fSlow1185 * fRec473[2]);
			fRec474[0] = fTemp1 - (fSlow1192 * fRec474[1] + fSlow1190 * fRec474[2]);
			fRec475[0] = fTemp1 - (fSlow1197 * fRec475[1] + fSlow1195 * fRec475[2]);
			fRec476[0] = fTemp1 - (fSlow1202 * fRec476[1] + fSlow1200 * fRec476[2]);
			fRec477[0] = fTemp1 - (fSlow1207 * fRec477[1] + fSlow1205 * fRec477[2]);
			fRec478[0] = fTemp1 - (fSlow1211 * fRec478[1] + fSlow1210 * fRec478[2]);
			fRec479[0] = fTemp1 - (fSlow1215 * fRec479[1] + fSlow1214 * fRec479[2]);
			fRec480[0] = fTemp1 - (fSlow1230 * fRec480[1] + fSlow1225 * fRec480[2]);
			fRec481[0] = fTemp1 - (fSlow1241 * fRec481[1] + fSlow1239 * fRec481[2]);
			fRec482[0] = fTemp1 - (fSlow1246 * fRec482[1] + fSlow1244 * fRec482[2]);
			fRec483[0] = fTemp1 - (fSlow1251 * fRec483[1] + fSlow1249 * fRec483[2]);
			fRec484[0] = fTemp1 - (fSlow1256 * fRec484[1] + fSlow1254 * fRec484[2]);
			fRec485[0] = fTemp1 - (fSlow1261 * fRec485[1] + fSlow1259 * fRec485[2]);
			fRec486[0] = fTemp1 - (fSlow1266 * fRec486[1] + fSlow1264 * fRec486[2]);
			fRec487[0] = fTemp1 - (fSlow1271 * fRec487[1] + fSlow1269 * fRec487[2]);
			fRec488[0] = fTemp1 - (fSlow1276 * fRec488[1] + fSlow1274 * fRec488[2]);
			fRec489[0] = fTemp1 - (fSlow1281 * fRec489[1] + fSlow1279 * fRec489[2]);
			fRec490[0] = fTemp1 - (fSlow1286 * fRec490[1] + fSlow1284 * fRec490[2]);
			fRec491[0] = fTemp1 - (fSlow1291 * fRec491[1] + fSlow1289 * fRec491[2]);
			fRec492[0] = fTemp1 - (fSlow1296 * fRec492[1] + fSlow1294 * fRec492[2]);
			fRec493[0] = fTemp1 - (fSlow1301 * fRec493[1] + fSlow1299 * fRec493[2]);
			fRec494[0] = fTemp1 - (fSlow1306 * fRec494[1] + fSlow1304 * fRec494[2]);
			fRec495[0] = fTemp1 - (fSlow1311 * fRec495[1] + fSlow1309 * fRec495[2]);
			fRec496[0] = fTemp1 - (fSlow1316 * fRec496[1] + fSlow1314 * fRec496[2]);
			fRec497[0] = fTemp1 - (fSlow1321 * fRec497[1] + fSlow1319 * fRec497[2]);
			fRec498[0] = fTemp1 - (fSlow1326 * fRec498[1] + fSlow1324 * fRec498[2]);
			fRec499[0] = fTemp1 - (fSlow1331 * fRec499[1] + fSlow1329 * fRec499[2]);
			fRec500[0] = fTemp1 - (fSlow1336 * fRec500[1] + fSlow1334 * fRec500[2]);
			fRec501[0] = fTemp1 - (fSlow1341 * fRec501[1] + fSlow1339 * fRec501[2]);
			fRec502[0] = fTemp1 - (fSlow1346 * fRec502[1] + fSlow1344 * fRec502[2]);
			fRec503[0] = fTemp1 - (fSlow1351 * fRec503[1] + fSlow1349 * fRec503[2]);
			fRec504[0] = fTemp1 - (fSlow1356 * fRec504[1] + fSlow1354 * fRec504[2]);
			fRec505[0] = fTemp1 - (fSlow1361 * fRec505[1] + fSlow1359 * fRec505[2]);
			fRec506[0] = fTemp1 - (fSlow1366 * fRec506[1] + fSlow1364 * fRec506[2]);
			fRec507[0] = fTemp1 - (fSlow1371 * fRec507[1] + fSlow1369 * fRec507[2]);
			fRec508[0] = fTemp1 - (fSlow1376 * fRec508[1] + fSlow1374 * fRec508[2]);
			fRec509[0] = fTemp1 - (fSlow1381 * fRec509[1] + fSlow1379 * fRec509[2]);
			fRec510[0] = fTemp1 - (fSlow1385 * fRec510[1] + fSlow1384 * fRec510[2]);
			fRec511[0] = fTemp1 - (fSlow1389 * fRec511[1] + fSlow1388 * fRec511[2]);
			output1[i0] = FAUSTFLOAT(0.00390625 * (fSlow1391 * (fSlow1390 * (fRec511[0] - fRec511[2]) + fSlow1386 * (fRec510[0] - fRec510[2]) + fSlow1382 * (fRec509[0] - fRec509[2]) + fSlow1377 * (fRec508[0] - fRec508[2]) + fSlow1372 * (fRec507[0] - fRec507[2]) + fSlow1367 * (fRec506[0] - fRec506[2]) + fSlow1362 * (fRec505[0] - fRec505[2]) + fSlow1357 * (fRec504[0] - fRec504[2]) + fSlow1352 * (fRec503[0] - fRec503[2]) + fSlow1347 * (fRec502[0] - fRec502[2]) + fSlow1342 * (fRec501[0] - fRec501[2]) + fSlow1337 * (fRec500[0] - fRec500[2]) + fSlow1332 * (fRec499[0] - fRec499[2]) + fSlow1327 * (fRec498[0] - fRec498[2]) + fSlow1322 * (fRec497[0] - fRec497[2]) + fSlow1317 * (fRec496[0] - fRec496[2]) + fSlow1312 * (fRec495[0] - fRec495[2]) + fSlow1307 * (fRec494[0] - fRec494[2]) + fSlow1302 * (fRec493[0] - fRec493[2]) + fSlow1297 * (fRec492[0] - fRec492[2]) + fSlow1292 * (fRec491[0] - fRec491[2]) + fSlow1287 * (fRec490[0] - fRec490[2]) + fSlow1282 * (fRec489[0] - fRec489[2]) + fSlow1277 * (fRec488[0] - fRec488[2]) + fSlow1272 * (fRec487[0] - fRec487[2]) + fSlow1267 * (fRec486[0] - fRec486[2]) + fSlow1262 * (fRec485[0] - fRec485[2]) + fSlow1257 * (fRec484[0] - fRec484[2]) + fSlow1252 * (fRec483[0] - fRec483[2]) + fSlow1247 * (fRec482[0] - fRec482[2]) + fSlow1242 * (fRec481[0] - fRec481[2]) + fSlow1237 * (fRec480[0] - fRec480[2])) + fSlow1217 * (fSlow1216 * (fRec479[0] - fRec479[2]) + fSlow1212 * (fRec478[0] - fRec478[2]) + fSlow1208 * (fRec477[0] - fRec477[2]) + fSlow1203 * (fRec476[0] - fRec476[2]) + fSlow1198 * (fRec475[0] - fRec475[2]) + fSlow1193 * (fRec474[0] - fRec474[2]) + fSlow1188 * (fRec473[0] - fRec473[2]) + fSlow1183 * (fRec472[0] - fRec472[2]) + fSlow1178 * (fRec471[0] - fRec471[2]) + fSlow1173 * (fRec470[0] - fRec470[2]) + fSlow1168 * (fRec469[0] - fRec469[2]) + fSlow1163 * (fRec468[0] - fRec468[2]) + fSlow1158 * (fRec467[0] - fRec467[2]) + fSlow1153 * (fRec466[0] - fRec466[2]) + fSlow1148 * (fRec465[0] - fRec465[2]) + fSlow1143 * (fRec464[0] - fRec464[2]) + fSlow1138 * (fRec463[0] - fRec463[2]) + fSlow1133 * (fRec462[0] - fRec462[2]) + fSlow1128 * (fRec461[0] - fRec461[2]) + fSlow1123 * (fRec460[0] - fRec460[2]) + fSlow1118 * (fRec459[0] - fRec459[2]) + fSlow1113 * (fRec458[0] - fRec458[2]) + fSlow1108 * (fRec457[0] - fRec457[2]) + fSlow1103 * (fRec456[0] - fRec456[2]) + fSlow1098 * (fRec455[0] - fRec455[2]) + fSlow1093 * (fRec454[0] - fRec454[2]) + fSlow1088 * (fRec453[0] - fRec453[2]) + fSlow1083 * (fRec452[0] - fRec452[2]) + fSlow1078 * (fRec451[0] - fRec451[2]) + fSlow1073 * (fRec450[0] - fRec450[2]) + fSlow1068 * (fRec449[0] - fRec449[2]) + fSlow1063 * (fRec448[0] - fRec448[2])) + fSlow1043 * (fSlow1042 * (fRec447[0] - fRec447[2]) + fSlow1038 * (fRec446[0] - fRec446[2]) + fSlow1034 * (fRec445[0] - fRec445[2]) + fSlow1029 * (fRec444[0] - fRec444[2]) + fSlow1024 * (fRec443[0] - fRec443[2]) + fSlow1019 * (fRec442[0] - fRec442[2]) + fSlow1014 * (fRec441[0] - fRec441[2]) + fSlow1009 * (fRec440[0] - fRec440[2]) + fSlow1004 * (fRec439[0] - fRec439[2]) + fSlow999 * (fRec438[0] - fRec438[2]) + fSlow994 * (fRec437[0] - fRec437[2]) + fSlow989 * (fRec436[0] - fRec436[2]) + fSlow984 * (fRec435[0] - fRec435[2]) + fSlow979 * (fRec434[0] - fRec434[2]) + fSlow974 * (fRec433[0] - fRec433[2]) + fSlow969 * (fRec432[0] - fRec432[2]) + fSlow964 * (fRec431[0] - fRec431[2]) + fSlow959 * (fRec430[0] - fRec430[2]) + fSlow954 * (fRec429[0] - fRec429[2]) + fSlow949 * (fRec428[0] - fRec428[2]) + fSlow944 * (fRec427[0] - fRec427[2]) + fSlow939 * (fRec426[0] - fRec426[2]) + fSlow934 * (fRec425[0] - fRec425[2]) + fSlow929 * (fRec424[0] - fRec424[2]) + fSlow924 * (fRec423[0] - fRec423[2]) + fSlow919 * (fRec422[0] - fRec422[2]) + fSlow914 * (fRec421[0] - fRec421[2]) + fSlow909 * (fRec420[0] - fRec420[2]) + fSlow904 * (fRec419[0] - fRec419[2]) + fSlow899 * (fRec418[0] - fRec418[2]) + fSlow894 * (fRec417[0] - fRec417[2]) + fSlow889 * (fRec416[0] - fRec416[2])) + fSlow869 * (fSlow868 * (fRec415[0] - fRec415[2]) + fSlow864 * (fRec414[0] - fRec414[2]) + fSlow860 * (fRec413[0] - fRec413[2]) + fSlow855 * (fRec412[0] - fRec412[2]) + fSlow850 * (fRec411[0] - fRec411[2]) + fSlow845 * (fRec410[0] - fRec410[2]) + fSlow840 * (fRec409[0] - fRec409[2]) + fSlow835 * (fRec408[0] - fRec408[2]) + fSlow830 * (fRec407[0] - fRec407[2]) + fSlow825 * (fRec406[0] - fRec406[2]) + fSlow820 * (fRec405[0] - fRec405[2]) + fSlow815 * (fRec404[0] - fRec404[2]) + fSlow810 * (fRec403[0] - fRec403[2]) + fSlow805 * (fRec402[0] - fRec402[2]) + fSlow800 * (fRec401[0] - fRec401[2]) + fSlow795 * (fRec400[0] - fRec400[2]) + fSlow790 * (fRec399[0] - fRec399[2]) + fSlow785 * (fRec398[0] - fRec398[2]) + fSlow780 * (fRec397[0] - fRec397[2]) + fSlow775 * (fRec396[0] - fRec396[2]) + fSlow770 * (fRec395[0] - fRec395[2]) + fSlow765 * (fRec394[0] - fRec394[2]) + fSlow760 * (fRec393[0] - fRec393[2]) + fSlow755 * (fRec392[0] - fRec392[2]) + fSlow750 * (fRec391[0] - fRec391[2]) + fSlow745 * (fRec390[0] - fRec390[2]) + fSlow740 * (fRec389[0] - fRec389[2]) + fSlow735 * (fRec388[0] - fRec388[2]) + fSlow730 * (fRec387[0] - fRec387[2]) + fSlow725 * (fRec386[0] - fRec386[2]) + fSlow720 * (fRec385[0] - fRec385[2]) + fSlow715 * (fRec384[0] - fRec384[2])) + fSlow695 * (fSlow694 * (fRec383[0] - fRec383[2]) + fSlow690 * (fRec382[0] - fRec382[2]) + fSlow686 * (fRec381[0] - fRec381[2]) + fSlow681 * (fRec380[0] - fRec380[2]) + fSlow676 * (fRec379[0] - fRec379[2]) + fSlow671 * (fRec378[0] - fRec378[2]) + fSlow666 * (fRec377[0] - fRec377[2]) + fSlow661 * (fRec376[0] - fRec376[2]) + fSlow656 * (fRec375[0] - fRec375[2]) + fSlow651 * (fRec374[0] - fRec374[2]) + fSlow646 * (fRec373[0] - fRec373[2]) + fSlow641 * (fRec372[0] - fRec372[2]) + fSlow636 * (fRec371[0] - fRec371[2]) + fSlow631 * (fRec370[0] - fRec370[2]) + fSlow626 * (fRec369[0] - fRec369[2]) + fSlow621 * (fRec368[0] - fRec368[2]) + fSlow616 * (fRec367[0] - fRec367[2]) + fSlow611 * (fRec366[0] - fRec366[2]) + fSlow606 * (fRec365[0] - fRec365[2]) + fSlow601 * (fRec364[0] - fRec364[2]) + fSlow596 * (fRec363[0] - fRec363[2]) + fSlow591 * (fRec362[0] - fRec362[2]) + fSlow586 * (fRec361[0] - fRec361[2]) + fSlow581 * (fRec360[0] - fRec360[2]) + fSlow576 * (fRec359[0] - fRec359[2]) + fSlow571 * (fRec358[0] - fRec358[2]) + fSlow566 * (fRec357[0] - fRec357[2]) + fSlow561 * (fRec356[0] - fRec356[2]) + fSlow556 * (fRec355[0] - fRec355[2]) + fSlow551 * (fRec354[0] - fRec354[2]) + fSlow546 * (fRec353[0] - fRec353[2]) + fSlow541 * (fRec352[0] - fRec352[2])) + fSlow521 * (fSlow520 * (fRec351[0] - fRec351[2]) + fSlow516 * (fRec350[0] - fRec350[2]) + fSlow512 * (fRec349[0] - fRec349[2]) + fSlow507 * (fRec348[0] - fRec348[2]) + fSlow502 * (fRec347[0] - fRec347[2]) + fSlow497 * (fRec346[0] - fRec346[2]) + fSlow492 * (fRec345[0] - fRec345[2]) + fSlow487 * (fRec344[0] - fRec344[2]) + fSlow482 * (fRec343[0] - fRec343[2]) + fSlow477 * (fRec342[0] - fRec342[2]) + fSlow472 * (fRec341[0] - fRec341[2]) + fSlow467 * (fRec340[0] - fRec340[2]) + fSlow462 * (fRec339[0] - fRec339[2]) + fSlow457 * (fRec338[0] - fRec338[2]) + fSlow452 * (fRec337[0] - fRec337[2]) + fSlow447 * (fRec336[0] - fRec336[2]) + fSlow442 * (fRec335[0] - fRec335[2]) + fSlow437 * (fRec334[0] - fRec334[2]) + fSlow432 * (fRec333[0] - fRec333[2]) + fSlow427 * (fRec332[0] - fRec332[2]) + fSlow422 * (fRec331[0] - fRec331[2]) + fSlow417 * (fRec330[0] - fRec330[2]) + fSlow412 * (fRec329[0] - fRec329[2]) + fSlow407 * (fRec328[0] - fRec328[2]) + fSlow402 * (fRec327[0] - fRec327[2]) + fSlow397 * (fRec326[0] - fRec326[2]) + fSlow392 * (fRec325[0] - fRec325[2]) + fSlow387 * (fRec324[0] - fRec324[2]) + fSlow382 * (fRec323[0] - fRec323[2]) + fSlow377 * (fRec322[0] - fRec322[2]) + fSlow372 * (fRec321[0] - fRec321[2]) + fSlow367 * (fRec320[0] - fRec320[2])) + fSlow347 * (fSlow346 * (fRec319[0] - fRec319[2]) + fSlow342 * (fRec318[0] - fRec318[2]) + fSlow338 * (fRec317[0] - fRec317[2]) + fSlow333 * (fRec316[0] - fRec316[2]) + fSlow328 * (fRec315[0] - fRec315[2]) + fSlow323 * (fRec314[0] - fRec314[2]) + fSlow318 * (fRec313[0] - fRec313[2]) + fSlow313 * (fRec312[0] - fRec312[2]) + fSlow308 * (fRec311[0] - fRec311[2]) + fSlow303 * (fRec310[0] - fRec310[2]) + fSlow298 * (fRec309[0] - fRec309[2]) + fSlow293 * (fRec308[0] - fRec308[2]) + fSlow288 * (fRec307[0] - fRec307[2]) + fSlow283 * (fRec306[0] - fRec306[2]) + fSlow278 * (fRec305[0] - fRec305[2]) + fSlow273 * (fRec304[0] - fRec304[2]) + fSlow268 * (fRec303[0] - fRec303[2]) + fSlow263 * (fRec302[0] - fRec302[2]) + fSlow258 * (fRec301[0] - fRec301[2]) + fSlow253 * (fRec300[0] - fRec300[2]) + fSlow248 * (fRec299[0] - fRec299[2]) + fSlow243 * (fRec298[0] - fRec298[2]) + fSlow238 * (fRec297[0] - fRec297[2]) + fSlow233 * (fRec296[0] - fRec296[2]) + fSlow228 * (fRec295[0] - fRec295[2]) + fSlow223 * (fRec294[0] - fRec294[2]) + fSlow218 * (fRec293[0] - fRec293[2]) + fSlow213 * (fRec292[0] - fRec292[2]) + fSlow208 * (fRec291[0] - fRec291[2]) + fSlow203 * (fRec290[0] - fRec290[2]) + fSlow198 * (fRec289[0] - fRec289[2]) + fSlow193 * (fRec288[0] - fRec288[2])) + fSlow173 * (fSlow172 * (fRec287[0] - fRec287[2]) + fSlow168 * (fRec286[0] - fRec286[2]) + fSlow164 * (fRec285[0] - fRec285[2]) + fSlow159 * (fRec284[0] - fRec284[2]) + fSlow154 * (fRec283[0] - fRec283[2]) + fSlow149 * (fRec282[0] - fRec282[2]) + fSlow144 * (fRec281[0] - fRec281[2]) + fSlow139 * (fRec280[0] - fRec280[2]) + fSlow134 * (fRec279[0] - fRec279[2]) + fSlow129 * (fRec278[0] - fRec278[2]) + fSlow124 * (fRec277[0] - fRec277[2]) + fSlow119 * (fRec276[0] - fRec276[2]) + fSlow114 * (fRec275[0] - fRec275[2]) + fSlow109 * (fRec274[0] - fRec274[2]) + fSlow104 * (fRec273[0] - fRec273[2]) + fSlow99 * (fRec272[0] - fRec272[2]) + fSlow94 * (fRec271[0] - fRec271[2]) + fSlow89 * (fRec270[0] - fRec270[2]) + fSlow84 * (fRec269[0] - fRec269[2]) + fSlow79 * (fRec268[0] - fRec268[2]) + fSlow74 * (fRec267[0] - fRec267[2]) + fSlow69 * (fRec266[0] - fRec266[2]) + fSlow64 * (fRec265[0] - fRec265[2]) + fSlow59 * (fRec264[0] - fRec264[2]) + fSlow54 * (fRec263[0] - fRec263[2]) + fSlow49 * (fRec262[0] - fRec262[2]) + fSlow44 * (fRec261[0] - fRec261[2]) + fSlow39 * (fRec260[0] - fRec260[2]) + fSlow34 * (fRec259[0] - fRec259[2]) + fSlow29 * (fRec258[0] - fRec258[2]) + fSlow24 * (fRec257[0] - fRec257[2]) + fSlow19 * (fRec256[0] - fRec256[2]))));
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec54[2] = fRec54[1];
			fRec54[1] = fRec54[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec63[2] = fRec63[1];
			fRec63[1] = fRec63[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fRec67[2] = fRec67[1];
			fRec67[1] = fRec67[0];
			fRec68[2] = fRec68[1];
			fRec68[1] = fRec68[0];
			fRec69[2] = fRec69[1];
			fRec69[1] = fRec69[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			fRec74[2] = fRec74[1];
			fRec74[1] = fRec74[0];
			fRec75[2] = fRec75[1];
			fRec75[1] = fRec75[0];
			fRec76[2] = fRec76[1];
			fRec76[1] = fRec76[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec83[2] = fRec83[1];
			fRec83[1] = fRec83[0];
			fRec84[2] = fRec84[1];
			fRec84[1] = fRec84[0];
			fRec85[2] = fRec85[1];
			fRec85[1] = fRec85[0];
			fRec86[2] = fRec86[1];
			fRec86[1] = fRec86[0];
			fRec87[2] = fRec87[1];
			fRec87[1] = fRec87[0];
			fRec88[2] = fRec88[1];
			fRec88[1] = fRec88[0];
			fRec89[2] = fRec89[1];
			fRec89[1] = fRec89[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec91[2] = fRec91[1];
			fRec91[1] = fRec91[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec95[2] = fRec95[1];
			fRec95[1] = fRec95[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec100[2] = fRec100[1];
			fRec100[1] = fRec100[0];
			fRec101[2] = fRec101[1];
			fRec101[1] = fRec101[0];
			fRec102[2] = fRec102[1];
			fRec102[1] = fRec102[0];
			fRec103[2] = fRec103[1];
			fRec103[1] = fRec103[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec105[2] = fRec105[1];
			fRec105[1] = fRec105[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fRec107[2] = fRec107[1];
			fRec107[1] = fRec107[0];
			fRec108[2] = fRec108[1];
			fRec108[1] = fRec108[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fRec111[2] = fRec111[1];
			fRec111[1] = fRec111[0];
			fRec112[2] = fRec112[1];
			fRec112[1] = fRec112[0];
			fRec113[2] = fRec113[1];
			fRec113[1] = fRec113[0];
			fRec114[2] = fRec114[1];
			fRec114[1] = fRec114[0];
			fRec115[2] = fRec115[1];
			fRec115[1] = fRec115[0];
			fRec116[2] = fRec116[1];
			fRec116[1] = fRec116[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec120[2] = fRec120[1];
			fRec120[1] = fRec120[0];
			fRec121[2] = fRec121[1];
			fRec121[1] = fRec121[0];
			fRec122[2] = fRec122[1];
			fRec122[1] = fRec122[0];
			fRec123[2] = fRec123[1];
			fRec123[1] = fRec123[0];
			fRec124[2] = fRec124[1];
			fRec124[1] = fRec124[0];
			fRec125[2] = fRec125[1];
			fRec125[1] = fRec125[0];
			fRec126[2] = fRec126[1];
			fRec126[1] = fRec126[0];
			fRec127[2] = fRec127[1];
			fRec127[1] = fRec127[0];
			fRec128[2] = fRec128[1];
			fRec128[1] = fRec128[0];
			fRec129[2] = fRec129[1];
			fRec129[1] = fRec129[0];
			fRec130[2] = fRec130[1];
			fRec130[1] = fRec130[0];
			fRec131[2] = fRec131[1];
			fRec131[1] = fRec131[0];
			fRec132[2] = fRec132[1];
			fRec132[1] = fRec132[0];
			fRec133[2] = fRec133[1];
			fRec133[1] = fRec133[0];
			fRec134[2] = fRec134[1];
			fRec134[1] = fRec134[0];
			fRec135[2] = fRec135[1];
			fRec135[1] = fRec135[0];
			fRec136[2] = fRec136[1];
			fRec136[1] = fRec136[0];
			fRec137[2] = fRec137[1];
			fRec137[1] = fRec137[0];
			fRec138[2] = fRec138[1];
			fRec138[1] = fRec138[0];
			fRec139[2] = fRec139[1];
			fRec139[1] = fRec139[0];
			fRec140[2] = fRec140[1];
			fRec140[1] = fRec140[0];
			fRec141[2] = fRec141[1];
			fRec141[1] = fRec141[0];
			fRec142[2] = fRec142[1];
			fRec142[1] = fRec142[0];
			fRec143[2] = fRec143[1];
			fRec143[1] = fRec143[0];
			fRec144[2] = fRec144[1];
			fRec144[1] = fRec144[0];
			fRec145[2] = fRec145[1];
			fRec145[1] = fRec145[0];
			fRec146[2] = fRec146[1];
			fRec146[1] = fRec146[0];
			fRec147[2] = fRec147[1];
			fRec147[1] = fRec147[0];
			fRec148[2] = fRec148[1];
			fRec148[1] = fRec148[0];
			fRec149[2] = fRec149[1];
			fRec149[1] = fRec149[0];
			fRec150[2] = fRec150[1];
			fRec150[1] = fRec150[0];
			fRec151[2] = fRec151[1];
			fRec151[1] = fRec151[0];
			fRec152[2] = fRec152[1];
			fRec152[1] = fRec152[0];
			fRec153[2] = fRec153[1];
			fRec153[1] = fRec153[0];
			fRec154[2] = fRec154[1];
			fRec154[1] = fRec154[0];
			fRec155[2] = fRec155[1];
			fRec155[1] = fRec155[0];
			fRec156[2] = fRec156[1];
			fRec156[1] = fRec156[0];
			fRec157[2] = fRec157[1];
			fRec157[1] = fRec157[0];
			fRec158[2] = fRec158[1];
			fRec158[1] = fRec158[0];
			fRec159[2] = fRec159[1];
			fRec159[1] = fRec159[0];
			fRec160[2] = fRec160[1];
			fRec160[1] = fRec160[0];
			fRec161[2] = fRec161[1];
			fRec161[1] = fRec161[0];
			fRec162[2] = fRec162[1];
			fRec162[1] = fRec162[0];
			fRec163[2] = fRec163[1];
			fRec163[1] = fRec163[0];
			fRec164[2] = fRec164[1];
			fRec164[1] = fRec164[0];
			fRec165[2] = fRec165[1];
			fRec165[1] = fRec165[0];
			fRec166[2] = fRec166[1];
			fRec166[1] = fRec166[0];
			fRec167[2] = fRec167[1];
			fRec167[1] = fRec167[0];
			fRec168[2] = fRec168[1];
			fRec168[1] = fRec168[0];
			fRec169[2] = fRec169[1];
			fRec169[1] = fRec169[0];
			fRec170[2] = fRec170[1];
			fRec170[1] = fRec170[0];
			fRec171[2] = fRec171[1];
			fRec171[1] = fRec171[0];
			fRec172[2] = fRec172[1];
			fRec172[1] = fRec172[0];
			fRec173[2] = fRec173[1];
			fRec173[1] = fRec173[0];
			fRec174[2] = fRec174[1];
			fRec174[1] = fRec174[0];
			fRec175[2] = fRec175[1];
			fRec175[1] = fRec175[0];
			fRec176[2] = fRec176[1];
			fRec176[1] = fRec176[0];
			fRec177[2] = fRec177[1];
			fRec177[1] = fRec177[0];
			fRec178[2] = fRec178[1];
			fRec178[1] = fRec178[0];
			fRec179[2] = fRec179[1];
			fRec179[1] = fRec179[0];
			fRec180[2] = fRec180[1];
			fRec180[1] = fRec180[0];
			fRec181[2] = fRec181[1];
			fRec181[1] = fRec181[0];
			fRec182[2] = fRec182[1];
			fRec182[1] = fRec182[0];
			fRec183[2] = fRec183[1];
			fRec183[1] = fRec183[0];
			fRec184[2] = fRec184[1];
			fRec184[1] = fRec184[0];
			fRec185[2] = fRec185[1];
			fRec185[1] = fRec185[0];
			fRec186[2] = fRec186[1];
			fRec186[1] = fRec186[0];
			fRec187[2] = fRec187[1];
			fRec187[1] = fRec187[0];
			fRec188[2] = fRec188[1];
			fRec188[1] = fRec188[0];
			fRec189[2] = fRec189[1];
			fRec189[1] = fRec189[0];
			fRec190[2] = fRec190[1];
			fRec190[1] = fRec190[0];
			fRec191[2] = fRec191[1];
			fRec191[1] = fRec191[0];
			fRec192[2] = fRec192[1];
			fRec192[1] = fRec192[0];
			fRec193[2] = fRec193[1];
			fRec193[1] = fRec193[0];
			fRec194[2] = fRec194[1];
			fRec194[1] = fRec194[0];
			fRec195[2] = fRec195[1];
			fRec195[1] = fRec195[0];
			fRec196[2] = fRec196[1];
			fRec196[1] = fRec196[0];
			fRec197[2] = fRec197[1];
			fRec197[1] = fRec197[0];
			fRec198[2] = fRec198[1];
			fRec198[1] = fRec198[0];
			fRec199[2] = fRec199[1];
			fRec199[1] = fRec199[0];
			fRec200[2] = fRec200[1];
			fRec200[1] = fRec200[0];
			fRec201[2] = fRec201[1];
			fRec201[1] = fRec201[0];
			fRec202[2] = fRec202[1];
			fRec202[1] = fRec202[0];
			fRec203[2] = fRec203[1];
			fRec203[1] = fRec203[0];
			fRec204[2] = fRec204[1];
			fRec204[1] = fRec204[0];
			fRec205[2] = fRec205[1];
			fRec205[1] = fRec205[0];
			fRec206[2] = fRec206[1];
			fRec206[1] = fRec206[0];
			fRec207[2] = fRec207[1];
			fRec207[1] = fRec207[0];
			fRec208[2] = fRec208[1];
			fRec208[1] = fRec208[0];
			fRec209[2] = fRec209[1];
			fRec209[1] = fRec209[0];
			fRec210[2] = fRec210[1];
			fRec210[1] = fRec210[0];
			fRec211[2] = fRec211[1];
			fRec211[1] = fRec211[0];
			fRec212[2] = fRec212[1];
			fRec212[1] = fRec212[0];
			fRec213[2] = fRec213[1];
			fRec213[1] = fRec213[0];
			fRec214[2] = fRec214[1];
			fRec214[1] = fRec214[0];
			fRec215[2] = fRec215[1];
			fRec215[1] = fRec215[0];
			fRec216[2] = fRec216[1];
			fRec216[1] = fRec216[0];
			fRec217[2] = fRec217[1];
			fRec217[1] = fRec217[0];
			fRec218[2] = fRec218[1];
			fRec218[1] = fRec218[0];
			fRec219[2] = fRec219[1];
			fRec219[1] = fRec219[0];
			fRec220[2] = fRec220[1];
			fRec220[1] = fRec220[0];
			fRec221[2] = fRec221[1];
			fRec221[1] = fRec221[0];
			fRec222[2] = fRec222[1];
			fRec222[1] = fRec222[0];
			fRec223[2] = fRec223[1];
			fRec223[1] = fRec223[0];
			fRec224[2] = fRec224[1];
			fRec224[1] = fRec224[0];
			fRec225[2] = fRec225[1];
			fRec225[1] = fRec225[0];
			fRec226[2] = fRec226[1];
			fRec226[1] = fRec226[0];
			fRec227[2] = fRec227[1];
			fRec227[1] = fRec227[0];
			fRec228[2] = fRec228[1];
			fRec228[1] = fRec228[0];
			fRec229[2] = fRec229[1];
			fRec229[1] = fRec229[0];
			fRec230[2] = fRec230[1];
			fRec230[1] = fRec230[0];
			fRec231[2] = fRec231[1];
			fRec231[1] = fRec231[0];
			fRec232[2] = fRec232[1];
			fRec232[1] = fRec232[0];
			fRec233[2] = fRec233[1];
			fRec233[1] = fRec233[0];
			fRec234[2] = fRec234[1];
			fRec234[1] = fRec234[0];
			fRec235[2] = fRec235[1];
			fRec235[1] = fRec235[0];
			fRec236[2] = fRec236[1];
			fRec236[1] = fRec236[0];
			fRec237[2] = fRec237[1];
			fRec237[1] = fRec237[0];
			fRec238[2] = fRec238[1];
			fRec238[1] = fRec238[0];
			fRec239[2] = fRec239[1];
			fRec239[1] = fRec239[0];
			fRec240[2] = fRec240[1];
			fRec240[1] = fRec240[0];
			fRec241[2] = fRec241[1];
			fRec241[1] = fRec241[0];
			fRec242[2] = fRec242[1];
			fRec242[1] = fRec242[0];
			fRec243[2] = fRec243[1];
			fRec243[1] = fRec243[0];
			fRec244[2] = fRec244[1];
			fRec244[1] = fRec244[0];
			fRec245[2] = fRec245[1];
			fRec245[1] = fRec245[0];
			fRec246[2] = fRec246[1];
			fRec246[1] = fRec246[0];
			fRec247[2] = fRec247[1];
			fRec247[1] = fRec247[0];
			fRec248[2] = fRec248[1];
			fRec248[1] = fRec248[0];
			fRec249[2] = fRec249[1];
			fRec249[1] = fRec249[0];
			fRec250[2] = fRec250[1];
			fRec250[1] = fRec250[0];
			fRec251[2] = fRec251[1];
			fRec251[1] = fRec251[0];
			fRec252[2] = fRec252[1];
			fRec252[1] = fRec252[0];
			fRec253[2] = fRec253[1];
			fRec253[1] = fRec253[0];
			fRec254[2] = fRec254[1];
			fRec254[1] = fRec254[0];
			fRec255[2] = fRec255[1];
			fRec255[1] = fRec255[0];
			fRec256[2] = fRec256[1];
			fRec256[1] = fRec256[0];
			fRec257[2] = fRec257[1];
			fRec257[1] = fRec257[0];
			fRec258[2] = fRec258[1];
			fRec258[1] = fRec258[0];
			fRec259[2] = fRec259[1];
			fRec259[1] = fRec259[0];
			fRec260[2] = fRec260[1];
			fRec260[1] = fRec260[0];
			fRec261[2] = fRec261[1];
			fRec261[1] = fRec261[0];
			fRec262[2] = fRec262[1];
			fRec262[1] = fRec262[0];
			fRec263[2] = fRec263[1];
			fRec263[1] = fRec263[0];
			fRec264[2] = fRec264[1];
			fRec264[1] = fRec264[0];
			fRec265[2] = fRec265[1];
			fRec265[1] = fRec265[0];
			fRec266[2] = fRec266[1];
			fRec266[1] = fRec266[0];
			fRec267[2] = fRec267[1];
			fRec267[1] = fRec267[0];
			fRec268[2] = fRec268[1];
			fRec268[1] = fRec268[0];
			fRec269[2] = fRec269[1];
			fRec269[1] = fRec269[0];
			fRec270[2] = fRec270[1];
			fRec270[1] = fRec270[0];
			fRec271[2] = fRec271[1];
			fRec271[1] = fRec271[0];
			fRec272[2] = fRec272[1];
			fRec272[1] = fRec272[0];
			fRec273[2] = fRec273[1];
			fRec273[1] = fRec273[0];
			fRec274[2] = fRec274[1];
			fRec274[1] = fRec274[0];
			fRec275[2] = fRec275[1];
			fRec275[1] = fRec275[0];
			fRec276[2] = fRec276[1];
			fRec276[1] = fRec276[0];
			fRec277[2] = fRec277[1];
			fRec277[1] = fRec277[0];
			fRec278[2] = fRec278[1];
			fRec278[1] = fRec278[0];
			fRec279[2] = fRec279[1];
			fRec279[1] = fRec279[0];
			fRec280[2] = fRec280[1];
			fRec280[1] = fRec280[0];
			fRec281[2] = fRec281[1];
			fRec281[1] = fRec281[0];
			fRec282[2] = fRec282[1];
			fRec282[1] = fRec282[0];
			fRec283[2] = fRec283[1];
			fRec283[1] = fRec283[0];
			fRec284[2] = fRec284[1];
			fRec284[1] = fRec284[0];
			fRec285[2] = fRec285[1];
			fRec285[1] = fRec285[0];
			fRec286[2] = fRec286[1];
			fRec286[1] = fRec286[0];
			fRec287[2] = fRec287[1];
			fRec287[1] = fRec287[0];
			fRec288[2] = fRec288[1];
			fRec288[1] = fRec288[0];
			fRec289[2] = fRec289[1];
			fRec289[1] = fRec289[0];
			fRec290[2] = fRec290[1];
			fRec290[1] = fRec290[0];
			fRec291[2] = fRec291[1];
			fRec291[1] = fRec291[0];
			fRec292[2] = fRec292[1];
			fRec292[1] = fRec292[0];
			fRec293[2] = fRec293[1];
			fRec293[1] = fRec293[0];
			fRec294[2] = fRec294[1];
			fRec294[1] = fRec294[0];
			fRec295[2] = fRec295[1];
			fRec295[1] = fRec295[0];
			fRec296[2] = fRec296[1];
			fRec296[1] = fRec296[0];
			fRec297[2] = fRec297[1];
			fRec297[1] = fRec297[0];
			fRec298[2] = fRec298[1];
			fRec298[1] = fRec298[0];
			fRec299[2] = fRec299[1];
			fRec299[1] = fRec299[0];
			fRec300[2] = fRec300[1];
			fRec300[1] = fRec300[0];
			fRec301[2] = fRec301[1];
			fRec301[1] = fRec301[0];
			fRec302[2] = fRec302[1];
			fRec302[1] = fRec302[0];
			fRec303[2] = fRec303[1];
			fRec303[1] = fRec303[0];
			fRec304[2] = fRec304[1];
			fRec304[1] = fRec304[0];
			fRec305[2] = fRec305[1];
			fRec305[1] = fRec305[0];
			fRec306[2] = fRec306[1];
			fRec306[1] = fRec306[0];
			fRec307[2] = fRec307[1];
			fRec307[1] = fRec307[0];
			fRec308[2] = fRec308[1];
			fRec308[1] = fRec308[0];
			fRec309[2] = fRec309[1];
			fRec309[1] = fRec309[0];
			fRec310[2] = fRec310[1];
			fRec310[1] = fRec310[0];
			fRec311[2] = fRec311[1];
			fRec311[1] = fRec311[0];
			fRec312[2] = fRec312[1];
			fRec312[1] = fRec312[0];
			fRec313[2] = fRec313[1];
			fRec313[1] = fRec313[0];
			fRec314[2] = fRec314[1];
			fRec314[1] = fRec314[0];
			fRec315[2] = fRec315[1];
			fRec315[1] = fRec315[0];
			fRec316[2] = fRec316[1];
			fRec316[1] = fRec316[0];
			fRec317[2] = fRec317[1];
			fRec317[1] = fRec317[0];
			fRec318[2] = fRec318[1];
			fRec318[1] = fRec318[0];
			fRec319[2] = fRec319[1];
			fRec319[1] = fRec319[0];
			fRec320[2] = fRec320[1];
			fRec320[1] = fRec320[0];
			fRec321[2] = fRec321[1];
			fRec321[1] = fRec321[0];
			fRec322[2] = fRec322[1];
			fRec322[1] = fRec322[0];
			fRec323[2] = fRec323[1];
			fRec323[1] = fRec323[0];
			fRec324[2] = fRec324[1];
			fRec324[1] = fRec324[0];
			fRec325[2] = fRec325[1];
			fRec325[1] = fRec325[0];
			fRec326[2] = fRec326[1];
			fRec326[1] = fRec326[0];
			fRec327[2] = fRec327[1];
			fRec327[1] = fRec327[0];
			fRec328[2] = fRec328[1];
			fRec328[1] = fRec328[0];
			fRec329[2] = fRec329[1];
			fRec329[1] = fRec329[0];
			fRec330[2] = fRec330[1];
			fRec330[1] = fRec330[0];
			fRec331[2] = fRec331[1];
			fRec331[1] = fRec331[0];
			fRec332[2] = fRec332[1];
			fRec332[1] = fRec332[0];
			fRec333[2] = fRec333[1];
			fRec333[1] = fRec333[0];
			fRec334[2] = fRec334[1];
			fRec334[1] = fRec334[0];
			fRec335[2] = fRec335[1];
			fRec335[1] = fRec335[0];
			fRec336[2] = fRec336[1];
			fRec336[1] = fRec336[0];
			fRec337[2] = fRec337[1];
			fRec337[1] = fRec337[0];
			fRec338[2] = fRec338[1];
			fRec338[1] = fRec338[0];
			fRec339[2] = fRec339[1];
			fRec339[1] = fRec339[0];
			fRec340[2] = fRec340[1];
			fRec340[1] = fRec340[0];
			fRec341[2] = fRec341[1];
			fRec341[1] = fRec341[0];
			fRec342[2] = fRec342[1];
			fRec342[1] = fRec342[0];
			fRec343[2] = fRec343[1];
			fRec343[1] = fRec343[0];
			fRec344[2] = fRec344[1];
			fRec344[1] = fRec344[0];
			fRec345[2] = fRec345[1];
			fRec345[1] = fRec345[0];
			fRec346[2] = fRec346[1];
			fRec346[1] = fRec346[0];
			fRec347[2] = fRec347[1];
			fRec347[1] = fRec347[0];
			fRec348[2] = fRec348[1];
			fRec348[1] = fRec348[0];
			fRec349[2] = fRec349[1];
			fRec349[1] = fRec349[0];
			fRec350[2] = fRec350[1];
			fRec350[1] = fRec350[0];
			fRec351[2] = fRec351[1];
			fRec351[1] = fRec351[0];
			fRec352[2] = fRec352[1];
			fRec352[1] = fRec352[0];
			fRec353[2] = fRec353[1];
			fRec353[1] = fRec353[0];
			fRec354[2] = fRec354[1];
			fRec354[1] = fRec354[0];
			fRec355[2] = fRec355[1];
			fRec355[1] = fRec355[0];
			fRec356[2] = fRec356[1];
			fRec356[1] = fRec356[0];
			fRec357[2] = fRec357[1];
			fRec357[1] = fRec357[0];
			fRec358[2] = fRec358[1];
			fRec358[1] = fRec358[0];
			fRec359[2] = fRec359[1];
			fRec359[1] = fRec359[0];
			fRec360[2] = fRec360[1];
			fRec360[1] = fRec360[0];
			fRec361[2] = fRec361[1];
			fRec361[1] = fRec361[0];
			fRec362[2] = fRec362[1];
			fRec362[1] = fRec362[0];
			fRec363[2] = fRec363[1];
			fRec363[1] = fRec363[0];
			fRec364[2] = fRec364[1];
			fRec364[1] = fRec364[0];
			fRec365[2] = fRec365[1];
			fRec365[1] = fRec365[0];
			fRec366[2] = fRec366[1];
			fRec366[1] = fRec366[0];
			fRec367[2] = fRec367[1];
			fRec367[1] = fRec367[0];
			fRec368[2] = fRec368[1];
			fRec368[1] = fRec368[0];
			fRec369[2] = fRec369[1];
			fRec369[1] = fRec369[0];
			fRec370[2] = fRec370[1];
			fRec370[1] = fRec370[0];
			fRec371[2] = fRec371[1];
			fRec371[1] = fRec371[0];
			fRec372[2] = fRec372[1];
			fRec372[1] = fRec372[0];
			fRec373[2] = fRec373[1];
			fRec373[1] = fRec373[0];
			fRec374[2] = fRec374[1];
			fRec374[1] = fRec374[0];
			fRec375[2] = fRec375[1];
			fRec375[1] = fRec375[0];
			fRec376[2] = fRec376[1];
			fRec376[1] = fRec376[0];
			fRec377[2] = fRec377[1];
			fRec377[1] = fRec377[0];
			fRec378[2] = fRec378[1];
			fRec378[1] = fRec378[0];
			fRec379[2] = fRec379[1];
			fRec379[1] = fRec379[0];
			fRec380[2] = fRec380[1];
			fRec380[1] = fRec380[0];
			fRec381[2] = fRec381[1];
			fRec381[1] = fRec381[0];
			fRec382[2] = fRec382[1];
			fRec382[1] = fRec382[0];
			fRec383[2] = fRec383[1];
			fRec383[1] = fRec383[0];
			fRec384[2] = fRec384[1];
			fRec384[1] = fRec384[0];
			fRec385[2] = fRec385[1];
			fRec385[1] = fRec385[0];
			fRec386[2] = fRec386[1];
			fRec386[1] = fRec386[0];
			fRec387[2] = fRec387[1];
			fRec387[1] = fRec387[0];
			fRec388[2] = fRec388[1];
			fRec388[1] = fRec388[0];
			fRec389[2] = fRec389[1];
			fRec389[1] = fRec389[0];
			fRec390[2] = fRec390[1];
			fRec390[1] = fRec390[0];
			fRec391[2] = fRec391[1];
			fRec391[1] = fRec391[0];
			fRec392[2] = fRec392[1];
			fRec392[1] = fRec392[0];
			fRec393[2] = fRec393[1];
			fRec393[1] = fRec393[0];
			fRec394[2] = fRec394[1];
			fRec394[1] = fRec394[0];
			fRec395[2] = fRec395[1];
			fRec395[1] = fRec395[0];
			fRec396[2] = fRec396[1];
			fRec396[1] = fRec396[0];
			fRec397[2] = fRec397[1];
			fRec397[1] = fRec397[0];
			fRec398[2] = fRec398[1];
			fRec398[1] = fRec398[0];
			fRec399[2] = fRec399[1];
			fRec399[1] = fRec399[0];
			fRec400[2] = fRec400[1];
			fRec400[1] = fRec400[0];
			fRec401[2] = fRec401[1];
			fRec401[1] = fRec401[0];
			fRec402[2] = fRec402[1];
			fRec402[1] = fRec402[0];
			fRec403[2] = fRec403[1];
			fRec403[1] = fRec403[0];
			fRec404[2] = fRec404[1];
			fRec404[1] = fRec404[0];
			fRec405[2] = fRec405[1];
			fRec405[1] = fRec405[0];
			fRec406[2] = fRec406[1];
			fRec406[1] = fRec406[0];
			fRec407[2] = fRec407[1];
			fRec407[1] = fRec407[0];
			fRec408[2] = fRec408[1];
			fRec408[1] = fRec408[0];
			fRec409[2] = fRec409[1];
			fRec409[1] = fRec409[0];
			fRec410[2] = fRec410[1];
			fRec410[1] = fRec410[0];
			fRec411[2] = fRec411[1];
			fRec411[1] = fRec411[0];
			fRec412[2] = fRec412[1];
			fRec412[1] = fRec412[0];
			fRec413[2] = fRec413[1];
			fRec413[1] = fRec413[0];
			fRec414[2] = fRec414[1];
			fRec414[1] = fRec414[0];
			fRec415[2] = fRec415[1];
			fRec415[1] = fRec415[0];
			fRec416[2] = fRec416[1];
			fRec416[1] = fRec416[0];
			fRec417[2] = fRec417[1];
			fRec417[1] = fRec417[0];
			fRec418[2] = fRec418[1];
			fRec418[1] = fRec418[0];
			fRec419[2] = fRec419[1];
			fRec419[1] = fRec419[0];
			fRec420[2] = fRec420[1];
			fRec420[1] = fRec420[0];
			fRec421[2] = fRec421[1];
			fRec421[1] = fRec421[0];
			fRec422[2] = fRec422[1];
			fRec422[1] = fRec422[0];
			fRec423[2] = fRec423[1];
			fRec423[1] = fRec423[0];
			fRec424[2] = fRec424[1];
			fRec424[1] = fRec424[0];
			fRec425[2] = fRec425[1];
			fRec425[1] = fRec425[0];
			fRec426[2] = fRec426[1];
			fRec426[1] = fRec426[0];
			fRec427[2] = fRec427[1];
			fRec427[1] = fRec427[0];
			fRec428[2] = fRec428[1];
			fRec428[1] = fRec428[0];
			fRec429[2] = fRec429[1];
			fRec429[1] = fRec429[0];
			fRec430[2] = fRec430[1];
			fRec430[1] = fRec430[0];
			fRec431[2] = fRec431[1];
			fRec431[1] = fRec431[0];
			fRec432[2] = fRec432[1];
			fRec432[1] = fRec432[0];
			fRec433[2] = fRec433[1];
			fRec433[1] = fRec433[0];
			fRec434[2] = fRec434[1];
			fRec434[1] = fRec434[0];
			fRec435[2] = fRec435[1];
			fRec435[1] = fRec435[0];
			fRec436[2] = fRec436[1];
			fRec436[1] = fRec436[0];
			fRec437[2] = fRec437[1];
			fRec437[1] = fRec437[0];
			fRec438[2] = fRec438[1];
			fRec438[1] = fRec438[0];
			fRec439[2] = fRec439[1];
			fRec439[1] = fRec439[0];
			fRec440[2] = fRec440[1];
			fRec440[1] = fRec440[0];
			fRec441[2] = fRec441[1];
			fRec441[1] = fRec441[0];
			fRec442[2] = fRec442[1];
			fRec442[1] = fRec442[0];
			fRec443[2] = fRec443[1];
			fRec443[1] = fRec443[0];
			fRec444[2] = fRec444[1];
			fRec444[1] = fRec444[0];
			fRec445[2] = fRec445[1];
			fRec445[1] = fRec445[0];
			fRec446[2] = fRec446[1];
			fRec446[1] = fRec446[0];
			fRec447[2] = fRec447[1];
			fRec447[1] = fRec447[0];
			fRec448[2] = fRec448[1];
			fRec448[1] = fRec448[0];
			fRec449[2] = fRec449[1];
			fRec449[1] = fRec449[0];
			fRec450[2] = fRec450[1];
			fRec450[1] = fRec450[0];
			fRec451[2] = fRec451[1];
			fRec451[1] = fRec451[0];
			fRec452[2] = fRec452[1];
			fRec452[1] = fRec452[0];
			fRec453[2] = fRec453[1];
			fRec453[1] = fRec453[0];
			fRec454[2] = fRec454[1];
			fRec454[1] = fRec454[0];
			fRec455[2] = fRec455[1];
			fRec455[1] = fRec455[0];
			fRec456[2] = fRec456[1];
			fRec456[1] = fRec456[0];
			fRec457[2] = fRec457[1];
			fRec457[1] = fRec457[0];
			fRec458[2] = fRec458[1];
			fRec458[1] = fRec458[0];
			fRec459[2] = fRec459[1];
			fRec459[1] = fRec459[0];
			fRec460[2] = fRec460[1];
			fRec460[1] = fRec460[0];
			fRec461[2] = fRec461[1];
			fRec461[1] = fRec461[0];
			fRec462[2] = fRec462[1];
			fRec462[1] = fRec462[0];
			fRec463[2] = fRec463[1];
			fRec463[1] = fRec463[0];
			fRec464[2] = fRec464[1];
			fRec464[1] = fRec464[0];
			fRec465[2] = fRec465[1];
			fRec465[1] = fRec465[0];
			fRec466[2] = fRec466[1];
			fRec466[1] = fRec466[0];
			fRec467[2] = fRec467[1];
			fRec467[1] = fRec467[0];
			fRec468[2] = fRec468[1];
			fRec468[1] = fRec468[0];
			fRec469[2] = fRec469[1];
			fRec469[1] = fRec469[0];
			fRec470[2] = fRec470[1];
			fRec470[1] = fRec470[0];
			fRec471[2] = fRec471[1];
			fRec471[1] = fRec471[0];
			fRec472[2] = fRec472[1];
			fRec472[1] = fRec472[0];
			fRec473[2] = fRec473[1];
			fRec473[1] = fRec473[0];
			fRec474[2] = fRec474[1];
			fRec474[1] = fRec474[0];
			fRec475[2] = fRec475[1];
			fRec475[1] = fRec475[0];
			fRec476[2] = fRec476[1];
			fRec476[1] = fRec476[0];
			fRec477[2] = fRec477[1];
			fRec477[1] = fRec477[0];
			fRec478[2] = fRec478[1];
			fRec478[1] = fRec478[0];
			fRec479[2] = fRec479[1];
			fRec479[1] = fRec479[0];
			fRec480[2] = fRec480[1];
			fRec480[1] = fRec480[0];
			fRec481[2] = fRec481[1];
			fRec481[1] = fRec481[0];
			fRec482[2] = fRec482[1];
			fRec482[1] = fRec482[0];
			fRec483[2] = fRec483[1];
			fRec483[1] = fRec483[0];
			fRec484[2] = fRec484[1];
			fRec484[1] = fRec484[0];
			fRec485[2] = fRec485[1];
			fRec485[1] = fRec485[0];
			fRec486[2] = fRec486[1];
			fRec486[1] = fRec486[0];
			fRec487[2] = fRec487[1];
			fRec487[1] = fRec487[0];
			fRec488[2] = fRec488[1];
			fRec488[1] = fRec488[0];
			fRec489[2] = fRec489[1];
			fRec489[1] = fRec489[0];
			fRec490[2] = fRec490[1];
			fRec490[1] = fRec490[0];
			fRec491[2] = fRec491[1];
			fRec491[1] = fRec491[0];
			fRec492[2] = fRec492[1];
			fRec492[1] = fRec492[0];
			fRec493[2] = fRec493[1];
			fRec493[1] = fRec493[0];
			fRec494[2] = fRec494[1];
			fRec494[1] = fRec494[0];
			fRec495[2] = fRec495[1];
			fRec495[1] = fRec495[0];
			fRec496[2] = fRec496[1];
			fRec496[1] = fRec496[0];
			fRec497[2] = fRec497[1];
			fRec497[1] = fRec497[0];
			fRec498[2] = fRec498[1];
			fRec498[1] = fRec498[0];
			fRec499[2] = fRec499[1];
			fRec499[1] = fRec499[0];
			fRec500[2] = fRec500[1];
			fRec500[1] = fRec500[0];
			fRec501[2] = fRec501[1];
			fRec501[1] = fRec501[0];
			fRec502[2] = fRec502[1];
			fRec502[1] = fRec502[0];
			fRec503[2] = fRec503[1];
			fRec503[1] = fRec503[0];
			fRec504[2] = fRec504[1];
			fRec504[1] = fRec504[0];
			fRec505[2] = fRec505[1];
			fRec505[1] = fRec505[0];
			fRec506[2] = fRec506[1];
			fRec506[1] = fRec506[0];
			fRec507[2] = fRec507[1];
			fRec507[1] = fRec507[0];
			fRec508[2] = fRec508[1];
			fRec508[1] = fRec508[0];
			fRec509[2] = fRec509[1];
			fRec509[1] = fRec509[0];
			fRec510[2] = fRec510[1];
			fRec510[1] = fRec510[0];
			fRec511[2] = fRec511[1];
			fRec511[1] = fRec511[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "moodygirl.dsp"
	#define FAUST_CLASS_NAME "mydsp"
	#define FAUST_COMPILATION_OPIONS "-a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -double -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 64
	#define FAUST_PASSIVES 0

	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 0/modes", fVslider62, 32.0, 0.0, 32.0, 1.0);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 0/base freq", fVslider60, 2.2e+02, 1.0, 1.5e+04, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 0/freq mult", fVslider59, 1.0, 0.0, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 0/freq shift", fVslider58, 0.0, 0.0, 5e+03, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 0/base dur", fVslider57, 1.0, 0.0, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 0/dur div", fVslider56, 1.0, 0.001, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 0/base amp", fVslider63, 0.1, 0.0, 4.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 0/amp div", fVslider61, 1.0, 0.01, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 1/modes", fVslider54, 32.0, 0.0, 32.0, 1.0);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 1/base freq", fVslider52, 2.2e+02, 1.0, 1.5e+04, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 1/freq mult", fVslider51, 1.0, 0.0, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 1/freq shift", fVslider50, 0.0, 0.0, 5e+03, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 1/base dur", fVslider49, 1.0, 0.0, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 1/dur div", fVslider48, 1.0, 0.001, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 1/base amp", fVslider55, 0.1, 0.0, 4.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 1/amp div", fVslider53, 1.0, 0.01, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 2/modes", fVslider46, 32.0, 0.0, 32.0, 1.0);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 2/base freq", fVslider44, 2.2e+02, 1.0, 1.5e+04, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 2/freq mult", fVslider43, 1.0, 0.0, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 2/freq shift", fVslider42, 0.0, 0.0, 5e+03, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 2/base dur", fVslider41, 1.0, 0.0, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 2/dur div", fVslider40, 1.0, 0.001, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 2/base amp", fVslider47, 0.1, 0.0, 4.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 2/amp div", fVslider45, 1.0, 0.01, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 3/modes", fVslider38, 32.0, 0.0, 32.0, 1.0);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 3/base freq", fVslider36, 2.2e+02, 1.0, 1.5e+04, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 3/freq mult", fVslider35, 1.0, 0.0, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 3/freq shift", fVslider34, 0.0, 0.0, 5e+03, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 3/base dur", fVslider33, 1.0, 0.0, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 3/dur div", fVslider32, 1.0, 0.001, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 3/base amp", fVslider39, 0.1, 0.0, 4.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 3/amp div", fVslider37, 1.0, 0.01, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 4/modes", fVslider30, 32.0, 0.0, 32.0, 1.0);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 4/base freq", fVslider28, 2.2e+02, 1.0, 1.5e+04, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 4/freq mult", fVslider27, 1.0, 0.0, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 4/freq shift", fVslider26, 0.0, 0.0, 5e+03, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 4/base dur", fVslider25, 1.0, 0.0, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 4/dur div", fVslider24, 1.0, 0.001, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 4/base amp", fVslider31, 0.1, 0.0, 4.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 4/amp div", fVslider29, 1.0, 0.01, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 5/modes", fVslider22, 32.0, 0.0, 32.0, 1.0);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 5/base freq", fVslider20, 2.2e+02, 1.0, 1.5e+04, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 5/freq mult", fVslider19, 1.0, 0.0, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 5/freq shift", fVslider18, 0.0, 0.0, 5e+03, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 5/base dur", fVslider17, 1.0, 0.0, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 5/dur div", fVslider16, 1.0, 0.001, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 5/base amp", fVslider23, 0.1, 0.0, 4.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 5/amp div", fVslider21, 1.0, 0.01, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 6/modes", fVslider14, 32.0, 0.0, 32.0, 1.0);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 6/base freq", fVslider12, 2.2e+02, 1.0, 1.5e+04, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 6/freq mult", fVslider11, 1.0, 0.0, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 6/freq shift", fVslider10, 0.0, 0.0, 5e+03, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 6/base dur", fVslider9, 1.0, 0.0, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 6/dur div", fVslider8, 1.0, 0.001, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 6/base amp", fVslider15, 0.1, 0.0, 4.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 6/amp div", fVslider13, 1.0, 0.01, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 7/modes", fVslider6, 32.0, 0.0, 32.0, 1.0);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 7/base freq", fVslider4, 2.2e+02, 1.0, 1.5e+04, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 7/freq mult", fVslider3, 1.0, 0.0, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 7/freq shift", fVslider2, 0.0, 0.0, 5e+03, 0.1);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 7/base dur", fVslider1, 1.0, 0.0, 1e+01, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 7/dur div", fVslider0, 1.0, 0.001, 2.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 7/base amp", fVslider7, 0.1, 0.0, 4.0, 0.001);
	FAUST_ADDVERTICALSLIDER("moodygirl 0.14/ 7/amp div", fVslider5, 1.0, 0.01, 2.0, 0.001);

	#define FAUST_LIST_ACTIVES(p) \
		p(VERTICALSLIDER, modes, "moodygirl 0.14/ 0/modes", fVslider62, 32.0, 0.0, 32.0, 1.0) \
		p(VERTICALSLIDER, base_freq, "moodygirl 0.14/ 0/base freq", fVslider60, 2.2e+02, 1.0, 1.5e+04, 0.1) \
		p(VERTICALSLIDER, freq_mult, "moodygirl 0.14/ 0/freq mult", fVslider59, 1.0, 0.0, 2.0, 0.001) \
		p(VERTICALSLIDER, freq_shift, "moodygirl 0.14/ 0/freq shift", fVslider58, 0.0, 0.0, 5e+03, 0.1) \
		p(VERTICALSLIDER, base_dur, "moodygirl 0.14/ 0/base dur", fVslider57, 1.0, 0.0, 1e+01, 0.001) \
		p(VERTICALSLIDER, dur_div, "moodygirl 0.14/ 0/dur div", fVslider56, 1.0, 0.001, 2.0, 0.001) \
		p(VERTICALSLIDER, base_amp, "moodygirl 0.14/ 0/base amp", fVslider63, 0.1, 0.0, 4.0, 0.001) \
		p(VERTICALSLIDER, amp_div, "moodygirl 0.14/ 0/amp div", fVslider61, 1.0, 0.01, 2.0, 0.001) \
		p(VERTICALSLIDER, modes, "moodygirl 0.14/ 1/modes", fVslider54, 32.0, 0.0, 32.0, 1.0) \
		p(VERTICALSLIDER, base_freq, "moodygirl 0.14/ 1/base freq", fVslider52, 2.2e+02, 1.0, 1.5e+04, 0.1) \
		p(VERTICALSLIDER, freq_mult, "moodygirl 0.14/ 1/freq mult", fVslider51, 1.0, 0.0, 2.0, 0.001) \
		p(VERTICALSLIDER, freq_shift, "moodygirl 0.14/ 1/freq shift", fVslider50, 0.0, 0.0, 5e+03, 0.1) \
		p(VERTICALSLIDER, base_dur, "moodygirl 0.14/ 1/base dur", fVslider49, 1.0, 0.0, 1e+01, 0.001) \
		p(VERTICALSLIDER, dur_div, "moodygirl 0.14/ 1/dur div", fVslider48, 1.0, 0.001, 2.0, 0.001) \
		p(VERTICALSLIDER, base_amp, "moodygirl 0.14/ 1/base amp", fVslider55, 0.1, 0.0, 4.0, 0.001) \
		p(VERTICALSLIDER, amp_div, "moodygirl 0.14/ 1/amp div", fVslider53, 1.0, 0.01, 2.0, 0.001) \
		p(VERTICALSLIDER, modes, "moodygirl 0.14/ 2/modes", fVslider46, 32.0, 0.0, 32.0, 1.0) \
		p(VERTICALSLIDER, base_freq, "moodygirl 0.14/ 2/base freq", fVslider44, 2.2e+02, 1.0, 1.5e+04, 0.1) \
		p(VERTICALSLIDER, freq_mult, "moodygirl 0.14/ 2/freq mult", fVslider43, 1.0, 0.0, 2.0, 0.001) \
		p(VERTICALSLIDER, freq_shift, "moodygirl 0.14/ 2/freq shift", fVslider42, 0.0, 0.0, 5e+03, 0.1) \
		p(VERTICALSLIDER, base_dur, "moodygirl 0.14/ 2/base dur", fVslider41, 1.0, 0.0, 1e+01, 0.001) \
		p(VERTICALSLIDER, dur_div, "moodygirl 0.14/ 2/dur div", fVslider40, 1.0, 0.001, 2.0, 0.001) \
		p(VERTICALSLIDER, base_amp, "moodygirl 0.14/ 2/base amp", fVslider47, 0.1, 0.0, 4.0, 0.001) \
		p(VERTICALSLIDER, amp_div, "moodygirl 0.14/ 2/amp div", fVslider45, 1.0, 0.01, 2.0, 0.001) \
		p(VERTICALSLIDER, modes, "moodygirl 0.14/ 3/modes", fVslider38, 32.0, 0.0, 32.0, 1.0) \
		p(VERTICALSLIDER, base_freq, "moodygirl 0.14/ 3/base freq", fVslider36, 2.2e+02, 1.0, 1.5e+04, 0.1) \
		p(VERTICALSLIDER, freq_mult, "moodygirl 0.14/ 3/freq mult", fVslider35, 1.0, 0.0, 2.0, 0.001) \
		p(VERTICALSLIDER, freq_shift, "moodygirl 0.14/ 3/freq shift", fVslider34, 0.0, 0.0, 5e+03, 0.1) \
		p(VERTICALSLIDER, base_dur, "moodygirl 0.14/ 3/base dur", fVslider33, 1.0, 0.0, 1e+01, 0.001) \
		p(VERTICALSLIDER, dur_div, "moodygirl 0.14/ 3/dur div", fVslider32, 1.0, 0.001, 2.0, 0.001) \
		p(VERTICALSLIDER, base_amp, "moodygirl 0.14/ 3/base amp", fVslider39, 0.1, 0.0, 4.0, 0.001) \
		p(VERTICALSLIDER, amp_div, "moodygirl 0.14/ 3/amp div", fVslider37, 1.0, 0.01, 2.0, 0.001) \
		p(VERTICALSLIDER, modes, "moodygirl 0.14/ 4/modes", fVslider30, 32.0, 0.0, 32.0, 1.0) \
		p(VERTICALSLIDER, base_freq, "moodygirl 0.14/ 4/base freq", fVslider28, 2.2e+02, 1.0, 1.5e+04, 0.1) \
		p(VERTICALSLIDER, freq_mult, "moodygirl 0.14/ 4/freq mult", fVslider27, 1.0, 0.0, 2.0, 0.001) \
		p(VERTICALSLIDER, freq_shift, "moodygirl 0.14/ 4/freq shift", fVslider26, 0.0, 0.0, 5e+03, 0.1) \
		p(VERTICALSLIDER, base_dur, "moodygirl 0.14/ 4/base dur", fVslider25, 1.0, 0.0, 1e+01, 0.001) \
		p(VERTICALSLIDER, dur_div, "moodygirl 0.14/ 4/dur div", fVslider24, 1.0, 0.001, 2.0, 0.001) \
		p(VERTICALSLIDER, base_amp, "moodygirl 0.14/ 4/base amp", fVslider31, 0.1, 0.0, 4.0, 0.001) \
		p(VERTICALSLIDER, amp_div, "moodygirl 0.14/ 4/amp div", fVslider29, 1.0, 0.01, 2.0, 0.001) \
		p(VERTICALSLIDER, modes, "moodygirl 0.14/ 5/modes", fVslider22, 32.0, 0.0, 32.0, 1.0) \
		p(VERTICALSLIDER, base_freq, "moodygirl 0.14/ 5/base freq", fVslider20, 2.2e+02, 1.0, 1.5e+04, 0.1) \
		p(VERTICALSLIDER, freq_mult, "moodygirl 0.14/ 5/freq mult", fVslider19, 1.0, 0.0, 2.0, 0.001) \
		p(VERTICALSLIDER, freq_shift, "moodygirl 0.14/ 5/freq shift", fVslider18, 0.0, 0.0, 5e+03, 0.1) \
		p(VERTICALSLIDER, base_dur, "moodygirl 0.14/ 5/base dur", fVslider17, 1.0, 0.0, 1e+01, 0.001) \
		p(VERTICALSLIDER, dur_div, "moodygirl 0.14/ 5/dur div", fVslider16, 1.0, 0.001, 2.0, 0.001) \
		p(VERTICALSLIDER, base_amp, "moodygirl 0.14/ 5/base amp", fVslider23, 0.1, 0.0, 4.0, 0.001) \
		p(VERTICALSLIDER, amp_div, "moodygirl 0.14/ 5/amp div", fVslider21, 1.0, 0.01, 2.0, 0.001) \
		p(VERTICALSLIDER, modes, "moodygirl 0.14/ 6/modes", fVslider14, 32.0, 0.0, 32.0, 1.0) \
		p(VERTICALSLIDER, base_freq, "moodygirl 0.14/ 6/base freq", fVslider12, 2.2e+02, 1.0, 1.5e+04, 0.1) \
		p(VERTICALSLIDER, freq_mult, "moodygirl 0.14/ 6/freq mult", fVslider11, 1.0, 0.0, 2.0, 0.001) \
		p(VERTICALSLIDER, freq_shift, "moodygirl 0.14/ 6/freq shift", fVslider10, 0.0, 0.0, 5e+03, 0.1) \
		p(VERTICALSLIDER, base_dur, "moodygirl 0.14/ 6/base dur", fVslider9, 1.0, 0.0, 1e+01, 0.001) \
		p(VERTICALSLIDER, dur_div, "moodygirl 0.14/ 6/dur div", fVslider8, 1.0, 0.001, 2.0, 0.001) \
		p(VERTICALSLIDER, base_amp, "moodygirl 0.14/ 6/base amp", fVslider15, 0.1, 0.0, 4.0, 0.001) \
		p(VERTICALSLIDER, amp_div, "moodygirl 0.14/ 6/amp div", fVslider13, 1.0, 0.01, 2.0, 0.001) \
		p(VERTICALSLIDER, modes, "moodygirl 0.14/ 7/modes", fVslider6, 32.0, 0.0, 32.0, 1.0) \
		p(VERTICALSLIDER, base_freq, "moodygirl 0.14/ 7/base freq", fVslider4, 2.2e+02, 1.0, 1.5e+04, 0.1) \
		p(VERTICALSLIDER, freq_mult, "moodygirl 0.14/ 7/freq mult", fVslider3, 1.0, 0.0, 2.0, 0.001) \
		p(VERTICALSLIDER, freq_shift, "moodygirl 0.14/ 7/freq shift", fVslider2, 0.0, 0.0, 5e+03, 0.1) \
		p(VERTICALSLIDER, base_dur, "moodygirl 0.14/ 7/base dur", fVslider1, 1.0, 0.0, 1e+01, 0.001) \
		p(VERTICALSLIDER, dur_div, "moodygirl 0.14/ 7/dur div", fVslider0, 1.0, 0.001, 2.0, 0.001) \
		p(VERTICALSLIDER, base_amp, "moodygirl 0.14/ 7/base amp", fVslider7, 0.1, 0.0, 4.0, 0.001) \
		p(VERTICALSLIDER, amp_div, "moodygirl 0.14/ 7/amp div", fVslider5, 1.0, 0.01, 2.0, 0.001) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#if defined(JUCE_POLY)

struct FaustSound : public juce::SynthesiserSound {
    
    bool appliesToNote (int /*midiNoteNumber*/) override        { return true; }
    bool appliesToChannel (int /*midiChannel*/) override        { return true; }
};

// An hybrid JUCE and Faust voice

class FaustVoice : public juce::SynthesiserVoice, public dsp_voice {
    
    private:
        
        std::unique_ptr<juce::AudioBuffer<FAUSTFLOAT>> fBuffer;
        
    public:
        
        FaustVoice(base_dsp* base_dsp):dsp_voice(base_dsp)
        {
            // Allocate buffer for mixing
            fBuffer = std::make_unique<juce::AudioBuffer<FAUSTFLOAT>>(base_dsp->getNumOutputs(), 8192);
            fDSP->init(juce::SynthesiserVoice::getSampleRate());
        }
        
        bool canPlaySound (juce::SynthesiserSound* sound) override
        {
            return dynamic_cast<FaustSound*> (sound) != nullptr;
        }
        
        void startNote (int midiNoteNumber,
                        float velocity,
                        juce::SynthesiserSound* s,
                        int currentPitchWheelPosition) override
        {
            // Note is triggered
            keyOn(midiNoteNumber, velocity);
        }
        
        void stopNote (float velocity, bool allowTailOff) override
        {
            keyOff(!allowTailOff);
        }
        
        void pitchWheelMoved (int newPitchWheelValue) override
        {
            // not implemented for now
        }
        
        void controllerMoved (int controllerNumber, int newControllerValue) override
        {
            // not implemented for now
        }
        
        void renderNextBlock (juce::AudioBuffer<FAUSTFLOAT>& outputBuffer,
                              int startSample,
                              int numSamples) override
        {
            // Only plays when the voice is active
            if (isVoiceActive()) {
                
                // Play the voice
                compute(numSamples, nullptr, (FAUSTFLOAT**)fBuffer->getArrayOfWritePointers());
                
                // Mix it in outputs
                for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                    outputBuffer.addFrom(i, startSample, *fBuffer, i, 0, numSamples);
                }
            }
        }
    
};

// Decorates the JUCE Synthesiser and adds Faust polyphonic code for GUI handling

class FaustSynthesiser : public juce::Synthesiser, public dsp_voice_group {
    
    private:
        
        juce::Synthesiser fSynth;
    
        static void panic(float val, void* arg)
        {
            static_cast<FaustSynthesiser*>(arg)->allNotesOff(0, false); // 0 stops all voices
        }
  
    public:
        
        FaustSynthesiser():dsp_voice_group(panic, this, true, true)
        {
            setNoteStealingEnabled(true);
        }
        
        virtual ~FaustSynthesiser()
        {
            // Voices will be deallocated by fSynth
            dsp_voice_group::clearVoices();
        }
        
        void addVoice(FaustVoice* voice)
        {
            fSynth.addVoice(voice);
            dsp_voice_group::addVoice(voice);
        }
        
        void addSound(juce::SynthesiserSound* sound)
        {
            fSynth.addSound(sound);
        }
        
        void allNotesOff(int midiChannel, bool allowTailOff)
        {
            fSynth.allNotesOff(midiChannel, allowTailOff);
        }
        
        void setCurrentPlaybackSampleRate (double newRate)
        {
            fSynth.setCurrentPlaybackSampleRate(newRate);
        }
        
        void renderNextBlock (juce::AudioBuffer<float>& outputAudio,
                              const juce::MidiBuffer& inputMidi,
                              int startSample,
                              int numSamples)
        {
            fSynth.renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
        }
        
        void renderNextBlock (juce::AudioBuffer<double>& outputAudio,
                              const juce::MidiBuffer& inputMidi,
                              int startSample,
                              int numSamples)
        {
            fSynth.renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
        }
    
};

#endif

// Using the PluginGuiMagic project (https://foleysfinest.com/developer/pluginguimagic/)

#if defined(PLUGIN_MAGIC)

class FaustPlugInAudioProcessor : public foleys::MagicProcessor, private juce::Timer
{
    
    public:
        FaustPlugInAudioProcessor();
        virtual ~FaustPlugInAudioProcessor() {}
        
        void prepareToPlay (double sampleRate, int samplesPerBlock) override;
        
        bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
        
        void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
        {
            jassert (! isUsingDoublePrecision());
            process (buffer, midiMessages);
    #ifdef MAGIC_LEVEL_SOURCE
            fOutputMeter->pushSamples(buffer);
    #endif
        }
        
        void processBlock (juce::AudioBuffer<double>& buffer, juce::MidiBuffer& midiMessages) override
        {
            jassert (isUsingDoublePrecision());
            process (buffer, midiMessages);
        }
        
        const juce::String getName() const override;
        
        bool acceptsMidi() const override;
        bool producesMidi() const override;
        double getTailLengthSeconds() const override;
        
        int getNumPrograms() override;
        int getCurrentProgram() override;
        void setCurrentProgram (int index) override;
        const juce::String getProgramName (int index) override;
        void changeProgramName (int index, const juce::String& newName) override;
        
        void releaseResources() override
        {}
        
        void timerCallback() override;
        
        juce::AudioProcessor::BusesProperties getBusesProperties();
        bool supportsDoublePrecisionProcessing() const override;
      
    #ifdef MAGIC_LEVEL_SOURCE
        foleys::MagicLevelSource* fOutputMeter = nullptr;
    #endif
        juce::AudioProcessorValueTreeState treeState{ *this, nullptr };
    
    #ifdef JUCE_POLY
        std::unique_ptr<FaustSynthesiser> fSynth;
    #else
    #if defined(MIDICTRL)
        std::unique_ptr<juce_midi_handler> fMIDIHandler;
        std::unique_ptr<MidiUI> fMIDIUI;
    #endif
        std::unique_ptr<base_dsp> fDSP;
    #endif
        
    #if defined(OSCCTRL)
        std::unique_ptr<JuceOSCUI> fOSCUI;
    #endif
        
    #if defined(SOUNDFILE)
        std::unique_ptr<SoundUI> fSoundUI;
    #endif
        
        JuceStateUI fStateUI;
        JuceParameterUI fParameterUI;
        
        bool fFirstcall = true;
        
    private:
        
        template <typename FloatType>
        void process (juce::AudioBuffer<FloatType>& buffer, juce::MidiBuffer& midiMessages);
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustPlugInAudioProcessor)
    
};

#else

class FaustPlugInAudioProcessor : public juce::AudioProcessor, private juce::Timer
{

    public:
        
        FaustPlugInAudioProcessor();
        virtual ~FaustPlugInAudioProcessor() {}
        
        void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    
        bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
        
        void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
        {
            jassert (! isUsingDoublePrecision());
            process (buffer, midiMessages);
        }
        
        void processBlock (juce::AudioBuffer<double>& buffer, juce::MidiBuffer& midiMessages) override
        {
            jassert (isUsingDoublePrecision());
            process (buffer, midiMessages);
        }
    
        juce::AudioProcessorEditor* createEditor() override;
        bool hasEditor() const override;
        
        const juce::String getName() const override;
        
        bool acceptsMidi() const override;
        bool producesMidi() const override;
        double getTailLengthSeconds() const override;
        
        int getNumPrograms() override;
        int getCurrentProgram() override;
        void setCurrentProgram (int index) override;
        const juce::String getProgramName (int index) override;
        void changeProgramName (int index, const juce::String& newName) override;
        
        void getStateInformation (juce::MemoryBlock& destData) override;
        void setStateInformation (const void* data, int sizeInBytes) override;
    
        void releaseResources() override
        {}
        
        void timerCallback() override;
    
        juce::AudioProcessor::BusesProperties getBusesProperties();
        bool supportsDoublePrecisionProcessing() const override;
    
    #ifdef JUCE_POLY
        std::unique_ptr<FaustSynthesiser> fSynth;
    #else
    #if defined(MIDICTRL)
        std::unique_ptr<juce_midi_handler> fMIDIHandler;
        std::unique_ptr<MidiUI> fMIDIUI;
    #endif
        std::unique_ptr<base_dsp> fDSP;
    #endif
        
    #if defined(OSCCTRL)
        std::unique_ptr<JuceOSCUI> fOSCUI;
    #endif
    
    #if defined(SOUNDFILE)
        std::unique_ptr<SoundUI> fSoundUI;
    #endif
    
        JuceStateUI fStateUI;
        JuceParameterUI fParameterUI;
    
        bool fFirstcall = true;
    
    private:
    
        template <typename FloatType>
        void process (juce::AudioBuffer<FloatType>& buffer, juce::MidiBuffer& midiMessages);
    
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustPlugInAudioProcessor)
    
};

#endif

class FaustPlugInAudioProcessorEditor : public juce::AudioProcessorEditor
{
    
    public:
        
        FaustPlugInAudioProcessorEditor (FaustPlugInAudioProcessor&);
        virtual ~FaustPlugInAudioProcessorEditor() {}
        
        void paint (juce::Graphics&) override;
        void resized() override;
        
    private:
        
        // This reference is provided as a quick way for your editor to
        // access the processor object that created it.
        FaustPlugInAudioProcessor& processor;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustPlugInAudioProcessorEditor)
#ifndef PLUGIN_MAGIC        
        JuceGUI fJuceGUI;
#endif    
};

#ifndef PLUGIN_MAGIC
FaustPlugInAudioProcessor::FaustPlugInAudioProcessor()
: juce::AudioProcessor (getBusesProperties()), fParameterUI(this)
#else
FaustPlugInAudioProcessor::FaustPlugInAudioProcessor()
: foleys::MagicProcessor (getBusesProperties()), fParameterUI(this)	
#endif
{
    bool midi_sync = false;
    int nvoices = 0;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
	
#ifdef PLUGIN_MAGIC
#ifdef MAGIC_LOAD_BINARY
    // change magic_xml and magic_xmlSize to match the name of your included
    // XML file from Plugin GUI Magic
    magicState.setGuiValueTree(BinaryData::magic_xml, BinaryData::magic_xmlSize);
#endif
// put other GUI Magic sources here, similar to expression below.
#ifdef MAGIC_LEVEL_SOURCE
    fOutputMeter = magicState.createAndAddObject<foleys::MagicLevelSource>("output");
#endif
#endif
   
#ifdef JUCE_POLY
    assert(nvoices > 0);
    fSynth = std::make_unique<FaustSynthesiser>();
    for (int i = 0; i < nvoices; i++) {
        fSynth->addVoice(new FaustVoice(new mydsp()));
    }
    fSynth->init();
    fSynth->addSound(new FaustSound());
#else
    
    bool group = true;
    
#ifdef POLY2
    assert(nvoices > 0);
    std::cout << "Started with " << nvoices << " voices\n";
    base_dsp* base_dsp = new mydsp_poly(new mydsp(), nvoices, true, group);
    
#if MIDICTRL
    if (midi_sync) {
        fDSP = std::make_unique<timed_dsp>(new dsp_sequencer(base_dsp, new effect()));
    } else {
        fDSP = std::make_unique<dsp_sequencer>(base_dsp, new effect());
    }
#else
    fDSP = std::make_unique<dsp_sequencer>(base_dsp, new effects());
#endif
    
#else
    if (nvoices > 0) {
        std::cout << "Started with " << nvoices << " voices\n";
        base_dsp* base_dsp = new mydsp_poly(new mydsp(), nvoices, true, group);
        
#if MIDICTRL
        if (midi_sync) {
            fDSP = std::make_unique<timed_dsp>(base_dsp);
        } else {
            fDSP = std::make_unique<decorator_dsp>(base_dsp);
        }
#else
        fDSP = std::make_unique<decorator_dsp>(base_dsp);
#endif
    } else {
#if MIDICTRL
        if (midi_sync) {
            fDSP = std::make_unique<timed_dsp>(new mydsp());
        } else {
            fDSP = std::make_unique<mydsp>();
        }
#else
        fDSP = std::make_unique<mydsp>();
#endif
    }
    
#endif
    
#if defined(MIDICTRL)
    fMIDIHandler = std::make_unique<juce_midi_handler>();
    fMIDIUI = std::make_unique<MidiUI>(fMIDIHandler.get());
    fDSP->buildUserInterface(fMIDIUI.get());
    if (!fMIDIUI->run()) {
        std::cerr << "JUCE MIDI handler cannot be started..." << std::endl;
    }
#endif
    
#endif
    
#if defined(OSCCTRL)
    fOSCUI = std::make_unique<JuceOSCUI>("127.0.0.1", 5510, 5511);
#ifdef JUCE_POLY
    fSynth->buildUserInterface(fOSCUI.get());
#else
    fDSP->buildUserInterface(fOSCUI.get());
#endif
    if (!fOSCUI->run()) {
        std::cerr << "JUCE OSC handler cannot be started..." << std::endl;
    }
#endif
    
#if defined(SOUNDFILE)
    // Use bundle path
    auto file = juce::File::getSpecialLocation(juce::File::currentExecutableFile)
        .getParentDirectory().getParentDirectory().getChildFile("Resources");
    fSoundUI = std::make_unique<SoundUI>(file.getFullPathName().toStdString());
    fDSP->buildUserInterface(fSoundUI.get());
#endif
    
#ifdef JUCE_POLY
    fSynth->buildUserInterface(&fStateUI);
    fSynth->buildUserInterface(&fParameterUI);
    // When no previous state was restored, init DSP controllers with their default values
    if (!fStateUI.fRestored) {
        fSynth->instanceResetUserInterface();
    }
#else
    fDSP->buildUserInterface(&fStateUI);
    fDSP->buildUserInterface(&fParameterUI);
    // When no previous state was restored, init DSP controllers with their default values
    if (!fStateUI.fRestored) {
        fDSP->instanceResetUserInterface();
    }
#endif
    
    startTimerHz(25);
}

juce::AudioProcessor::BusesProperties FaustPlugInAudioProcessor::getBusesProperties()
{
    if (juce::PluginHostType::getPluginLoadedAs() == wrapperType_Standalone) {
        if (FAUST_INPUTS == 0) {
            return BusesProperties().withOutput("Output", juce::AudioChannelSet::discreteChannels(std::min<int>(2, FAUST_OUTPUTS)), true);
        } else {
            return BusesProperties()
            .withInput("Input", juce::AudioChannelSet::discreteChannels(std::min<int>(2, FAUST_INPUTS)), true)
            .withOutput("Output", juce::AudioChannelSet::discreteChannels(std::min<int>(2, FAUST_OUTPUTS)), true);
        }
    } else {
        if (FAUST_INPUTS == 0) {
            return BusesProperties().withOutput("Output", juce::AudioChannelSet::discreteChannels(FAUST_OUTPUTS), true);
        } else {
            return BusesProperties()
            .withInput("Input", juce::AudioChannelSet::discreteChannels(FAUST_INPUTS), true)
            .withOutput("Output", juce::AudioChannelSet::discreteChannels(FAUST_OUTPUTS), true);
        }
    }
}

void FaustPlugInAudioProcessor::timerCallback()
{
    GUI::updateAllGuis();
}

//==============================================================================
const juce::String FaustPlugInAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FaustPlugInAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool FaustPlugInAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

double FaustPlugInAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FaustPlugInAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int FaustPlugInAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FaustPlugInAudioProcessor::setCurrentProgram (int index)
{}

const juce::String FaustPlugInAudioProcessor::getProgramName (int index)
{
    return juce::String();
}

void FaustPlugInAudioProcessor::changeProgramName (int index, const juce::String& newName)
{}

bool FaustPlugInAudioProcessor::supportsDoublePrecisionProcessing() const
{
    return sizeof(FAUSTFLOAT) == 8;
}

//==============================================================================
void FaustPlugInAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
#ifdef JUCE_POLY
    fSynth->setCurrentPlaybackSampleRate (sampleRate);
#else
    
    // Setting the DSP control values has already been done
    // by 'buildUserInterface(&fStateUI)', using the saved values or the default ones.
    // What has to be done to finish the DSP initialization is done now.
    mydsp::classInit(int(sampleRate));
    fDSP->instanceConstants(int(sampleRate));
    fDSP->instanceClear();
    
    // Get latency metadata
    struct LatencyMeta : public Meta {
        
        float fLatencyFrames = -1.f;
        float fLatencySec = -1.f;
        
        void declare(const char* key, const char* value)
        {
            if (std::string(key) == "latency_frames" || std::string(key) == "latency_samples") {
                fLatencyFrames = std::atof(value);
            } else if (std::string(key) == "latency_sec") {
                fLatencySec = std::atof(value);
            }
        }
    };
    
    LatencyMeta meta;
    fDSP->metadata(&meta);
    if (meta.fLatencyFrames > 0) {
        setLatencySamples(meta.fLatencyFrames);
    } else if (meta.fLatencySec > 0) {
        setLatencySamples(meta.fLatencySec * sampleRate);
    }
    
#endif
#ifdef MAGIC_LEVEL_SOURCE
    magicState.prepareToPlay(sampleRate, samplesPerBlock);
    fOutputMeter->setupSource(getMainBusNumOutputChannels(), sampleRate, 500, 200);
#endif
}

bool FaustPlugInAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#ifdef JUCE_POLY
    return true;
#else
    
#if JucePlugin_IsSynth
    // Stereo is supported
    return (layouts.getMainOutputChannelSet().size() == 2) || (layouts.getMainOutputChannelSet().size() == fDSP->getNumOutputs());
#else
    // Stereo is supported
    return
    ((layouts.getMainInputChannelSet().size() == 2) && (layouts.getMainOutputChannelSet().size() == 2))
    ||
    ((layouts.getMainInputChannelSet().size() == fDSP->getNumInputs()) && (layouts.getMainOutputChannelSet().size() == fDSP->getNumOutputs()));
#endif
    
#endif
}

template <typename FloatType>
void FaustPlugInAudioProcessor::process (juce::AudioBuffer<FloatType>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    
    /*
        prepareToPlay is possibly called several times with different values for sampleRate
        and isUsingDoublePrecision() state (this has been seen in particular with VTS3),
        making proper sample format (float/double) and the inputs/outputs layout adaptation
        more complex at this stage.
        
        So adapting the sample format (float/double) and the inputs/outputs layout is done
        once at first process call even if this possibly allocates memory, which is not RT safe.
    */
    if (fFirstcall) {
        fFirstcall = false;
        
        // Possible sample size adaptation
        if (supportsDoublePrecisionProcessing()) {
            if (isUsingDoublePrecision()) {
                // Nothing to do
            } else {
                fDSP = std::make_unique<dsp_sample_adapter<double, float>>(fDSP.release());
            }
        } else {
            if (isUsingDoublePrecision()) {
                fDSP = std::make_unique<dsp_sample_adapter<float, double>>(fDSP.release());
            } else {
                // Nothing to do
            }
        }
        
        // Possibly adapt DSP inputs/outputs number
        if (fDSP->getNumInputs() > getTotalNumInputChannels() || fDSP->getNumOutputs() > getTotalNumOutputChannels()) {
            fDSP = std::make_unique<dsp_adapter>(fDSP.release(), getTotalNumInputChannels(), getTotalNumOutputChannels(), 4096);
        }
    }
    
#ifdef JUCE_POLY
    fSynth->renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
#else
#if defined(MIDICTRL)
    // Read MIDI input events from midiMessages
    fMIDIHandler->decodeBuffer(midiMessages);
    // Then write MIDI output events to midiMessages
    fMIDIHandler->encodeBuffer(midiMessages);
#endif
    // MIDI timestamp is expressed in frames
    fDSP->compute(-1, buffer.getNumSamples(),
                  (FAUSTFLOAT**)buffer.getArrayOfReadPointers(),
                  (FAUSTFLOAT**)buffer.getArrayOfWritePointers());
#endif
}

//==============================================================================
#ifndef PLUGIN_MAGIC
bool FaustPlugInAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* FaustPlugInAudioProcessor::createEditor()
{
    return new FaustPlugInAudioProcessorEditor (*this);
}

//==============================================================================
void FaustPlugInAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    fStateUI.getStateInformation(destData);
}

void FaustPlugInAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    fStateUI.setStateInformation(data, sizeInBytes);
 }
#endif
//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FaustPlugInAudioProcessor();
}

//==============================================================================
#ifndef PLUGIN_MAGIC
FaustPlugInAudioProcessorEditor::FaustPlugInAudioProcessorEditor (FaustPlugInAudioProcessor& p)
: juce::AudioProcessorEditor (&p), processor (p)
{
#ifdef JUCE_POLY
    p.fSynth->buildUserInterface(&fJuceGUI);
#else
    p.fDSP->buildUserInterface(&fJuceGUI);
#endif
    
    addAndMakeVisible(fJuceGUI);
    
    juce::Rectangle<int> recommendedSize = fJuceGUI.getSize();
    setSize (recommendedSize.getWidth(), recommendedSize.getHeight());
}

//==============================================================================
void FaustPlugInAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::white);
}

void FaustPlugInAudioProcessorEditor::resized()
{
    fJuceGUI.setBounds(getLocalBounds());
}

#endif
// Globals
std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

#endif
