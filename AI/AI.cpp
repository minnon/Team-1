#include "AI.h"


  
        void AI::setShips(vector<Ship> newShips)
        {
            __ships = newShips;
        }

        void AI::setShipPath(Ship *shipToPath)
        {

        }

        /*void AI::updateVertex(vector<int> s, vector<int> neighbor)
        {
            
        }*/

        int AI::calculateDistance(pair<int,int> start, pair<int,int> stop)
        {
        	int x = stop.first - start.first;
        	int y = stop.second - start.second;

        	int z = sqrt(x*x + y*y);

        	return z;
        }

    	void AI::lineOfSight()
    	{

    	}

    	bool AI::createMapState(Sector currentSector)
    	{

    		vector<int> sectorSize = currentSector.getSize();

    		vector<vector<bool> > newStoredMapState (sectorSize[0], std::vector<bool>(sectorSize[1], 0));

            vector<Star> stars = currentSector.getStars();
            
            for (Star star : stars)
            {
                vector<int> starSize = star.getSize();

                vector<int> starPosition = star.getPosition();

                for (int x = starPosition[0]; x < starPosition[0] + starSize[0]; x++)
                {

                    newStoredMapState[x][starPosition[1]] = 1;

                    newStoredMapState[x][starPosition[1] + starSize[1]] = 1;
                }


                for (int y = starPosition[1]; y < starPosition[0] - starSize[0]; y--)
                {
                    newStoredMapState[starPosition[0]][y] = 1;
                    newStoredMapState[starPosition[0] + starSize[0]][y] = 1;
                }
            }
            
            if(checkMapState(newStoredMapState)){
                storedMapState=newStoredMapState;
                return true;
            }
            return false;

    	}

        vector<vector<bool>> AI::getMapState(){
            return storedMapState;
        }

		//true if different, false if same
		bool AI::checkMapState(vector<vector<bool> > newState)
		{
		    if(storedMapState==newState){
                return false;
            }
			     

		    return true;
		}
		//calculate the path for a ship and destination
		queue<pair<int,int>>* AI::calculatePath(Ship theShip, Pathfinder path )
		{
		    pair<int,int> curPos=theShip.getPosition();
		    queue<pair<int,int>>* pth = path.pathfind(theShip.getPosition(), theShip.getDestination());
            //queue<pair<int,int>> tmp_queue = *pth;

            //while(!tmp_queue.empty()){

                //std::cout << "X point: " << tmp_queue.front().first << "Y point: " << tmp_queue.front().second << endl;
                //tmp_queue.pop();
            //}

		    return pth;
		}
