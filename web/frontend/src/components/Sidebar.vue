<template>
  <v-navigation-drawer class="cyan darken-1" 
        permanent
        app>
    <v-col
      height="140"
      class="blue-grey darken-3"
    >
      <div class="text-center">
        <v-avatar class="mb-4" color="grey darken-1" size="64">
          <v-img
            aspect-ratio="30"
            src="https://images.almatalent.fi/cx0,cy1,cw1140,ch855,650x/https://assets.almatalent.fi/image/1887dfab-fdfd-3291-89a7-ad3ffa65304e"
          />
        </v-avatar>
        <h2 class="cyan--text text--darken-1">Customer</h2>
      </div>
    </v-col>
    <v-divider></v-divider>
    <v-list rounded dense>
        <v-list-item class="item" v-for="link in links" :key="link.text" router :to="link.route">
          
          <v-list-item-action>
            <v-icon class="#202227--text">{{ link.icon }}</v-icon>
          </v-list-item-action>
          <v-list-item-content>
            <v-list-item-title class="#202227--text">{{ link.text }}</v-list-item-title>
          </v-list-item-content>
        </v-list-item>
    </v-list>
  </v-navigation-drawer>
</template>

<script>
export default {
  name: "Sidebar",
  props: ["drawer"],
  data() {
    return {
      links: [
        { icon: 'mdi-account', text: 'Home', route: '/home' },
        { icon: 'mdi-cash', text: 'Balance', route: '/balance' },
        { icon: 'mdi-credit-card', text: 'Cards', route: '/cards' },
        { icon: 'mdi-door', text: 'Logout', route: '/logout' }
      ],
    };
  },
};
</script>


<style scoped>
  .item {
    margin: 5px;
    border-radius: 4px;
  }
  .item:hover {
    background: #0097A7;
  }
  .item:active {
    background: #00838F;
  }
</style>



