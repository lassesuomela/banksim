<template>
   <v-row >
    <v-col cols="12" sm="8" >
      <v-card>
        <v-card-title class="cyan darken-1">
          <span class="font-weight-bold text-h5 blue-grey--text text--darken-3">Cards</span>
          <v-spacer></v-spacer>
         <v-icon color="blue-grey darken-3" >
            mdi-credit-card
         </v-icon>
         <span class="text-subtitle-1 blue-grey--text text--darken-3">Debit</span>
         <v-icon color="blue-grey darken-3" >
            mdi-credit-card-outline
         </v-icon>
         <span class="text-subtitle-1 blue-grey--text text--darken-3">Credit</span>
        </v-card-title>

        <v-list color="blue-grey darken-3" v-for="(item,index) in activityLog" :key="index">
          <v-list-item dark>
            <v-list-item-action>
              <v-icon>{{item.amount}}</v-icon>
            </v-list-item-action>

            <v-list-item-content>
              <v-list-item-title>{{ item.title }}</v-list-item-title>
            </v-list-item-content>
          </v-list-item>
          
          <v-divider dark inset></v-divider>        
        </v-list>
      </v-card>
    </v-col>
   </v-row>
</template>


<script>
    export default {
        name: "Dashboard",
        data() {
            return {
                activityLog: [
                    {title: 'card', amount: 'mdi-credit-card',},
                    {title: 'test', amount: 'mdi-credit-card-outline',},
                    {title: 'debit card', amount: 'mdi-credit-card',},
                    {title: 'credit card', amount: 'mdi-credit-card-outline',},

                ],
                
            }
        },

    }
    
</script>