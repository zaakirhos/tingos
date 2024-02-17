let restaurants

export default class RestaurantDAO{
    static async injectDB(conn) {
        if(restaurants){
            return
        }
        try {
            restaurants = await conn.db(proc)
        }
    }
}