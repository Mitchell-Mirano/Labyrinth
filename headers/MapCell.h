#ifndef MAPCELL_H
#define MAPCELL_H

class MapCell
    {
        private:
            /* data */
        public:
            MapCell();
            
            char id;

            bool isBlocked();   
            bool isTreasure();                     

        protected:

    };

#endif //MAPCELL_H