import RestaurantDAO from "../dao/restaurantsDAO";

export default class RestaurantsController {
 static async apiGetRestaurants(req, res, next){
     const restaurantsPerPage = req.query.restaurantsPerPage ? parseInt(req) : 0
     
 }

}