import RestaurantDAO from "../dao/restaurantsDAO";

export default class RestaurantsController {
 static async apiGetRestaurants(req, res, next){
     const restaurantsPerPage = req.query.restaurantsPerPage ? parseInt(req) : 0
     const page = req.query.page? parseInt(req.query.page, 10): 0

     let filters = {}

     if (req.query)
 }

}