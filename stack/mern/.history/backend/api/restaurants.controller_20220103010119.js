import RestaurantDAO from "../dao/restaurantsDAO.js";

export default class RestaurantsController {
  static async apiGetRestaurants(req, res, next) {
    const restaurantsPerPage = req.query.restaurantsPerPage
      ? parseInt(req.query.restaurantsPerPage, 10)
      : 20;
    const page = req.query.page ? parseInt(req.query.page, 10) : 0;

    let filters = {};

    if (req.query.cuisine) {
      filters.cuisine = req.query.cuisine;
    } else if (req.query.zipcode) {
      filters.zipcode = req.query.zipcode;
    } else if (req.query.name) {
      filters.name = req.query.name;
    }

    const { restaurantsList, totalNumRestaurants, cursor } =
      await RestaurantDAO.getRestaurant({
        filters,
        page,
        restaurantsPerPage,
      });

    let response = {
      restaurants: restaurantsList,
      page: page,
      filters: filters,
      entries_per_page: restaurantsPerPage,
      total_results: totalNumRestaurants,
      cursor: cursor,
    };
    res.json(response);
  }

  static async apiGetRestaurantById(req, res, next) {
    try {
      let id = req.param.id || '';
      let restaurant = await RestaurantDAO.getRestaurantByID(id);
      if (!restaurant) {
        res.status(404).json({ error: "Not found" });
        return;
      }
      res.json(restaurant);
    } catch (e) {
      console.log(`api, ${e}`);
      res.status(500).json({ error: e });
    }
  }
}