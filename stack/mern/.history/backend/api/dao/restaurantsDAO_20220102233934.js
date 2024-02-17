let restaurants

export default class RestaurantDAO{
    static async injectDB(conn) {
        if(restaurants){
            return
        }
        try {
            restaurants = await conn.db(process.env.NS).collection('restaurants')

        } catch (e){
            console.error(
                `Unable to establish a collection handle in restaurantsDAO: ${e}`
            )
        }
    }

    static async getRestaurant ({
        filters =null,
        page=0,
        restaurantsPerPage = 20,
    } = {}){
        let query

        if(filters){
            if ('name' in filters){
                query = {$text: {$search: filters['name']}}
            }else if ('cuisine' in filters){
                query = { 'cuisine': {$eq: filters['cuisine']}}
            }else if ('zipcode' in filters){
                query = {"address.zipcode": {$eq: filters['zipcode']}}
            }
        }
        let cursor

        try {
            cursor = await restaurants.find(query)
        } catch (e){
            console.error(`Unable to issue find command ${e}`)
            return { restaurantsList: [], totalNumRestaurants: 0}
        }
        const displayCursor = cursor.limit(restaurantsPerPage).skip(restaurantsPerPage * page)
        try{
            const restaurantsList = await displayCursor.toArray()
            const totalNumRestaurants = page === 0? await restaurants.countDocument() : 0
            return {rest}
        }
    }
}