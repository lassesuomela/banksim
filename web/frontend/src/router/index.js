import Vue from 'vue'
import VueRouter from 'vue-router'
import LoginComponent from "../views/login.vue"
import HomeComponent from "../views/home.vue"
import RegisterComponent from "../views/register.vue"
import LogoutComponent from "../views/logout.vue"
import AccountsComponent from "../views/accounts.vue"
import CardsComponent from "../views/cards.vue"
import axios from "../axios"

Vue.use(VueRouter)

const routes = [
    {
        path: '/',
        redirect: "login"
    },
    {
        path: "/login",
        name: "Login",
        component: LoginComponent
        
    },
    {
        path: "/home",
        name: "Home",
        component: HomeComponent,
        meta:{
          requireAuth: true
        }
    },
    {
      path: "/accounts",
      name: "Accounts",
      component: AccountsComponent,
      meta:{
        requireAuth: true
      }
    },
    {
      path: "/cards",
      name: "Cards",
      component: CardsComponent,
      meta:{
        requireAuth: true
      }
    },
    {
        path: "/register",
        name: "Register",
        component: RegisterComponent
    },
    {
        path: "/logout",
        name: "Logout",
        component: LogoutComponent,
        meta:{
          requireAuth: true
        }
    }
  ]
  
  const router = new VueRouter({
    mode: 'history',
    base: process.env.BASE_URL,
    routes
  })
  
  router.beforeEach(async (to, from, next) => {
    if(to.matched.some(record=>record.meta.requireAuth)){
      try {
        const response = await axios.get("/api/user/info");
        if(response.data.user_ID){
          next();
        }
      }catch(err){
        if(err.response.status === 403 || err.response.status === 401){
          localStorage.removeItem("token");
          return router.replace("/login");
        }else{
          next();
        }
      }
    }else{
      next();
    }
  });

  router.beforeEach((to, from, next) => {
    document.title = `${to.name}`;
    next();
  });
  
  export default router
  