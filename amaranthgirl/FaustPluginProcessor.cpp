/* ------------------------------------------------------------
author: "amy universe"
license: "WTFPL"
name: "amaranthgirl"
version: "10.04"
Code generated with Faust 2.50.6 (https://faust.grame.fr)
Compilation options: -a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -single -ftz 0
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
                res.setSize(std::max<int>(1, res.getWidth()), std::max<int>(1, res.getHeight()));
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

/* link with : "" */
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

class mydspSIG0 {
	
  public:
	
	int iRec12[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iRec12[l10] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iRec12[0] = iRec12[1] + 1;
			table[i1] = std::log(19.540567f * float(iRec12[0] + -1) + 1e+01f);
			iRec12[1] = iRec12[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[1024];
static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float mydsp_faustpower4_f(float value) {
	return value * value * value * value;
}
static float mydsp_faustpower3_f(float value) {
	return value * value * value;
}

class mydsp : public base_dsp {
	
 public:
	
	int iVec0[2];
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fEntry0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	int iRec7[2];
	int iVec1[2];
	int iRec6[2];
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fEntry2;
	FAUSTFLOAT fEntry3;
	FAUSTFLOAT fEntry4;
	FAUSTFLOAT fEntry5;
	FAUSTFLOAT fEntry6;
	FAUSTFLOAT fEntry7;
	FAUSTFLOAT fEntry8;
	FAUSTFLOAT fEntry9;
	FAUSTFLOAT fEntry10;
	FAUSTFLOAT fEntry11;
	FAUSTFLOAT fEntry12;
	FAUSTFLOAT fEntry13;
	FAUSTFLOAT fEntry14;
	FAUSTFLOAT fEntry15;
	FAUSTFLOAT fEntry16;
	FAUSTFLOAT fEntry17;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fEntry18;
	FAUSTFLOAT fEntry19;
	FAUSTFLOAT fEntry20;
	FAUSTFLOAT fEntry21;
	FAUSTFLOAT fEntry22;
	FAUSTFLOAT fEntry23;
	FAUSTFLOAT fEntry24;
	FAUSTFLOAT fEntry25;
	FAUSTFLOAT fEntry26;
	FAUSTFLOAT fEntry27;
	FAUSTFLOAT fEntry28;
	FAUSTFLOAT fEntry29;
	FAUSTFLOAT fEntry30;
	FAUSTFLOAT fEntry31;
	FAUSTFLOAT fEntry32;
	FAUSTFLOAT fEntry33;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fEntry34;
	FAUSTFLOAT fEntry35;
	FAUSTFLOAT fEntry36;
	FAUSTFLOAT fEntry37;
	FAUSTFLOAT fEntry38;
	FAUSTFLOAT fEntry39;
	FAUSTFLOAT fEntry40;
	FAUSTFLOAT fEntry41;
	FAUSTFLOAT fEntry42;
	FAUSTFLOAT fEntry43;
	FAUSTFLOAT fEntry44;
	FAUSTFLOAT fEntry45;
	FAUSTFLOAT fEntry46;
	FAUSTFLOAT fEntry47;
	FAUSTFLOAT fEntry48;
	FAUSTFLOAT fEntry49;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fEntry50;
	FAUSTFLOAT fEntry51;
	FAUSTFLOAT fEntry52;
	FAUSTFLOAT fEntry53;
	FAUSTFLOAT fEntry54;
	FAUSTFLOAT fEntry55;
	FAUSTFLOAT fEntry56;
	FAUSTFLOAT fEntry57;
	FAUSTFLOAT fEntry58;
	FAUSTFLOAT fEntry59;
	FAUSTFLOAT fEntry60;
	FAUSTFLOAT fEntry61;
	FAUSTFLOAT fEntry62;
	FAUSTFLOAT fEntry63;
	FAUSTFLOAT fEntry64;
	FAUSTFLOAT fEntry65;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fEntry66;
	FAUSTFLOAT fEntry67;
	FAUSTFLOAT fEntry68;
	FAUSTFLOAT fEntry69;
	FAUSTFLOAT fEntry70;
	FAUSTFLOAT fEntry71;
	FAUSTFLOAT fEntry72;
	FAUSTFLOAT fEntry73;
	FAUSTFLOAT fEntry74;
	FAUSTFLOAT fEntry75;
	FAUSTFLOAT fEntry76;
	FAUSTFLOAT fEntry77;
	FAUSTFLOAT fEntry78;
	FAUSTFLOAT fEntry79;
	FAUSTFLOAT fEntry80;
	FAUSTFLOAT fEntry81;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fEntry82;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fEntry83;
	int iRec9[2];
	int iVec2[2];
	int iRec8[2];
	FAUSTFLOAT fEntry84;
	FAUSTFLOAT fEntry85;
	FAUSTFLOAT fEntry86;
	FAUSTFLOAT fEntry87;
	FAUSTFLOAT fEntry88;
	FAUSTFLOAT fEntry89;
	FAUSTFLOAT fEntry90;
	FAUSTFLOAT fEntry91;
	FAUSTFLOAT fEntry92;
	FAUSTFLOAT fEntry93;
	FAUSTFLOAT fEntry94;
	FAUSTFLOAT fEntry95;
	FAUSTFLOAT fEntry96;
	FAUSTFLOAT fEntry97;
	FAUSTFLOAT fEntry98;
	FAUSTFLOAT fEntry99;
	FAUSTFLOAT fEntry100;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fEntry101;
	int iRec11[2];
	int iVec3[2];
	int iRec10[2];
	FAUSTFLOAT fEntry102;
	FAUSTFLOAT fEntry103;
	FAUSTFLOAT fEntry104;
	FAUSTFLOAT fEntry105;
	FAUSTFLOAT fEntry106;
	FAUSTFLOAT fEntry107;
	FAUSTFLOAT fEntry108;
	FAUSTFLOAT fEntry109;
	FAUSTFLOAT fEntry110;
	FAUSTFLOAT fEntry111;
	FAUSTFLOAT fEntry112;
	FAUSTFLOAT fEntry113;
	FAUSTFLOAT fEntry114;
	FAUSTFLOAT fEntry115;
	FAUSTFLOAT fEntry116;
	FAUSTFLOAT fEntry117;
	FAUSTFLOAT fEntry118;
	FAUSTFLOAT fHslider9;
	float fConst2;
	float fRec13[2];
	float fVec4[2];
	int IOTA0;
	float fVec5[4096];
	float fConst3;
	FAUSTFLOAT fEntry119;
	int iRec15[2];
	int iRec16[2];
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fCheckbox5;
	FAUSTFLOAT fCheckbox6;
	FAUSTFLOAT fCheckbox7;
	FAUSTFLOAT fCheckbox8;
	FAUSTFLOAT fCheckbox9;
	FAUSTFLOAT fCheckbox10;
	FAUSTFLOAT fCheckbox11;
	FAUSTFLOAT fCheckbox12;
	FAUSTFLOAT fCheckbox13;
	FAUSTFLOAT fCheckbox14;
	FAUSTFLOAT fCheckbox15;
	FAUSTFLOAT fVslider1;
	float fRec14[2];
	FAUSTFLOAT fVslider2;
	float fRec17[2];
	float fVec6[2];
	float fVec7[4096];
	FAUSTFLOAT fEntry120;
	int iRec19[2];
	int iRec20[2];
	FAUSTFLOAT fCheckbox16;
	FAUSTFLOAT fCheckbox17;
	FAUSTFLOAT fCheckbox18;
	FAUSTFLOAT fCheckbox19;
	FAUSTFLOAT fCheckbox20;
	FAUSTFLOAT fCheckbox21;
	FAUSTFLOAT fCheckbox22;
	FAUSTFLOAT fCheckbox23;
	FAUSTFLOAT fCheckbox24;
	FAUSTFLOAT fCheckbox25;
	FAUSTFLOAT fCheckbox26;
	FAUSTFLOAT fCheckbox27;
	FAUSTFLOAT fCheckbox28;
	FAUSTFLOAT fCheckbox29;
	FAUSTFLOAT fCheckbox30;
	FAUSTFLOAT fCheckbox31;
	FAUSTFLOAT fVslider3;
	float fRec18[2];
	FAUSTFLOAT fVslider4;
	float fRec21[2];
	float fVec8[2];
	float fVec9[4096];
	FAUSTFLOAT fEntry121;
	int iRec23[2];
	int iRec24[2];
	FAUSTFLOAT fCheckbox32;
	FAUSTFLOAT fCheckbox33;
	FAUSTFLOAT fCheckbox34;
	FAUSTFLOAT fCheckbox35;
	FAUSTFLOAT fCheckbox36;
	FAUSTFLOAT fCheckbox37;
	FAUSTFLOAT fCheckbox38;
	FAUSTFLOAT fCheckbox39;
	FAUSTFLOAT fCheckbox40;
	FAUSTFLOAT fCheckbox41;
	FAUSTFLOAT fCheckbox42;
	FAUSTFLOAT fCheckbox43;
	FAUSTFLOAT fCheckbox44;
	FAUSTFLOAT fCheckbox45;
	FAUSTFLOAT fCheckbox46;
	FAUSTFLOAT fCheckbox47;
	FAUSTFLOAT fVslider5;
	float fRec22[2];
	FAUSTFLOAT fVslider6;
	float fConst4;
	FAUSTFLOAT fVslider7;
	float fConst5;
	FAUSTFLOAT fVslider8;
	float fRec3[2];
	float fRec4[2];
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT fVslider10;
	FAUSTFLOAT fVslider11;
	float fRec0[2];
	float fRec1[2];
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	FAUSTFLOAT fCheckbox48;
	FAUSTFLOAT fVslider14;
	float fRec25[2];
	FAUSTFLOAT fVslider15;
	float fVec10[131072];
	float fRec26[2];
	float fRec27[2];
	float fRec28[2];
	float fRec29[2];
	float fRec30[2];
	float fRec31[2];
	float fRec32[2];
	float fRec33[2];
	float fRec34[2];
	float fRec35[2];
	float fRec36[2];
	float fRec37[2];
	float fRec38[2];
	float fRec39[2];
	float fRec40[2];
	FAUSTFLOAT fVslider16;
	FAUSTFLOAT fVslider17;
	FAUSTFLOAT fVslider18;
	FAUSTFLOAT fVslider19;
	FAUSTFLOAT fVslider20;
	float fVec11[3];
	FAUSTFLOAT fVslider21;
	float fVec12[3];
	FAUSTFLOAT fVslider22;
	float fVec13[3];
	FAUSTFLOAT fVslider23;
	FAUSTFLOAT fVslider24;
	FAUSTFLOAT fVslider25;
	float fConst6;
	float fRec50[2];
	FAUSTFLOAT fVslider26;
	float fConst7;
	float fVec14[8192];
	int iConst8;
	float fRec49[2];
	float fRec52[2];
	float fVec15[8192];
	int iConst9;
	float fRec51[2];
	float fRec54[2];
	float fVec16[8192];
	int iConst10;
	float fRec53[2];
	float fRec56[2];
	float fVec17[8192];
	int iConst11;
	float fRec55[2];
	float fRec58[2];
	float fVec18[8192];
	int iConst12;
	float fRec57[2];
	float fRec60[2];
	float fVec19[8192];
	int iConst13;
	float fRec59[2];
	float fRec62[2];
	float fVec20[8192];
	int iConst14;
	float fRec61[2];
	float fRec64[2];
	float fVec21[8192];
	int iConst15;
	float fRec63[2];
	float fVec22[2048];
	int iConst16;
	int iConst17;
	float fRec47[2];
	float fVec23[2048];
	int iConst18;
	int iConst19;
	float fRec45[2];
	float fVec24[2048];
	int iConst20;
	int iConst21;
	float fRec43[2];
	float fVec25[1024];
	int iConst22;
	int iConst23;
	float fRec41[2];
	float fRec74[2];
	float fVec26[8192];
	FAUSTFLOAT fVslider27;
	float fConst24;
	float fRec73[2];
	float fRec76[2];
	float fVec27[8192];
	float fRec75[2];
	float fRec78[2];
	float fVec28[8192];
	float fRec77[2];
	float fRec80[2];
	float fVec29[8192];
	float fRec79[2];
	float fRec82[2];
	float fVec30[8192];
	float fRec81[2];
	float fRec84[2];
	float fVec31[8192];
	float fRec83[2];
	float fRec86[2];
	float fVec32[8192];
	float fRec85[2];
	float fRec88[2];
	float fVec33[8192];
	float fRec87[2];
	float fVec34[2048];
	float fRec71[2];
	float fVec35[2048];
	float fRec69[2];
	float fVec36[2048];
	float fRec67[2];
	float fVec37[2048];
	float fRec65[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("aanl.lib/ADAA1:author", "Dario Sanfilippo");
		m->declare("aanl.lib/ADAA1:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/ADAA1:license", "LGPL v3.0 license");
		m->declare("aanl.lib/ADAA2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/ADAA2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/ADAA2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/acosh2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/acosh2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/acosh2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/arccos2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/arccos2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/arccos2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/arcsin2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/arcsin2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/arcsin2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/arctan2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/arctan2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/arctan2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/asinh2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/asinh2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/asinh2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/cosine2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/cosine2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/cosine2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/cubic1:author", "Dario Sanfilippo");
		m->declare("aanl.lib/cubic1:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/cubic1:license", "LGPL v3.0 license");
		m->declare("aanl.lib/hardclip2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/hardclip2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/hardclip2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/hyperbolic2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/hyperbolic2:copyright", "Copyright (C) 2021 Dario Sanfilippo      <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/hyperbolic2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/name", "Faust Antialiased Nonlinearities");
		m->declare("aanl.lib/parabolic2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/parabolic2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/parabolic2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/sinarctan2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/sinarctan2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/sinarctan2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/sine2:author", "Dario Sanfilippo");
		m->declare("aanl.lib/sine2:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/sine2:license", "LGPL v3.0 license");
		m->declare("aanl.lib/tanh1:author", "Dario Sanfilippo");
		m->declare("aanl.lib/tanh1:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/tanh1:license", "LGPL v3.0 license");
		m->declare("aanl.lib/version", "0.3");
		m->declare("author", "amy universe");
		m->declare("basics.lib/counter:author", "Stephane Letz");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/pulse_countup_loop:author", "Vince");
		m->declare("basics.lib/resetCtr:author", "Mike Olsen");
		m->declare("basics.lib/tabulate:author", "Stephane Letz");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("demos.lib/freeverb_demo:author", " Romain Michon");
		m->declare("demos.lib/freeverb_demo:licence", "LGPL");
		m->declare("demos.lib/name", "Faust Demos Library");
		m->declare("demos.lib/version", "0.1");
		m->declare("envelopes.lib/are:author", "Julius O. Smith III, revised by Stephane Letz");
		m->declare("envelopes.lib/are:licence", "STK-4.3");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.2");
		m->declare("filename", "amaranthgirl.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/svf:author", "Oleg Nesterov");
		m->declare("filters.lib/svf:copyright", "Copyright (C) 2020 Oleg Nesterov <oleg@redhat.com>");
		m->declare("filters.lib/svf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("interpolators.lib/interpolate_cubic:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_cubic:licence", "MIT");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/version", "0.3");
		m->declare("license", "WTFPL");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "amaranthgirl");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.3");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("quantizers.lib/name", "Faust Frequency Quantization Library");
		m->declare("quantizers.lib/version", "0.1");
		m->declare("reverbs.lib/mono_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/stereo_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
		m->declare("version", "10.04");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(1024, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 15.0f * fConst0;
		fConst2 = 1.0f / fConst0;
		fConst3 = 0.5f * fConst0;
		fConst4 = 0.25f * fConst0;
		fConst5 = 3.1415927f / fConst0;
		fConst6 = 1.764e+04f / fConst0;
		fConst7 = 12348.0f / fConst0;
		iConst8 = int(0.036666665f * fConst0);
		iConst9 = int(0.035306122f * fConst0);
		iConst10 = int(0.033809524f * fConst0);
		iConst11 = int(0.0322449f * fConst0);
		iConst12 = int(0.030748298f * fConst0);
		iConst13 = int(0.028956916f * fConst0);
		iConst14 = int(0.026938776f * fConst0);
		iConst15 = int(0.025306122f * fConst0);
		iConst16 = int(0.0126077095f * fConst0);
		iConst17 = std::min<int>(1024, std::max<int>(0, iConst16 + -1));
		iConst18 = int(0.01f * fConst0);
		iConst19 = std::min<int>(1024, std::max<int>(0, iConst18 + -1));
		iConst20 = int(0.0077324263f * fConst0);
		iConst21 = std::min<int>(1024, std::max<int>(0, iConst20 + -1));
		iConst22 = int(0.0051020407f * fConst0);
		iConst23 = std::min<int>(1024, std::max<int>(0, iConst22 + -1));
		fConst24 = 0.0010430838f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(0.5f);
		fHslider0 = FAUSTFLOAT(0.0f);
		fEntry0 = FAUSTFLOAT(1.2e+02f);
		fEntry1 = FAUSTFLOAT(16.0f);
		fEntry2 = FAUSTFLOAT(0.0f);
		fEntry3 = FAUSTFLOAT(0.0f);
		fEntry4 = FAUSTFLOAT(0.0f);
		fEntry5 = FAUSTFLOAT(0.0f);
		fEntry6 = FAUSTFLOAT(0.0f);
		fEntry7 = FAUSTFLOAT(0.0f);
		fEntry8 = FAUSTFLOAT(0.0f);
		fEntry9 = FAUSTFLOAT(0.0f);
		fEntry10 = FAUSTFLOAT(0.0f);
		fEntry11 = FAUSTFLOAT(0.0f);
		fEntry12 = FAUSTFLOAT(0.0f);
		fEntry13 = FAUSTFLOAT(0.0f);
		fEntry14 = FAUSTFLOAT(0.0f);
		fEntry15 = FAUSTFLOAT(0.0f);
		fEntry16 = FAUSTFLOAT(0.0f);
		fEntry17 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fEntry18 = FAUSTFLOAT(0.0f);
		fEntry19 = FAUSTFLOAT(0.0f);
		fEntry20 = FAUSTFLOAT(0.0f);
		fEntry21 = FAUSTFLOAT(0.0f);
		fEntry22 = FAUSTFLOAT(0.0f);
		fEntry23 = FAUSTFLOAT(0.0f);
		fEntry24 = FAUSTFLOAT(0.0f);
		fEntry25 = FAUSTFLOAT(0.0f);
		fEntry26 = FAUSTFLOAT(0.0f);
		fEntry27 = FAUSTFLOAT(0.0f);
		fEntry28 = FAUSTFLOAT(0.0f);
		fEntry29 = FAUSTFLOAT(0.0f);
		fEntry30 = FAUSTFLOAT(0.0f);
		fEntry31 = FAUSTFLOAT(0.0f);
		fEntry32 = FAUSTFLOAT(0.0f);
		fEntry33 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fEntry34 = FAUSTFLOAT(0.0f);
		fEntry35 = FAUSTFLOAT(0.0f);
		fEntry36 = FAUSTFLOAT(0.0f);
		fEntry37 = FAUSTFLOAT(0.0f);
		fEntry38 = FAUSTFLOAT(0.0f);
		fEntry39 = FAUSTFLOAT(0.0f);
		fEntry40 = FAUSTFLOAT(0.0f);
		fEntry41 = FAUSTFLOAT(0.0f);
		fEntry42 = FAUSTFLOAT(0.0f);
		fEntry43 = FAUSTFLOAT(0.0f);
		fEntry44 = FAUSTFLOAT(0.0f);
		fEntry45 = FAUSTFLOAT(0.0f);
		fEntry46 = FAUSTFLOAT(0.0f);
		fEntry47 = FAUSTFLOAT(0.0f);
		fEntry48 = FAUSTFLOAT(0.0f);
		fEntry49 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fEntry50 = FAUSTFLOAT(0.0f);
		fEntry51 = FAUSTFLOAT(0.0f);
		fEntry52 = FAUSTFLOAT(0.0f);
		fEntry53 = FAUSTFLOAT(0.0f);
		fEntry54 = FAUSTFLOAT(0.0f);
		fEntry55 = FAUSTFLOAT(0.0f);
		fEntry56 = FAUSTFLOAT(0.0f);
		fEntry57 = FAUSTFLOAT(0.0f);
		fEntry58 = FAUSTFLOAT(0.0f);
		fEntry59 = FAUSTFLOAT(0.0f);
		fEntry60 = FAUSTFLOAT(0.0f);
		fEntry61 = FAUSTFLOAT(0.0f);
		fEntry62 = FAUSTFLOAT(0.0f);
		fEntry63 = FAUSTFLOAT(0.0f);
		fEntry64 = FAUSTFLOAT(0.0f);
		fEntry65 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fEntry66 = FAUSTFLOAT(0.0f);
		fEntry67 = FAUSTFLOAT(0.0f);
		fEntry68 = FAUSTFLOAT(0.0f);
		fEntry69 = FAUSTFLOAT(0.0f);
		fEntry70 = FAUSTFLOAT(0.0f);
		fEntry71 = FAUSTFLOAT(0.0f);
		fEntry72 = FAUSTFLOAT(0.0f);
		fEntry73 = FAUSTFLOAT(0.0f);
		fEntry74 = FAUSTFLOAT(0.0f);
		fEntry75 = FAUSTFLOAT(0.0f);
		fEntry76 = FAUSTFLOAT(0.0f);
		fEntry77 = FAUSTFLOAT(0.0f);
		fEntry78 = FAUSTFLOAT(0.0f);
		fEntry79 = FAUSTFLOAT(0.0f);
		fEntry80 = FAUSTFLOAT(0.0f);
		fEntry81 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(36.0f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fEntry82 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fEntry83 = FAUSTFLOAT(1.2e+02f);
		fEntry84 = FAUSTFLOAT(16.0f);
		fEntry85 = FAUSTFLOAT(0.0f);
		fEntry86 = FAUSTFLOAT(0.0f);
		fEntry87 = FAUSTFLOAT(0.0f);
		fEntry88 = FAUSTFLOAT(0.0f);
		fEntry89 = FAUSTFLOAT(0.0f);
		fEntry90 = FAUSTFLOAT(0.0f);
		fEntry91 = FAUSTFLOAT(0.0f);
		fEntry92 = FAUSTFLOAT(0.0f);
		fEntry93 = FAUSTFLOAT(0.0f);
		fEntry94 = FAUSTFLOAT(0.0f);
		fEntry95 = FAUSTFLOAT(0.0f);
		fEntry96 = FAUSTFLOAT(0.0f);
		fEntry97 = FAUSTFLOAT(0.0f);
		fEntry98 = FAUSTFLOAT(0.0f);
		fEntry99 = FAUSTFLOAT(0.0f);
		fEntry100 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(1.0f);
		fEntry101 = FAUSTFLOAT(1.2e+02f);
		fEntry102 = FAUSTFLOAT(16.0f);
		fEntry103 = FAUSTFLOAT(0.0f);
		fEntry104 = FAUSTFLOAT(0.0f);
		fEntry105 = FAUSTFLOAT(0.0f);
		fEntry106 = FAUSTFLOAT(0.0f);
		fEntry107 = FAUSTFLOAT(0.0f);
		fEntry108 = FAUSTFLOAT(0.0f);
		fEntry109 = FAUSTFLOAT(0.0f);
		fEntry110 = FAUSTFLOAT(0.0f);
		fEntry111 = FAUSTFLOAT(0.0f);
		fEntry112 = FAUSTFLOAT(0.0f);
		fEntry113 = FAUSTFLOAT(0.0f);
		fEntry114 = FAUSTFLOAT(0.0f);
		fEntry115 = FAUSTFLOAT(0.0f);
		fEntry116 = FAUSTFLOAT(0.0f);
		fEntry117 = FAUSTFLOAT(0.0f);
		fEntry118 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(1.0f);
		fEntry119 = FAUSTFLOAT(1.2e+02f);
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fCheckbox6 = FAUSTFLOAT(0.0f);
		fCheckbox7 = FAUSTFLOAT(0.0f);
		fCheckbox8 = FAUSTFLOAT(0.0f);
		fCheckbox9 = FAUSTFLOAT(0.0f);
		fCheckbox10 = FAUSTFLOAT(0.0f);
		fCheckbox11 = FAUSTFLOAT(0.0f);
		fCheckbox12 = FAUSTFLOAT(0.0f);
		fCheckbox13 = FAUSTFLOAT(0.0f);
		fCheckbox14 = FAUSTFLOAT(0.0f);
		fCheckbox15 = FAUSTFLOAT(0.0f);
		fVslider1 = FAUSTFLOAT(0.1f);
		fVslider2 = FAUSTFLOAT(0.1f);
		fEntry120 = FAUSTFLOAT(1.2e+02f);
		fCheckbox16 = FAUSTFLOAT(0.0f);
		fCheckbox17 = FAUSTFLOAT(0.0f);
		fCheckbox18 = FAUSTFLOAT(0.0f);
		fCheckbox19 = FAUSTFLOAT(0.0f);
		fCheckbox20 = FAUSTFLOAT(0.0f);
		fCheckbox21 = FAUSTFLOAT(0.0f);
		fCheckbox22 = FAUSTFLOAT(0.0f);
		fCheckbox23 = FAUSTFLOAT(0.0f);
		fCheckbox24 = FAUSTFLOAT(0.0f);
		fCheckbox25 = FAUSTFLOAT(0.0f);
		fCheckbox26 = FAUSTFLOAT(0.0f);
		fCheckbox27 = FAUSTFLOAT(0.0f);
		fCheckbox28 = FAUSTFLOAT(0.0f);
		fCheckbox29 = FAUSTFLOAT(0.0f);
		fCheckbox30 = FAUSTFLOAT(0.0f);
		fCheckbox31 = FAUSTFLOAT(0.0f);
		fVslider3 = FAUSTFLOAT(0.1f);
		fVslider4 = FAUSTFLOAT(0.1f);
		fEntry121 = FAUSTFLOAT(1.2e+02f);
		fCheckbox32 = FAUSTFLOAT(0.0f);
		fCheckbox33 = FAUSTFLOAT(0.0f);
		fCheckbox34 = FAUSTFLOAT(0.0f);
		fCheckbox35 = FAUSTFLOAT(0.0f);
		fCheckbox36 = FAUSTFLOAT(0.0f);
		fCheckbox37 = FAUSTFLOAT(0.0f);
		fCheckbox38 = FAUSTFLOAT(0.0f);
		fCheckbox39 = FAUSTFLOAT(0.0f);
		fCheckbox40 = FAUSTFLOAT(0.0f);
		fCheckbox41 = FAUSTFLOAT(0.0f);
		fCheckbox42 = FAUSTFLOAT(0.0f);
		fCheckbox43 = FAUSTFLOAT(0.0f);
		fCheckbox44 = FAUSTFLOAT(0.0f);
		fCheckbox45 = FAUSTFLOAT(0.0f);
		fCheckbox46 = FAUSTFLOAT(0.0f);
		fCheckbox47 = FAUSTFLOAT(0.0f);
		fVslider5 = FAUSTFLOAT(0.1f);
		fVslider6 = FAUSTFLOAT(0.1f);
		fVslider7 = FAUSTFLOAT(2e+04f);
		fVslider8 = FAUSTFLOAT(1.0f);
		fVslider9 = FAUSTFLOAT(0.5f);
		fVslider10 = FAUSTFLOAT(2e+04f);
		fVslider11 = FAUSTFLOAT(1.0f);
		fVslider12 = FAUSTFLOAT(0.0f);
		fVslider13 = FAUSTFLOAT(1.0f);
		fCheckbox48 = FAUSTFLOAT(0.0f);
		fVslider14 = FAUSTFLOAT(0.1f);
		fVslider15 = FAUSTFLOAT(0.1f);
		fVslider16 = FAUSTFLOAT(0.0f);
		fVslider17 = FAUSTFLOAT(0.0f);
		fVslider18 = FAUSTFLOAT(0.0f);
		fVslider19 = FAUSTFLOAT(0.0f);
		fVslider20 = FAUSTFLOAT(1.0f);
		fVslider21 = FAUSTFLOAT(1.0f);
		fVslider22 = FAUSTFLOAT(1.0f);
		fVslider23 = FAUSTFLOAT(0.5f);
		fVslider24 = FAUSTFLOAT(0.3333f);
		fVslider25 = FAUSTFLOAT(0.5f);
		fVslider26 = FAUSTFLOAT(0.5f);
		fVslider27 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec7[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec6[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iRec9[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iRec8[l6] = 0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec11[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iVec3[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iRec10[l9] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec13[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fVec4[l12] = 0.0f;
		}
		IOTA0 = 0;
		for (int l13 = 0; l13 < 4096; l13 = l13 + 1) {
			fVec5[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			iRec15[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iRec16[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec17[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fVec6[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 4096; l19 = l19 + 1) {
			fVec7[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iRec19[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			iRec20[l21] = 0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec18[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec21[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fVec8[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 4096; l25 = l25 + 1) {
			fVec9[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			iRec23[l26] = 0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			iRec24[l27] = 0;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec22[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec3[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec4[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec0[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec1[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec25[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 131072; l34 = l34 + 1) {
			fVec10[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec26[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec27[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec28[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec29[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec30[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec31[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec32[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec33[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec34[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec35[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec36[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec37[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec38[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec39[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec40[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 3; l50 = l50 + 1) {
			fVec11[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 3; l51 = l51 + 1) {
			fVec12[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 3; l52 = l52 + 1) {
			fVec13[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec50[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 8192; l54 = l54 + 1) {
			fVec14[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fRec49[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec52[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 8192; l57 = l57 + 1) {
			fVec15[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec51[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec54[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 8192; l60 = l60 + 1) {
			fVec16[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec53[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec56[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 8192; l63 = l63 + 1) {
			fVec17[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			fRec55[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			fRec58[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 8192; l66 = l66 + 1) {
			fVec18[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec57[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fRec60[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 8192; l69 = l69 + 1) {
			fVec19[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fRec59[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec62[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 8192; l72 = l72 + 1) {
			fVec20[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			fRec61[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			fRec64[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 8192; l75 = l75 + 1) {
			fVec21[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			fRec63[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2048; l77 = l77 + 1) {
			fVec22[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec47[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2048; l79 = l79 + 1) {
			fVec23[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			fRec45[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2048; l81 = l81 + 1) {
			fVec24[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			fRec43[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 1024; l83 = l83 + 1) {
			fVec25[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			fRec41[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			fRec74[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 8192; l86 = l86 + 1) {
			fVec26[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fRec73[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec76[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 8192; l89 = l89 + 1) {
			fVec27[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			fRec75[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fRec78[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 8192; l92 = l92 + 1) {
			fVec28[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 2; l93 = l93 + 1) {
			fRec77[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			fRec80[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 8192; l95 = l95 + 1) {
			fVec29[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			fRec79[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec82[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 8192; l98 = l98 + 1) {
			fVec30[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			fRec81[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			fRec84[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 8192; l101 = l101 + 1) {
			fVec31[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fRec83[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			fRec86[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 8192; l104 = l104 + 1) {
			fVec32[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			fRec85[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			fRec88[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 8192; l107 = l107 + 1) {
			fVec33[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			fRec87[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2048; l109 = l109 + 1) {
			fVec34[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 2; l110 = l110 + 1) {
			fRec71[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2048; l111 = l111 + 1) {
			fVec35[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 2; l112 = l112 + 1) {
			fRec69[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 2048; l113 = l113 + 1) {
			fVec36[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 2; l114 = l114 + 1) {
			fRec67[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 2048; l115 = l115 + 1) {
			fVec37[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			fRec65[l116] = 0.0f;
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
		ui_interface->openVerticalBox("amaranthgirl");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("seq");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("env trig a");
		ui_interface->declare(&fCheckbox47, "0", "");
		ui_interface->addCheckButton("a  0", &fCheckbox47);
		ui_interface->declare(&fCheckbox46, "1", "");
		ui_interface->addCheckButton("a  1", &fCheckbox46);
		ui_interface->declare(&fCheckbox45, "2", "");
		ui_interface->addCheckButton("a  2", &fCheckbox45);
		ui_interface->declare(&fCheckbox44, "3", "");
		ui_interface->addCheckButton("a  3", &fCheckbox44);
		ui_interface->declare(&fCheckbox43, "4", "");
		ui_interface->addCheckButton("a  4", &fCheckbox43);
		ui_interface->declare(&fCheckbox42, "5", "");
		ui_interface->addCheckButton("a  5", &fCheckbox42);
		ui_interface->declare(&fCheckbox41, "6", "");
		ui_interface->addCheckButton("a  6", &fCheckbox41);
		ui_interface->declare(&fCheckbox40, "7", "");
		ui_interface->addCheckButton("a  7", &fCheckbox40);
		ui_interface->declare(&fCheckbox39, "8", "");
		ui_interface->addCheckButton("a  8", &fCheckbox39);
		ui_interface->declare(&fCheckbox38, "9", "");
		ui_interface->addCheckButton("a  9", &fCheckbox38);
		ui_interface->declare(&fCheckbox37, "10", "");
		ui_interface->addCheckButton("a 10", &fCheckbox37);
		ui_interface->declare(&fCheckbox36, "11", "");
		ui_interface->addCheckButton("a 11", &fCheckbox36);
		ui_interface->declare(&fCheckbox35, "12", "");
		ui_interface->addCheckButton("a 12", &fCheckbox35);
		ui_interface->declare(&fCheckbox34, "13", "");
		ui_interface->addCheckButton("a 13", &fCheckbox34);
		ui_interface->declare(&fCheckbox33, "14", "");
		ui_interface->addCheckButton("a 14", &fCheckbox33);
		ui_interface->declare(&fCheckbox32, "15", "");
		ui_interface->addCheckButton("a 15", &fCheckbox32);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("env trig b");
		ui_interface->declare(&fCheckbox31, "0", "");
		ui_interface->addCheckButton("b  0", &fCheckbox31);
		ui_interface->declare(&fCheckbox30, "1", "");
		ui_interface->addCheckButton("b  1", &fCheckbox30);
		ui_interface->declare(&fCheckbox29, "2", "");
		ui_interface->addCheckButton("b  2", &fCheckbox29);
		ui_interface->declare(&fCheckbox28, "3", "");
		ui_interface->addCheckButton("b  3", &fCheckbox28);
		ui_interface->declare(&fCheckbox27, "4", "");
		ui_interface->addCheckButton("b  4", &fCheckbox27);
		ui_interface->declare(&fCheckbox26, "5", "");
		ui_interface->addCheckButton("b  5", &fCheckbox26);
		ui_interface->declare(&fCheckbox25, "6", "");
		ui_interface->addCheckButton("b  6", &fCheckbox25);
		ui_interface->declare(&fCheckbox24, "7", "");
		ui_interface->addCheckButton("b  7", &fCheckbox24);
		ui_interface->declare(&fCheckbox23, "8", "");
		ui_interface->addCheckButton("b  8", &fCheckbox23);
		ui_interface->declare(&fCheckbox22, "9", "");
		ui_interface->addCheckButton("b  9", &fCheckbox22);
		ui_interface->declare(&fCheckbox21, "10", "");
		ui_interface->addCheckButton("b 10", &fCheckbox21);
		ui_interface->declare(&fCheckbox20, "11", "");
		ui_interface->addCheckButton("b 11", &fCheckbox20);
		ui_interface->declare(&fCheckbox19, "12", "");
		ui_interface->addCheckButton("b 12", &fCheckbox19);
		ui_interface->declare(&fCheckbox18, "13", "");
		ui_interface->addCheckButton("b 13", &fCheckbox18);
		ui_interface->declare(&fCheckbox17, "14", "");
		ui_interface->addCheckButton("b 14", &fCheckbox17);
		ui_interface->declare(&fCheckbox16, "15", "");
		ui_interface->addCheckButton("b 15", &fCheckbox16);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("env trig c");
		ui_interface->declare(&fCheckbox15, "0", "");
		ui_interface->addCheckButton("c  0", &fCheckbox15);
		ui_interface->declare(&fCheckbox14, "1", "");
		ui_interface->addCheckButton("c  1", &fCheckbox14);
		ui_interface->declare(&fCheckbox13, "2", "");
		ui_interface->addCheckButton("c  2", &fCheckbox13);
		ui_interface->declare(&fCheckbox12, "3", "");
		ui_interface->addCheckButton("c  3", &fCheckbox12);
		ui_interface->declare(&fCheckbox11, "4", "");
		ui_interface->addCheckButton("c  4", &fCheckbox11);
		ui_interface->declare(&fCheckbox10, "5", "");
		ui_interface->addCheckButton("c  5", &fCheckbox10);
		ui_interface->declare(&fCheckbox9, "6", "");
		ui_interface->addCheckButton("c  6", &fCheckbox9);
		ui_interface->declare(&fCheckbox8, "7", "");
		ui_interface->addCheckButton("c  7", &fCheckbox8);
		ui_interface->declare(&fCheckbox7, "8", "");
		ui_interface->addCheckButton("c  8", &fCheckbox7);
		ui_interface->declare(&fCheckbox6, "9", "");
		ui_interface->addCheckButton("c  9", &fCheckbox6);
		ui_interface->declare(&fCheckbox5, "10", "");
		ui_interface->addCheckButton("c 10", &fCheckbox5);
		ui_interface->declare(&fCheckbox4, "11", "");
		ui_interface->addCheckButton("c 11", &fCheckbox4);
		ui_interface->declare(&fCheckbox3, "12", "");
		ui_interface->addCheckButton("c 12", &fCheckbox3);
		ui_interface->declare(&fCheckbox2, "13", "");
		ui_interface->addCheckButton("c 13", &fCheckbox2);
		ui_interface->declare(&fCheckbox1, "14", "");
		ui_interface->addCheckButton("c 14", &fCheckbox1);
		ui_interface->declare(&fCheckbox0, "15", "");
		ui_interface->addCheckButton("c 15", &fCheckbox0);
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openVerticalBox("t val");
		ui_interface->declare(&fEntry66, "0", "");
		ui_interface->addNumEntry("t  0", &fEntry66, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry67, "1", "");
		ui_interface->addNumEntry("t  1", &fEntry67, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry68, "2", "");
		ui_interface->addNumEntry("t  2", &fEntry68, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry69, "3", "");
		ui_interface->addNumEntry("t  3", &fEntry69, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry70, "4", "");
		ui_interface->addNumEntry("t  4", &fEntry70, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry71, "5", "");
		ui_interface->addNumEntry("t  5", &fEntry71, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry72, "6", "");
		ui_interface->addNumEntry("t  6", &fEntry72, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry73, "7", "");
		ui_interface->addNumEntry("t  7", &fEntry73, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry74, "8", "");
		ui_interface->addNumEntry("t  8", &fEntry74, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry75, "9", "");
		ui_interface->addNumEntry("t  9", &fEntry75, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry76, "10", "");
		ui_interface->addNumEntry("t 10", &fEntry76, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry77, "11", "");
		ui_interface->addNumEntry("t 11", &fEntry77, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry78, "12", "");
		ui_interface->addNumEntry("t 12", &fEntry78, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry79, "13", "");
		ui_interface->addNumEntry("t 13", &fEntry79, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry80, "14", "");
		ui_interface->addNumEntry("t 14", &fEntry80, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry81, "15", "");
		ui_interface->addNumEntry("t 15", &fEntry81, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "6", "");
		ui_interface->openVerticalBox("x mod");
		ui_interface->declare(&fEntry50, "0", "");
		ui_interface->addNumEntry("x  0", &fEntry50, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry51, "1", "");
		ui_interface->addNumEntry("x  1", &fEntry51, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry52, "2", "");
		ui_interface->addNumEntry("x  2", &fEntry52, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry53, "3", "");
		ui_interface->addNumEntry("x  3", &fEntry53, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry54, "4", "");
		ui_interface->addNumEntry("x  4", &fEntry54, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry55, "5", "");
		ui_interface->addNumEntry("x  5", &fEntry55, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry56, "6", "");
		ui_interface->addNumEntry("x  6", &fEntry56, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry57, "7", "");
		ui_interface->addNumEntry("x  7", &fEntry57, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry58, "8", "");
		ui_interface->addNumEntry("x  8", &fEntry58, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry59, "9", "");
		ui_interface->addNumEntry("x  9", &fEntry59, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry60, "10", "");
		ui_interface->addNumEntry("x 10", &fEntry60, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry61, "11", "");
		ui_interface->addNumEntry("x 11", &fEntry61, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry62, "12", "");
		ui_interface->addNumEntry("x 12", &fEntry62, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry63, "13", "");
		ui_interface->addNumEntry("x 13", &fEntry63, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry64, "14", "");
		ui_interface->addNumEntry("x 14", &fEntry64, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry65, "15", "");
		ui_interface->addNumEntry("x 15", &fEntry65, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "7", "");
		ui_interface->openVerticalBox("y mod");
		ui_interface->declare(&fEntry34, "0", "");
		ui_interface->addNumEntry("y  0", &fEntry34, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry35, "1", "");
		ui_interface->addNumEntry("y  1", &fEntry35, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry36, "2", "");
		ui_interface->addNumEntry("y  2", &fEntry36, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry37, "3", "");
		ui_interface->addNumEntry("y  3", &fEntry37, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry38, "4", "");
		ui_interface->addNumEntry("y  4", &fEntry38, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry39, "5", "");
		ui_interface->addNumEntry("y  5", &fEntry39, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry40, "6", "");
		ui_interface->addNumEntry("y  6", &fEntry40, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry41, "7", "");
		ui_interface->addNumEntry("y  7", &fEntry41, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry42, "8", "");
		ui_interface->addNumEntry("y  8", &fEntry42, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry43, "9", "");
		ui_interface->addNumEntry("y  9", &fEntry43, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry44, "10", "");
		ui_interface->addNumEntry("y 10", &fEntry44, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry45, "11", "");
		ui_interface->addNumEntry("y 11", &fEntry45, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry46, "12", "");
		ui_interface->addNumEntry("y 12", &fEntry46, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry47, "13", "");
		ui_interface->addNumEntry("y 13", &fEntry47, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry48, "14", "");
		ui_interface->addNumEntry("y 14", &fEntry48, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry49, "15", "");
		ui_interface->addNumEntry("y 15", &fEntry49, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "8", "");
		ui_interface->openVerticalBox("z mod");
		ui_interface->declare(&fEntry18, "0", "");
		ui_interface->addNumEntry("z  0", &fEntry18, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry19, "1", "");
		ui_interface->addNumEntry("z  1", &fEntry19, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry20, "2", "");
		ui_interface->addNumEntry("z  2", &fEntry20, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry21, "3", "");
		ui_interface->addNumEntry("z  3", &fEntry21, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry22, "4", "");
		ui_interface->addNumEntry("z  4", &fEntry22, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry23, "5", "");
		ui_interface->addNumEntry("z  5", &fEntry23, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry24, "6", "");
		ui_interface->addNumEntry("z  6", &fEntry24, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry25, "7", "");
		ui_interface->addNumEntry("z  7", &fEntry25, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry26, "8", "");
		ui_interface->addNumEntry("z  8", &fEntry26, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry27, "9", "");
		ui_interface->addNumEntry("z  9", &fEntry27, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry28, "10", "");
		ui_interface->addNumEntry("z 10", &fEntry28, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry29, "11", "");
		ui_interface->addNumEntry("z 11", &fEntry29, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry30, "12", "");
		ui_interface->addNumEntry("z 12", &fEntry30, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry31, "13", "");
		ui_interface->addNumEntry("z 13", &fEntry31, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry32, "14", "");
		ui_interface->addNumEntry("z 14", &fEntry32, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry33, "15", "");
		ui_interface->addNumEntry("z 15", &fEntry33, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "9", "");
		ui_interface->openVerticalBox("a trans");
		ui_interface->declare(&fEntry2, "0", "");
		ui_interface->addNumEntry("a  0", &fEntry2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry3, "1", "");
		ui_interface->addNumEntry("a  1", &fEntry3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry4, "2", "");
		ui_interface->addNumEntry("a  2", &fEntry4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry5, "3", "");
		ui_interface->addNumEntry("a  3", &fEntry5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry6, "4", "");
		ui_interface->addNumEntry("a  4", &fEntry6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry7, "5", "");
		ui_interface->addNumEntry("a  5", &fEntry7, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry8, "6", "");
		ui_interface->addNumEntry("a  6", &fEntry8, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry9, "7", "");
		ui_interface->addNumEntry("a  7", &fEntry9, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry10, "8", "");
		ui_interface->addNumEntry("a  8", &fEntry10, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry11, "9", "");
		ui_interface->addNumEntry("a  9", &fEntry11, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry12, "10", "");
		ui_interface->addNumEntry("a 10", &fEntry12, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry13, "11", "");
		ui_interface->addNumEntry("a 11", &fEntry13, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry14, "12", "");
		ui_interface->addNumEntry("a 12", &fEntry14, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry15, "13", "");
		ui_interface->addNumEntry("a 13", &fEntry15, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry16, "14", "");
		ui_interface->addNumEntry("a 14", &fEntry16, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry17, "15", "");
		ui_interface->addNumEntry("a 15", &fEntry17, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "a", "");
		ui_interface->openVerticalBox("b trans");
		ui_interface->declare(&fEntry85, "0", "");
		ui_interface->addNumEntry("b  0", &fEntry85, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry86, "1", "");
		ui_interface->addNumEntry("b  1", &fEntry86, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry87, "2", "");
		ui_interface->addNumEntry("b  2", &fEntry87, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry88, "3", "");
		ui_interface->addNumEntry("b  3", &fEntry88, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry89, "4", "");
		ui_interface->addNumEntry("b  4", &fEntry89, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry90, "5", "");
		ui_interface->addNumEntry("b  5", &fEntry90, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry91, "6", "");
		ui_interface->addNumEntry("b  6", &fEntry91, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry92, "7", "");
		ui_interface->addNumEntry("b  7", &fEntry92, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry93, "8", "");
		ui_interface->addNumEntry("b  8", &fEntry93, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry94, "9", "");
		ui_interface->addNumEntry("b  9", &fEntry94, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry95, "10", "");
		ui_interface->addNumEntry("b 10", &fEntry95, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry96, "11", "");
		ui_interface->addNumEntry("b 11", &fEntry96, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry97, "12", "");
		ui_interface->addNumEntry("b 12", &fEntry97, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry98, "13", "");
		ui_interface->addNumEntry("b 13", &fEntry98, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry99, "14", "");
		ui_interface->addNumEntry("b 14", &fEntry99, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry100, "15", "");
		ui_interface->addNumEntry("b 15", &fEntry100, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "b", "");
		ui_interface->openVerticalBox("c trans");
		ui_interface->declare(&fEntry103, "0", "");
		ui_interface->addNumEntry("c  0", &fEntry103, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry104, "1", "");
		ui_interface->addNumEntry("c  1", &fEntry104, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry105, "2", "");
		ui_interface->addNumEntry("c  2", &fEntry105, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry106, "3", "");
		ui_interface->addNumEntry("c  3", &fEntry106, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry107, "4", "");
		ui_interface->addNumEntry("c  4", &fEntry107, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry108, "5", "");
		ui_interface->addNumEntry("c  5", &fEntry108, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry109, "6", "");
		ui_interface->addNumEntry("c  6", &fEntry109, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry110, "7", "");
		ui_interface->addNumEntry("c  7", &fEntry110, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry111, "8", "");
		ui_interface->addNumEntry("c  8", &fEntry111, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry112, "9", "");
		ui_interface->addNumEntry("c  9", &fEntry112, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry113, "10", "");
		ui_interface->addNumEntry("c 10", &fEntry113, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry114, "11", "");
		ui_interface->addNumEntry("c 11", &fEntry114, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry115, "12", "");
		ui_interface->addNumEntry("c 12", &fEntry115, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry116, "13", "");
		ui_interface->addNumEntry("c 13", &fEntry116, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry117, "14", "");
		ui_interface->addNumEntry("c 14", &fEntry117, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fEntry118, "15", "");
		ui_interface->addNumEntry("c 15", &fEntry118, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("controls");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("key");
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "style", "menu{'none':0;'major':1;'minor':2}");
		ui_interface->addHorizontalSlider("quantization", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fEntry82, "2", "");
		ui_interface->addNumEntry("root note", &fEntry82, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(11.5f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("length");
		ui_interface->declare(&fEntry1, "0", "");
		ui_interface->addNumEntry("active steps a", &fEntry1, FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fEntry84, "1", "");
		ui_interface->addNumEntry("active steps b", &fEntry84, FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fEntry102, "2", "");
		ui_interface->addNumEntry("active steps c", &fEntry102, FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("seq speed");
		ui_interface->declare(&fEntry0, "0", "");
		ui_interface->addNumEntry("bpm a", &fEntry0, FAUSTFLOAT(1.2e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6e+05f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fEntry83, "1", "");
		ui_interface->addNumEntry("bpm b", &fEntry83, FAUSTFLOAT(1.2e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6e+05f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fEntry101, "2", "");
		ui_interface->addNumEntry("bpm c", &fEntry101, FAUSTFLOAT(1.2e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6e+05f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("env clock");
		ui_interface->addNumEntry("bpm a", &fEntry121, FAUSTFLOAT(1.2e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6e+05f), FAUSTFLOAT(0.001f));
		ui_interface->addNumEntry("bpm b", &fEntry120, FAUSTFLOAT(1.2e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6e+05f), FAUSTFLOAT(0.001f));
		ui_interface->addNumEntry("bpm c", &fEntry119, FAUSTFLOAT(1.2e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6e+05f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openVerticalBox("mult");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->addHorizontalSlider("x", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->addHorizontalSlider("y", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->addHorizontalSlider("z", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openVerticalBox("trans mult");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->addHorizontalSlider("a", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider8, "0", "");
		ui_interface->addHorizontalSlider("b", &fHslider8, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider9, "0", "");
		ui_interface->addHorizontalSlider("c", &fHslider9, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "d", "");
		ui_interface->openVerticalBox("range");
		ui_interface->declare(&fHslider6, "0", "");
		ui_interface->addHorizontalSlider("min (psych!)", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(128.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "1", "");
		ui_interface->addHorizontalSlider("max", &fHslider5, FAUSTFLOAT(36.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(128.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider7, "2", "");
		ui_interface->addHorizontalSlider("octave", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(-8.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openTabBox("sound");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("out");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("gain");
		ui_interface->declare(&fVslider6, "0", "");
		ui_interface->addVerticalSlider("a", &fVslider6, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider4, "0", "");
		ui_interface->addVerticalSlider("b", &fVslider4, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider2, "0", "");
		ui_interface->addVerticalSlider("c", &fVslider2, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("env release");
		ui_interface->declare(&fVslider5, "0", "");
		ui_interface->addVerticalSlider("a", &fVslider5, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(1e-05f));
		ui_interface->declare(&fVslider3, "1", "");
		ui_interface->addVerticalSlider("b", &fVslider3, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(1e-05f));
		ui_interface->declare(&fVslider1, "2", "");
		ui_interface->addVerticalSlider("c", &fVslider1, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(1e-05f));
		ui_interface->closeBox();
		ui_interface->declare(&fVslider7, "2", "");
		ui_interface->addVerticalSlider("filter 1 cf", &fVslider7, FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.1e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider8, "3", "");
		ui_interface->addVerticalSlider("filter 1 q", &fVslider8, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider0, "4", "");
		ui_interface->addVerticalSlider("clip", &fVslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider9, "5", "");
		ui_interface->addVerticalSlider("post gain", &fVslider9, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider10, "6", "");
		ui_interface->addVerticalSlider("filter 2 cf", &fVslider10, FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.1e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider11, "7", "");
		ui_interface->addVerticalSlider("filter 2 q", &fVslider11, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("effects");
		ui_interface->openHorizontalBox("Freeverb");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(&fVslider25, "0", "");
		ui_interface->declare(&fVslider25, "style", "knob");
		ui_interface->declare(&fVslider25, "tooltip", "Somehow control the         density of the reverb.");
		ui_interface->addVerticalSlider("Damp", &fVslider25, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.025f));
		ui_interface->declare(&fVslider26, "1", "");
		ui_interface->declare(&fVslider26, "style", "knob");
		ui_interface->declare(&fVslider26, "tooltip", "The room size         between 0 and 1 with 1 for the largest room.");
		ui_interface->addVerticalSlider("RoomSize", &fVslider26, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.025f));
		ui_interface->declare(&fVslider27, "2", "");
		ui_interface->declare(&fVslider27, "style", "knob");
		ui_interface->declare(&fVslider27, "tooltip", "Spatial         spread between 0 and 1 with 1 for maximum spread.");
		ui_interface->addVerticalSlider("Stereo Spread", &fVslider27, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(&fVslider24, "1", "");
		ui_interface->declare(&fVslider24, "tooltip", "The amount of reverb applied to the signal         between 0 and 1 with 1 for the maximum amount of reverb.");
		ui_interface->addVerticalSlider("Wet", &fVslider24, FAUSTFLOAT(0.3333f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.025f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("dandeliongirl");
		ui_interface->declare(&fCheckbox48, "-1", "");
		ui_interface->addCheckButton("space windows", &fCheckbox48);
		ui_interface->declare(&fVslider14, "0", "");
		ui_interface->addVerticalSlider("window length (s)", &fVslider14, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.001f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider15, "1", "");
		ui_interface->addVerticalSlider("crossfade dur (s)", &fVslider15, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.001f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fVslider13, "2", "");
		ui_interface->addVerticalSlider("shift (semitones)", &fVslider13, FAUSTFLOAT(1.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.001f));
		ui_interface->addVerticalSlider("wet", &fVslider12, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("nailgirl");
		ui_interface->openHorizontalBox("0");
		ui_interface->addVerticalSlider("0 amount", &fVslider20, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.01f));
		ui_interface->addVerticalSlider("0 function", &fVslider19, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(13.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("1");
		ui_interface->addVerticalSlider("1 amount", &fVslider21, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.01f));
		ui_interface->addVerticalSlider("1 function", &fVslider18, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(13.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("2");
		ui_interface->addVerticalSlider("2 amount", &fVslider22, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.01f));
		ui_interface->addVerticalSlider("2 function", &fVslider17, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(13.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->addVerticalSlider("post gain", &fVslider23, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addVerticalSlider("wet", &fVslider16, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fVslider0);
		float fSlow1 = -1.0f * fSlow0;
		float fSlow2 = 3.0f * float(fHslider0);
		float fSlow3 = fSlow2 + 2.0f;
		int iSlow4 = fSlow3 >= 5.0f;
		int iSlow5 = fSlow3 >= 3.0f;
		int iSlow6 = fSlow3 >= 2.0f;
		int iSlow7 = fSlow3 >= 1.0f;
		int iSlow8 = int(fConst1 / float(fEntry0));
		float fSlow9 = float(fEntry1);
		float fSlow10 = float(fEntry2);
		float fSlow11 = float(fEntry3);
		float fSlow12 = float(fEntry4);
		float fSlow13 = float(fEntry5);
		float fSlow14 = float(fEntry6);
		float fSlow15 = float(fEntry7);
		float fSlow16 = float(fEntry8);
		float fSlow17 = float(fEntry9);
		float fSlow18 = float(fEntry10);
		float fSlow19 = float(fEntry11);
		float fSlow20 = float(fEntry12);
		float fSlow21 = float(fEntry13);
		float fSlow22 = float(fEntry14);
		float fSlow23 = float(fEntry15);
		float fSlow24 = float(fEntry16);
		float fSlow25 = float(fEntry17);
		float fSlow26 = float(fHslider1);
		float fSlow27 = float(fEntry18);
		float fSlow28 = float(fEntry19);
		float fSlow29 = float(fEntry20);
		float fSlow30 = float(fEntry21);
		float fSlow31 = float(fEntry22);
		float fSlow32 = float(fEntry23);
		float fSlow33 = float(fEntry24);
		float fSlow34 = float(fEntry25);
		float fSlow35 = float(fEntry26);
		float fSlow36 = float(fEntry27);
		float fSlow37 = float(fEntry28);
		float fSlow38 = float(fEntry29);
		float fSlow39 = float(fEntry30);
		float fSlow40 = float(fEntry31);
		float fSlow41 = float(fEntry32);
		float fSlow42 = float(fEntry33);
		float fSlow43 = float(fHslider2);
		float fSlow44 = float(fEntry34);
		float fSlow45 = float(fEntry35);
		float fSlow46 = float(fEntry36);
		float fSlow47 = float(fEntry37);
		float fSlow48 = float(fEntry38);
		float fSlow49 = float(fEntry39);
		float fSlow50 = float(fEntry40);
		float fSlow51 = float(fEntry41);
		float fSlow52 = float(fEntry42);
		float fSlow53 = float(fEntry43);
		float fSlow54 = float(fEntry44);
		float fSlow55 = float(fEntry45);
		float fSlow56 = float(fEntry46);
		float fSlow57 = float(fEntry47);
		float fSlow58 = float(fEntry48);
		float fSlow59 = float(fEntry49);
		float fSlow60 = float(fHslider3);
		float fSlow61 = float(fEntry50);
		float fSlow62 = float(fEntry51);
		float fSlow63 = float(fEntry52);
		float fSlow64 = float(fEntry53);
		float fSlow65 = float(fEntry54);
		float fSlow66 = float(fEntry55);
		float fSlow67 = float(fEntry56);
		float fSlow68 = float(fEntry57);
		float fSlow69 = float(fEntry58);
		float fSlow70 = float(fEntry59);
		float fSlow71 = float(fEntry60);
		float fSlow72 = float(fEntry61);
		float fSlow73 = float(fEntry62);
		float fSlow74 = float(fEntry63);
		float fSlow75 = float(fEntry64);
		float fSlow76 = float(fEntry65);
		float fSlow77 = float(fHslider4);
		float fSlow78 = float(fEntry66);
		float fSlow79 = float(fEntry67);
		float fSlow80 = float(fEntry68);
		float fSlow81 = float(fEntry69);
		float fSlow82 = float(fEntry70);
		float fSlow83 = float(fEntry71);
		float fSlow84 = float(fEntry72);
		float fSlow85 = float(fEntry73);
		float fSlow86 = float(fEntry74);
		float fSlow87 = float(fEntry75);
		float fSlow88 = float(fEntry76);
		float fSlow89 = float(fEntry77);
		float fSlow90 = float(fEntry78);
		float fSlow91 = float(fEntry79);
		float fSlow92 = float(fEntry80);
		float fSlow93 = float(fEntry81);
		float fSlow94 = float(fHslider5);
		float fSlow95 = float(fHslider6);
		float fSlow96 = std::pow(2.0f, 0.083333336f * float(fEntry82));
		float fSlow97 = std::pow(2.0f, float(fHslider7));
		float fSlow98 = 261.62558f * fSlow97 * fSlow96;
		int iSlow99 = int(fConst1 / float(fEntry83));
		float fSlow100 = float(fEntry84);
		float fSlow101 = float(fEntry85);
		float fSlow102 = float(fEntry86);
		float fSlow103 = float(fEntry87);
		float fSlow104 = float(fEntry88);
		float fSlow105 = float(fEntry89);
		float fSlow106 = float(fEntry90);
		float fSlow107 = float(fEntry91);
		float fSlow108 = float(fEntry92);
		float fSlow109 = float(fEntry93);
		float fSlow110 = float(fEntry94);
		float fSlow111 = float(fEntry95);
		float fSlow112 = float(fEntry96);
		float fSlow113 = float(fEntry97);
		float fSlow114 = float(fEntry98);
		float fSlow115 = float(fEntry99);
		float fSlow116 = float(fEntry100);
		float fSlow117 = float(fHslider8);
		int iSlow118 = int(fConst1 / float(fEntry101));
		float fSlow119 = float(fEntry102);
		float fSlow120 = float(fEntry103);
		float fSlow121 = float(fEntry104);
		float fSlow122 = float(fEntry105);
		float fSlow123 = float(fEntry106);
		float fSlow124 = float(fEntry107);
		float fSlow125 = float(fEntry108);
		float fSlow126 = float(fEntry109);
		float fSlow127 = float(fEntry110);
		float fSlow128 = float(fEntry111);
		float fSlow129 = float(fEntry112);
		float fSlow130 = float(fEntry113);
		float fSlow131 = float(fEntry114);
		float fSlow132 = float(fEntry115);
		float fSlow133 = float(fEntry116);
		float fSlow134 = float(fEntry117);
		float fSlow135 = float(fEntry118);
		float fSlow136 = float(fHslider9);
		int iSlow137 = fSlow3 >= 4.0f;
		float fSlow138 = 261.62558f * fSlow96;
		float fSlow139 = std::log(fSlow138);
		int iSlow140 = fSlow3 >= 7.0f;
		int iSlow141 = fSlow3 >= 6.0f;
		int iSlow142 = fSlow3 >= 8.0f;
		int iSlow143 = int(fConst1 / float(fEntry119));
		float fSlow144 = float(fCheckbox0);
		float fSlow145 = float(fCheckbox1);
		float fSlow146 = float(fCheckbox2);
		float fSlow147 = float(fCheckbox3);
		float fSlow148 = float(fCheckbox4);
		float fSlow149 = float(fCheckbox5);
		float fSlow150 = float(fCheckbox6);
		float fSlow151 = float(fCheckbox7);
		float fSlow152 = float(fCheckbox8);
		float fSlow153 = float(fCheckbox9);
		float fSlow154 = float(fCheckbox10);
		float fSlow155 = float(fCheckbox11);
		float fSlow156 = float(fCheckbox12);
		float fSlow157 = float(fCheckbox13);
		float fSlow158 = float(fCheckbox14);
		float fSlow159 = float(fCheckbox15);
		float fSlow160 = float(fVslider1);
		float fSlow161 = float(fVslider2);
		float fSlow162 = fSlow2 + 1.0f;
		int iSlow163 = fSlow162 >= 5.0f;
		int iSlow164 = fSlow162 >= 3.0f;
		int iSlow165 = fSlow162 >= 2.0f;
		int iSlow166 = fSlow162 >= 1.0f;
		int iSlow167 = fSlow162 >= 4.0f;
		int iSlow168 = fSlow162 >= 7.0f;
		int iSlow169 = fSlow162 >= 6.0f;
		int iSlow170 = fSlow162 >= 8.0f;
		int iSlow171 = int(fConst1 / float(fEntry120));
		float fSlow172 = float(fCheckbox16);
		float fSlow173 = float(fCheckbox17);
		float fSlow174 = float(fCheckbox18);
		float fSlow175 = float(fCheckbox19);
		float fSlow176 = float(fCheckbox20);
		float fSlow177 = float(fCheckbox21);
		float fSlow178 = float(fCheckbox22);
		float fSlow179 = float(fCheckbox23);
		float fSlow180 = float(fCheckbox24);
		float fSlow181 = float(fCheckbox25);
		float fSlow182 = float(fCheckbox26);
		float fSlow183 = float(fCheckbox27);
		float fSlow184 = float(fCheckbox28);
		float fSlow185 = float(fCheckbox29);
		float fSlow186 = float(fCheckbox30);
		float fSlow187 = float(fCheckbox31);
		float fSlow188 = float(fVslider3);
		float fSlow189 = float(fVslider4);
		int iSlow190 = fSlow2 >= 5.0f;
		int iSlow191 = fSlow2 >= 3.0f;
		int iSlow192 = fSlow2 >= 2.0f;
		int iSlow193 = fSlow2 >= 1.0f;
		int iSlow194 = fSlow2 >= 4.0f;
		int iSlow195 = fSlow2 >= 7.0f;
		int iSlow196 = fSlow2 >= 6.0f;
		int iSlow197 = fSlow2 >= 8.0f;
		int iSlow198 = int(fConst1 / float(fEntry121));
		float fSlow199 = float(fCheckbox32);
		float fSlow200 = float(fCheckbox33);
		float fSlow201 = float(fCheckbox34);
		float fSlow202 = float(fCheckbox35);
		float fSlow203 = float(fCheckbox36);
		float fSlow204 = float(fCheckbox37);
		float fSlow205 = float(fCheckbox38);
		float fSlow206 = float(fCheckbox39);
		float fSlow207 = float(fCheckbox40);
		float fSlow208 = float(fCheckbox41);
		float fSlow209 = float(fCheckbox42);
		float fSlow210 = float(fCheckbox43);
		float fSlow211 = float(fCheckbox44);
		float fSlow212 = float(fCheckbox45);
		float fSlow213 = float(fCheckbox46);
		float fSlow214 = float(fCheckbox47);
		float fSlow215 = float(fVslider5);
		float fSlow216 = float(fVslider6);
		float fSlow217 = std::tan(fConst5 * float(fVslider7));
		float fSlow218 = fSlow217 * (1.0f / float(fVslider8) + fSlow217) + 1.0f;
		float fSlow219 = 2.0f / fSlow218;
		float fSlow220 = fSlow217 / fSlow218;
		float fSlow221 = float(fVslider9);
		float fSlow222 = std::tan(fConst5 * float(fVslider10));
		float fSlow223 = fSlow222 * (1.0f / float(fVslider11) + fSlow222) + 1.0f;
		float fSlow224 = 2.0f / fSlow223;
		float fSlow225 = fSlow222 / fSlow223;
		float fSlow226 = float(fVslider12);
		float fSlow227 = 1.0f - fSlow226;
		float fSlow228 = float(fVslider13);
		float fSlow229 = std::pow(2.0f, 1.25f * fSlow228);
		float fSlow230 = float(fCheckbox48);
		float fSlow231 = float(fVslider14);
		float fSlow232 = fConst0 * fSlow231 * (15.0f * fSlow230 + 1.0f);
		float fSlow233 = fConst2 / float(fVslider15);
		float fSlow234 = std::pow(2.0f, 1.1666666f * fSlow228);
		float fSlow235 = fConst0 * fSlow231 * (14.0f * fSlow230 + 1.0f);
		float fSlow236 = std::pow(2.0f, 1.0833334f * fSlow228);
		float fSlow237 = fConst0 * fSlow231 * (13.0f * fSlow230 + 1.0f);
		float fSlow238 = std::pow(2.0f, fSlow228);
		float fSlow239 = fConst0 * fSlow231 * (12.0f * fSlow230 + 1.0f);
		float fSlow240 = std::pow(2.0f, 0.9166667f * fSlow228);
		float fSlow241 = fConst0 * fSlow231 * (11.0f * fSlow230 + 1.0f);
		float fSlow242 = std::pow(2.0f, 0.8333333f * fSlow228);
		float fSlow243 = fConst0 * fSlow231 * (1e+01f * fSlow230 + 1.0f);
		float fSlow244 = std::pow(2.0f, 0.75f * fSlow228);
		float fSlow245 = fConst0 * fSlow231 * (9.0f * fSlow230 + 1.0f);
		float fSlow246 = std::pow(2.0f, 0.6666667f * fSlow228);
		float fSlow247 = fConst0 * fSlow231 * (8.0f * fSlow230 + 1.0f);
		float fSlow248 = std::pow(2.0f, 0.5833333f * fSlow228);
		float fSlow249 = fConst0 * fSlow231 * (7.0f * fSlow230 + 1.0f);
		float fSlow250 = std::pow(2.0f, 0.5f * fSlow228);
		float fSlow251 = fConst0 * fSlow231 * (6.0f * fSlow230 + 1.0f);
		float fSlow252 = std::pow(2.0f, 0.41666666f * fSlow228);
		float fSlow253 = fConst0 * fSlow231 * (5.0f * fSlow230 + 1.0f);
		float fSlow254 = std::pow(2.0f, 0.33333334f * fSlow228);
		float fSlow255 = fConst0 * fSlow231 * (4.0f * fSlow230 + 1.0f);
		float fSlow256 = std::pow(2.0f, 0.25f * fSlow228);
		float fSlow257 = fConst0 * fSlow231 * (3.0f * fSlow230 + 1.0f);
		float fSlow258 = std::pow(2.0f, 0.16666667f * fSlow228);
		float fSlow259 = fConst0 * fSlow231 * (2.0f * fSlow230 + 1.0f);
		float fSlow260 = std::pow(2.0f, 0.083333336f * fSlow228);
		float fSlow261 = fConst0 * fSlow231 * (fSlow230 + 1.0f);
		float fSlow262 = fConst0 * fSlow231;
		float fSlow263 = float(fVslider16);
		float fSlow264 = 1.0f - fSlow263;
		float fSlow265 = float(fVslider17);
		int iSlow266 = fSlow265 >= 7.0f;
		int iSlow267 = fSlow265 >= 4.0f;
		int iSlow268 = fSlow265 >= 2.0f;
		int iSlow269 = fSlow265 >= 1.0f;
		float fSlow270 = float(fVslider18);
		int iSlow271 = fSlow270 >= 7.0f;
		int iSlow272 = fSlow270 >= 4.0f;
		int iSlow273 = fSlow270 >= 2.0f;
		int iSlow274 = fSlow270 >= 1.0f;
		float fSlow275 = float(fVslider19);
		int iSlow276 = fSlow275 >= 7.0f;
		int iSlow277 = fSlow275 >= 4.0f;
		int iSlow278 = fSlow275 >= 2.0f;
		int iSlow279 = fSlow275 >= 1.0f;
		float fSlow280 = fSlow263 * float(fVslider20);
		int iSlow281 = fSlow275 >= 3.0f;
		int iSlow282 = fSlow275 >= 6.0f;
		int iSlow283 = fSlow275 >= 5.0f;
		int iSlow284 = fSlow275 >= 11.0f;
		int iSlow285 = fSlow275 >= 9.0f;
		int iSlow286 = fSlow275 >= 8.0f;
		float fSlow287 = 0.6666667f * fSlow280;
		float fSlow288 = 2.0f * fSlow280;
		int iSlow289 = fSlow275 >= 1e+01f;
		float fSlow290 = 3.0f * fSlow280;
		int iSlow291 = fSlow275 >= 13.0f;
		int iSlow292 = fSlow275 >= 12.0f;
		float fSlow293 = float(fVslider21);
		int iSlow294 = fSlow270 >= 3.0f;
		int iSlow295 = fSlow270 >= 6.0f;
		int iSlow296 = fSlow270 >= 5.0f;
		int iSlow297 = fSlow270 >= 11.0f;
		int iSlow298 = fSlow270 >= 9.0f;
		int iSlow299 = fSlow270 >= 8.0f;
		float fSlow300 = 0.6666667f * fSlow293;
		float fSlow301 = 2.0f * fSlow293;
		int iSlow302 = fSlow270 >= 1e+01f;
		float fSlow303 = 3.0f * fSlow293;
		int iSlow304 = fSlow270 >= 13.0f;
		int iSlow305 = fSlow270 >= 12.0f;
		float fSlow306 = float(fVslider22);
		int iSlow307 = fSlow265 >= 3.0f;
		int iSlow308 = fSlow265 >= 6.0f;
		int iSlow309 = fSlow265 >= 5.0f;
		int iSlow310 = fSlow265 >= 11.0f;
		int iSlow311 = fSlow265 >= 9.0f;
		int iSlow312 = fSlow265 >= 8.0f;
		float fSlow313 = 0.6666667f * fSlow306;
		float fSlow314 = 2.0f * fSlow306;
		int iSlow315 = fSlow265 >= 1e+01f;
		float fSlow316 = 3.0f * fSlow306;
		int iSlow317 = fSlow265 >= 13.0f;
		int iSlow318 = fSlow265 >= 12.0f;
		float fSlow319 = float(fVslider23);
		float fSlow320 = float(fVslider24);
		float fSlow321 = 1.0f - fSlow320;
		float fSlow322 = fConst6 * float(fVslider25);
		float fSlow323 = 1.0f - fSlow322;
		float fSlow324 = fConst7 * float(fVslider26) + 0.7f;
		float fSlow325 = 0.2f * fSlow320;
		int iSlow326 = int(fConst24 * float(fVslider27));
		int iSlow327 = iConst8 + iSlow326;
		int iSlow328 = iConst9 + iSlow326;
		int iSlow329 = iConst10 + iSlow326;
		int iSlow330 = iConst11 + iSlow326;
		int iSlow331 = iConst12 + iSlow326;
		int iSlow332 = iConst13 + iSlow326;
		int iSlow333 = iConst14 + iSlow326;
		int iSlow334 = iConst15 + iSlow326;
		int iSlow335 = iSlow326 + -1;
		int iSlow336 = std::min<int>(1024, std::max<int>(0, iConst16 + iSlow335));
		int iSlow337 = std::min<int>(1024, std::max<int>(0, iConst18 + iSlow335));
		int iSlow338 = std::min<int>(1024, std::max<int>(0, iConst20 + iSlow335));
		int iSlow339 = std::min<int>(1024, std::max<int>(0, iConst22 + iSlow335));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			iRec7[0] = (iVec0[1] + iRec7[1]) % iSlow8;
			int iTemp0 = iRec7[0] <= iRec7[1];
			iVec1[0] = iTemp0;
			iRec6[0] = iRec6[1] + (iTemp0 > iVec1[1]);
			float fTemp1 = std::fmod(float(iRec6[0]), fSlow9);
			int iTemp2 = fTemp1 >= 8.0f;
			int iTemp3 = fTemp1 >= 4.0f;
			int iTemp4 = fTemp1 >= 2.0f;
			int iTemp5 = fTemp1 >= 1.0f;
			int iTemp6 = fTemp1 >= 3.0f;
			float fThen2 = ((iTemp5) ? fSlow11 : fSlow10);
			float fElse2 = ((iTemp6) ? fSlow13 : fSlow12);
			int iTemp7 = fTemp1 >= 6.0f;
			int iTemp8 = fTemp1 >= 5.0f;
			int iTemp9 = fTemp1 >= 7.0f;
			float fThen5 = ((iTemp8) ? fSlow15 : fSlow14);
			float fElse5 = ((iTemp9) ? fSlow17 : fSlow16);
			float fThen6 = ((iTemp4) ? fElse2 : fThen2);
			float fElse6 = ((iTemp7) ? fElse5 : fThen5);
			int iTemp10 = fTemp1 >= 12.0f;
			int iTemp11 = fTemp1 >= 1e+01f;
			int iTemp12 = fTemp1 >= 9.0f;
			int iTemp13 = fTemp1 >= 11.0f;
			float fThen9 = ((iTemp12) ? fSlow19 : fSlow18);
			float fElse9 = ((iTemp13) ? fSlow21 : fSlow20);
			int iTemp14 = fTemp1 >= 14.0f;
			int iTemp15 = fTemp1 >= 13.0f;
			int iTemp16 = fTemp1 >= 15.0f;
			float fThen12 = ((iTemp15) ? fSlow23 : fSlow22);
			float fElse12 = ((iTemp16) ? fSlow25 : fSlow24);
			float fThen13 = ((iTemp11) ? fElse9 : fThen9);
			float fElse13 = ((iTemp14) ? fElse12 : fThen12);
			float fThen14 = ((iTemp3) ? fElse6 : fThen6);
			float fElse14 = ((iTemp10) ? fElse13 : fThen13);
			float fThen17 = ((iTemp5) ? fSlow28 : fSlow27);
			float fElse17 = ((iTemp6) ? fSlow30 : fSlow29);
			float fThen20 = ((iTemp8) ? fSlow32 : fSlow31);
			float fElse20 = ((iTemp9) ? fSlow34 : fSlow33);
			float fThen21 = ((iTemp4) ? fElse17 : fThen17);
			float fElse21 = ((iTemp7) ? fElse20 : fThen20);
			float fThen24 = ((iTemp12) ? fSlow36 : fSlow35);
			float fElse24 = ((iTemp13) ? fSlow38 : fSlow37);
			float fThen27 = ((iTemp15) ? fSlow40 : fSlow39);
			float fElse27 = ((iTemp16) ? fSlow42 : fSlow41);
			float fThen28 = ((iTemp11) ? fElse24 : fThen24);
			float fElse28 = ((iTemp14) ? fElse27 : fThen27);
			float fThen29 = ((iTemp3) ? fElse21 : fThen21);
			float fElse29 = ((iTemp10) ? fElse28 : fThen28);
			float fThen32 = ((iTemp5) ? fSlow45 : fSlow44);
			float fElse32 = ((iTemp6) ? fSlow47 : fSlow46);
			float fThen35 = ((iTemp8) ? fSlow49 : fSlow48);
			float fElse35 = ((iTemp9) ? fSlow51 : fSlow50);
			float fThen36 = ((iTemp4) ? fElse32 : fThen32);
			float fElse36 = ((iTemp7) ? fElse35 : fThen35);
			float fThen39 = ((iTemp12) ? fSlow53 : fSlow52);
			float fElse39 = ((iTemp13) ? fSlow55 : fSlow54);
			float fThen42 = ((iTemp15) ? fSlow57 : fSlow56);
			float fElse42 = ((iTemp16) ? fSlow59 : fSlow58);
			float fThen43 = ((iTemp11) ? fElse39 : fThen39);
			float fElse43 = ((iTemp14) ? fElse42 : fThen42);
			float fThen44 = ((iTemp3) ? fElse36 : fThen36);
			float fElse44 = ((iTemp10) ? fElse43 : fThen43);
			float fThen47 = ((iTemp5) ? fSlow62 : fSlow61);
			float fElse47 = ((iTemp6) ? fSlow64 : fSlow63);
			float fThen50 = ((iTemp8) ? fSlow66 : fSlow65);
			float fElse50 = ((iTemp9) ? fSlow68 : fSlow67);
			float fThen51 = ((iTemp4) ? fElse47 : fThen47);
			float fElse51 = ((iTemp7) ? fElse50 : fThen50);
			float fThen54 = ((iTemp12) ? fSlow70 : fSlow69);
			float fElse54 = ((iTemp13) ? fSlow72 : fSlow71);
			float fThen57 = ((iTemp15) ? fSlow74 : fSlow73);
			float fElse57 = ((iTemp16) ? fSlow76 : fSlow75);
			float fThen58 = ((iTemp11) ? fElse54 : fThen54);
			float fElse58 = ((iTemp14) ? fElse57 : fThen57);
			float fThen59 = ((iTemp3) ? fElse51 : fThen51);
			float fElse59 = ((iTemp10) ? fElse58 : fThen58);
			float fThen62 = ((iTemp5) ? fSlow79 : fSlow78);
			float fElse62 = ((iTemp6) ? fSlow81 : fSlow80);
			float fThen65 = ((iTemp8) ? fSlow83 : fSlow82);
			float fElse65 = ((iTemp9) ? fSlow85 : fSlow84);
			float fThen66 = ((iTemp4) ? fElse62 : fThen62);
			float fElse66 = ((iTemp7) ? fElse65 : fThen65);
			float fThen69 = ((iTemp12) ? fSlow87 : fSlow86);
			float fElse69 = ((iTemp13) ? fSlow89 : fSlow88);
			float fThen72 = ((iTemp15) ? fSlow91 : fSlow90);
			float fElse72 = ((iTemp16) ? fSlow93 : fSlow92);
			float fThen73 = ((iTemp11) ? fElse69 : fThen69);
			float fElse73 = ((iTemp14) ? fElse72 : fThen72);
			float fThen74 = ((iTemp3) ? fElse66 : fThen66);
			float fElse74 = ((iTemp10) ? fElse73 : fThen73);
			float fTemp17 = std::pow(2.0f, 0.083333336f * (fSlow95 + std::fmod(((iTemp2) ? fElse74 : fThen74) + fSlow77 * ((iTemp2) ? fElse59 : fThen59) + fSlow60 * ((iTemp2) ? fElse44 : fThen44) + fSlow43 * ((iTemp2) ? fElse29 : fThen29) + fSlow26 * ((iTemp2) ? fElse14 : fThen14), fSlow94)));
			float fTemp18 = fSlow98 * fTemp17;
			iRec9[0] = (iVec0[1] + iRec9[1]) % iSlow99;
			int iTemp19 = iRec9[0] <= iRec9[1];
			iVec2[0] = iTemp19;
			iRec8[0] = iRec8[1] + (iTemp19 > iVec2[1]);
			float fTemp20 = std::fmod(float(iRec8[0]), fSlow100);
			int iTemp21 = fTemp20 >= 8.0f;
			int iTemp22 = fTemp20 >= 4.0f;
			int iTemp23 = fTemp20 >= 2.0f;
			int iTemp24 = fTemp20 >= 1.0f;
			int iTemp25 = fTemp20 >= 3.0f;
			float fThen77 = ((iTemp24) ? fSlow102 : fSlow101);
			float fElse77 = ((iTemp25) ? fSlow104 : fSlow103);
			int iTemp26 = fTemp20 >= 6.0f;
			int iTemp27 = fTemp20 >= 5.0f;
			int iTemp28 = fTemp20 >= 7.0f;
			float fThen80 = ((iTemp27) ? fSlow106 : fSlow105);
			float fElse80 = ((iTemp28) ? fSlow108 : fSlow107);
			float fThen81 = ((iTemp23) ? fElse77 : fThen77);
			float fElse81 = ((iTemp26) ? fElse80 : fThen80);
			int iTemp29 = fTemp20 >= 12.0f;
			int iTemp30 = fTemp20 >= 1e+01f;
			int iTemp31 = fTemp20 >= 9.0f;
			int iTemp32 = fTemp20 >= 11.0f;
			float fThen84 = ((iTemp31) ? fSlow110 : fSlow109);
			float fElse84 = ((iTemp32) ? fSlow112 : fSlow111);
			int iTemp33 = fTemp20 >= 14.0f;
			int iTemp34 = fTemp20 >= 13.0f;
			int iTemp35 = fTemp20 >= 15.0f;
			float fThen87 = ((iTemp34) ? fSlow114 : fSlow113);
			float fElse87 = ((iTemp35) ? fSlow116 : fSlow115);
			float fThen88 = ((iTemp30) ? fElse84 : fThen84);
			float fElse88 = ((iTemp33) ? fElse87 : fThen87);
			float fThen89 = ((iTemp22) ? fElse81 : fThen81);
			float fElse89 = ((iTemp29) ? fElse88 : fThen88);
			float fThen92 = ((iTemp24) ? fSlow28 : fSlow27);
			float fElse92 = ((iTemp25) ? fSlow30 : fSlow29);
			float fThen95 = ((iTemp27) ? fSlow32 : fSlow31);
			float fElse95 = ((iTemp28) ? fSlow34 : fSlow33);
			float fThen96 = ((iTemp23) ? fElse92 : fThen92);
			float fElse96 = ((iTemp26) ? fElse95 : fThen95);
			float fThen99 = ((iTemp31) ? fSlow36 : fSlow35);
			float fElse99 = ((iTemp32) ? fSlow38 : fSlow37);
			float fThen102 = ((iTemp34) ? fSlow40 : fSlow39);
			float fElse102 = ((iTemp35) ? fSlow42 : fSlow41);
			float fThen103 = ((iTemp30) ? fElse99 : fThen99);
			float fElse103 = ((iTemp33) ? fElse102 : fThen102);
			float fThen104 = ((iTemp22) ? fElse96 : fThen96);
			float fElse104 = ((iTemp29) ? fElse103 : fThen103);
			float fThen107 = ((iTemp24) ? fSlow45 : fSlow44);
			float fElse107 = ((iTemp25) ? fSlow47 : fSlow46);
			float fThen110 = ((iTemp27) ? fSlow49 : fSlow48);
			float fElse110 = ((iTemp28) ? fSlow51 : fSlow50);
			float fThen111 = ((iTemp23) ? fElse107 : fThen107);
			float fElse111 = ((iTemp26) ? fElse110 : fThen110);
			float fThen114 = ((iTemp31) ? fSlow53 : fSlow52);
			float fElse114 = ((iTemp32) ? fSlow55 : fSlow54);
			float fThen117 = ((iTemp34) ? fSlow57 : fSlow56);
			float fElse117 = ((iTemp35) ? fSlow59 : fSlow58);
			float fThen118 = ((iTemp30) ? fElse114 : fThen114);
			float fElse118 = ((iTemp33) ? fElse117 : fThen117);
			float fThen119 = ((iTemp22) ? fElse111 : fThen111);
			float fElse119 = ((iTemp29) ? fElse118 : fThen118);
			float fThen122 = ((iTemp24) ? fSlow62 : fSlow61);
			float fElse122 = ((iTemp25) ? fSlow64 : fSlow63);
			float fThen125 = ((iTemp27) ? fSlow66 : fSlow65);
			float fElse125 = ((iTemp28) ? fSlow68 : fSlow67);
			float fThen126 = ((iTemp23) ? fElse122 : fThen122);
			float fElse126 = ((iTemp26) ? fElse125 : fThen125);
			float fThen129 = ((iTemp31) ? fSlow70 : fSlow69);
			float fElse129 = ((iTemp32) ? fSlow72 : fSlow71);
			float fThen132 = ((iTemp34) ? fSlow74 : fSlow73);
			float fElse132 = ((iTemp35) ? fSlow76 : fSlow75);
			float fThen133 = ((iTemp30) ? fElse129 : fThen129);
			float fElse133 = ((iTemp33) ? fElse132 : fThen132);
			float fThen134 = ((iTemp22) ? fElse126 : fThen126);
			float fElse134 = ((iTemp29) ? fElse133 : fThen133);
			float fThen137 = ((iTemp24) ? fSlow79 : fSlow78);
			float fElse137 = ((iTemp25) ? fSlow81 : fSlow80);
			float fThen140 = ((iTemp27) ? fSlow83 : fSlow82);
			float fElse140 = ((iTemp28) ? fSlow85 : fSlow84);
			float fThen141 = ((iTemp23) ? fElse137 : fThen137);
			float fElse141 = ((iTemp26) ? fElse140 : fThen140);
			float fThen144 = ((iTemp31) ? fSlow87 : fSlow86);
			float fElse144 = ((iTemp32) ? fSlow89 : fSlow88);
			float fThen147 = ((iTemp34) ? fSlow91 : fSlow90);
			float fElse147 = ((iTemp35) ? fSlow93 : fSlow92);
			float fThen148 = ((iTemp30) ? fElse144 : fThen144);
			float fElse148 = ((iTemp33) ? fElse147 : fThen147);
			float fThen149 = ((iTemp22) ? fElse141 : fThen141);
			float fElse149 = ((iTemp29) ? fElse148 : fThen148);
			float fTemp36 = std::pow(2.0f, 0.083333336f * (fSlow95 + std::fmod(((iTemp21) ? fElse149 : fThen149) + fSlow77 * ((iTemp21) ? fElse134 : fThen134) + fSlow60 * ((iTemp21) ? fElse119 : fThen119) + fSlow43 * ((iTemp21) ? fElse104 : fThen104) + fSlow117 * ((iTemp21) ? fElse89 : fThen89), fSlow94)));
			float fTemp37 = fSlow98 * fTemp36;
			iRec11[0] = (iVec0[1] + iRec11[1]) % iSlow118;
			int iTemp38 = iRec11[0] <= iRec11[1];
			iVec3[0] = iTemp38;
			iRec10[0] = iRec10[1] + (iTemp38 > iVec3[1]);
			float fTemp39 = std::fmod(float(iRec10[0]), fSlow119);
			int iTemp40 = fTemp39 >= 8.0f;
			int iTemp41 = fTemp39 >= 4.0f;
			int iTemp42 = fTemp39 >= 2.0f;
			int iTemp43 = fTemp39 >= 1.0f;
			int iTemp44 = fTemp39 >= 3.0f;
			float fThen153 = ((iTemp43) ? fSlow121 : fSlow120);
			float fElse153 = ((iTemp44) ? fSlow123 : fSlow122);
			int iTemp45 = fTemp39 >= 6.0f;
			int iTemp46 = fTemp39 >= 5.0f;
			int iTemp47 = fTemp39 >= 7.0f;
			float fThen156 = ((iTemp46) ? fSlow125 : fSlow124);
			float fElse156 = ((iTemp47) ? fSlow127 : fSlow126);
			float fThen157 = ((iTemp42) ? fElse153 : fThen153);
			float fElse157 = ((iTemp45) ? fElse156 : fThen156);
			int iTemp48 = fTemp39 >= 12.0f;
			int iTemp49 = fTemp39 >= 1e+01f;
			int iTemp50 = fTemp39 >= 9.0f;
			int iTemp51 = fTemp39 >= 11.0f;
			float fThen160 = ((iTemp50) ? fSlow129 : fSlow128);
			float fElse160 = ((iTemp51) ? fSlow131 : fSlow130);
			int iTemp52 = fTemp39 >= 14.0f;
			int iTemp53 = fTemp39 >= 13.0f;
			int iTemp54 = fTemp39 >= 15.0f;
			float fThen163 = ((iTemp53) ? fSlow133 : fSlow132);
			float fElse163 = ((iTemp54) ? fSlow135 : fSlow134);
			float fThen164 = ((iTemp49) ? fElse160 : fThen160);
			float fElse164 = ((iTemp52) ? fElse163 : fThen163);
			float fThen165 = ((iTemp41) ? fElse157 : fThen157);
			float fElse165 = ((iTemp48) ? fElse164 : fThen164);
			float fThen168 = ((iTemp43) ? fSlow28 : fSlow27);
			float fElse168 = ((iTemp44) ? fSlow30 : fSlow29);
			float fThen171 = ((iTemp46) ? fSlow32 : fSlow31);
			float fElse171 = ((iTemp47) ? fSlow34 : fSlow33);
			float fThen172 = ((iTemp42) ? fElse168 : fThen168);
			float fElse172 = ((iTemp45) ? fElse171 : fThen171);
			float fThen175 = ((iTemp50) ? fSlow36 : fSlow35);
			float fElse175 = ((iTemp51) ? fSlow38 : fSlow37);
			float fThen178 = ((iTemp53) ? fSlow40 : fSlow39);
			float fElse178 = ((iTemp54) ? fSlow42 : fSlow41);
			float fThen179 = ((iTemp49) ? fElse175 : fThen175);
			float fElse179 = ((iTemp52) ? fElse178 : fThen178);
			float fThen180 = ((iTemp41) ? fElse172 : fThen172);
			float fElse180 = ((iTemp48) ? fElse179 : fThen179);
			float fThen183 = ((iTemp43) ? fSlow45 : fSlow44);
			float fElse183 = ((iTemp44) ? fSlow47 : fSlow46);
			float fThen186 = ((iTemp46) ? fSlow49 : fSlow48);
			float fElse186 = ((iTemp47) ? fSlow51 : fSlow50);
			float fThen187 = ((iTemp42) ? fElse183 : fThen183);
			float fElse187 = ((iTemp45) ? fElse186 : fThen186);
			float fThen190 = ((iTemp50) ? fSlow53 : fSlow52);
			float fElse190 = ((iTemp51) ? fSlow55 : fSlow54);
			float fThen193 = ((iTemp53) ? fSlow57 : fSlow56);
			float fElse193 = ((iTemp54) ? fSlow59 : fSlow58);
			float fThen194 = ((iTemp49) ? fElse190 : fThen190);
			float fElse194 = ((iTemp52) ? fElse193 : fThen193);
			float fThen195 = ((iTemp41) ? fElse187 : fThen187);
			float fElse195 = ((iTemp48) ? fElse194 : fThen194);
			float fThen198 = ((iTemp43) ? fSlow62 : fSlow61);
			float fElse198 = ((iTemp44) ? fSlow64 : fSlow63);
			float fThen201 = ((iTemp46) ? fSlow66 : fSlow65);
			float fElse201 = ((iTemp47) ? fSlow68 : fSlow67);
			float fThen202 = ((iTemp42) ? fElse198 : fThen198);
			float fElse202 = ((iTemp45) ? fElse201 : fThen201);
			float fThen205 = ((iTemp50) ? fSlow70 : fSlow69);
			float fElse205 = ((iTemp51) ? fSlow72 : fSlow71);
			float fThen208 = ((iTemp53) ? fSlow74 : fSlow73);
			float fElse208 = ((iTemp54) ? fSlow76 : fSlow75);
			float fThen209 = ((iTemp49) ? fElse205 : fThen205);
			float fElse209 = ((iTemp52) ? fElse208 : fThen208);
			float fThen210 = ((iTemp41) ? fElse202 : fThen202);
			float fElse210 = ((iTemp48) ? fElse209 : fThen209);
			float fThen213 = ((iTemp43) ? fSlow79 : fSlow78);
			float fElse213 = ((iTemp44) ? fSlow81 : fSlow80);
			float fThen216 = ((iTemp46) ? fSlow83 : fSlow82);
			float fElse216 = ((iTemp47) ? fSlow85 : fSlow84);
			float fThen217 = ((iTemp42) ? fElse213 : fThen213);
			float fElse217 = ((iTemp45) ? fElse216 : fThen216);
			float fThen220 = ((iTemp50) ? fSlow87 : fSlow86);
			float fElse220 = ((iTemp51) ? fSlow89 : fSlow88);
			float fThen223 = ((iTemp53) ? fSlow91 : fSlow90);
			float fElse223 = ((iTemp54) ? fSlow93 : fSlow92);
			float fThen224 = ((iTemp49) ? fElse220 : fThen220);
			float fElse224 = ((iTemp52) ? fElse223 : fThen223);
			float fThen225 = ((iTemp41) ? fElse217 : fThen217);
			float fElse225 = ((iTemp48) ? fElse224 : fThen224);
			float fTemp55 = std::pow(2.0f, 0.083333336f * (fSlow95 + std::fmod(((iTemp40) ? fElse225 : fThen225) + fSlow77 * ((iTemp40) ? fElse210 : fThen210) + fSlow60 * ((iTemp40) ? fElse195 : fThen195) + fSlow43 * ((iTemp40) ? fElse180 : fThen180) + fSlow136 * ((iTemp40) ? fElse165 : fThen165), fSlow94)));
			float fTemp56 = fSlow98 * fTemp55;
			float fThen226 = ((iSlow7) ? fTemp37 : fTemp18);
			float fTemp57 = 0.051175587f * (fTemp18 + -1e+01f);
			int iTemp58 = int(fTemp57);
			float fTemp59 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp58 + -1, 1023))];
			float fTemp60 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp58 + 2, 1023))];
			float fTemp61 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp58, 1023))];
			float fTemp62 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp58 + 1, 1023))];
			float fTemp63 = fTemp57 - float(iTemp58);
			float fTemp64 = 1.442695f * (fTemp61 + 0.5f * fTemp63 * (fTemp62 + fTemp63 * (2.0f * fTemp59 + 4.0f * fTemp62 + fTemp63 * (fTemp60 + 3.0f * (fTemp61 - fTemp62) - fTemp59) - (5.0f * fTemp61 + fTemp60)) - fTemp59) - fSlow139);
			float fTemp65 = float(fTemp64 < 0.0f) / float(1 << int(0.0f - (fTemp64 + -1.0f))) + float((fTemp64 >= 0.0f) * (1 << int(fTemp64)));
			float fTemp66 = fSlow97 * (fTemp17 / fTemp65);
			float fTemp67 = 1.122462f * float(1.122462f <= fTemp66) + float(1.122462f > fTemp66);
			float fTemp68 = float(1.3348398f > fTemp66);
			float fTemp69 = 1.3348398f * float(1.3348398f <= fTemp66);
			float fTemp70 = float(1.4983071f > fTemp66);
			float fTemp71 = 1.4983071f * float(1.4983071f <= fTemp66);
			float fTemp72 = fSlow138 * fTemp65 * (1.8877486f * float(1.8877486f <= fTemp66) + float(1.8877486f > fTemp66) * (1.6817929f * float(1.6817929f <= fTemp66) + float(1.6817929f > fTemp66) * (fTemp71 + fTemp70 * (fTemp69 + fTemp68 * (1.2599211f * float(1.2599211f <= fTemp66) + float(1.2599211f > fTemp66) * fTemp67)))));
			float fTemp73 = 0.051175587f * (fTemp37 + -1e+01f);
			int iTemp74 = int(fTemp73);
			float fTemp75 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp74 + -1, 1023))];
			float fTemp76 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp74 + 2, 1023))];
			float fTemp77 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp74, 1023))];
			float fTemp78 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp74 + 1, 1023))];
			float fTemp79 = fTemp73 - float(iTemp74);
			float fTemp80 = 1.442695f * (fTemp77 + 0.5f * fTemp79 * (fTemp78 + fTemp79 * (2.0f * fTemp75 + 4.0f * fTemp78 + fTemp79 * (fTemp76 + 3.0f * (fTemp77 - fTemp78) - fTemp75) - (5.0f * fTemp77 + fTemp76)) - fTemp75) - fSlow139);
			float fTemp81 = float(fTemp80 < 0.0f) / float(1 << int(0.0f - (fTemp80 + -1.0f))) + float((fTemp80 >= 0.0f) * (1 << int(fTemp80)));
			float fTemp82 = fSlow97 * (fTemp36 / fTemp81);
			float fTemp83 = 1.122462f * float(1.122462f <= fTemp82) + float(1.122462f > fTemp82);
			float fTemp84 = float(1.3348398f > fTemp82);
			float fTemp85 = 1.3348398f * float(1.3348398f <= fTemp82);
			float fTemp86 = float(1.4983071f > fTemp82);
			float fTemp87 = 1.4983071f * float(1.4983071f <= fTemp82);
			float fTemp88 = fSlow138 * fTemp81 * (1.8877486f * float(1.8877486f <= fTemp82) + float(1.8877486f > fTemp82) * (1.6817929f * float(1.6817929f <= fTemp82) + float(1.6817929f > fTemp82) * (fTemp87 + fTemp86 * (fTemp85 + fTemp84 * (1.2599211f * float(1.2599211f <= fTemp82) + float(1.2599211f > fTemp82) * fTemp83)))));
			float fThen228 = ((iSlow6) ? fTemp56 : fThen226);
			float fElse228 = ((iSlow137) ? fTemp88 : fTemp72);
			float fTemp89 = 0.051175587f * (fTemp56 + -1e+01f);
			int iTemp90 = int(fTemp89);
			float fTemp91 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp90 + -1, 1023))];
			float fTemp92 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp90 + 2, 1023))];
			float fTemp93 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp90, 1023))];
			float fTemp94 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(iTemp90 + 1, 1023))];
			float fTemp95 = fTemp89 - float(iTemp90);
			float fTemp96 = 1.442695f * (fTemp93 + 0.5f * fTemp95 * (fTemp94 + fTemp95 * (2.0f * fTemp91 + 4.0f * fTemp94 + fTemp95 * (fTemp92 + 3.0f * (fTemp93 - fTemp94) - fTemp91) - (5.0f * fTemp93 + fTemp92)) - fTemp91) - fSlow139);
			float fTemp97 = float(fTemp96 < 0.0f) / float(1 << int(0.0f - (fTemp96 + -1.0f))) + float((fTemp96 >= 0.0f) * (1 << int(fTemp96)));
			float fTemp98 = fSlow97 * (fTemp55 / fTemp97);
			float fTemp99 = 1.122462f * float(1.122462f <= fTemp98) + float(1.122462f > fTemp98);
			float fTemp100 = float(1.3348398f > fTemp98);
			float fTemp101 = 1.3348398f * float(1.3348398f <= fTemp98);
			float fTemp102 = float(1.4983071f > fTemp98);
			float fTemp103 = 1.4983071f * float(1.4983071f <= fTemp98);
			float fTemp104 = fSlow138 * fTemp97 * (1.8877486f * float(1.8877486f <= fTemp98) + float(1.8877486f > fTemp98) * (1.6817929f * float(1.6817929f <= fTemp98) + float(1.6817929f > fTemp98) * (fTemp103 + fTemp102 * (fTemp101 + fTemp100 * (1.2599211f * float(1.2599211f <= fTemp98) + float(1.2599211f > fTemp98) * fTemp99)))));
			float fTemp105 = fSlow138 * fTemp65 * (1.7817974f * float(1.7817974f <= fTemp66) + float(1.7817974f > fTemp66) * (1.587401f * float(1.587401f <= fTemp66) + float(1.587401f > fTemp66) * (fTemp71 + fTemp70 * (fTemp69 + fTemp68 * (1.1892071f * float(1.1892071f <= fTemp66) + fTemp67 * float(1.1892071f > fTemp66))))));
			float fTemp106 = fSlow138 * fTemp81 * (1.7817974f * float(1.7817974f <= fTemp82) + float(1.7817974f > fTemp82) * (1.587401f * float(1.587401f <= fTemp82) + float(1.587401f > fTemp82) * (fTemp87 + fTemp86 * (fTemp85 + fTemp84 * (1.1892071f * float(1.1892071f <= fTemp82) + fTemp83 * float(1.1892071f > fTemp82))))));
			float fTemp107 = fSlow138 * fTemp97 * (1.7817974f * float(1.7817974f <= fTemp98) + float(1.7817974f > fTemp98) * (1.587401f * float(1.587401f <= fTemp98) + float(1.587401f > fTemp98) * (fTemp103 + fTemp102 * (fTemp101 + fTemp100 * (1.1892071f * float(1.1892071f <= fTemp98) + fTemp99 * float(1.1892071f > fTemp98))))));
			float fThen231 = ((iSlow141) ? fTemp105 : fTemp104);
			float fElse231 = ((iSlow142) ? fTemp107 : fTemp106);
			float fThen232 = ((iSlow5) ? fElse228 : fThen228);
			float fElse232 = ((iSlow140) ? fElse231 : fThen231);
			float fTemp108 = std::max<float>(((iSlow4) ? fElse232 : fThen232), 23.44895f);
			float fTemp109 = std::max<float>(2e+01f, std::fabs(fTemp108));
			float fTemp110 = fRec13[1] + fConst2 * fTemp109;
			fRec13[0] = fTemp110 - std::floor(fTemp110);
			float fTemp111 = mydsp_faustpower2_f(2.0f * fRec13[0] + -1.0f);
			fVec4[0] = fTemp111;
			float fTemp112 = float(iVec0[1]);
			float fTemp113 = fTemp112 * (fTemp111 - fVec4[1]) / fTemp109;
			fVec5[IOTA0 & 4095] = fTemp113;
			float fTemp114 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst3 / fTemp108));
			int iTemp115 = int(fTemp114);
			float fTemp116 = std::floor(fTemp114);
			iRec15[0] = (iVec0[1] + iRec15[1]) % iSlow143;
			int iTemp117 = iRec15[0] <= iRec15[1];
			iRec16[0] = iTemp117 + iRec16[1] * (iRec16[1] <= 15);
			int iTemp118 = (fSlow159 * float((iRec16[0] == 16) * iTemp117) + fSlow158 * float((iRec16[0] == 1) * iTemp117) + fSlow157 * float((iRec16[0] == 2) * iTemp117) + fSlow156 * float((iRec16[0] == 3) * iTemp117) + fSlow155 * float((iRec16[0] == 4) * iTemp117) + fSlow154 * float((iRec16[0] == 5) * iTemp117) + fSlow153 * float((iRec16[0] == 6) * iTemp117) + fSlow152 * float((iRec16[0] == 7) * iTemp117) + fSlow151 * float((iRec16[0] == 8) * iTemp117) + fSlow150 * float((iRec16[0] == 9) * iTemp117) + fSlow149 * float((iRec16[0] == 10) * iTemp117) + fSlow148 * float((iRec16[0] == 11) * iTemp117) + fSlow147 * float((iRec16[0] == 12) * iTemp117) + fSlow146 * float((iRec16[0] == 13) * iTemp117) + fSlow145 * float((iRec16[0] == 14) * iTemp117) + fSlow144 * float((iRec16[0] == 15) * iTemp117)) > 0.0f;
			float fTemp119 = 0.1447178f * ((iTemp118) ? 0.0f : fSlow160);
			int iTemp120 = std::fabs(fTemp119) < 1.1920929e-07f;
			float fThen235 = std::exp(0.0f - fConst2 / ((iTemp120) ? 1.0f : fTemp119));
			float fTemp121 = ((iTemp120) ? 0.0f : fThen235);
			float fElse236 = float(iTemp118);
			fRec14[0] = (1.0f - fTemp121) * ((iTemp118) ? fElse236 : 0.0f) + fTemp121 * fRec14[1];
			float fThen238 = ((iSlow166) ? fTemp37 : fTemp18);
			float fThen240 = ((iSlow165) ? fTemp56 : fThen238);
			float fElse240 = ((iSlow167) ? fTemp88 : fTemp72);
			float fThen243 = ((iSlow169) ? fTemp105 : fTemp104);
			float fElse243 = ((iSlow170) ? fTemp107 : fTemp106);
			float fThen244 = ((iSlow164) ? fElse240 : fThen240);
			float fElse244 = ((iSlow168) ? fElse243 : fThen243);
			float fTemp122 = std::max<float>(((iSlow163) ? fElse244 : fThen244), 23.44895f);
			float fTemp123 = std::max<float>(2e+01f, std::fabs(fTemp122));
			float fTemp124 = fRec17[1] + fConst2 * fTemp123;
			fRec17[0] = fTemp124 - std::floor(fTemp124);
			float fTemp125 = mydsp_faustpower2_f(2.0f * fRec17[0] + -1.0f);
			fVec6[0] = fTemp125;
			float fTemp126 = fTemp112 * (fTemp125 - fVec6[1]) / fTemp123;
			fVec7[IOTA0 & 4095] = fTemp126;
			float fTemp127 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst3 / fTemp122));
			int iTemp128 = int(fTemp127);
			float fTemp129 = std::floor(fTemp127);
			iRec19[0] = (iVec0[1] + iRec19[1]) % iSlow171;
			int iTemp130 = iRec19[0] <= iRec19[1];
			iRec20[0] = iTemp130 + iRec20[1] * (iRec20[1] <= 15);
			int iTemp131 = (fSlow187 * float((iRec20[0] == 16) * iTemp130) + fSlow186 * float((iRec20[0] == 1) * iTemp130) + fSlow185 * float((iRec20[0] == 2) * iTemp130) + fSlow184 * float((iRec20[0] == 3) * iTemp130) + fSlow183 * float((iRec20[0] == 4) * iTemp130) + fSlow182 * float((iRec20[0] == 5) * iTemp130) + fSlow181 * float((iRec20[0] == 6) * iTemp130) + fSlow180 * float((iRec20[0] == 7) * iTemp130) + fSlow179 * float((iRec20[0] == 8) * iTemp130) + fSlow178 * float((iRec20[0] == 9) * iTemp130) + fSlow177 * float((iRec20[0] == 10) * iTemp130) + fSlow176 * float((iRec20[0] == 11) * iTemp130) + fSlow175 * float((iRec20[0] == 12) * iTemp130) + fSlow174 * float((iRec20[0] == 13) * iTemp130) + fSlow173 * float((iRec20[0] == 14) * iTemp130) + fSlow172 * float((iRec20[0] == 15) * iTemp130)) > 0.0f;
			float fTemp132 = 0.1447178f * ((iTemp131) ? 0.0f : fSlow188);
			int iTemp133 = std::fabs(fTemp132) < 1.1920929e-07f;
			float fThen247 = std::exp(0.0f - fConst2 / ((iTemp133) ? 1.0f : fTemp132));
			float fTemp134 = ((iTemp133) ? 0.0f : fThen247);
			float fElse248 = float(iTemp131);
			fRec18[0] = (1.0f - fTemp134) * ((iTemp131) ? fElse248 : 0.0f) + fTemp134 * fRec18[1];
			float fThen250 = ((iSlow193) ? fTemp37 : fTemp18);
			float fThen252 = ((iSlow192) ? fTemp56 : fThen250);
			float fElse252 = ((iSlow194) ? fTemp88 : fTemp72);
			float fThen255 = ((iSlow196) ? fTemp105 : fTemp104);
			float fElse255 = ((iSlow197) ? fTemp107 : fTemp106);
			float fThen256 = ((iSlow191) ? fElse252 : fThen252);
			float fElse256 = ((iSlow195) ? fElse255 : fThen255);
			float fTemp135 = std::max<float>(((iSlow190) ? fElse256 : fThen256), 23.44895f);
			float fTemp136 = std::max<float>(2e+01f, std::fabs(fTemp135));
			float fTemp137 = fRec21[1] + fConst2 * fTemp136;
			fRec21[0] = fTemp137 - std::floor(fTemp137);
			float fTemp138 = mydsp_faustpower2_f(2.0f * fRec21[0] + -1.0f);
			fVec8[0] = fTemp138;
			float fTemp139 = fTemp112 * (fTemp138 - fVec8[1]) / fTemp136;
			fVec9[IOTA0 & 4095] = fTemp139;
			float fTemp140 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst3 / fTemp135));
			int iTemp141 = int(fTemp140);
			float fTemp142 = std::floor(fTemp140);
			iRec23[0] = (iVec0[1] + iRec23[1]) % iSlow198;
			int iTemp143 = iRec23[0] <= iRec23[1];
			iRec24[0] = iTemp143 + iRec24[1] * (iRec24[1] <= 15);
			int iTemp144 = (fSlow214 * float((iRec24[0] == 16) * iTemp143) + fSlow213 * float((iRec24[0] == 1) * iTemp143) + fSlow212 * float((iRec24[0] == 2) * iTemp143) + fSlow211 * float((iRec24[0] == 3) * iTemp143) + fSlow210 * float((iRec24[0] == 4) * iTemp143) + fSlow209 * float((iRec24[0] == 5) * iTemp143) + fSlow208 * float((iRec24[0] == 6) * iTemp143) + fSlow207 * float((iRec24[0] == 7) * iTemp143) + fSlow206 * float((iRec24[0] == 8) * iTemp143) + fSlow205 * float((iRec24[0] == 9) * iTemp143) + fSlow204 * float((iRec24[0] == 10) * iTemp143) + fSlow203 * float((iRec24[0] == 11) * iTemp143) + fSlow202 * float((iRec24[0] == 12) * iTemp143) + fSlow201 * float((iRec24[0] == 13) * iTemp143) + fSlow200 * float((iRec24[0] == 14) * iTemp143) + fSlow199 * float((iRec24[0] == 15) * iTemp143)) > 0.0f;
			float fTemp145 = 0.1447178f * ((iTemp144) ? 0.0f : fSlow215);
			int iTemp146 = std::fabs(fTemp145) < 1.1920929e-07f;
			float fThen259 = std::exp(0.0f - fConst2 / ((iTemp146) ? 1.0f : fTemp145));
			float fTemp147 = ((iTemp146) ? 0.0f : fThen259);
			float fElse260 = float(iTemp144);
			fRec22[0] = (1.0f - fTemp147) * ((iTemp144) ? fElse260 : 0.0f) + fTemp147 * fRec22[1];
			float fTemp148 = fConst4 * (fSlow216 * fRec22[0] * (fTemp139 - fVec9[(IOTA0 - iTemp141) & 4095] * (fTemp142 + (1.0f - fTemp140)) - (fTemp140 - fTemp142) * fVec9[(IOTA0 - (iTemp141 + 1)) & 4095]) + fSlow189 * fRec18[0] * (fTemp126 - fVec7[(IOTA0 - iTemp128) & 4095] * (fTemp129 + (1.0f - fTemp127)) - (fTemp127 - fTemp129) * fVec7[(IOTA0 - (iTemp128 + 1)) & 4095]) + fSlow161 * fRec14[0] * (fTemp113 - fVec5[(IOTA0 - iTemp115) & 4095] * (fTemp116 + (1.0f - fTemp114)) - (fTemp114 - fTemp116) * fVec5[(IOTA0 - (iTemp115 + 1)) & 4095]));
			float fTemp149 = fRec3[1] + fSlow217 * (fTemp148 - fRec4[1]);
			fRec3[0] = fSlow219 * fTemp149 - fRec3[1];
			float fTemp150 = fRec4[1] + fSlow220 * fTemp149;
			fRec4[0] = 2.0f * fTemp150 - fRec4[1];
			float fRec5 = fTemp150;
			float fTemp151 = fSlow221 * std::max<float>(fSlow1, std::min<float>(fSlow0, fRec5));
			float fTemp152 = fRec0[1] + fSlow222 * (fTemp151 - fRec1[1]);
			fRec0[0] = fSlow224 * fTemp152 - fRec0[1];
			float fTemp153 = fRec1[1] + fSlow225 * fTemp152;
			fRec1[0] = 2.0f * fTemp153 - fRec1[1];
			float fRec2 = fTemp153;
			fRec25[0] = std::fmod(fSlow232 + (fRec25[1] + 1.0f - fSlow229), fSlow232);
			float fTemp154 = std::min<float>(fSlow233 * fRec25[0], 1.0f);
			float fTemp155 = fSlow226 * fRec2;
			fVec10[IOTA0 & 131071] = fTemp155;
			int iTemp156 = int(fRec25[0]);
			float fTemp157 = std::floor(fRec25[0]);
			float fTemp158 = 1.0f - fRec25[0];
			fRec26[0] = std::fmod(fSlow235 + (fRec26[1] + 1.0f - fSlow234), fSlow235);
			float fTemp159 = std::min<float>(fSlow233 * fRec26[0], 1.0f);
			int iTemp160 = int(fRec26[0]);
			float fTemp161 = std::floor(fRec26[0]);
			float fTemp162 = 1.0f - fRec26[0];
			fRec27[0] = std::fmod(fSlow237 + (fRec27[1] + 1.0f - fSlow236), fSlow237);
			float fTemp163 = std::min<float>(fSlow233 * fRec27[0], 1.0f);
			int iTemp164 = int(fRec27[0]);
			float fTemp165 = std::floor(fRec27[0]);
			float fTemp166 = 1.0f - fRec27[0];
			fRec28[0] = std::fmod(fSlow239 + (fRec28[1] + 1.0f - fSlow238), fSlow239);
			float fTemp167 = std::min<float>(fSlow233 * fRec28[0], 1.0f);
			int iTemp168 = int(fRec28[0]);
			float fTemp169 = std::floor(fRec28[0]);
			float fTemp170 = 1.0f - fRec28[0];
			fRec29[0] = std::fmod(fSlow241 + (fRec29[1] + 1.0f - fSlow240), fSlow241);
			float fTemp171 = std::min<float>(fSlow233 * fRec29[0], 1.0f);
			int iTemp172 = int(fRec29[0]);
			float fTemp173 = std::floor(fRec29[0]);
			float fTemp174 = 1.0f - fRec29[0];
			fRec30[0] = std::fmod(fSlow243 + (fRec30[1] + 1.0f - fSlow242), fSlow243);
			float fTemp175 = std::min<float>(fSlow233 * fRec30[0], 1.0f);
			int iTemp176 = int(fRec30[0]);
			float fTemp177 = std::floor(fRec30[0]);
			float fTemp178 = 1.0f - fRec30[0];
			fRec31[0] = std::fmod(fSlow245 + (fRec31[1] + 1.0f - fSlow244), fSlow245);
			float fTemp179 = std::min<float>(fSlow233 * fRec31[0], 1.0f);
			int iTemp180 = int(fRec31[0]);
			float fTemp181 = std::floor(fRec31[0]);
			float fTemp182 = 1.0f - fRec31[0];
			fRec32[0] = std::fmod(fSlow247 + (fRec32[1] + 1.0f - fSlow246), fSlow247);
			float fTemp183 = std::min<float>(fSlow233 * fRec32[0], 1.0f);
			int iTemp184 = int(fRec32[0]);
			float fTemp185 = std::floor(fRec32[0]);
			float fTemp186 = 1.0f - fRec32[0];
			fRec33[0] = std::fmod(fSlow249 + (fRec33[1] + 1.0f - fSlow248), fSlow249);
			float fTemp187 = std::min<float>(fSlow233 * fRec33[0], 1.0f);
			int iTemp188 = int(fRec33[0]);
			float fTemp189 = std::floor(fRec33[0]);
			float fTemp190 = 1.0f - fRec33[0];
			fRec34[0] = std::fmod(fSlow251 + (fRec34[1] + 1.0f - fSlow250), fSlow251);
			float fTemp191 = std::min<float>(fSlow233 * fRec34[0], 1.0f);
			int iTemp192 = int(fRec34[0]);
			float fTemp193 = std::floor(fRec34[0]);
			float fTemp194 = 1.0f - fRec34[0];
			fRec35[0] = std::fmod(fSlow253 + (fRec35[1] + 1.0f - fSlow252), fSlow253);
			float fTemp195 = std::min<float>(fSlow233 * fRec35[0], 1.0f);
			int iTemp196 = int(fRec35[0]);
			float fTemp197 = std::floor(fRec35[0]);
			float fTemp198 = 1.0f - fRec35[0];
			fRec36[0] = std::fmod(fSlow255 + (fRec36[1] + 1.0f - fSlow254), fSlow255);
			float fTemp199 = std::min<float>(fSlow233 * fRec36[0], 1.0f);
			int iTemp200 = int(fRec36[0]);
			float fTemp201 = std::floor(fRec36[0]);
			float fTemp202 = 1.0f - fRec36[0];
			fRec37[0] = std::fmod(fSlow257 + (fRec37[1] + 1.0f - fSlow256), fSlow257);
			float fTemp203 = std::min<float>(fSlow233 * fRec37[0], 1.0f);
			int iTemp204 = int(fRec37[0]);
			float fTemp205 = std::floor(fRec37[0]);
			float fTemp206 = 1.0f - fRec37[0];
			fRec38[0] = std::fmod(fSlow259 + (fRec38[1] + 1.0f - fSlow258), fSlow259);
			float fTemp207 = std::min<float>(fSlow233 * fRec38[0], 1.0f);
			int iTemp208 = int(fRec38[0]);
			float fTemp209 = std::floor(fRec38[0]);
			float fTemp210 = 1.0f - fRec38[0];
			fRec39[0] = std::fmod(fSlow261 + (fRec39[1] + 1.0f - fSlow260), fSlow261);
			float fTemp211 = std::min<float>(fSlow233 * fRec39[0], 1.0f);
			int iTemp212 = int(fRec39[0]);
			float fTemp213 = std::floor(fRec39[0]);
			float fTemp214 = 1.0f - fRec39[0];
			fRec40[0] = std::fmod(fSlow262 + fRec40[1], fSlow262);
			float fTemp215 = std::min<float>(fSlow233 * fRec40[0], 1.0f);
			float fTemp216 = fSlow262 + fRec40[0];
			int iTemp217 = int(fTemp216);
			float fTemp218 = std::floor(fTemp216);
			float fTemp219 = 1.0f - fRec40[0];
			int iTemp220 = int(fRec40[0]);
			float fTemp221 = std::floor(fRec40[0]);
			float fTemp222 = fSlow261 + fRec39[0];
			int iTemp223 = int(fTemp222);
			float fTemp224 = std::floor(fTemp222);
			float fTemp225 = fSlow259 + fRec38[0];
			int iTemp226 = int(fTemp225);
			float fTemp227 = std::floor(fTemp225);
			float fTemp228 = fSlow257 + fRec37[0];
			int iTemp229 = int(fTemp228);
			float fTemp230 = std::floor(fTemp228);
			float fTemp231 = fSlow255 + fRec36[0];
			int iTemp232 = int(fTemp231);
			float fTemp233 = std::floor(fTemp231);
			float fTemp234 = fSlow253 + fRec35[0];
			int iTemp235 = int(fTemp234);
			float fTemp236 = std::floor(fTemp234);
			float fTemp237 = fSlow251 + fRec34[0];
			int iTemp238 = int(fTemp237);
			float fTemp239 = std::floor(fTemp237);
			float fTemp240 = fSlow249 + fRec33[0];
			int iTemp241 = int(fTemp240);
			float fTemp242 = std::floor(fTemp240);
			float fTemp243 = fSlow247 + fRec32[0];
			int iTemp244 = int(fTemp243);
			float fTemp245 = std::floor(fTemp243);
			float fTemp246 = fSlow245 + fRec31[0];
			int iTemp247 = int(fTemp246);
			float fTemp248 = std::floor(fTemp246);
			float fTemp249 = fSlow243 + fRec30[0];
			int iTemp250 = int(fTemp249);
			float fTemp251 = std::floor(fTemp249);
			float fTemp252 = fSlow241 + fRec29[0];
			int iTemp253 = int(fTemp252);
			float fTemp254 = std::floor(fTemp252);
			float fTemp255 = fSlow239 + fRec28[0];
			int iTemp256 = int(fTemp255);
			float fTemp257 = std::floor(fTemp255);
			float fTemp258 = fSlow237 + fRec27[0];
			int iTemp259 = int(fTemp258);
			float fTemp260 = std::floor(fTemp258);
			float fTemp261 = fSlow235 + fRec26[0];
			int iTemp262 = int(fTemp261);
			float fTemp263 = std::floor(fTemp261);
			float fTemp264 = fSlow232 + fRec25[0];
			int iTemp265 = int(fTemp264);
			float fTemp266 = std::floor(fTemp264);
			float fTemp267 = 0.0625f * ((fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp265))) & 131071] * (fTemp266 + fTemp158 - fSlow232) + (fSlow232 + (fRec25[0] - fTemp266)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp265 + 1))) & 131071]) * (1.0f - fTemp154) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp262))) & 131071] * (fTemp263 + fTemp162 - fSlow235) + (fSlow235 + (fRec26[0] - fTemp263)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp262 + 1))) & 131071]) * (1.0f - fTemp159) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp259))) & 131071] * (fTemp260 + fTemp166 - fSlow237) + (fSlow237 + (fRec27[0] - fTemp260)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp259 + 1))) & 131071]) * (1.0f - fTemp163) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp256))) & 131071] * (fTemp257 + fTemp170 - fSlow239) + (fSlow239 + (fRec28[0] - fTemp257)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp256 + 1))) & 131071]) * (1.0f - fTemp167) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp253))) & 131071] * (fTemp254 + fTemp174 - fSlow241) + (fSlow241 + (fRec29[0] - fTemp254)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp253 + 1))) & 131071]) * (1.0f - fTemp171) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp250))) & 131071] * (fTemp251 + fTemp178 - fSlow243) + (fSlow243 + (fRec30[0] - fTemp251)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp250 + 1))) & 131071]) * (1.0f - fTemp175) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp247))) & 131071] * (fTemp248 + fTemp182 - fSlow245) + (fSlow245 + (fRec31[0] - fTemp248)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp247 + 1))) & 131071]) * (1.0f - fTemp179) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp244))) & 131071] * (fTemp245 + fTemp186 - fSlow247) + (fSlow247 + (fRec32[0] - fTemp245)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp244 + 1))) & 131071]) * (1.0f - fTemp183) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp241))) & 131071] * (fTemp242 + fTemp190 - fSlow249) + (fSlow249 + (fRec33[0] - fTemp242)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp241 + 1))) & 131071]) * (1.0f - fTemp187) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp238))) & 131071] * (fTemp239 + fTemp194 - fSlow251) + (fSlow251 + (fRec34[0] - fTemp239)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp238 + 1))) & 131071]) * (1.0f - fTemp191) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp235))) & 131071] * (fTemp236 + fTemp198 - fSlow253) + (fSlow253 + (fRec35[0] - fTemp236)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp235 + 1))) & 131071]) * (1.0f - fTemp195) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp232))) & 131071] * (fTemp233 + fTemp202 - fSlow255) + (fSlow255 + (fRec36[0] - fTemp233)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp232 + 1))) & 131071]) * (1.0f - fTemp199) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp229))) & 131071] * (fTemp230 + fTemp206 - fSlow257) + (fSlow257 + (fRec37[0] - fTemp230)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp229 + 1))) & 131071]) * (1.0f - fTemp203) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp226))) & 131071] * (fTemp227 + fTemp210 - fSlow259) + (fSlow259 + (fRec38[0] - fTemp227)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp226 + 1))) & 131071]) * (1.0f - fTemp207) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp223))) & 131071] * (fTemp224 + fTemp214 - fSlow261) + (fSlow261 + (fRec39[0] - fTemp224)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp223 + 1))) & 131071]) * (1.0f - fTemp211) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp220))) & 131071] * (fTemp221 + fTemp219) + (fRec40[0] - fTemp221) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp220 + 1))) & 131071]) * fTemp215 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp217))) & 131071] * (fTemp218 + fTemp219 - fSlow262) + (fSlow262 + (fRec40[0] - fTemp218)) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp217 + 1))) & 131071]) * (1.0f - fTemp215) + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp212))) & 131071] * (fTemp213 + fTemp214) + (fRec39[0] - fTemp213) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp212 + 1))) & 131071]) * fTemp211 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp208))) & 131071] * (fTemp209 + fTemp210) + (fRec38[0] - fTemp209) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp208 + 1))) & 131071]) * fTemp207 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp204))) & 131071] * (fTemp205 + fTemp206) + (fRec37[0] - fTemp205) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp204 + 1))) & 131071]) * fTemp203 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp200))) & 131071] * (fTemp201 + fTemp202) + (fRec36[0] - fTemp201) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp200 + 1))) & 131071]) * fTemp199 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp196))) & 131071] * (fTemp197 + fTemp198) + (fRec35[0] - fTemp197) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp196 + 1))) & 131071]) * fTemp195 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp192))) & 131071] * (fTemp193 + fTemp194) + (fRec34[0] - fTemp193) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp192 + 1))) & 131071]) * fTemp191 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp188))) & 131071] * (fTemp189 + fTemp190) + (fRec33[0] - fTemp189) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp188 + 1))) & 131071]) * fTemp187 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp184))) & 131071] * (fTemp185 + fTemp186) + (fRec32[0] - fTemp185) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp184 + 1))) & 131071]) * fTemp183 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp180))) & 131071] * (fTemp181 + fTemp182) + (fRec31[0] - fTemp181) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp180 + 1))) & 131071]) * fTemp179 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp176))) & 131071] * (fTemp177 + fTemp178) + (fRec30[0] - fTemp177) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp176 + 1))) & 131071]) * fTemp175 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp172))) & 131071] * (fTemp173 + fTemp174) + (fRec29[0] - fTemp173) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp172 + 1))) & 131071]) * fTemp171 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp168))) & 131071] * (fTemp169 + fTemp170) + (fRec28[0] - fTemp169) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp168 + 1))) & 131071]) * fTemp167 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp164))) & 131071] * (fTemp165 + fTemp166) + (fRec27[0] - fTemp165) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp164 + 1))) & 131071]) * fTemp163 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp160))) & 131071] * (fTemp161 + fTemp162) + (fRec26[0] - fTemp161) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp160 + 1))) & 131071]) * fTemp159 + (fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp156))) & 131071] * (fTemp157 + fTemp158) + (fRec25[0] - fTemp157) * fVec10[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp156 + 1))) & 131071]) * fTemp154) + fSlow227 * fRec2;
			float fTemp268 = fSlow280 * fTemp267;
			fVec11[0] = fTemp268;
			int iTemp269 = mydsp_faustpower2_f(fVec11[1] - fVec11[2]) <= fConst2;
			float fTemp270 = mydsp_faustpower2_f(fVec11[2] - fVec11[1]);
			float fTemp271 = std::sqrt(std::max<float>(0.0f, fVec11[2] + 1.0f));
			float fTemp272 = std::sqrt(std::max<float>(0.0f, fVec11[2] + -1.0f));
			float fTemp273 = fTemp272 * fTemp271;
			float fTemp274 = std::sqrt(std::max<float>(0.0f, fVec11[1] + 1.0f));
			float fTemp275 = std::sqrt(std::max<float>(0.0f, fVec11[1] + -1.0f));
			float fTemp276 = fTemp275 * fTemp274;
			float fTemp277 = fVec11[1] * fTemp275 * fTemp274 + std::log(std::max<float>(1.1920929e-07f, fVec11[1] + fTemp276));
			float fTemp278 = mydsp_faustpower2_f(fVec11[2]);
			float fTemp279 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fVec11[2])));
			float fTemp280 = mydsp_faustpower2_f(fVec11[1]);
			float fTemp281 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fVec11[1])));
			float fTemp282 = fTemp281 * fTemp280;
			float fTemp283 = fVec11[1] * fTemp281;
			float fTemp284 = 2.0f * fVec11[1];
			float fTemp285 = fTemp284 + fVec11[2];
			float fTemp286 = 0.33333334f * fTemp285;
			float fThen261 = (fVec11[2] * (fTemp276 + fVec11[2] * fTemp279 - (fTemp283 + fTemp273)) + 0.5f * (fTemp282 - fTemp279 * fTemp278) - 0.25f * (fTemp277 - (fVec11[2] * fTemp272 * fTemp271 + std::log(std::max<float>(1.1920929e-07f, fVec11[2] + fTemp273))))) / fTemp270;
			float fElse261 = 0.5f * acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp286)));
			float fTemp287 = fTemp268 - fVec11[1];
			float fTemp288 = mydsp_faustpower2_f(fTemp287);
			int iTemp289 = fTemp288 <= fConst2;
			float fTemp290 = mydsp_faustpower2_f(fTemp268);
			float fTemp291 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp268)));
			float fTemp292 = std::sqrt(std::max<float>(0.0f, fTemp268 + 1.0f));
			float fTemp293 = std::sqrt(std::max<float>(0.0f, fTemp268 + -1.0f));
			float fTemp294 = fTemp293 * fTemp292;
			float fTemp295 = fTemp268 + fTemp284;
			float fTemp296 = 0.33333334f * fTemp295;
			float fThen262 = (fSlow280 * fTemp267 * (fSlow280 * fTemp267 * fTemp291 + fTemp276 - (fTemp294 + fTemp283)) + 0.25f * (fSlow280 * fTemp267 * fTemp293 * fTemp292 + std::log(std::max<float>(1.1920929e-07f, fTemp268 + fTemp294)) - fTemp277) - 0.5f * (fTemp291 * fTemp290 - fTemp282)) / fTemp288;
			float fElse262 = 0.5f * acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp296)));
			float fTemp297 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp278));
			float fTemp298 = std::max<float>(-1.0f, std::min<float>(1.0f, fVec11[2]));
			float fTemp299 = std::asin(fTemp298);
			float fTemp300 = std::acos(fTemp298);
			float fTemp301 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp280));
			float fTemp302 = std::max<float>(-1.0f, std::min<float>(1.0f, fVec11[1]));
			float fTemp303 = std::asin(fTemp302);
			float fTemp304 = std::acos(fTemp302);
			float fTemp305 = 2.0f * fTemp280 * fTemp304 + fTemp303 - fTemp301;
			float fTemp306 = fVec11[1] * fTemp304;
			float fTemp307 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp286));
			float fThen263 = (fVec11[2] * (fTemp301 + fVec11[2] * fTemp300 - (fTemp306 + fTemp297)) + 0.25f * (fTemp305 - (2.0f * fTemp278 * fTemp300 + fTemp299 - fTemp297))) / fTemp270;
			float fElse263 = 0.5f * std::acos(fTemp307);
			float fTemp308 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp290));
			float fTemp309 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp268));
			float fTemp310 = std::asin(fTemp309);
			float fTemp311 = std::acos(fTemp309);
			float fTemp312 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp296));
			float fThen264 = (fSlow280 * fTemp267 * (fSlow280 * fTemp267 * fTemp311 + fTemp301 - (fTemp308 + fTemp306)) - 0.25f * (2.0f * fTemp290 * fTemp311 + fTemp310 - fTemp308 - fTemp305)) / fTemp288;
			float fElse264 = 0.5f * std::acos(fTemp312);
			float fThen265 = ((iTemp289) ? fElse262 : fThen262) + ((iTemp269) ? fElse261 : fThen261);
			float fElse265 = ((iTemp289) ? fElse264 : fThen264) + ((iTemp269) ? fElse263 : fThen263);
			float fTemp313 = 2.0f * fTemp278;
			float fTemp314 = 2.0f * fTemp280;
			float fTemp315 = fVec11[1] * fTemp301 + fTemp303 * (fTemp314 + -1.0f);
			float fTemp316 = fTemp301 + fVec11[1] * fTemp303;
			float fThen266 = (fVec11[2] * (fTemp297 + fVec11[2] * fTemp299 - fTemp316) + 0.25f * (fTemp315 - (fVec11[2] * fTemp297 + fTemp299 * (fTemp313 + -1.0f)))) / fTemp270;
			float fElse266 = 0.5f * std::asin(fTemp307);
			float fTemp317 = 2.0f * fTemp290;
			float fThen267 = (fSlow280 * fTemp267 * (fTemp308 + fSlow280 * fTemp267 * fTemp310 - fTemp316) - 0.25f * (fSlow280 * fTemp267 * fTemp308 + fTemp310 * (fTemp317 + -1.0f) - fTemp315)) / fTemp288;
			float fElse267 = 0.5f * std::asin(fTemp312);
			float fTemp318 = std::atan(fVec11[2]);
			float fTemp319 = std::atan(fVec11[1]);
			float fTemp320 = fTemp319 - (fVec11[1] - fTemp280 * fTemp319);
			float fTemp321 = fVec11[1] * fTemp319;
			float fTemp322 = fTemp278 + 1.0f;
			float fTemp323 = fTemp280 + 1.0f;
			float fTemp324 = std::log(fTemp323);
			float fThen268 = (fVec11[2] * (fVec11[2] * fTemp318 + 0.5f * (fTemp324 - std::log(fTemp322)) - fTemp321) + 0.5f * (fTemp320 - (fTemp318 - (fVec11[2] - fTemp278 * fTemp318)))) / fTemp270;
			float fElse268 = 0.5f * std::atan(fTemp286);
			float fTemp325 = std::atan(fTemp268);
			float fTemp326 = fTemp290 + 1.0f;
			float fThen269 = (fSlow280 * fTemp267 * (fSlow280 * fTemp267 * fTemp325 - (fTemp321 + 0.5f * (std::log(fTemp326) - fTemp324))) - 0.5f * (fTemp325 - (fTemp268 - fTemp290 * fTemp325) - fTemp320)) / fTemp288;
			float fElse269 = 0.5f * std::atan(fTemp296);
			float fThen270 = ((iTemp289) ? fElse267 : fThen267) + ((iTemp269) ? fElse266 : fThen266);
			float fElse270 = ((iTemp289) ? fElse269 : fThen269) + ((iTemp269) ? fElse268 : fThen268);
			float fThen271 = ((iSlow279) ? fElse265 : fThen265);
			float fElse271 = ((iSlow281) ? fElse270 : fThen270);
			float fTemp327 = std::sqrt(fTemp322);
			float fTemp328 = fVec11[2] * fTemp327;
			float fTemp329 = asinhf(fVec11[2]);
			float fTemp330 = std::sqrt(fTemp323);
			float fTemp331 = fVec11[1] * fTemp330;
			float fTemp332 = asinhf(fVec11[1]);
			float fTemp333 = fTemp332 * (fTemp314 + 1.0f) - fTemp331;
			float fTemp334 = fVec11[1] * fTemp332;
			float fThen272 = (fVec11[2] * (fTemp330 + fVec11[2] * fTemp329 - (fTemp334 + fTemp327)) + 0.25f * (fTemp333 - (fTemp329 * (fTemp313 + 1.0f) - fTemp328))) / fTemp270;
			float fElse272 = 0.5f * asinhf(fTemp286);
			float fTemp335 = std::sqrt(fTemp326);
			float fTemp336 = fSlow280 * fTemp267 * fTemp335;
			float fTemp337 = asinhf(fTemp268);
			float fThen273 = (fSlow280 * fTemp267 * (fSlow280 * fTemp267 * fTemp337 + fTemp330 - (fTemp335 + fTemp334)) - 0.25f * (fTemp337 * (fTemp317 + 1.0f) - fTemp336 - fTemp333)) / fTemp288;
			float fElse273 = 0.5f * asinhf(fTemp296);
			float fThen274 = ((iTemp289) ? fElse273 : fThen273) + ((iTemp269) ? fElse272 : fThen272);
			float fTemp338 = std::cos(fVec11[2]);
			float fTemp339 = std::sin(fVec11[2]);
			float fTemp340 = std::sin(fVec11[1]);
			float fTemp341 = std::cos(fVec11[1]);
			float fTemp342 = fVec11[1] * fTemp340 + fTemp341;
			float fThen275 = (fTemp342 + fVec11[2] * (fTemp339 - fTemp340 - fTemp339) - fTemp338) / fTemp270;
			float fElse275 = 0.5f * std::cos(fTemp286);
			float fTemp343 = std::cos(fTemp268);
			float fTemp344 = std::sin(fTemp268);
			float fThen276 = (fTemp342 + fSlow280 * fTemp267 * (fTemp344 - fTemp340 - fTemp344) - fTemp343) / fTemp288;
			float fElse276 = 0.5f * std::cos(fTemp296);
			float fThen277 = ((iSlow283) ? fTemp309 : fThen274);
			float fElse277 = ((iTemp289) ? fElse276 : fThen276) + ((iTemp269) ? fElse275 : fThen275);
			float fThen278 = ((iSlow278) ? fElse271 : fThen271);
			float fElse278 = ((iSlow282) ? fElse277 : fThen277);
			int iTemp345 = std::fabs(fTemp287) <= fConst2;
			float fTemp346 = 0.5f * fTemp280;
			float fThen279 = fTemp346 - 0.083333336f * mydsp_faustpower4_f(fVec11[1]);
			float fElse279 = 0.6666667f * fVec11[1];
			float fThen280 = ((fVec11[1] >= 1.0f) ? fElse279 : fThen279);
			float fElse280 = 0.33333334f * (0.0f - fTemp284);
			float fTemp347 = 0.5f * fTemp290;
			float fThen281 = fTemp347 - 0.083333336f * mydsp_faustpower4_f(fTemp268);
			float fElse281 = fSlow287 * fTemp267;
			float fThen282 = ((fTemp268 >= 1.0f) ? fElse281 : fThen281);
			float fElse282 = 0.33333334f * (0.0f - fSlow288 * fTemp267);
			float fTemp348 = 0.5f * (fTemp268 + fVec11[1]);
			float fThen283 = 0.6666667f * float((fTemp348 > 0.0f) - (fTemp348 < 0.0f));
			float fElse283 = fTemp348 - 0.33333334f * mydsp_faustpower3_f(fTemp348);
			float fThen284 = (((fTemp268 <= -1.0f) ? fElse282 : fThen282) - ((fVec11[1] <= -1.0f) ? fElse280 : fThen280)) / fTemp287;
			float fElse284 = (((fTemp348 < 1.0f) & (fTemp348 > -1.0f)) ? fElse283 : fThen283);
			int iTemp349 = (fVec11[2] <= 1.0f) & (fVec11[2] >= -1.0f);
			float fTemp350 = 0.5f * fTemp278;
			float fTemp351 = float((fVec11[2] > 0.0f) - (fVec11[2] < 0.0f));
			float fTemp352 = mydsp_faustpower3_f(fVec11[2]);
			float fThen285 = fTemp351 * (fTemp350 + -0.16666667f);
			float fElse285 = 0.33333334f * fTemp352;
			int iTemp353 = (fVec11[1] <= 1.0f) & (fVec11[1] >= -1.0f);
			float fTemp354 = float((fVec11[1] > 0.0f) - (fVec11[1] < 0.0f));
			float fTemp355 = fVec11[1] * fTemp354;
			float fThen286 = fTemp355 + -0.5f;
			float fTemp356 = ((iTemp353) ? fTemp346 : fThen286);
			float fTemp357 = fVec11[2] * fTemp351;
			float fThen287 = fTemp357 + -0.5f;
			float fTemp358 = mydsp_faustpower3_f(fVec11[1]);
			float fThen288 = fTemp354 * (fTemp346 + -0.16666667f);
			float fElse288 = 0.33333334f * fTemp358;
			float fTemp359 = ((iTemp353) ? fElse288 : fThen288);
			float fThen289 = (fTemp359 + fVec11[2] * (((iTemp349) ? fTemp350 : fThen287) - fTemp356) - ((iTemp349) ? fElse285 : fThen285)) / fTemp270;
			float fElse289 = 0.5f * fTemp307;
			int iTemp360 = (fTemp268 <= 1.0f) & (fTemp268 >= -1.0f);
			float fTemp361 = float((fTemp268 > 0.0f) - (fTemp268 < 0.0f));
			float fTemp362 = mydsp_faustpower3_f(fTemp268);
			float fThen290 = fTemp361 * (fTemp347 + -0.16666667f);
			float fElse290 = 0.33333334f * fTemp362;
			float fTemp363 = fTemp267 * fTemp361;
			float fTemp364 = fSlow280 * fTemp363;
			float fThen291 = fTemp364 + -0.5f;
			float fThen292 = (fSlow280 * fTemp267 * (((iTemp360) ? fTemp347 : fThen291) - fTemp356) + fTemp359 - ((iTemp360) ? fElse290 : fThen290)) / fTemp288;
			float fElse292 = 0.5f * fTemp312;
			float fThen293 = ((iTemp345) ? fElse284 : fThen284);
			float fElse293 = ((iTemp289) ? fElse292 : fThen292) + ((iTemp269) ? fElse289 : fThen289);
			float fTemp365 = std::fabs(fVec11[2]);
			float fTemp366 = std::log(fTemp365 + 1.0f);
			float fTemp367 = std::fabs(fVec11[1]);
			float fTemp368 = std::log(fTemp367 + 1.0f);
			float fTemp369 = fTemp354 * (0.5f * (fTemp280 + (3.0f - 2.0f * (fTemp367 - fTemp368))) + -1.5f);
			float fTemp370 = std::fabs(fTemp286);
			float fThen294 = (fTemp369 + fVec11[2] * (fTemp368 + fTemp365 - (fTemp367 + fTemp366)) - fTemp351 * (0.5f * (fTemp278 + (3.0f - 2.0f * (fTemp365 - fTemp366))) + -1.5f)) / fTemp270;
			float fElse294 = 0.16666667f * (fTemp285 / (fTemp370 + 1.0f));
			float fTemp371 = std::fabs(fTemp268);
			float fTemp372 = std::log(fTemp371 + 1.0f);
			float fTemp373 = std::fabs(fTemp296);
			float fThen295 = (fSlow280 * fTemp267 * (fTemp371 + fTemp368 - (fTemp372 + fTemp367)) + fTemp369 - fTemp361 * (0.5f * (fTemp290 + (3.0f - 2.0f * (fTemp371 - fTemp372))) + -1.5f)) / fTemp288;
			float fElse295 = 0.16666667f * (fTemp295 / (fTemp373 + 1.0f));
			int iTemp374 = fTemp365 <= 2.0f;
			float fThen296 = 0.5f * fTemp278 * fTemp351;
			float fElse296 = 0.020833334f * fTemp352 * (16.0f - 3.0f * fTemp357);
			int iTemp375 = fTemp367 <= 2.0f;
			float fElse297 = (0.0f - 0.083333336f * fTemp280) * (fTemp355 + -6.0f);
			float fTemp376 = ((iTemp375) ? fElse297 : fTemp367);
			float fElse298 = (0.0f - 0.083333336f * fTemp278) * (fTemp357 + -6.0f);
			float fThen299 = 0.5f * fTemp280 * fTemp354;
			float fElse299 = 0.020833334f * fTemp358 * (16.0f - 3.0f * fTemp355);
			float fTemp377 = ((iTemp375) ? fElse299 : fThen299);
			float fThen300 = float((fTemp286 > 0.0f) - (fTemp286 < 0.0f));
			float fElse300 = 0.33333334f * fTemp285 * (1.0f - 0.25f * fTemp370);
			float fThen301 = (fTemp377 + fVec11[2] * (((iTemp374) ? fElse298 : fTemp365) - fTemp376) - ((iTemp374) ? fElse296 : fThen296)) / fTemp270;
			float fElse301 = 0.5f * ((fTemp370 <= 2.0f) ? fElse300 : fThen300);
			int iTemp378 = fTemp371 <= 2.0f;
			float fThen302 = 0.5f * fTemp290 * fTemp361;
			float fElse302 = 0.020833334f * fTemp362 * (16.0f - fSlow290 * fTemp363);
			float fElse303 = (0.0f - 0.083333336f * fTemp290) * (fTemp364 + -6.0f);
			float fThen304 = float((fTemp296 > 0.0f) - (fTemp296 < 0.0f));
			float fElse304 = 0.33333334f * fTemp295 * (1.0f - 0.25f * fTemp373);
			float fThen305 = (fSlow280 * fTemp267 * (((iTemp378) ? fElse303 : fTemp371) - fTemp376) + fTemp377 - ((iTemp378) ? fElse302 : fThen302)) / fTemp288;
			float fElse305 = 0.5f * ((fTemp373 <= 2.0f) ? fElse304 : fThen304);
			float fThen306 = ((iTemp289) ? fElse295 : fThen295) + ((iTemp269) ? fElse294 : fThen294);
			float fElse306 = ((iTemp289) ? fElse305 : fThen305) + ((iTemp269) ? fElse301 : fThen301);
			float fThen307 = ((iSlow286) ? fElse293 : fThen293);
			float fElse307 = ((iSlow289) ? fElse306 : fThen306);
			float fTemp379 = fTemp332 - fTemp331;
			float fThen308 = (fVec11[2] * (fTemp327 - fTemp330) - 0.5f * (fTemp379 - (fTemp329 - fTemp328))) / fTemp270;
			float fElse308 = 0.16666667f * (fTemp285 / std::sqrt(mydsp_faustpower2_f(fTemp286) + 1.0f));
			float fThen309 = (fSlow280 * fTemp267 * (fTemp335 - fTemp330) + 0.5f * (fTemp337 - fTemp336 - fTemp379)) / fTemp288;
			float fElse309 = 0.16666667f * (fTemp295 / std::sqrt(mydsp_faustpower2_f(fTemp296) + 1.0f));
			float fTemp380 = fVec11[1] * fTemp341;
			float fThen310 = (fTemp340 + fVec11[2] * (fTemp338 + (fTemp341 - fTemp338)) - (fTemp339 + fTemp380)) / fTemp270;
			float fElse310 = 0.5f * std::sin(fTemp286);
			float fThen311 = (fTemp340 + fSlow280 * fTemp267 * (fTemp343 + (fTemp341 - fTemp343)) - (fTemp344 + fTemp380)) / fTemp288;
			float fElse311 = 0.5f * std::sin(fTemp296);
			float fThen312 = ((iTemp289) ? fElse309 : fThen309) + ((iTemp269) ? fElse308 : fThen308);
			float fElse312 = ((iTemp289) ? fElse311 : fThen311) + ((iTemp269) ? fElse310 : fThen310);
			float fThen313 = (std::log(std::min<float>(3.4028235e+38f, coshf(fTemp268))) - std::log(std::min<float>(3.4028235e+38f, coshf(fVec11[1])))) / fTemp287;
			float fElse313 = tanhf(fTemp348);
			float fThen314 = ((iSlow292) ? fElse312 : fThen312);
			float fElse314 = ((iTemp345) ? fElse313 : fThen313);
			float fThen315 = ((iSlow285) ? fElse307 : fThen307);
			float fElse315 = ((iSlow291) ? fElse314 : fThen314);
			float fThen316 = ((iSlow277) ? fElse278 : fThen278);
			float fElse316 = ((iSlow284) ? fElse315 : fThen315);
			float fTemp381 = ((iSlow276) ? fElse316 : fThen316);
			float fTemp382 = fSlow293 * fTemp381;
			fVec12[0] = fTemp382;
			int iTemp383 = mydsp_faustpower2_f(fVec12[1] - fVec12[2]) <= fConst2;
			float fTemp384 = mydsp_faustpower2_f(fVec12[2] - fVec12[1]);
			float fTemp385 = std::sqrt(std::max<float>(0.0f, fVec12[2] + 1.0f));
			float fTemp386 = std::sqrt(std::max<float>(0.0f, fVec12[2] + -1.0f));
			float fTemp387 = fTemp386 * fTemp385;
			float fTemp388 = std::sqrt(std::max<float>(0.0f, fVec12[1] + 1.0f));
			float fTemp389 = std::sqrt(std::max<float>(0.0f, fVec12[1] + -1.0f));
			float fTemp390 = fTemp389 * fTemp388;
			float fTemp391 = fVec12[1] * fTemp389 * fTemp388 + std::log(std::max<float>(1.1920929e-07f, fVec12[1] + fTemp390));
			float fTemp392 = mydsp_faustpower2_f(fVec12[2]);
			float fTemp393 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fVec12[2])));
			float fTemp394 = mydsp_faustpower2_f(fVec12[1]);
			float fTemp395 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fVec12[1])));
			float fTemp396 = fTemp395 * fTemp394;
			float fTemp397 = fVec12[1] * fTemp395;
			float fTemp398 = 2.0f * fVec12[1];
			float fTemp399 = fTemp398 + fVec12[2];
			float fTemp400 = 0.33333334f * fTemp399;
			float fThen317 = (fVec12[2] * (fTemp390 + fVec12[2] * fTemp393 - (fTemp397 + fTemp387)) + 0.5f * (fTemp396 - fTemp393 * fTemp392) - 0.25f * (fTemp391 - (fVec12[2] * fTemp386 * fTemp385 + std::log(std::max<float>(1.1920929e-07f, fVec12[2] + fTemp387))))) / fTemp384;
			float fElse317 = 0.5f * acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp400)));
			float fTemp401 = fTemp382 - fVec12[1];
			float fTemp402 = mydsp_faustpower2_f(fTemp401);
			int iTemp403 = fTemp402 <= fConst2;
			float fTemp404 = mydsp_faustpower2_f(fTemp382);
			float fTemp405 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp382)));
			float fTemp406 = std::sqrt(std::max<float>(0.0f, fTemp382 + 1.0f));
			float fTemp407 = std::sqrt(std::max<float>(0.0f, fTemp382 + -1.0f));
			float fTemp408 = fTemp407 * fTemp406;
			float fTemp409 = fTemp382 + fTemp398;
			float fTemp410 = 0.33333334f * fTemp409;
			float fThen318 = (fSlow293 * fTemp381 * (fSlow293 * fTemp381 * fTemp405 + fTemp390 - (fTemp408 + fTemp397)) + 0.25f * (fSlow293 * fTemp381 * fTemp407 * fTemp406 + std::log(std::max<float>(1.1920929e-07f, fTemp382 + fTemp408)) - fTemp391) - 0.5f * (fTemp405 * fTemp404 - fTemp396)) / fTemp402;
			float fElse318 = 0.5f * acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp410)));
			float fTemp411 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp392));
			float fTemp412 = std::max<float>(-1.0f, std::min<float>(1.0f, fVec12[2]));
			float fTemp413 = std::asin(fTemp412);
			float fTemp414 = std::acos(fTemp412);
			float fTemp415 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp394));
			float fTemp416 = std::max<float>(-1.0f, std::min<float>(1.0f, fVec12[1]));
			float fTemp417 = std::asin(fTemp416);
			float fTemp418 = std::acos(fTemp416);
			float fTemp419 = 2.0f * fTemp394 * fTemp418 + fTemp417 - fTemp415;
			float fTemp420 = fVec12[1] * fTemp418;
			float fTemp421 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp400));
			float fThen319 = (fVec12[2] * (fTemp415 + fVec12[2] * fTemp414 - (fTemp420 + fTemp411)) + 0.25f * (fTemp419 - (2.0f * fTemp392 * fTemp414 + fTemp413 - fTemp411))) / fTemp384;
			float fElse319 = 0.5f * std::acos(fTemp421);
			float fTemp422 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp404));
			float fTemp423 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp382));
			float fTemp424 = std::asin(fTemp423);
			float fTemp425 = std::acos(fTemp423);
			float fTemp426 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp410));
			float fThen320 = (fSlow293 * fTemp381 * (fSlow293 * fTemp381 * fTemp425 + fTemp415 - (fTemp422 + fTemp420)) - 0.25f * (2.0f * fTemp404 * fTemp425 + fTemp424 - fTemp422 - fTemp419)) / fTemp402;
			float fElse320 = 0.5f * std::acos(fTemp426);
			float fThen321 = ((iTemp403) ? fElse318 : fThen318) + ((iTemp383) ? fElse317 : fThen317);
			float fElse321 = ((iTemp403) ? fElse320 : fThen320) + ((iTemp383) ? fElse319 : fThen319);
			float fTemp427 = 2.0f * fTemp392;
			float fTemp428 = 2.0f * fTemp394;
			float fTemp429 = fVec12[1] * fTemp415 + fTemp417 * (fTemp428 + -1.0f);
			float fTemp430 = fTemp415 + fVec12[1] * fTemp417;
			float fThen322 = (fVec12[2] * (fTemp411 + fVec12[2] * fTemp413 - fTemp430) + 0.25f * (fTemp429 - (fVec12[2] * fTemp411 + fTemp413 * (fTemp427 + -1.0f)))) / fTemp384;
			float fElse322 = 0.5f * std::asin(fTemp421);
			float fTemp431 = 2.0f * fTemp404;
			float fThen323 = (fSlow293 * fTemp381 * (fTemp422 + fSlow293 * fTemp381 * fTemp424 - fTemp430) - 0.25f * (fSlow293 * fTemp381 * fTemp422 + fTemp424 * (fTemp431 + -1.0f) - fTemp429)) / fTemp402;
			float fElse323 = 0.5f * std::asin(fTemp426);
			float fTemp432 = std::atan(fVec12[2]);
			float fTemp433 = std::atan(fVec12[1]);
			float fTemp434 = fTemp433 - (fVec12[1] - fTemp394 * fTemp433);
			float fTemp435 = fVec12[1] * fTemp433;
			float fTemp436 = fTemp392 + 1.0f;
			float fTemp437 = fTemp394 + 1.0f;
			float fTemp438 = std::log(fTemp437);
			float fThen324 = (fVec12[2] * (fVec12[2] * fTemp432 + 0.5f * (fTemp438 - std::log(fTemp436)) - fTemp435) + 0.5f * (fTemp434 - (fTemp432 - (fVec12[2] - fTemp392 * fTemp432)))) / fTemp384;
			float fElse324 = 0.5f * std::atan(fTemp400);
			float fTemp439 = std::atan(fTemp382);
			float fTemp440 = fTemp404 + 1.0f;
			float fThen325 = (fSlow293 * fTemp381 * (fSlow293 * fTemp381 * fTemp439 - (fTemp435 + 0.5f * (std::log(fTemp440) - fTemp438))) - 0.5f * (fTemp439 - (fTemp382 - fTemp404 * fTemp439) - fTemp434)) / fTemp402;
			float fElse325 = 0.5f * std::atan(fTemp410);
			float fThen326 = ((iTemp403) ? fElse323 : fThen323) + ((iTemp383) ? fElse322 : fThen322);
			float fElse326 = ((iTemp403) ? fElse325 : fThen325) + ((iTemp383) ? fElse324 : fThen324);
			float fThen327 = ((iSlow274) ? fElse321 : fThen321);
			float fElse327 = ((iSlow294) ? fElse326 : fThen326);
			float fTemp441 = std::sqrt(fTemp436);
			float fTemp442 = fVec12[2] * fTemp441;
			float fTemp443 = asinhf(fVec12[2]);
			float fTemp444 = std::sqrt(fTemp437);
			float fTemp445 = fVec12[1] * fTemp444;
			float fTemp446 = asinhf(fVec12[1]);
			float fTemp447 = fTemp446 * (fTemp428 + 1.0f) - fTemp445;
			float fTemp448 = fVec12[1] * fTemp446;
			float fThen328 = (fVec12[2] * (fTemp444 + fVec12[2] * fTemp443 - (fTemp448 + fTemp441)) + 0.25f * (fTemp447 - (fTemp443 * (fTemp427 + 1.0f) - fTemp442))) / fTemp384;
			float fElse328 = 0.5f * asinhf(fTemp400);
			float fTemp449 = std::sqrt(fTemp440);
			float fTemp450 = fSlow293 * fTemp381 * fTemp449;
			float fTemp451 = asinhf(fTemp382);
			float fThen329 = (fSlow293 * fTemp381 * (fSlow293 * fTemp381 * fTemp451 + fTemp444 - (fTemp449 + fTemp448)) - 0.25f * (fTemp451 * (fTemp431 + 1.0f) - fTemp450 - fTemp447)) / fTemp402;
			float fElse329 = 0.5f * asinhf(fTemp410);
			float fThen330 = ((iTemp403) ? fElse329 : fThen329) + ((iTemp383) ? fElse328 : fThen328);
			float fTemp452 = std::cos(fVec12[2]);
			float fTemp453 = std::sin(fVec12[2]);
			float fTemp454 = std::sin(fVec12[1]);
			float fTemp455 = std::cos(fVec12[1]);
			float fTemp456 = fVec12[1] * fTemp454 + fTemp455;
			float fThen331 = (fTemp456 + fVec12[2] * (fTemp453 - fTemp454 - fTemp453) - fTemp452) / fTemp384;
			float fElse331 = 0.5f * std::cos(fTemp400);
			float fTemp457 = std::cos(fTemp382);
			float fTemp458 = std::sin(fTemp382);
			float fThen332 = (fTemp456 + fSlow293 * fTemp381 * (fTemp458 - fTemp454 - fTemp458) - fTemp457) / fTemp402;
			float fElse332 = 0.5f * std::cos(fTemp410);
			float fThen333 = ((iSlow296) ? fTemp423 : fThen330);
			float fElse333 = ((iTemp403) ? fElse332 : fThen332) + ((iTemp383) ? fElse331 : fThen331);
			float fThen334 = ((iSlow273) ? fElse327 : fThen327);
			float fElse334 = ((iSlow295) ? fElse333 : fThen333);
			int iTemp459 = std::fabs(fTemp401) <= fConst2;
			float fTemp460 = 0.5f * fTemp394;
			float fThen335 = fTemp460 - 0.083333336f * mydsp_faustpower4_f(fVec12[1]);
			float fElse335 = 0.6666667f * fVec12[1];
			float fThen336 = ((fVec12[1] >= 1.0f) ? fElse335 : fThen335);
			float fElse336 = 0.33333334f * (0.0f - fTemp398);
			float fTemp461 = 0.5f * fTemp404;
			float fThen337 = fTemp461 - 0.083333336f * mydsp_faustpower4_f(fTemp382);
			float fElse337 = fSlow300 * fTemp381;
			float fThen338 = ((fTemp382 >= 1.0f) ? fElse337 : fThen337);
			float fElse338 = 0.33333334f * (0.0f - fSlow301 * fTemp381);
			float fTemp462 = 0.5f * (fTemp382 + fVec12[1]);
			float fThen339 = 0.6666667f * float((fTemp462 > 0.0f) - (fTemp462 < 0.0f));
			float fElse339 = fTemp462 - 0.33333334f * mydsp_faustpower3_f(fTemp462);
			float fThen340 = (((fTemp382 <= -1.0f) ? fElse338 : fThen338) - ((fVec12[1] <= -1.0f) ? fElse336 : fThen336)) / fTemp401;
			float fElse340 = (((fTemp462 < 1.0f) & (fTemp462 > -1.0f)) ? fElse339 : fThen339);
			int iTemp463 = (fVec12[2] <= 1.0f) & (fVec12[2] >= -1.0f);
			float fTemp464 = 0.5f * fTemp392;
			float fTemp465 = float((fVec12[2] > 0.0f) - (fVec12[2] < 0.0f));
			float fTemp466 = mydsp_faustpower3_f(fVec12[2]);
			float fThen341 = fTemp465 * (fTemp464 + -0.16666667f);
			float fElse341 = 0.33333334f * fTemp466;
			int iTemp467 = (fVec12[1] <= 1.0f) & (fVec12[1] >= -1.0f);
			float fTemp468 = float((fVec12[1] > 0.0f) - (fVec12[1] < 0.0f));
			float fTemp469 = fVec12[1] * fTemp468;
			float fThen342 = fTemp469 + -0.5f;
			float fTemp470 = ((iTemp467) ? fTemp460 : fThen342);
			float fTemp471 = fVec12[2] * fTemp465;
			float fThen343 = fTemp471 + -0.5f;
			float fTemp472 = mydsp_faustpower3_f(fVec12[1]);
			float fThen344 = fTemp468 * (fTemp460 + -0.16666667f);
			float fElse344 = 0.33333334f * fTemp472;
			float fTemp473 = ((iTemp467) ? fElse344 : fThen344);
			float fThen345 = (fTemp473 + fVec12[2] * (((iTemp463) ? fTemp464 : fThen343) - fTemp470) - ((iTemp463) ? fElse341 : fThen341)) / fTemp384;
			float fElse345 = 0.5f * fTemp421;
			int iTemp474 = (fTemp382 <= 1.0f) & (fTemp382 >= -1.0f);
			float fTemp475 = float((fTemp382 > 0.0f) - (fTemp382 < 0.0f));
			float fTemp476 = mydsp_faustpower3_f(fTemp382);
			float fThen346 = fTemp475 * (fTemp461 + -0.16666667f);
			float fElse346 = 0.33333334f * fTemp476;
			float fTemp477 = fTemp381 * fTemp475;
			float fTemp478 = fSlow293 * fTemp477;
			float fThen347 = fTemp478 + -0.5f;
			float fThen348 = (fSlow293 * fTemp381 * (((iTemp474) ? fTemp461 : fThen347) - fTemp470) + fTemp473 - ((iTemp474) ? fElse346 : fThen346)) / fTemp402;
			float fElse348 = 0.5f * fTemp426;
			float fThen349 = ((iTemp459) ? fElse340 : fThen340);
			float fElse349 = ((iTemp403) ? fElse348 : fThen348) + ((iTemp383) ? fElse345 : fThen345);
			float fTemp479 = std::fabs(fVec12[2]);
			float fTemp480 = std::log(fTemp479 + 1.0f);
			float fTemp481 = std::fabs(fVec12[1]);
			float fTemp482 = std::log(fTemp481 + 1.0f);
			float fTemp483 = fTemp468 * (0.5f * (fTemp394 + (3.0f - 2.0f * (fTemp481 - fTemp482))) + -1.5f);
			float fTemp484 = std::fabs(fTemp400);
			float fThen350 = (fTemp483 + fVec12[2] * (fTemp482 + fTemp479 - (fTemp481 + fTemp480)) - fTemp465 * (0.5f * (fTemp392 + (3.0f - 2.0f * (fTemp479 - fTemp480))) + -1.5f)) / fTemp384;
			float fElse350 = 0.16666667f * (fTemp399 / (fTemp484 + 1.0f));
			float fTemp485 = std::fabs(fTemp382);
			float fTemp486 = std::log(fTemp485 + 1.0f);
			float fTemp487 = std::fabs(fTemp410);
			float fThen351 = (fSlow293 * fTemp381 * (fTemp485 + fTemp482 - (fTemp486 + fTemp481)) + fTemp483 - fTemp475 * (0.5f * (fTemp404 + (3.0f - 2.0f * (fTemp485 - fTemp486))) + -1.5f)) / fTemp402;
			float fElse351 = 0.16666667f * (fTemp409 / (fTemp487 + 1.0f));
			int iTemp488 = fTemp479 <= 2.0f;
			float fThen352 = 0.5f * fTemp392 * fTemp465;
			float fElse352 = 0.020833334f * fTemp466 * (16.0f - 3.0f * fTemp471);
			int iTemp489 = fTemp481 <= 2.0f;
			float fElse353 = (0.0f - 0.083333336f * fTemp394) * (fTemp469 + -6.0f);
			float fTemp490 = ((iTemp489) ? fElse353 : fTemp481);
			float fElse354 = (0.0f - 0.083333336f * fTemp392) * (fTemp471 + -6.0f);
			float fThen355 = 0.5f * fTemp394 * fTemp468;
			float fElse355 = 0.020833334f * fTemp472 * (16.0f - 3.0f * fTemp469);
			float fTemp491 = ((iTemp489) ? fElse355 : fThen355);
			float fThen356 = float((fTemp400 > 0.0f) - (fTemp400 < 0.0f));
			float fElse356 = 0.33333334f * fTemp399 * (1.0f - 0.25f * fTemp484);
			float fThen357 = (fTemp491 + fVec12[2] * (((iTemp488) ? fElse354 : fTemp479) - fTemp490) - ((iTemp488) ? fElse352 : fThen352)) / fTemp384;
			float fElse357 = 0.5f * ((fTemp484 <= 2.0f) ? fElse356 : fThen356);
			int iTemp492 = fTemp485 <= 2.0f;
			float fThen358 = 0.5f * fTemp404 * fTemp475;
			float fElse358 = 0.020833334f * fTemp476 * (16.0f - fSlow303 * fTemp477);
			float fElse359 = (0.0f - 0.083333336f * fTemp404) * (fTemp478 + -6.0f);
			float fThen360 = float((fTemp410 > 0.0f) - (fTemp410 < 0.0f));
			float fElse360 = 0.33333334f * fTemp409 * (1.0f - 0.25f * fTemp487);
			float fThen361 = (fSlow293 * fTemp381 * (((iTemp492) ? fElse359 : fTemp485) - fTemp490) + fTemp491 - ((iTemp492) ? fElse358 : fThen358)) / fTemp402;
			float fElse361 = 0.5f * ((fTemp487 <= 2.0f) ? fElse360 : fThen360);
			float fThen362 = ((iTemp403) ? fElse351 : fThen351) + ((iTemp383) ? fElse350 : fThen350);
			float fElse362 = ((iTemp403) ? fElse361 : fThen361) + ((iTemp383) ? fElse357 : fThen357);
			float fThen363 = ((iSlow299) ? fElse349 : fThen349);
			float fElse363 = ((iSlow302) ? fElse362 : fThen362);
			float fTemp493 = fTemp446 - fTemp445;
			float fThen364 = (fVec12[2] * (fTemp441 - fTemp444) - 0.5f * (fTemp493 - (fTemp443 - fTemp442))) / fTemp384;
			float fElse364 = 0.16666667f * (fTemp399 / std::sqrt(mydsp_faustpower2_f(fTemp400) + 1.0f));
			float fThen365 = (fSlow293 * fTemp381 * (fTemp449 - fTemp444) + 0.5f * (fTemp451 - fTemp450 - fTemp493)) / fTemp402;
			float fElse365 = 0.16666667f * (fTemp409 / std::sqrt(mydsp_faustpower2_f(fTemp410) + 1.0f));
			float fTemp494 = fVec12[1] * fTemp455;
			float fThen366 = (fTemp454 + fVec12[2] * (fTemp452 + (fTemp455 - fTemp452)) - (fTemp453 + fTemp494)) / fTemp384;
			float fElse366 = 0.5f * std::sin(fTemp400);
			float fThen367 = (fTemp454 + fSlow293 * fTemp381 * (fTemp457 + (fTemp455 - fTemp457)) - (fTemp458 + fTemp494)) / fTemp402;
			float fElse367 = 0.5f * std::sin(fTemp410);
			float fThen368 = ((iTemp403) ? fElse365 : fThen365) + ((iTemp383) ? fElse364 : fThen364);
			float fElse368 = ((iTemp403) ? fElse367 : fThen367) + ((iTemp383) ? fElse366 : fThen366);
			float fThen369 = (std::log(std::min<float>(3.4028235e+38f, coshf(fTemp382))) - std::log(std::min<float>(3.4028235e+38f, coshf(fVec12[1])))) / fTemp401;
			float fElse369 = tanhf(fTemp462);
			float fThen370 = ((iSlow305) ? fElse368 : fThen368);
			float fElse370 = ((iTemp459) ? fElse369 : fThen369);
			float fThen371 = ((iSlow298) ? fElse363 : fThen363);
			float fElse371 = ((iSlow304) ? fElse370 : fThen370);
			float fThen372 = ((iSlow272) ? fElse334 : fThen334);
			float fElse372 = ((iSlow297) ? fElse371 : fThen371);
			float fTemp495 = ((iSlow271) ? fElse372 : fThen372);
			float fTemp496 = fSlow306 * fTemp495;
			fVec13[0] = fTemp496;
			int iTemp497 = mydsp_faustpower2_f(fVec13[1] - fVec13[2]) <= fConst2;
			float fTemp498 = mydsp_faustpower2_f(fVec13[2] - fVec13[1]);
			float fTemp499 = std::sqrt(std::max<float>(0.0f, fVec13[2] + 1.0f));
			float fTemp500 = std::sqrt(std::max<float>(0.0f, fVec13[2] + -1.0f));
			float fTemp501 = fTemp500 * fTemp499;
			float fTemp502 = std::sqrt(std::max<float>(0.0f, fVec13[1] + 1.0f));
			float fTemp503 = std::sqrt(std::max<float>(0.0f, fVec13[1] + -1.0f));
			float fTemp504 = fTemp503 * fTemp502;
			float fTemp505 = fVec13[1] * fTemp503 * fTemp502 + std::log(std::max<float>(1.1920929e-07f, fVec13[1] + fTemp504));
			float fTemp506 = mydsp_faustpower2_f(fVec13[2]);
			float fTemp507 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fVec13[2])));
			float fTemp508 = mydsp_faustpower2_f(fVec13[1]);
			float fTemp509 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fVec13[1])));
			float fTemp510 = fTemp509 * fTemp508;
			float fTemp511 = fVec13[1] * fTemp509;
			float fTemp512 = 2.0f * fVec13[1];
			float fTemp513 = fTemp512 + fVec13[2];
			float fTemp514 = 0.33333334f * fTemp513;
			float fThen373 = (fVec13[2] * (fTemp504 + fVec13[2] * fTemp507 - (fTemp511 + fTemp501)) + 0.5f * (fTemp510 - fTemp507 * fTemp506) - 0.25f * (fTemp505 - (fVec13[2] * fTemp500 * fTemp499 + std::log(std::max<float>(1.1920929e-07f, fVec13[2] + fTemp501))))) / fTemp498;
			float fElse373 = 0.5f * acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp514)));
			float fTemp515 = fTemp496 - fVec13[1];
			float fTemp516 = mydsp_faustpower2_f(fTemp515);
			int iTemp517 = fTemp516 <= fConst2;
			float fTemp518 = mydsp_faustpower2_f(fTemp496);
			float fTemp519 = acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp496)));
			float fTemp520 = std::sqrt(std::max<float>(0.0f, fTemp496 + 1.0f));
			float fTemp521 = std::sqrt(std::max<float>(0.0f, fTemp496 + -1.0f));
			float fTemp522 = fTemp521 * fTemp520;
			float fTemp523 = fTemp496 + fTemp512;
			float fTemp524 = 0.33333334f * fTemp523;
			float fThen374 = (fSlow306 * fTemp495 * (fSlow306 * fTemp495 * fTemp519 + fTemp504 - (fTemp522 + fTemp511)) + 0.25f * (fSlow306 * fTemp495 * fTemp521 * fTemp520 + std::log(std::max<float>(1.1920929e-07f, fTemp496 + fTemp522)) - fTemp505) - 0.5f * (fTemp519 * fTemp518 - fTemp510)) / fTemp516;
			float fElse374 = 0.5f * acoshf(std::max<float>(1.0f, std::min<float>(3.4028235e+38f, fTemp524)));
			float fTemp525 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp506));
			float fTemp526 = std::max<float>(-1.0f, std::min<float>(1.0f, fVec13[2]));
			float fTemp527 = std::asin(fTemp526);
			float fTemp528 = std::acos(fTemp526);
			float fTemp529 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp508));
			float fTemp530 = std::max<float>(-1.0f, std::min<float>(1.0f, fVec13[1]));
			float fTemp531 = std::asin(fTemp530);
			float fTemp532 = std::acos(fTemp530);
			float fTemp533 = 2.0f * fTemp508 * fTemp532 + fTemp531 - fTemp529;
			float fTemp534 = fVec13[1] * fTemp532;
			float fTemp535 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp514));
			float fThen375 = (fVec13[2] * (fTemp529 + fVec13[2] * fTemp528 - (fTemp534 + fTemp525)) + 0.25f * (fTemp533 - (2.0f * fTemp506 * fTemp528 + fTemp527 - fTemp525))) / fTemp498;
			float fElse375 = 0.5f * std::acos(fTemp535);
			float fTemp536 = std::sqrt(std::max<float>(0.0f, 1.0f - fTemp518));
			float fTemp537 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp496));
			float fTemp538 = std::asin(fTemp537);
			float fTemp539 = std::acos(fTemp537);
			float fTemp540 = std::max<float>(-1.0f, std::min<float>(1.0f, fTemp524));
			float fThen376 = (fSlow306 * fTemp495 * (fSlow306 * fTemp495 * fTemp539 + fTemp529 - (fTemp536 + fTemp534)) - 0.25f * (2.0f * fTemp518 * fTemp539 + fTemp538 - fTemp536 - fTemp533)) / fTemp516;
			float fElse376 = 0.5f * std::acos(fTemp540);
			float fThen377 = ((iTemp517) ? fElse374 : fThen374) + ((iTemp497) ? fElse373 : fThen373);
			float fElse377 = ((iTemp517) ? fElse376 : fThen376) + ((iTemp497) ? fElse375 : fThen375);
			float fTemp541 = 2.0f * fTemp506;
			float fTemp542 = 2.0f * fTemp508;
			float fTemp543 = fVec13[1] * fTemp529 + fTemp531 * (fTemp542 + -1.0f);
			float fTemp544 = fTemp529 + fVec13[1] * fTemp531;
			float fThen378 = (fVec13[2] * (fTemp525 + fVec13[2] * fTemp527 - fTemp544) + 0.25f * (fTemp543 - (fVec13[2] * fTemp525 + fTemp527 * (fTemp541 + -1.0f)))) / fTemp498;
			float fElse378 = 0.5f * std::asin(fTemp535);
			float fTemp545 = 2.0f * fTemp518;
			float fThen379 = (fSlow306 * fTemp495 * (fTemp536 + fSlow306 * fTemp495 * fTemp538 - fTemp544) - 0.25f * (fSlow306 * fTemp495 * fTemp536 + fTemp538 * (fTemp545 + -1.0f) - fTemp543)) / fTemp516;
			float fElse379 = 0.5f * std::asin(fTemp540);
			float fTemp546 = std::atan(fVec13[2]);
			float fTemp547 = std::atan(fVec13[1]);
			float fTemp548 = fTemp547 - (fVec13[1] - fTemp508 * fTemp547);
			float fTemp549 = fVec13[1] * fTemp547;
			float fTemp550 = fTemp506 + 1.0f;
			float fTemp551 = fTemp508 + 1.0f;
			float fTemp552 = std::log(fTemp551);
			float fThen380 = (fVec13[2] * (fVec13[2] * fTemp546 + 0.5f * (fTemp552 - std::log(fTemp550)) - fTemp549) + 0.5f * (fTemp548 - (fTemp546 - (fVec13[2] - fTemp506 * fTemp546)))) / fTemp498;
			float fElse380 = 0.5f * std::atan(fTemp514);
			float fTemp553 = std::atan(fTemp496);
			float fTemp554 = fTemp518 + 1.0f;
			float fThen381 = (fSlow306 * fTemp495 * (fSlow306 * fTemp495 * fTemp553 - (fTemp549 + 0.5f * (std::log(fTemp554) - fTemp552))) - 0.5f * (fTemp553 - (fTemp496 - fTemp518 * fTemp553) - fTemp548)) / fTemp516;
			float fElse381 = 0.5f * std::atan(fTemp524);
			float fThen382 = ((iTemp517) ? fElse379 : fThen379) + ((iTemp497) ? fElse378 : fThen378);
			float fElse382 = ((iTemp517) ? fElse381 : fThen381) + ((iTemp497) ? fElse380 : fThen380);
			float fThen383 = ((iSlow269) ? fElse377 : fThen377);
			float fElse383 = ((iSlow307) ? fElse382 : fThen382);
			float fTemp555 = std::sqrt(fTemp550);
			float fTemp556 = fVec13[2] * fTemp555;
			float fTemp557 = asinhf(fVec13[2]);
			float fTemp558 = std::sqrt(fTemp551);
			float fTemp559 = fVec13[1] * fTemp558;
			float fTemp560 = asinhf(fVec13[1]);
			float fTemp561 = fTemp560 * (fTemp542 + 1.0f) - fTemp559;
			float fTemp562 = fVec13[1] * fTemp560;
			float fThen384 = (fVec13[2] * (fTemp558 + fVec13[2] * fTemp557 - (fTemp562 + fTemp555)) + 0.25f * (fTemp561 - (fTemp557 * (fTemp541 + 1.0f) - fTemp556))) / fTemp498;
			float fElse384 = 0.5f * asinhf(fTemp514);
			float fTemp563 = std::sqrt(fTemp554);
			float fTemp564 = fSlow306 * fTemp495 * fTemp563;
			float fTemp565 = asinhf(fTemp496);
			float fThen385 = (fSlow306 * fTemp495 * (fSlow306 * fTemp495 * fTemp565 + fTemp558 - (fTemp563 + fTemp562)) - 0.25f * (fTemp565 * (fTemp545 + 1.0f) - fTemp564 - fTemp561)) / fTemp516;
			float fElse385 = 0.5f * asinhf(fTemp524);
			float fThen386 = ((iTemp517) ? fElse385 : fThen385) + ((iTemp497) ? fElse384 : fThen384);
			float fTemp566 = std::cos(fVec13[2]);
			float fTemp567 = std::sin(fVec13[2]);
			float fTemp568 = std::sin(fVec13[1]);
			float fTemp569 = std::cos(fVec13[1]);
			float fTemp570 = fVec13[1] * fTemp568 + fTemp569;
			float fThen387 = (fTemp570 + fVec13[2] * (fTemp567 - fTemp568 - fTemp567) - fTemp566) / fTemp498;
			float fElse387 = 0.5f * std::cos(fTemp514);
			float fTemp571 = std::cos(fTemp496);
			float fTemp572 = std::sin(fTemp496);
			float fThen388 = (fTemp570 + fSlow306 * fTemp495 * (fTemp572 - fTemp568 - fTemp572) - fTemp571) / fTemp516;
			float fElse388 = 0.5f * std::cos(fTemp524);
			float fThen389 = ((iSlow309) ? fTemp537 : fThen386);
			float fElse389 = ((iTemp517) ? fElse388 : fThen388) + ((iTemp497) ? fElse387 : fThen387);
			float fThen390 = ((iSlow268) ? fElse383 : fThen383);
			float fElse390 = ((iSlow308) ? fElse389 : fThen389);
			int iTemp573 = std::fabs(fTemp515) <= fConst2;
			float fTemp574 = 0.5f * fTemp508;
			float fThen391 = fTemp574 - 0.083333336f * mydsp_faustpower4_f(fVec13[1]);
			float fElse391 = 0.6666667f * fVec13[1];
			float fThen392 = ((fVec13[1] >= 1.0f) ? fElse391 : fThen391);
			float fElse392 = 0.33333334f * (0.0f - fTemp512);
			float fTemp575 = 0.5f * fTemp518;
			float fThen393 = fTemp575 - 0.083333336f * mydsp_faustpower4_f(fTemp496);
			float fElse393 = fSlow313 * fTemp495;
			float fThen394 = ((fTemp496 >= 1.0f) ? fElse393 : fThen393);
			float fElse394 = 0.33333334f * (0.0f - fSlow314 * fTemp495);
			float fTemp576 = 0.5f * (fTemp496 + fVec13[1]);
			float fThen395 = 0.6666667f * float((fTemp576 > 0.0f) - (fTemp576 < 0.0f));
			float fElse395 = fTemp576 - 0.33333334f * mydsp_faustpower3_f(fTemp576);
			float fThen396 = (((fTemp496 <= -1.0f) ? fElse394 : fThen394) - ((fVec13[1] <= -1.0f) ? fElse392 : fThen392)) / fTemp515;
			float fElse396 = (((fTemp576 < 1.0f) & (fTemp576 > -1.0f)) ? fElse395 : fThen395);
			int iTemp577 = (fVec13[2] <= 1.0f) & (fVec13[2] >= -1.0f);
			float fTemp578 = 0.5f * fTemp506;
			float fTemp579 = float((fVec13[2] > 0.0f) - (fVec13[2] < 0.0f));
			float fTemp580 = mydsp_faustpower3_f(fVec13[2]);
			float fThen397 = fTemp579 * (fTemp578 + -0.16666667f);
			float fElse397 = 0.33333334f * fTemp580;
			int iTemp581 = (fVec13[1] <= 1.0f) & (fVec13[1] >= -1.0f);
			float fTemp582 = float((fVec13[1] > 0.0f) - (fVec13[1] < 0.0f));
			float fTemp583 = fVec13[1] * fTemp582;
			float fThen398 = fTemp583 + -0.5f;
			float fTemp584 = ((iTemp581) ? fTemp574 : fThen398);
			float fTemp585 = fVec13[2] * fTemp579;
			float fThen399 = fTemp585 + -0.5f;
			float fTemp586 = mydsp_faustpower3_f(fVec13[1]);
			float fThen400 = fTemp582 * (fTemp574 + -0.16666667f);
			float fElse400 = 0.33333334f * fTemp586;
			float fTemp587 = ((iTemp581) ? fElse400 : fThen400);
			float fThen401 = (fTemp587 + fVec13[2] * (((iTemp577) ? fTemp578 : fThen399) - fTemp584) - ((iTemp577) ? fElse397 : fThen397)) / fTemp498;
			float fElse401 = 0.5f * fTemp535;
			int iTemp588 = (fTemp496 <= 1.0f) & (fTemp496 >= -1.0f);
			float fTemp589 = float((fTemp496 > 0.0f) - (fTemp496 < 0.0f));
			float fTemp590 = mydsp_faustpower3_f(fTemp496);
			float fThen402 = fTemp589 * (fTemp575 + -0.16666667f);
			float fElse402 = 0.33333334f * fTemp590;
			float fTemp591 = fTemp495 * fTemp589;
			float fTemp592 = fSlow306 * fTemp591;
			float fThen403 = fTemp592 + -0.5f;
			float fThen404 = (fSlow306 * fTemp495 * (((iTemp588) ? fTemp575 : fThen403) - fTemp584) + fTemp587 - ((iTemp588) ? fElse402 : fThen402)) / fTemp516;
			float fElse404 = 0.5f * fTemp540;
			float fThen405 = ((iTemp573) ? fElse396 : fThen396);
			float fElse405 = ((iTemp517) ? fElse404 : fThen404) + ((iTemp497) ? fElse401 : fThen401);
			float fTemp593 = std::fabs(fVec13[2]);
			float fTemp594 = std::log(fTemp593 + 1.0f);
			float fTemp595 = std::fabs(fVec13[1]);
			float fTemp596 = std::log(fTemp595 + 1.0f);
			float fTemp597 = fTemp582 * (0.5f * (fTemp508 + (3.0f - 2.0f * (fTemp595 - fTemp596))) + -1.5f);
			float fTemp598 = std::fabs(fTemp514);
			float fThen406 = (fTemp597 + fVec13[2] * (fTemp596 + fTemp593 - (fTemp595 + fTemp594)) - fTemp579 * (0.5f * (fTemp506 + (3.0f - 2.0f * (fTemp593 - fTemp594))) + -1.5f)) / fTemp498;
			float fElse406 = 0.16666667f * (fTemp513 / (fTemp598 + 1.0f));
			float fTemp599 = std::fabs(fTemp496);
			float fTemp600 = std::log(fTemp599 + 1.0f);
			float fTemp601 = std::fabs(fTemp524);
			float fThen407 = (fSlow306 * fTemp495 * (fTemp599 + fTemp596 - (fTemp600 + fTemp595)) + fTemp597 - fTemp589 * (0.5f * (fTemp518 + (3.0f - 2.0f * (fTemp599 - fTemp600))) + -1.5f)) / fTemp516;
			float fElse407 = 0.16666667f * (fTemp523 / (fTemp601 + 1.0f));
			int iTemp602 = fTemp593 <= 2.0f;
			float fThen408 = 0.5f * fTemp506 * fTemp579;
			float fElse408 = 0.020833334f * fTemp580 * (16.0f - 3.0f * fTemp585);
			int iTemp603 = fTemp595 <= 2.0f;
			float fElse409 = (0.0f - 0.083333336f * fTemp508) * (fTemp583 + -6.0f);
			float fTemp604 = ((iTemp603) ? fElse409 : fTemp595);
			float fElse410 = (0.0f - 0.083333336f * fTemp506) * (fTemp585 + -6.0f);
			float fThen411 = 0.5f * fTemp508 * fTemp582;
			float fElse411 = 0.020833334f * fTemp586 * (16.0f - 3.0f * fTemp583);
			float fTemp605 = ((iTemp603) ? fElse411 : fThen411);
			float fThen412 = float((fTemp514 > 0.0f) - (fTemp514 < 0.0f));
			float fElse412 = 0.33333334f * fTemp513 * (1.0f - 0.25f * fTemp598);
			float fThen413 = (fTemp605 + fVec13[2] * (((iTemp602) ? fElse410 : fTemp593) - fTemp604) - ((iTemp602) ? fElse408 : fThen408)) / fTemp498;
			float fElse413 = 0.5f * ((fTemp598 <= 2.0f) ? fElse412 : fThen412);
			int iTemp606 = fTemp599 <= 2.0f;
			float fThen414 = 0.5f * fTemp518 * fTemp589;
			float fElse414 = 0.020833334f * fTemp590 * (16.0f - fSlow316 * fTemp591);
			float fElse415 = (0.0f - 0.083333336f * fTemp518) * (fTemp592 + -6.0f);
			float fThen416 = float((fTemp524 > 0.0f) - (fTemp524 < 0.0f));
			float fElse416 = 0.33333334f * fTemp523 * (1.0f - 0.25f * fTemp601);
			float fThen417 = (fSlow306 * fTemp495 * (((iTemp606) ? fElse415 : fTemp599) - fTemp604) + fTemp605 - ((iTemp606) ? fElse414 : fThen414)) / fTemp516;
			float fElse417 = 0.5f * ((fTemp601 <= 2.0f) ? fElse416 : fThen416);
			float fThen418 = ((iTemp517) ? fElse407 : fThen407) + ((iTemp497) ? fElse406 : fThen406);
			float fElse418 = ((iTemp517) ? fElse417 : fThen417) + ((iTemp497) ? fElse413 : fThen413);
			float fThen419 = ((iSlow312) ? fElse405 : fThen405);
			float fElse419 = ((iSlow315) ? fElse418 : fThen418);
			float fTemp607 = fTemp560 - fTemp559;
			float fThen420 = (fVec13[2] * (fTemp555 - fTemp558) - 0.5f * (fTemp607 - (fTemp557 - fTemp556))) / fTemp498;
			float fElse420 = 0.16666667f * (fTemp513 / std::sqrt(mydsp_faustpower2_f(fTemp514) + 1.0f));
			float fThen421 = (fSlow306 * fTemp495 * (fTemp563 - fTemp558) + 0.5f * (fTemp565 - fTemp564 - fTemp607)) / fTemp516;
			float fElse421 = 0.16666667f * (fTemp523 / std::sqrt(mydsp_faustpower2_f(fTemp524) + 1.0f));
			float fTemp608 = fVec13[1] * fTemp569;
			float fThen422 = (fTemp568 + fVec13[2] * (fTemp566 + (fTemp569 - fTemp566)) - (fTemp567 + fTemp608)) / fTemp498;
			float fElse422 = 0.5f * std::sin(fTemp514);
			float fThen423 = (fTemp568 + fSlow306 * fTemp495 * (fTemp571 + (fTemp569 - fTemp571)) - (fTemp572 + fTemp608)) / fTemp516;
			float fElse423 = 0.5f * std::sin(fTemp524);
			float fThen424 = ((iTemp517) ? fElse421 : fThen421) + ((iTemp497) ? fElse420 : fThen420);
			float fElse424 = ((iTemp517) ? fElse423 : fThen423) + ((iTemp497) ? fElse422 : fThen422);
			float fThen425 = (std::log(std::min<float>(3.4028235e+38f, coshf(fTemp496))) - std::log(std::min<float>(3.4028235e+38f, coshf(fVec13[1])))) / fTemp515;
			float fElse425 = tanhf(fTemp576);
			float fThen426 = ((iSlow318) ? fElse424 : fThen424);
			float fElse426 = ((iTemp573) ? fElse425 : fThen425);
			float fThen427 = ((iSlow311) ? fElse419 : fThen419);
			float fElse427 = ((iSlow317) ? fElse426 : fThen426);
			float fThen428 = ((iSlow267) ? fElse390 : fThen390);
			float fElse428 = ((iSlow310) ? fElse427 : fThen427);
			float fTemp609 = fSlow319 * ((iSlow266) ? fElse428 : fThen428) + fSlow264 * fTemp267;
			float fTemp610 = fSlow321 * fTemp609;
			fRec50[0] = fSlow322 * fRec50[1] + fSlow323 * fRec49[1];
			float fTemp611 = fSlow325 * fTemp609;
			fVec14[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec50[0];
			fRec49[0] = fVec14[(IOTA0 - iConst8) & 8191];
			fRec52[0] = fSlow322 * fRec52[1] + fSlow323 * fRec51[1];
			fVec15[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec52[0];
			fRec51[0] = fVec15[(IOTA0 - iConst9) & 8191];
			fRec54[0] = fSlow322 * fRec54[1] + fSlow323 * fRec53[1];
			fVec16[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec54[0];
			fRec53[0] = fVec16[(IOTA0 - iConst10) & 8191];
			fRec56[0] = fSlow322 * fRec56[1] + fSlow323 * fRec55[1];
			fVec17[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec56[0];
			fRec55[0] = fVec17[(IOTA0 - iConst11) & 8191];
			fRec58[0] = fSlow322 * fRec58[1] + fSlow323 * fRec57[1];
			fVec18[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec58[0];
			fRec57[0] = fVec18[(IOTA0 - iConst12) & 8191];
			fRec60[0] = fSlow322 * fRec60[1] + fSlow323 * fRec59[1];
			fVec19[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec60[0];
			fRec59[0] = fVec19[(IOTA0 - iConst13) & 8191];
			fRec62[0] = fSlow322 * fRec62[1] + fSlow323 * fRec61[1];
			fVec20[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec62[0];
			fRec61[0] = fVec20[(IOTA0 - iConst14) & 8191];
			fRec64[0] = fSlow322 * fRec64[1] + fSlow323 * fRec63[1];
			fVec21[IOTA0 & 8191] = fSlow324 * fRec64[0] + fTemp611;
			fRec63[0] = fVec21[(IOTA0 - iConst15) & 8191];
			float fTemp612 = fRec63[0] + fRec61[0] + fRec59[0] + fRec57[0] + fRec55[0] + fRec53[0] + fRec51[0] + fRec49[0] + 0.5f * fRec47[1];
			fVec22[IOTA0 & 2047] = fTemp612;
			fRec47[0] = fVec22[(IOTA0 - iConst17) & 2047];
			float fRec48 = 0.0f - 0.5f * fTemp612;
			float fTemp613 = fRec47[1] + fRec48 + 0.5f * fRec45[1];
			fVec23[IOTA0 & 2047] = fTemp613;
			fRec45[0] = fVec23[(IOTA0 - iConst19) & 2047];
			float fRec46 = 0.0f - 0.5f * fTemp613;
			float fTemp614 = fRec45[1] + fRec46 + 0.5f * fRec43[1];
			fVec24[IOTA0 & 2047] = fTemp614;
			fRec43[0] = fVec24[(IOTA0 - iConst21) & 2047];
			float fRec44 = 0.0f - 0.5f * fTemp614;
			float fTemp615 = fRec43[1] + fRec44 + 0.5f * fRec41[1];
			fVec25[IOTA0 & 1023] = fTemp615;
			fRec41[0] = fVec25[(IOTA0 - iConst23) & 1023];
			float fRec42 = 0.0f - 0.5f * fTemp615;
			output0[i0] = FAUSTFLOAT(fRec42 + fRec41[1] + fTemp610);
			fRec74[0] = fSlow322 * fRec74[1] + fSlow323 * fRec73[1];
			fVec26[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec74[0];
			fRec73[0] = fVec26[(IOTA0 - iSlow327) & 8191];
			fRec76[0] = fSlow322 * fRec76[1] + fSlow323 * fRec75[1];
			fVec27[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec76[0];
			fRec75[0] = fVec27[(IOTA0 - iSlow328) & 8191];
			fRec78[0] = fSlow322 * fRec78[1] + fSlow323 * fRec77[1];
			fVec28[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec78[0];
			fRec77[0] = fVec28[(IOTA0 - iSlow329) & 8191];
			fRec80[0] = fSlow322 * fRec80[1] + fSlow323 * fRec79[1];
			fVec29[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec80[0];
			fRec79[0] = fVec29[(IOTA0 - iSlow330) & 8191];
			fRec82[0] = fSlow322 * fRec82[1] + fSlow323 * fRec81[1];
			fVec30[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec82[0];
			fRec81[0] = fVec30[(IOTA0 - iSlow331) & 8191];
			fRec84[0] = fSlow322 * fRec84[1] + fSlow323 * fRec83[1];
			fVec31[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec84[0];
			fRec83[0] = fVec31[(IOTA0 - iSlow332) & 8191];
			fRec86[0] = fSlow322 * fRec86[1] + fSlow323 * fRec85[1];
			fVec32[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec86[0];
			fRec85[0] = fVec32[(IOTA0 - iSlow333) & 8191];
			fRec88[0] = fSlow322 * fRec88[1] + fSlow323 * fRec87[1];
			fVec33[IOTA0 & 8191] = fTemp611 + fSlow324 * fRec88[0];
			fRec87[0] = fVec33[(IOTA0 - iSlow334) & 8191];
			float fTemp616 = fRec87[0] + fRec85[0] + fRec83[0] + fRec81[0] + fRec79[0] + fRec77[0] + fRec75[0] + fRec73[0] + 0.5f * fRec71[1];
			fVec34[IOTA0 & 2047] = fTemp616;
			fRec71[0] = fVec34[(IOTA0 - iSlow336) & 2047];
			float fRec72 = 0.0f - 0.5f * fTemp616;
			float fTemp617 = fRec71[1] + fRec72 + 0.5f * fRec69[1];
			fVec35[IOTA0 & 2047] = fTemp617;
			fRec69[0] = fVec35[(IOTA0 - iSlow337) & 2047];
			float fRec70 = 0.0f - 0.5f * fTemp617;
			float fTemp618 = fRec69[1] + fRec70 + 0.5f * fRec67[1];
			fVec36[IOTA0 & 2047] = fTemp618;
			fRec67[0] = fVec36[(IOTA0 - iSlow338) & 2047];
			float fRec68 = 0.0f - 0.5f * fTemp618;
			float fTemp619 = fRec67[1] + fRec68 + 0.5f * fRec65[1];
			fVec37[IOTA0 & 2047] = fTemp619;
			fRec65[0] = fVec37[(IOTA0 - iSlow339) & 2047];
			float fRec66 = 0.0f - 0.5f * fTemp619;
			output1[i0] = FAUSTFLOAT(fRec65[1] + fRec66 + fTemp610);
			iVec0[1] = iVec0[0];
			iRec7[1] = iRec7[0];
			iVec1[1] = iVec1[0];
			iRec6[1] = iRec6[0];
			iRec9[1] = iRec9[0];
			iVec2[1] = iVec2[0];
			iRec8[1] = iRec8[0];
			iRec11[1] = iRec11[0];
			iVec3[1] = iVec3[0];
			iRec10[1] = iRec10[0];
			fRec13[1] = fRec13[0];
			fVec4[1] = fVec4[0];
			IOTA0 = IOTA0 + 1;
			iRec15[1] = iRec15[0];
			iRec16[1] = iRec16[0];
			fRec14[1] = fRec14[0];
			fRec17[1] = fRec17[0];
			fVec6[1] = fVec6[0];
			iRec19[1] = iRec19[0];
			iRec20[1] = iRec20[0];
			fRec18[1] = fRec18[0];
			fRec21[1] = fRec21[0];
			fVec8[1] = fVec8[0];
			iRec23[1] = iRec23[0];
			iRec24[1] = iRec24[0];
			fRec22[1] = fRec22[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fVec11[2] = fVec11[1];
			fVec11[1] = fVec11[0];
			fVec12[2] = fVec12[1];
			fVec12[1] = fVec12[0];
			fVec13[2] = fVec13[1];
			fVec13[1] = fVec13[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec47[1] = fRec47[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec74[1] = fRec74[0];
			fRec73[1] = fRec73[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "amaranthgirl.dsp"
	#define FAUST_CLASS_NAME "mydsp"
	#define FAUST_COMPILATION_OPIONS "-a /usr/local/share/faust/juce/juce-plugin.cpp -lang cpp -i -scn base_dsp -es 1 -mcd 16 -uim -single -ftz 0"
	#define FAUST_INPUTS 0
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 209
	#define FAUST_PASSIVES 0

	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  0", fCheckbox47);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  1", fCheckbox46);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  2", fCheckbox45);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  3", fCheckbox44);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  4", fCheckbox43);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  5", fCheckbox42);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  6", fCheckbox41);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  7", fCheckbox40);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  8", fCheckbox39);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a  9", fCheckbox38);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a 10", fCheckbox37);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a 11", fCheckbox36);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a 12", fCheckbox35);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a 13", fCheckbox34);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a 14", fCheckbox33);
	FAUST_ADDCHECKBOX("[0]seq/[0]env trig a/a 15", fCheckbox32);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  0", fCheckbox31);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  1", fCheckbox30);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  2", fCheckbox29);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  3", fCheckbox28);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  4", fCheckbox27);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  5", fCheckbox26);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  6", fCheckbox25);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  7", fCheckbox24);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  8", fCheckbox23);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b  9", fCheckbox22);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b 10", fCheckbox21);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b 11", fCheckbox20);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b 12", fCheckbox19);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b 13", fCheckbox18);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b 14", fCheckbox17);
	FAUST_ADDCHECKBOX("[0]seq/[1]env trig b/b 15", fCheckbox16);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  0", fCheckbox15);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  1", fCheckbox14);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  2", fCheckbox13);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  3", fCheckbox12);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  4", fCheckbox11);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  5", fCheckbox10);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  6", fCheckbox9);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  7", fCheckbox8);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  8", fCheckbox7);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c  9", fCheckbox6);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c 10", fCheckbox5);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c 11", fCheckbox4);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c 12", fCheckbox3);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c 13", fCheckbox2);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c 14", fCheckbox1);
	FAUST_ADDCHECKBOX("[0]seq/[2]env trig c/c 15", fCheckbox0);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  0", fEntry66, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  1", fEntry67, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  2", fEntry68, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  3", fEntry69, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  4", fEntry70, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  5", fEntry71, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  6", fEntry72, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  7", fEntry73, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  8", fEntry74, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t  9", fEntry75, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t 10", fEntry76, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t 11", fEntry77, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t 12", fEntry78, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t 13", fEntry79, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t 14", fEntry80, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[5]t val/t 15", fEntry81, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  0", fEntry50, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  1", fEntry51, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  2", fEntry52, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  3", fEntry53, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  4", fEntry54, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  5", fEntry55, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  6", fEntry56, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  7", fEntry57, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  8", fEntry58, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x  9", fEntry59, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x 10", fEntry60, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x 11", fEntry61, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x 12", fEntry62, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x 13", fEntry63, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x 14", fEntry64, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[6]x mod/x 15", fEntry65, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  0", fEntry34, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  1", fEntry35, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  2", fEntry36, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  3", fEntry37, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  4", fEntry38, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  5", fEntry39, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  6", fEntry40, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  7", fEntry41, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  8", fEntry42, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y  9", fEntry43, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y 10", fEntry44, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y 11", fEntry45, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y 12", fEntry46, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y 13", fEntry47, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y 14", fEntry48, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[7]y mod/y 15", fEntry49, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  0", fEntry18, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  1", fEntry19, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  2", fEntry20, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  3", fEntry21, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  4", fEntry22, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  5", fEntry23, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  6", fEntry24, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  7", fEntry25, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  8", fEntry26, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z  9", fEntry27, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z 10", fEntry28, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z 11", fEntry29, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z 12", fEntry30, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z 13", fEntry31, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z 14", fEntry32, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[8]z mod/z 15", fEntry33, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  0", fEntry2, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  1", fEntry3, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  2", fEntry4, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  3", fEntry5, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  4", fEntry6, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  5", fEntry7, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  6", fEntry8, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  7", fEntry9, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  8", fEntry10, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a  9", fEntry11, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a 10", fEntry12, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a 11", fEntry13, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a 12", fEntry14, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a 13", fEntry15, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a 14", fEntry16, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[9]a trans/a 15", fEntry17, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  0", fEntry85, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  1", fEntry86, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  2", fEntry87, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  3", fEntry88, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  4", fEntry89, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  5", fEntry90, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  6", fEntry91, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  7", fEntry92, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  8", fEntry93, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b  9", fEntry94, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b 10", fEntry95, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b 11", fEntry96, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b 12", fEntry97, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b 13", fEntry98, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b 14", fEntry99, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[a]b trans/b 15", fEntry100, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  0", fEntry103, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  1", fEntry104, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  2", fEntry105, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  3", fEntry106, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  4", fEntry107, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  5", fEntry108, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  6", fEntry109, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  7", fEntry110, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  8", fEntry111, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c  9", fEntry112, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c 10", fEntry113, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c 11", fEntry114, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c 12", fEntry115, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c 13", fEntry116, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c 14", fEntry117, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/[b]c trans/c 15", fEntry118, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[0]key/quantization", fHslider0, 0.0f, 0.0f, 2.0f, 1.0f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[0]key/root note", fEntry82, 0.0f, 0.0f, 11.5f, 0.1f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[1]length/active steps a", fEntry1, 16.0f, 1.0f, 16.0f, 1.0f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[1]length/active steps b", fEntry84, 16.0f, 1.0f, 16.0f, 1.0f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[1]length/active steps c", fEntry102, 16.0f, 1.0f, 16.0f, 1.0f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[2]seq speed/bpm a", fEntry0, 1.2e+02f, 0.0f, 6e+05f, 0.001f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[2]seq speed/bpm b", fEntry83, 1.2e+02f, 0.0f, 6e+05f, 0.001f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[2]seq speed/bpm c", fEntry101, 1.2e+02f, 0.0f, 6e+05f, 0.001f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[3]env clock/bpm a", fEntry121, 1.2e+02f, 0.0f, 6e+05f, 0.001f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[3]env clock/bpm b", fEntry120, 1.2e+02f, 0.0f, 6e+05f, 0.001f);
	FAUST_ADDNUMENTRY("[0]seq/controls/[3]env clock/bpm c", fEntry119, 1.2e+02f, 0.0f, 6e+05f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[3]mult/x", fHslider4, 1.0f, 0.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[3]mult/y", fHslider3, 1.0f, 0.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[3]mult/z", fHslider2, 1.0f, 0.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[4]trans mult/a", fHslider1, 1.0f, 0.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[4]trans mult/b", fHslider8, 1.0f, 0.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[4]trans mult/c", fHslider9, 1.0f, 0.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[d]range/min (psych!)", fHslider6, 0.0f, 0.0f, 128.0f, 0.1f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[d]range/max", fHslider5, 36.0f, 1.0f, 128.0f, 0.1f);
	FAUST_ADDHORIZONTALSLIDER("[0]seq/controls/[d]range/octave", fHslider7, 0.0f, -8.0f, 8.0f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/[0]gain/a", fVslider6, 0.1f, 0.0f, 2.0f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/[0]gain/b", fVslider4, 0.1f, 0.0f, 2.0f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/[0]gain/c", fVslider2, 0.1f, 0.0f, 2.0f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/[1]env release/a", fVslider5, 0.1f, 0.0f, 8.0f, 1e-05f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/[1]env release/b", fVslider3, 0.1f, 0.0f, 8.0f, 1e-05f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/[1]env release/c", fVslider1, 0.1f, 0.0f, 8.0f, 1e-05f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/filter 1 cf", fVslider7, 2e+04f, 0.0f, 2.1e+04f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/filter 1 q", fVslider8, 1.0f, 0.001f, 1e+02f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/clip", fVslider0, 0.5f, 0.0f, 1.0f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/post gain", fVslider9, 0.5f, 0.0f, 2.0f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/filter 2 cf", fVslider10, 2e+04f, 0.0f, 2.1e+04f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/[0]out/filter 2 q", fVslider11, 1.0f, 0.001f, 1e+02f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/Freeverb/[0]/Damp", fVslider25, 0.5f, 0.0f, 1.0f, 0.025f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/Freeverb/[0]/RoomSize", fVslider26, 0.5f, 0.0f, 1.0f, 0.025f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/Freeverb/[0]/Stereo Spread", fVslider27, 0.5f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/Freeverb/Wet", fVslider24, 0.3333f, 0.0f, 1.0f, 0.025f);
	FAUST_ADDCHECKBOX("[1]sound/effects/dandeliongirl/space windows", fCheckbox48);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/dandeliongirl/window length (s)", fVslider14, 0.1f, 0.001f, 4.0f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/dandeliongirl/crossfade dur (s)", fVslider15, 0.1f, 0.001f, 1.0f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/dandeliongirl/shift (semitones)", fVslider13, 1.0f, -24.0f, 24.0f, 0.001f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/dandeliongirl/wet", fVslider12, 0.0f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/nailgirl/0/0 amount", fVslider20, 1.0f, 1.0f, 1e+02f, 0.01f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/nailgirl/0/0 function", fVslider19, 0.0f, 0.0f, 13.0f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/nailgirl/1/1 amount", fVslider21, 1.0f, 1.0f, 1e+02f, 0.01f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/nailgirl/1/1 function", fVslider18, 0.0f, 0.0f, 13.0f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/nailgirl/2/2 amount", fVslider22, 1.0f, 1.0f, 1e+02f, 0.01f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/nailgirl/2/2 function", fVslider17, 0.0f, 0.0f, 13.0f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/nailgirl/post gain", fVslider23, 0.5f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDVERTICALSLIDER("[1]sound/effects/nailgirl/wet", fVslider16, 0.0f, 0.0f, 1.0f, 0.01f);

	#define FAUST_LIST_ACTIVES(p) \
		p(CHECKBOX, a__0, "[0]seq/[0]env trig a/a  0", fCheckbox47, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__1, "[0]seq/[0]env trig a/a  1", fCheckbox46, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__2, "[0]seq/[0]env trig a/a  2", fCheckbox45, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__3, "[0]seq/[0]env trig a/a  3", fCheckbox44, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__4, "[0]seq/[0]env trig a/a  4", fCheckbox43, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__5, "[0]seq/[0]env trig a/a  5", fCheckbox42, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__6, "[0]seq/[0]env trig a/a  6", fCheckbox41, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__7, "[0]seq/[0]env trig a/a  7", fCheckbox40, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__8, "[0]seq/[0]env trig a/a  8", fCheckbox39, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a__9, "[0]seq/[0]env trig a/a  9", fCheckbox38, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a_10, "[0]seq/[0]env trig a/a 10", fCheckbox37, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a_11, "[0]seq/[0]env trig a/a 11", fCheckbox36, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a_12, "[0]seq/[0]env trig a/a 12", fCheckbox35, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a_13, "[0]seq/[0]env trig a/a 13", fCheckbox34, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a_14, "[0]seq/[0]env trig a/a 14", fCheckbox33, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, a_15, "[0]seq/[0]env trig a/a 15", fCheckbox32, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__0, "[0]seq/[1]env trig b/b  0", fCheckbox31, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__1, "[0]seq/[1]env trig b/b  1", fCheckbox30, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__2, "[0]seq/[1]env trig b/b  2", fCheckbox29, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__3, "[0]seq/[1]env trig b/b  3", fCheckbox28, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__4, "[0]seq/[1]env trig b/b  4", fCheckbox27, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__5, "[0]seq/[1]env trig b/b  5", fCheckbox26, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__6, "[0]seq/[1]env trig b/b  6", fCheckbox25, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__7, "[0]seq/[1]env trig b/b  7", fCheckbox24, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__8, "[0]seq/[1]env trig b/b  8", fCheckbox23, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b__9, "[0]seq/[1]env trig b/b  9", fCheckbox22, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b_10, "[0]seq/[1]env trig b/b 10", fCheckbox21, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b_11, "[0]seq/[1]env trig b/b 11", fCheckbox20, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b_12, "[0]seq/[1]env trig b/b 12", fCheckbox19, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b_13, "[0]seq/[1]env trig b/b 13", fCheckbox18, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b_14, "[0]seq/[1]env trig b/b 14", fCheckbox17, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, b_15, "[0]seq/[1]env trig b/b 15", fCheckbox16, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__0, "[0]seq/[2]env trig c/c  0", fCheckbox15, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__1, "[0]seq/[2]env trig c/c  1", fCheckbox14, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__2, "[0]seq/[2]env trig c/c  2", fCheckbox13, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__3, "[0]seq/[2]env trig c/c  3", fCheckbox12, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__4, "[0]seq/[2]env trig c/c  4", fCheckbox11, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__5, "[0]seq/[2]env trig c/c  5", fCheckbox10, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__6, "[0]seq/[2]env trig c/c  6", fCheckbox9, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__7, "[0]seq/[2]env trig c/c  7", fCheckbox8, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__8, "[0]seq/[2]env trig c/c  8", fCheckbox7, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c__9, "[0]seq/[2]env trig c/c  9", fCheckbox6, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c_10, "[0]seq/[2]env trig c/c 10", fCheckbox5, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c_11, "[0]seq/[2]env trig c/c 11", fCheckbox4, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c_12, "[0]seq/[2]env trig c/c 12", fCheckbox3, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c_13, "[0]seq/[2]env trig c/c 13", fCheckbox2, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c_14, "[0]seq/[2]env trig c/c 14", fCheckbox1, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(CHECKBOX, c_15, "[0]seq/[2]env trig c/c 15", fCheckbox0, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(NUMENTRY, t__0, "[0]seq/[5]t val/t  0", fEntry66, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__1, "[0]seq/[5]t val/t  1", fEntry67, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__2, "[0]seq/[5]t val/t  2", fEntry68, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__3, "[0]seq/[5]t val/t  3", fEntry69, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__4, "[0]seq/[5]t val/t  4", fEntry70, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__5, "[0]seq/[5]t val/t  5", fEntry71, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__6, "[0]seq/[5]t val/t  6", fEntry72, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__7, "[0]seq/[5]t val/t  7", fEntry73, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__8, "[0]seq/[5]t val/t  8", fEntry74, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t__9, "[0]seq/[5]t val/t  9", fEntry75, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t_10, "[0]seq/[5]t val/t 10", fEntry76, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t_11, "[0]seq/[5]t val/t 11", fEntry77, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t_12, "[0]seq/[5]t val/t 12", fEntry78, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t_13, "[0]seq/[5]t val/t 13", fEntry79, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t_14, "[0]seq/[5]t val/t 14", fEntry80, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, t_15, "[0]seq/[5]t val/t 15", fEntry81, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__0, "[0]seq/[6]x mod/x  0", fEntry50, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__1, "[0]seq/[6]x mod/x  1", fEntry51, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__2, "[0]seq/[6]x mod/x  2", fEntry52, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__3, "[0]seq/[6]x mod/x  3", fEntry53, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__4, "[0]seq/[6]x mod/x  4", fEntry54, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__5, "[0]seq/[6]x mod/x  5", fEntry55, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__6, "[0]seq/[6]x mod/x  6", fEntry56, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__7, "[0]seq/[6]x mod/x  7", fEntry57, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__8, "[0]seq/[6]x mod/x  8", fEntry58, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x__9, "[0]seq/[6]x mod/x  9", fEntry59, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x_10, "[0]seq/[6]x mod/x 10", fEntry60, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x_11, "[0]seq/[6]x mod/x 11", fEntry61, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x_12, "[0]seq/[6]x mod/x 12", fEntry62, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x_13, "[0]seq/[6]x mod/x 13", fEntry63, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x_14, "[0]seq/[6]x mod/x 14", fEntry64, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, x_15, "[0]seq/[6]x mod/x 15", fEntry65, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__0, "[0]seq/[7]y mod/y  0", fEntry34, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__1, "[0]seq/[7]y mod/y  1", fEntry35, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__2, "[0]seq/[7]y mod/y  2", fEntry36, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__3, "[0]seq/[7]y mod/y  3", fEntry37, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__4, "[0]seq/[7]y mod/y  4", fEntry38, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__5, "[0]seq/[7]y mod/y  5", fEntry39, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__6, "[0]seq/[7]y mod/y  6", fEntry40, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__7, "[0]seq/[7]y mod/y  7", fEntry41, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__8, "[0]seq/[7]y mod/y  8", fEntry42, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y__9, "[0]seq/[7]y mod/y  9", fEntry43, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y_10, "[0]seq/[7]y mod/y 10", fEntry44, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y_11, "[0]seq/[7]y mod/y 11", fEntry45, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y_12, "[0]seq/[7]y mod/y 12", fEntry46, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y_13, "[0]seq/[7]y mod/y 13", fEntry47, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y_14, "[0]seq/[7]y mod/y 14", fEntry48, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, y_15, "[0]seq/[7]y mod/y 15", fEntry49, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__0, "[0]seq/[8]z mod/z  0", fEntry18, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__1, "[0]seq/[8]z mod/z  1", fEntry19, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__2, "[0]seq/[8]z mod/z  2", fEntry20, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__3, "[0]seq/[8]z mod/z  3", fEntry21, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__4, "[0]seq/[8]z mod/z  4", fEntry22, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__5, "[0]seq/[8]z mod/z  5", fEntry23, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__6, "[0]seq/[8]z mod/z  6", fEntry24, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__7, "[0]seq/[8]z mod/z  7", fEntry25, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__8, "[0]seq/[8]z mod/z  8", fEntry26, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z__9, "[0]seq/[8]z mod/z  9", fEntry27, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z_10, "[0]seq/[8]z mod/z 10", fEntry28, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z_11, "[0]seq/[8]z mod/z 11", fEntry29, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z_12, "[0]seq/[8]z mod/z 12", fEntry30, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z_13, "[0]seq/[8]z mod/z 13", fEntry31, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z_14, "[0]seq/[8]z mod/z 14", fEntry32, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, z_15, "[0]seq/[8]z mod/z 15", fEntry33, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__0, "[0]seq/[9]a trans/a  0", fEntry2, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__1, "[0]seq/[9]a trans/a  1", fEntry3, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__2, "[0]seq/[9]a trans/a  2", fEntry4, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__3, "[0]seq/[9]a trans/a  3", fEntry5, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__4, "[0]seq/[9]a trans/a  4", fEntry6, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__5, "[0]seq/[9]a trans/a  5", fEntry7, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__6, "[0]seq/[9]a trans/a  6", fEntry8, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__7, "[0]seq/[9]a trans/a  7", fEntry9, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__8, "[0]seq/[9]a trans/a  8", fEntry10, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a__9, "[0]seq/[9]a trans/a  9", fEntry11, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a_10, "[0]seq/[9]a trans/a 10", fEntry12, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a_11, "[0]seq/[9]a trans/a 11", fEntry13, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a_12, "[0]seq/[9]a trans/a 12", fEntry14, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a_13, "[0]seq/[9]a trans/a 13", fEntry15, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a_14, "[0]seq/[9]a trans/a 14", fEntry16, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, a_15, "[0]seq/[9]a trans/a 15", fEntry17, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__0, "[0]seq/[a]b trans/b  0", fEntry85, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__1, "[0]seq/[a]b trans/b  1", fEntry86, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__2, "[0]seq/[a]b trans/b  2", fEntry87, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__3, "[0]seq/[a]b trans/b  3", fEntry88, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__4, "[0]seq/[a]b trans/b  4", fEntry89, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__5, "[0]seq/[a]b trans/b  5", fEntry90, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__6, "[0]seq/[a]b trans/b  6", fEntry91, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__7, "[0]seq/[a]b trans/b  7", fEntry92, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__8, "[0]seq/[a]b trans/b  8", fEntry93, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b__9, "[0]seq/[a]b trans/b  9", fEntry94, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b_10, "[0]seq/[a]b trans/b 10", fEntry95, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b_11, "[0]seq/[a]b trans/b 11", fEntry96, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b_12, "[0]seq/[a]b trans/b 12", fEntry97, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b_13, "[0]seq/[a]b trans/b 13", fEntry98, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b_14, "[0]seq/[a]b trans/b 14", fEntry99, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, b_15, "[0]seq/[a]b trans/b 15", fEntry100, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__0, "[0]seq/[b]c trans/c  0", fEntry103, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__1, "[0]seq/[b]c trans/c  1", fEntry104, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__2, "[0]seq/[b]c trans/c  2", fEntry105, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__3, "[0]seq/[b]c trans/c  3", fEntry106, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__4, "[0]seq/[b]c trans/c  4", fEntry107, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__5, "[0]seq/[b]c trans/c  5", fEntry108, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__6, "[0]seq/[b]c trans/c  6", fEntry109, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__7, "[0]seq/[b]c trans/c  7", fEntry110, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__8, "[0]seq/[b]c trans/c  8", fEntry111, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c__9, "[0]seq/[b]c trans/c  9", fEntry112, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c_10, "[0]seq/[b]c trans/c 10", fEntry113, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c_11, "[0]seq/[b]c trans/c 11", fEntry114, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c_12, "[0]seq/[b]c trans/c 12", fEntry115, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c_13, "[0]seq/[b]c trans/c 13", fEntry116, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c_14, "[0]seq/[b]c trans/c 14", fEntry117, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(NUMENTRY, c_15, "[0]seq/[b]c trans/c 15", fEntry118, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(HORIZONTALSLIDER, quantization, "[0]seq/controls/[0]key/quantization", fHslider0, 0.0f, 0.0f, 2.0f, 1.0f) \
		p(NUMENTRY, root_note, "[0]seq/controls/[0]key/root note", fEntry82, 0.0f, 0.0f, 11.5f, 0.1f) \
		p(NUMENTRY, active_steps_a, "[0]seq/controls/[1]length/active steps a", fEntry1, 16.0f, 1.0f, 16.0f, 1.0f) \
		p(NUMENTRY, active_steps_b, "[0]seq/controls/[1]length/active steps b", fEntry84, 16.0f, 1.0f, 16.0f, 1.0f) \
		p(NUMENTRY, active_steps_c, "[0]seq/controls/[1]length/active steps c", fEntry102, 16.0f, 1.0f, 16.0f, 1.0f) \
		p(NUMENTRY, bpm_a, "[0]seq/controls/[2]seq speed/bpm a", fEntry0, 1.2e+02f, 0.0f, 6e+05f, 0.001f) \
		p(NUMENTRY, bpm_b, "[0]seq/controls/[2]seq speed/bpm b", fEntry83, 1.2e+02f, 0.0f, 6e+05f, 0.001f) \
		p(NUMENTRY, bpm_c, "[0]seq/controls/[2]seq speed/bpm c", fEntry101, 1.2e+02f, 0.0f, 6e+05f, 0.001f) \
		p(NUMENTRY, bpm_a, "[0]seq/controls/[3]env clock/bpm a", fEntry121, 1.2e+02f, 0.0f, 6e+05f, 0.001f) \
		p(NUMENTRY, bpm_b, "[0]seq/controls/[3]env clock/bpm b", fEntry120, 1.2e+02f, 0.0f, 6e+05f, 0.001f) \
		p(NUMENTRY, bpm_c, "[0]seq/controls/[3]env clock/bpm c", fEntry119, 1.2e+02f, 0.0f, 6e+05f, 0.001f) \
		p(HORIZONTALSLIDER, x, "[0]seq/controls/[3]mult/x", fHslider4, 1.0f, 0.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, y, "[0]seq/controls/[3]mult/y", fHslider3, 1.0f, 0.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, z, "[0]seq/controls/[3]mult/z", fHslider2, 1.0f, 0.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, a, "[0]seq/controls/[4]trans mult/a", fHslider1, 1.0f, 0.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, b, "[0]seq/controls/[4]trans mult/b", fHslider8, 1.0f, 0.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, c, "[0]seq/controls/[4]trans mult/c", fHslider9, 1.0f, 0.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, min_(psych!), "[0]seq/controls/[d]range/min (psych!)", fHslider6, 0.0f, 0.0f, 128.0f, 0.1f) \
		p(HORIZONTALSLIDER, max, "[0]seq/controls/[d]range/max", fHslider5, 36.0f, 1.0f, 128.0f, 0.1f) \
		p(HORIZONTALSLIDER, octave, "[0]seq/controls/[d]range/octave", fHslider7, 0.0f, -8.0f, 8.0f, 1.0f) \
		p(VERTICALSLIDER, a, "[1]sound/[0]out/[0]gain/a", fVslider6, 0.1f, 0.0f, 2.0f, 0.001f) \
		p(VERTICALSLIDER, b, "[1]sound/[0]out/[0]gain/b", fVslider4, 0.1f, 0.0f, 2.0f, 0.001f) \
		p(VERTICALSLIDER, c, "[1]sound/[0]out/[0]gain/c", fVslider2, 0.1f, 0.0f, 2.0f, 0.001f) \
		p(VERTICALSLIDER, a, "[1]sound/[0]out/[1]env release/a", fVslider5, 0.1f, 0.0f, 8.0f, 1e-05f) \
		p(VERTICALSLIDER, b, "[1]sound/[0]out/[1]env release/b", fVslider3, 0.1f, 0.0f, 8.0f, 1e-05f) \
		p(VERTICALSLIDER, c, "[1]sound/[0]out/[1]env release/c", fVslider1, 0.1f, 0.0f, 8.0f, 1e-05f) \
		p(VERTICALSLIDER, filter_1_cf, "[1]sound/[0]out/filter 1 cf", fVslider7, 2e+04f, 0.0f, 2.1e+04f, 0.001f) \
		p(VERTICALSLIDER, filter_1_q, "[1]sound/[0]out/filter 1 q", fVslider8, 1.0f, 0.001f, 1e+02f, 0.001f) \
		p(VERTICALSLIDER, clip, "[1]sound/[0]out/clip", fVslider0, 0.5f, 0.0f, 1.0f, 0.001f) \
		p(VERTICALSLIDER, post_gain, "[1]sound/[0]out/post gain", fVslider9, 0.5f, 0.0f, 2.0f, 0.001f) \
		p(VERTICALSLIDER, filter_2_cf, "[1]sound/[0]out/filter 2 cf", fVslider10, 2e+04f, 0.0f, 2.1e+04f, 0.001f) \
		p(VERTICALSLIDER, filter_2_q, "[1]sound/[0]out/filter 2 q", fVslider11, 1.0f, 0.001f, 1e+02f, 0.001f) \
		p(VERTICALSLIDER, Damp, "[1]sound/effects/Freeverb/[0]/Damp", fVslider25, 0.5f, 0.0f, 1.0f, 0.025f) \
		p(VERTICALSLIDER, RoomSize, "[1]sound/effects/Freeverb/[0]/RoomSize", fVslider26, 0.5f, 0.0f, 1.0f, 0.025f) \
		p(VERTICALSLIDER, Stereo_Spread, "[1]sound/effects/Freeverb/[0]/Stereo Spread", fVslider27, 0.5f, 0.0f, 1.0f, 0.01f) \
		p(VERTICALSLIDER, Wet, "[1]sound/effects/Freeverb/Wet", fVslider24, 0.3333f, 0.0f, 1.0f, 0.025f) \
		p(CHECKBOX, space_windows, "[1]sound/effects/dandeliongirl/space windows", fCheckbox48, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(VERTICALSLIDER, window_length_(s), "[1]sound/effects/dandeliongirl/window length (s)", fVslider14, 0.1f, 0.001f, 4.0f, 0.001f) \
		p(VERTICALSLIDER, crossfade_dur_(s), "[1]sound/effects/dandeliongirl/crossfade dur (s)", fVslider15, 0.1f, 0.001f, 1.0f, 0.001f) \
		p(VERTICALSLIDER, shift_(semitones), "[1]sound/effects/dandeliongirl/shift (semitones)", fVslider13, 1.0f, -24.0f, 24.0f, 0.001f) \
		p(VERTICALSLIDER, wet, "[1]sound/effects/dandeliongirl/wet", fVslider12, 0.0f, 0.0f, 1.0f, 0.01f) \
		p(VERTICALSLIDER, 0_amount, "[1]sound/effects/nailgirl/0/0 amount", fVslider20, 1.0f, 1.0f, 1e+02f, 0.01f) \
		p(VERTICALSLIDER, 0_function, "[1]sound/effects/nailgirl/0/0 function", fVslider19, 0.0f, 0.0f, 13.0f, 1.0f) \
		p(VERTICALSLIDER, 1_amount, "[1]sound/effects/nailgirl/1/1 amount", fVslider21, 1.0f, 1.0f, 1e+02f, 0.01f) \
		p(VERTICALSLIDER, 1_function, "[1]sound/effects/nailgirl/1/1 function", fVslider18, 0.0f, 0.0f, 13.0f, 1.0f) \
		p(VERTICALSLIDER, 2_amount, "[1]sound/effects/nailgirl/2/2 amount", fVslider22, 1.0f, 1.0f, 1e+02f, 0.01f) \
		p(VERTICALSLIDER, 2_function, "[1]sound/effects/nailgirl/2/2 function", fVslider17, 0.0f, 0.0f, 13.0f, 1.0f) \
		p(VERTICALSLIDER, post_gain, "[1]sound/effects/nailgirl/post gain", fVslider23, 0.5f, 0.0f, 1.0f, 0.01f) \
		p(VERTICALSLIDER, wet, "[1]sound/effects/nailgirl/wet", fVslider16, 0.0f, 0.0f, 1.0f, 0.01f) \

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
